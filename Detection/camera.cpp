#include "camera.h"
#include "ui_camera.h"
#include "HalconCpp.h"
#include "HDevThread.h"
#include "qmessagebox.h"
#include "string.h"
#include "halcon2QT.h"
#include "qfiledialog.h"
#include "qfile.h"
#include "qtextstream.h"
using namespace HalconCpp;
Camera::Camera(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
	cameramode = "area_scan_division";
	capureIndex = 0;
	fileopen = false;
	paramadd = false;
	platefile = false;
	index = 0;
}

Camera::~Camera()
{
    delete ui;
}
void Camera::tranLabel(QLabel* main)
{
	DisWin = main;
}
void get_index_of_camera_model(HTuple hv_ValueList, HTuple hv_Model, HTuple *hv_DeviceIndex)
{

	// Local iconic variables

	// Local control variables
	HTuple  hv_Int, hv_IsNumber, hv_Index, hv_Substrings;
	HTuple  hv_CameraID;

	TupleNumber(hv_Model, &hv_Int);
	TupleIsNumber(hv_Int, &hv_IsNumber);
	if (0 != (hv_IsNumber != 1))
	{
		{
			HTuple end_val3 = (hv_ValueList.TupleLength()) - 1;
			HTuple step_val3 = 1;
			for (hv_Index = 0; hv_Index.Continue(end_val3, step_val3); hv_Index += step_val3)
			{
				TupleSplit(HTuple(hv_ValueList[hv_Index]), " ", &hv_Substrings);
				TupleSplit(HTuple(hv_Substrings[1]), ":", &hv_CameraID);
				if (0 != (HTuple(hv_CameraID[1]) == hv_Model))
				{
					TupleString(hv_Index, "d", &(*hv_DeviceIndex));
					break;
				}
			}
		}
	}
	else
	{
		(*hv_DeviceIndex) = hv_Model;
	}
	return;
	//
}
/*void Camera::update_device()
{
	// Local iconic variables
	HObject  ho_Image;

	// Local control variables
	HTuple  hv_RevInfo, hv_RevValue, hv_Information;

	InfoFramegrabber("DirectShow", "revision", &hv_RevInfo, &hv_RevValue);
	InfoFramegrabber("DirectShow", "info_boards", &hv_Information, &hv_ValueList);
	int i = 0, j = 0;
	QString temp = hv_ValueList[i].S().Text();
	DeviceBuf.push_back(temp.mid(0, 8));
	for (i; i < hv_ValueList.Length(); i++)
	{
		QString temp = hv_ValueList[i].S().Text();
		int num = DeviceBuf.length();
		if (DeviceBuf[j].compare(temp.mid(0, 8)) != 0)
		{
			DeviceBuf.push_back(temp.mid(0, 8));
			j++;
		}
	}
	ui->comboBox->clear();
	for (i = 0; i < DeviceBuf.length(); i++)
	{
		ui->comboBox->addItem(DeviceBuf[i]);
	}
}*/
void Camera::update_device()
{
	// Local iconic variables
	HObject  ho_Image;

	// Local control variables
	HTuple  hv_RevInfo, hv_RevValue, hv_Information;
	
	InfoFramegrabber("GigEVision", "revision", &hv_RevInfo, &hv_RevValue);
	InfoFramegrabber("GigEVision", "info_boards", &hv_Information, &hv_ValueList);
	int i = 0;
	DeviceBuf.clear();
	for (i; i < hv_ValueList.Length(); i++)
	{
		QString temp = hv_ValueList[i].S().Text();
		DeviceBuf.push_back(temp.mid(temp.indexOf(':')+1, temp.indexOf('|') - temp.indexOf(':')-2));
		DeviceIPBuf.push_back(temp.mid(temp.indexOf(':', temp.indexOf('|'))+1, temp.indexOf('|', temp.indexOf('|')+1) - temp.indexOf(':', temp.indexOf('|')) - 2));
	}
	ui->comboBox->clear();
	for (i = 0; i < DeviceBuf.length(); i++)
	{
		ui->comboBox->addItem(DeviceIPBuf[i]);
	}
}
void Camera::selectdevice(int index)
{
	// Local iconic variables
	HTuple  hv_MyCameraType, hv_MyDevice;
	HTuple  hv_MyPort;
	HTuple  hv_CurrentSettings;
	//Check for the proper CameraType, Device, and Port settings
	//(see output of info_framegrabber(..,'info_boards',..))
	//hv_MyCameraType = "default";
	//QString index_str = QString::number(index, 10);
	//hv_MyDevice = index_str.toStdString().data();
	//hv_MyPort = -1;
	//
	OpenFramegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "default", -1, "default", -1, "false", "default", DeviceBuf[index].toStdString().data(), 0, -1, &hv_AcqHandle);
	//OpenFramegrabber("GigEVision", 0, 0, 0, 0, 0, 0, "default", -1, "default", -1, "false", "default", "c42f90ff75c5_Hikvision_MVCE10030GM", 0, -1, &hv_AcqHandle);
}
void Camera::startcamera()
{
	HTuple  hv_DistortionCoeffs, hv_CarParamVirtualFixed;
	if (fileopen || paramadd)
	{
		//赋值相机内参（带畸变），标定得到的数据
		hv_DistortionCoeffs.Clear();
		hv_DistortionCoeffs[0] = 0;
		hv_DistortionCoeffs[1] = 0;
		hv_DistortionCoeffs[2] = 0;
		hv_DistortionCoeffs[3] = 0;
		hv_DistortionCoeffs[4] = 0;
		hv_CarParamVirtualFixed = CameraParameters;
		hv_CarParamVirtualFixed[1] = 0;
		//转化为无畸变内参,采用 adaptive 模式
		ChangeRadialDistortionCamPar("adaptive", CameraParameters, hv_DistortionCoeffs, &hv_CarParamVirtualFixed);
		//生成 map
		GenRadialDistortionMap(&ho_Map, CameraParameters, hv_CarParamVirtualFixed, "bilinear");
		emit cameraStart();
	}
	else
	{
		QMessageBox::about(NULL, "Error", "Camera Parameter Is Not Set");
	}
	
}

void Camera::importPlatedata()
{
	hv_TmpCtrl_PlateDescription = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("plate parameter(*.descr)")).toStdString().data();
	QList <QString> lines;
	QFile file(hv_TmpCtrl_PlateDescription.S().Text());
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::about(NULL, "Error", "Can Not Open File");
	}
	else
	{
		QTextStream stream(&file);
		QString line;
		int n = 1;
		while (!stream.atEnd()) {
			line = stream.readLine();
			lines.push_back(line);
		}
		file.close();
	}
	ui->lineEdit->setText(lines[16].mid(2,-1));
	ui->lineEdit_2->setText(lines[13].mid(2, -1));
	ui->lineEdit_3->setText(lines[10].mid(41, -1));
	ui->lineEdit_4->setText(QString("%1").arg(lines[31].mid(2, -1).toFloat()/lines[10].mid(41, -1).toFloat()*2));
	QMessageBox::about(NULL, "Error", "success");
	platefile = true;
}
void Camera::addPlatedata()
{

}
void Camera::capture()
{
	GrabImage(&ho_Image, hv_AcqHandle);
	QImage capture = Hobject2QImage(ho_Image);
	/*QImage capture;
	capture.load("./Resources/OK.png");*/
	capture.save(QString("capture_%1.png").arg(capureIndex), "PNG", 100);
	ui->listWidget->addItem(QString("capture_%1.png").arg(capureIndex));
	ImageFilesList.push_back(QString("capture_%1.png").arg(capureIndex));
	QImage test;
	test.load(QString("capture_%1.png").arg(capureIndex));
	QImage testImg = test.scaled(DisWin->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	DisWin->setPixmap(QPixmap::fromImage(testImg));
	DisWin->show();

}
void Camera::addimage()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("image(*.png)"));
	ui->listWidget->addItem(fileName.mid(fileName.lastIndexOf('/')+1));
	ImageFilesList.push_back(fileName);
}
void Camera::deletimage()
{
	ui->listWidget->takeItem(ui->listWidget->currentRow());
	ImageFilesList.removeAt(ui->listWidget->currentRow());
	
}
void Camera::importdata()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ", tr("camera parameter(*.dat)"));
	HTuple HfileName = fileName.toStdString().data();
	HTuple tempParameters;
	ReadCamPar(HfileName, &tempParameters);
	if (((cameramode.compare("area_scan_polynomial") == 0) && (tempParameters.Length() == 12)) || ((cameramode.compare("area_scan_division") == 0) && (tempParameters.Length() == 8)))
	{

		CameraParameters.Clear();	
		fileopen = true;
		if (cameramode.compare("area_scan_polynomial") == 0)
		{
			ui->lineEdit_5->setText(QString("%1").arg(tempParameters[6].D() * 1000000));
			ui->lineEdit_6->setText(QString("%1").arg(tempParameters[7].D() * 1000000));
			ui->lineEdit_7->setText(QString("%1").arg(tempParameters[0].D() * 1000));
			
		}
		if (cameramode.compare("area_scan_division") == 0)
		{
			ui->lineEdit_5->setText(QString("%1").arg(tempParameters[2].D() * 1000000));
			ui->lineEdit_6->setText(QString("%1").arg(tempParameters[3].D() * 1000000));
			ui->lineEdit_7->setText(QString("%1").arg(tempParameters[0].D() * 1000));
		}

		ReadCamPar(HfileName, &CameraParameters);
	}
	else
	{
		QMessageBox::about(NULL, "Error", "Wrong Camera Parameter File");
		fileopen = false;
	}	
}
void Camera::addparameters()
{
	if (cameramode.compare("area_scan_polynomial")==0)
	{
		CameraParameters[0] = ui->lineEdit_5->text().toFloat()/1000;
		CameraParameters[1] = 0;
		CameraParameters[2] = 0;
		CameraParameters[3] = 0;
		CameraParameters[4] = 0;
		CameraParameters[5] = 0;
		CameraParameters[6] = ui->lineEdit_6->text().toFloat() / 1000000;
		CameraParameters[7] = ui->lineEdit_7->text().toFloat() / 1000000;
		CameraParameters[8] = 0;
		CameraParameters[9] = 0;
		CameraParameters[10] = 0;
		CameraParameters[11] = 0;
		if ((CameraParameters[0] != 0) && (CameraParameters[6] != 0) && (CameraParameters[7] != 0))
		{
			paramadd = true;
		}
		else
		{
			paramadd = false;
		}
	}
	if (cameramode.compare("area_scan_division") == 0)
	{
		CameraParameters[0] = ui->lineEdit_5->text().toFloat() / 1000;
		CameraParameters[1] = 0;
		CameraParameters[2] = ui->lineEdit_6->text().toFloat() / 1000000;
		CameraParameters[3] = ui->lineEdit_7->text().toFloat() / 1000000;
		CameraParameters[4] = 0;
		CameraParameters[5] = 0;
		CameraParameters[6] = 0;
		CameraParameters[7] = 0;
		if ((CameraParameters[0] != 0) && (CameraParameters[2] != 0) && (CameraParameters[3] != 0))
		{
			paramadd = true;
		}
		else
		{
			paramadd = false;
		}
	}
	if ((cameramode.compare("area_scan_polynomial") != 0) && cameramode.compare("area_scan_division") != 0)
	{
		QMessageBox::about(NULL, "Error", "Wrong Camera Mode");
	}
}
void Camera::changemode(int mode)
{
	if (mode)
	{
		cameramode = "area_scan_polynomial";
		CameraParameters.Clear();
		paramadd = false;
		fileopen = false;
	}
	else
	{
		cameramode = "area_scan_division";
		CameraParameters.Clear();
		paramadd = false;
		fileopen = false;
	}
}
void Camera::calibrate_cameras()
{
	// Local iconic variables
	HObject  ho_Image;

	// Local control variables
	HTuple  hv_ImageFiles, hv_CalibHandle;
	HTuple  hv_TmpCtrl_FindCalObjParNames, hv_TmpCtrl_FindCalObjParValues;
	HTuple  hv_Index, hv_Error;
	HTuple  hv_DistortionCoeffs, hv_CarParamVirtualFixed;
	hv_ImageFiles = HTuple();
	for (int i = 0; i < ImageFilesList.length(); i++)
	{
		hv_ImageFiles[i] = ImageFilesList[i].toStdString().data();
	}
	hv_TmpCtrl_FindCalObjParNames.Clear();
	hv_TmpCtrl_FindCalObjParNames[0] = "gap_tolerance";
	hv_TmpCtrl_FindCalObjParNames[1] = "alpha";
	hv_TmpCtrl_FindCalObjParNames[2] = "skip_find_caltab";
	hv_TmpCtrl_FindCalObjParValues.Clear();
	hv_TmpCtrl_FindCalObjParValues[0] = 1;
	hv_TmpCtrl_FindCalObjParValues[1] = 1;
	hv_TmpCtrl_FindCalObjParValues[2] = "false";
	//创建标定数据（标定类型，相机数量，标定板数量，标定板模型句柄）
	CreateCalibData("calibration_object", 1, 1, &hv_CalibHandle);
	//设定相机参数
	SetCalibDataCamParam(hv_CalibHandle, 0, cameramode.toStdString().data(), CameraParameters);
	//指定标定描述文件
	SetCalibDataCalibObject(hv_CalibHandle, 0, hv_TmpCtrl_PlateDescription);
	ui->progressBar->setRange(0, (hv_ImageFiles.TupleLength()) - 1);
	{
		HTuple end_val34 = (hv_ImageFiles.TupleLength()) - 1;
		HTuple step_val34 = 1;

		for (hv_Index = 0; hv_Index.Continue(end_val34, step_val34); hv_Index += step_val34)
		{
			ReadImage(&ho_Image, HTuple(hv_ImageFiles[hv_Index]));
			FindCalibObject(ho_Image, hv_CalibHandle, 0, 0, hv_Index, hv_TmpCtrl_FindCalObjParNames,
				hv_TmpCtrl_FindCalObjParValues);
			ui->progressBar->setValue(hv_Index);
		}
	}
	//*******************************标定相机**************************************
	//标定相机，注意 calibrate_cameras 与 camera_calibration 的区别
	CalibrateCameras(hv_CalibHandle, &hv_Error);
	//*取相机内外参数
	GetCalibData(hv_CalibHandle, "camera", 0, "params", &CameraParameters);
	//********************保存相机内参，且该函数只能保存内参**********************
	WriteCamPar(CameraParameters, "CarParam.dat");
	//赋值相机内参（带畸变），标定得到的数据
	hv_DistortionCoeffs.Clear();
	hv_DistortionCoeffs[0] = 0;
	hv_DistortionCoeffs[1] = 0;
	hv_DistortionCoeffs[2] = 0;
	hv_DistortionCoeffs[3] = 0;
	hv_DistortionCoeffs[4] = 0;
	hv_CarParamVirtualFixed = CameraParameters;
	hv_CarParamVirtualFixed[1] = 0;
	//转化为无畸变内参,采用 adaptive 模式
	ChangeRadialDistortionCamPar("adaptive", CameraParameters, hv_DistortionCoeffs, &hv_CarParamVirtualFixed);
	//生成 map
	GenRadialDistortionMap(&ho_Map, CameraParameters, hv_CarParamVirtualFixed, "bilinear");
	ClearCalibData(hv_CalibHandle);
	
}
QImage Camera::getcameradata()
{
	//HObject tempImage;
	//GrabImage(&tempImage, hv_AcqHandle);
	//RotateImage(tempImage, &ho_Image, -90,"constant");
	GrabImage(&ho_Image, hv_AcqHandle);
	MapImage(ho_Image, ho_Map, &cal_Image);
	QImage Image = Hobject2QImage(cal_Image);
	return Image;
}
QImage Camera::detection()
{
	// Local iconic variables
	HObject  ho_Template1, ho_Marker_ROI, ho_Displayer_ROI;
	HObject  ho_UNION_Region, ho_Handle_ROI, ho_Hole_ROI, ho_Detect_ROI;
	HObject  ho_Surf_ROI, ho_Marker_Image, ho_Displayer_Image;
	HObject  ho_Handle_Image, ho_Hole_Image;
	HObject  ho_Marker_ImageAffinTrans, ho_Defect_Marker_Image;
	HObject  ho_Diff_Marker_Image, ho_Displayer_ImageAffinTrans;
	HObject  ho_Defect_Displayer_Image, ho_Diff_Displayer_Image;
	HObject  ho_Handle_ImageAffinTrans, ho_Defect_Handle_Image;
	HObject  ho_Diff_Handle_Image, ho_Hole_ImageAffinTrans, ho_Defect_Hole_Image;
	HObject  ho_Diff_Hole_Image, ho_Defect_Image, ho_ImageFFT;
	HObject  ho_ImageGauss, ho_ImageConvol, ho_IlluminationImage;
	HObject  ho_ImageSub, ho_ImageFilter, ho_EdgeAmplitude, ho_ImageInvert;
	HObject  ho_ImageScaleMax, ho_Edges, ho_RegionClosing, ho_ConnectedRegions;
	HObject  ho_SelectedRegions, ho_ImageCleared, ho_Regions1, ho_ImageResult;

	// Local control variables
	HTuple  hv_Marker_ROI_Row, hv_Marker_ROI_Column;
	HTuple  hv_Marker_ROI_Length1, hv_Marker_ROI_Length2, hv_Displayer_ROI_Row;
	HTuple  hv_Displayer_ROI_Column, hv_Displayer_ROI_Length1;
	HTuple  hv_Displayer_ROI_Length2, hv_Handle_ROI_Row, hv_Handle_ROI_Column;
	HTuple  hv_Handle_ROI_Length1, hv_Handle_ROI_Length2, hv_Hole_ROI_Row;
	HTuple  hv_Hole_ROI_Column, hv_Hole_ROI_Length1, hv_Hole_ROI_Length2;
	HTuple  hv_Marker_ID, hv_Displayer_ID, hv_Handle_ID, hv_Hole_ID;
	HTuple  hv_RowsF, hv_ColsF, hv_CoRRJunctions;
	HTuple  hv_CoRCJunctions, hv_CoCCJunctions, hv_RowArea;
	HTuple  hv_ColumnArea, hv_CoRRArea, hv_CoRCArea, hv_CoCCArea;
	HTuple  hv_RowsT, hv_ColsT, hv_CoRRJunctions1, hv_CoRCJunctions1;
	HTuple  hv_CoCCJunctions1, hv_RowArea1, hv_ColumnArea1;
	HTuple  hv_CoRRArea1, hv_CoRCArea1, hv_CoCCArea1, hv_HomMat2D;
	HTuple  hv_Points1, hv_Points2, hv_Marker_Row, hv_Marker_Column;
	HTuple  hv_Marker_Angle, hv_Marker_Score, hv_Marker_HomMat2DIdentity;
	HTuple  hv_Marker_HomMat2DTranslate, hv_Marker_HomMat2DRotate;
	HTuple  hv_Displayer_Row, hv_Displayer_Column, hv_Displayer_Angle;
	HTuple  hv_Displayer_Score, hv_Displayer_HomMat2DIdentity;
	HTuple  hv_Displayer_HomMat2DTranslate, hv_Displayer_HomMat2DRotate;
	HTuple  hv_Handle_Row, hv_Handle_Column, hv_Handle_Angle;
	HTuple  hv_Handle_Score, hv_Handle_HomMat2DIdentity, hv_Handle_HomMat2DTranslate;
	HTuple  hv_Handle_HomMat2DRotate, hv_Hole_Row, hv_Hole_Column;
	HTuple  hv_Hole_Angle, hv_Hole_Score, hv_Hole_HomMat2DIdentity;
	HTuple  hv_Hole_HomMat2DTranslate, hv_Hole_HomMat2DRotate;
	HTuple  hv_Width, hv_Height, hv_GNum, hv_RNum;

	ReadImage(&ho_Template1, "C:/Users/Administrator/Desktop/UpTemplate.png");

	hv_Marker_ROI_Row = 1961;
	hv_Marker_ROI_Column = 776;
	hv_Marker_ROI_Length1 = 107;
	hv_Marker_ROI_Length2 = 64;
	GenRectangle2(&ho_Marker_ROI, 1961, 776, HTuple(-0).TupleRad(), 107, 64);

	hv_Displayer_ROI_Row = 2920;
	hv_Displayer_ROI_Column = 1380;
	hv_Displayer_ROI_Length1 = 183;
	hv_Displayer_ROI_Length2 = 90;
	GenRectangle2(&ho_Displayer_ROI, 2920, 1380, HTuple(-0).TupleRad(), 183, 90);
	Union2(ho_Marker_ROI, ho_Displayer_ROI, &ho_UNION_Region);

	hv_Handle_ROI_Row = 2678;
	hv_Handle_ROI_Column = 2239;
	hv_Handle_ROI_Length1 = 47;
	hv_Handle_ROI_Length2 = 85;
	GenRectangle2(&ho_Handle_ROI, 2678, 2239, HTuple(-0).TupleRad(), 47, 85);
	Union2(ho_Handle_ROI, ho_UNION_Region, &ho_UNION_Region);

	hv_Hole_ROI_Row = 2922;
	hv_Hole_ROI_Column = 876;
	hv_Hole_ROI_Length1 = 19;
	hv_Hole_ROI_Length2 = 19;
	GenRectangle2(&ho_Hole_ROI, 2922, 876, HTuple(-0).TupleRad(), 19, 19);
	Union2(ho_Hole_ROI, ho_UNION_Region, &ho_UNION_Region);

	Complement(ho_UNION_Region, &ho_Detect_ROI);
	GenRectangle1(&ho_Surf_ROI, 1837.09, 509.775, 3495.59, 2263.62);
	Intersection(ho_Surf_ROI, ho_Detect_ROI, &ho_Detect_ROI);

	ReduceDomain(ho_Template1, ho_Marker_ROI, &ho_Marker_Image);
	CreateShapeModel(ho_Marker_Image, 10, -(HTuple(0).TupleRad()), HTuple(360).TupleRad(),
		"auto", "no_pregeneration", "ignore_local_polarity", 40, 10, &hv_Marker_ID);

	ReduceDomain(ho_Template1, ho_Displayer_ROI, &ho_Displayer_Image);
	CreateShapeModel(ho_Displayer_Image, 10, -(HTuple(0).TupleRad()), HTuple(360).TupleRad(),
		"auto", "no_pregeneration", "ignore_local_polarity", 40, 10, &hv_Displayer_ID);

	ReduceDomain(ho_Template1, ho_Handle_ROI, &ho_Handle_Image);
	CreateShapeModel(ho_Handle_Image, 10, -(HTuple(0).TupleRad()), HTuple(360).TupleRad(),
		"auto", "no_pregeneration", "ignore_local_polarity", 40, 10, &hv_Handle_ID);

	ReduceDomain(ho_Template1, ho_Hole_ROI, &ho_Hole_Image);
	CreateShapeModel(ho_Hole_Image, 10, -(HTuple(1).TupleRad()), HTuple(1).TupleRad(),
		"auto", "no_pregeneration", "ignore_local_polarity", 40, 10, &hv_Hole_ID);

	GrabImage(&ho_Image, hv_AcqHandle);
	MapImage(ho_Image, ho_Map, &cal_Image);
	RotateImage(cal_Image, &ho_Image, -90, "constant");
	PointsFoerstner(ho_Image, 1, 2, 3, 50, 0.1, "gauss", "true", &hv_RowsF, &hv_ColsF,
		&hv_CoRRJunctions, &hv_CoRCJunctions, &hv_CoCCJunctions, &hv_RowArea, &hv_ColumnArea,
		&hv_CoRRArea, &hv_CoRCArea, &hv_CoCCArea);
	PointsFoerstner(ho_Template1, 1, 2, 3, 50, 0.1, "gauss", "true", &hv_RowsT, &hv_ColsT,
		&hv_CoRRJunctions1, &hv_CoRCJunctions1, &hv_CoCCJunctions1, &hv_RowArea1,
		&hv_ColumnArea1, &hv_CoRRArea1, &hv_CoRCArea1, &hv_CoCCArea1);
	ProjMatchPointsRansac(ho_Image, ho_Template1, hv_RowsF, hv_ColsF, hv_RowsT,
		hv_ColsT, "ncc", 10, 0, 0, 648, 968, HTuple(HTuple(-10).TupleRad()).TupleConcat(HTuple(40).TupleRad()),
		0.5, "gold_standard", 10, 42, &hv_HomMat2D, &hv_Points1, &hv_Points2);
	ProjectiveTransImage(ho_Image, &ho_Image, hv_HomMat2D, "bilinear", "false",
		"false");

	FindShapeModel(ho_Image, hv_Marker_ID, HTuple(-5).TupleRad(), HTuple(5).TupleRad(),
		0.5, 1, 0.5, "least_squares_high", 8, 0.9, &hv_Marker_Row, &hv_Marker_Column,
		&hv_Marker_Angle, &hv_Marker_Score);
	HomMat2dIdentity(&hv_Marker_HomMat2DIdentity);
	HomMat2dTranslate(hv_Marker_HomMat2DIdentity, hv_Marker_ROI_Row - hv_Marker_Row,
		hv_Marker_ROI_Column - hv_Marker_Column, &hv_Marker_HomMat2DTranslate);
	HomMat2dRotate(hv_Marker_HomMat2DTranslate, -hv_Marker_Angle, hv_Marker_ROI_Row,
		hv_Marker_ROI_Column, &hv_Marker_HomMat2DRotate);
	AffineTransImage(ho_Image, &ho_Marker_ImageAffinTrans, hv_Marker_HomMat2DRotate,
		"constant", "false");
	ReduceDomain(ho_Marker_ImageAffinTrans, ho_Marker_ROI, &ho_Defect_Marker_Image
	);
	AbsDiffImage(ho_Marker_Image, ho_Defect_Marker_Image, &ho_Diff_Marker_Image,
		1);
	InvertImage(ho_Diff_Marker_Image, &ho_Diff_Marker_Image);

	FindShapeModel(ho_Image, hv_Displayer_ID, HTuple(-5).TupleRad(), HTuple(5).TupleRad(),
		0.5, 1, 0.5, "least_squares_high", 8, 0.9, &hv_Displayer_Row, &hv_Displayer_Column,
		&hv_Displayer_Angle, &hv_Displayer_Score);
	HomMat2dIdentity(&hv_Displayer_HomMat2DIdentity);
	HomMat2dTranslate(hv_Displayer_HomMat2DIdentity, hv_Displayer_ROI_Row - hv_Displayer_Row,
		hv_Displayer_ROI_Column - hv_Displayer_Column, &hv_Displayer_HomMat2DTranslate);
	HomMat2dRotate(hv_Displayer_HomMat2DTranslate, -hv_Displayer_Angle, hv_Displayer_ROI_Row,
		hv_Displayer_ROI_Column, &hv_Displayer_HomMat2DRotate);
	AffineTransImage(ho_Image, &ho_Displayer_ImageAffinTrans, hv_Displayer_HomMat2DRotate,
		"constant", "false");
	ReduceDomain(ho_Displayer_ImageAffinTrans, ho_Displayer_ROI, &ho_Defect_Displayer_Image
	);
	AbsDiffImage(ho_Displayer_Image, ho_Defect_Displayer_Image, &ho_Diff_Displayer_Image,
		1);
	InvertImage(ho_Diff_Displayer_Image, &ho_Diff_Displayer_Image);

	FindShapeModel(ho_Image, hv_Handle_ID, HTuple(-5).TupleRad(), HTuple(5).TupleRad(),
		0.5, 1, 0.5, "least_squares_high", 8, 0.9, &hv_Handle_Row, &hv_Handle_Column,
		&hv_Handle_Angle, &hv_Handle_Score);
	HomMat2dIdentity(&hv_Handle_HomMat2DIdentity);
	HomMat2dTranslate(hv_Handle_HomMat2DIdentity, hv_Handle_ROI_Row - hv_Handle_Row,
		hv_Handle_ROI_Column - hv_Handle_Column, &hv_Handle_HomMat2DTranslate);
	HomMat2dRotate(hv_Handle_HomMat2DTranslate, -hv_Handle_Angle, hv_Handle_ROI_Row,
		hv_Handle_ROI_Column, &hv_Handle_HomMat2DRotate);
	AffineTransImage(ho_Image, &ho_Handle_ImageAffinTrans, hv_Handle_HomMat2DRotate,
		"constant", "false");
	ReduceDomain(ho_Handle_ImageAffinTrans, ho_Handle_ROI, &ho_Defect_Handle_Image
	);
	AbsDiffImage(ho_Handle_Image, ho_Defect_Handle_Image, &ho_Diff_Handle_Image,
		1);
	InvertImage(ho_Diff_Handle_Image, &ho_Diff_Handle_Image);

	FindShapeModel(ho_Image, hv_Hole_ID, HTuple(-1).TupleRad(), HTuple(1).TupleRad(),
		0.5, 1, 0.5, "least_squares_high", 8, 0.9, &hv_Hole_Row, &hv_Hole_Column,
		&hv_Hole_Angle, &hv_Hole_Score);
	HomMat2dIdentity(&hv_Hole_HomMat2DIdentity);
	HomMat2dTranslate(hv_Hole_HomMat2DIdentity, hv_Hole_ROI_Row - hv_Hole_Row, hv_Hole_ROI_Column - hv_Hole_Column,
		&hv_Hole_HomMat2DTranslate);
	HomMat2dRotate(hv_Hole_HomMat2DTranslate, -hv_Hole_Angle, hv_Hole_ROI_Row, hv_Hole_ROI_Column,
		&hv_Hole_HomMat2DRotate);
	AffineTransImage(ho_Image, &ho_Hole_ImageAffinTrans, hv_Hole_HomMat2DRotate,
		"constant", "false");
	ReduceDomain(ho_Hole_ImageAffinTrans, ho_Hole_ROI, &ho_Defect_Hole_Image);
	AbsDiffImage(ho_Hole_Image, ho_Defect_Hole_Image, &ho_Diff_Hole_Image, 1);
	InvertImage(ho_Diff_Hole_Image, &ho_Diff_Hole_Image);

	ReduceDomain(ho_Image, ho_Detect_ROI, &ho_Defect_Image);
	GetImageSize(ho_Defect_Image, &hv_Width, &hv_Height);
	RftGeneric(ho_Defect_Image, &ho_ImageFFT, "to_freq", "none", "complex", hv_Width);
	GenGaussFilter(&ho_ImageGauss, 300, 300, 0, "n", "rft", hv_Width, hv_Height);
	ConvolFft(ho_ImageFFT, ho_ImageGauss, &ho_ImageConvol);
	RftGeneric(ho_ImageConvol, &ho_IlluminationImage, "from_freq", "none", "byte",
		hv_Width);
	SubImage(ho_Defect_Image, ho_IlluminationImage, &ho_ImageSub, 2, 100);
	MeanImage(ho_ImageSub, &ho_ImageFilter, 9, 9);
	SobelAmp(ho_Defect_Image, &ho_EdgeAmplitude, "sum_abs", 5);
	InvertImage(ho_EdgeAmplitude, &ho_ImageInvert);
	ScaleImageMax(ho_ImageInvert, &ho_ImageScaleMax);
	Threshold(ho_EdgeAmplitude, &ho_Edges, 11, 255);
	ClosingRectangle1(ho_Edges, &ho_RegionClosing, 3, 3);
	Connection(ho_RegionClosing, &ho_ConnectedRegions);
	SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, "area", "and", 15, 316792);
	FillUp(ho_SelectedRegions, &ho_SelectedRegions);

	GenImageProto(ho_Image, &ho_ImageCleared, 255);
	OverpaintGray(ho_ImageCleared, ho_Diff_Displayer_Image);
	OverpaintGray(ho_ImageCleared, ho_Diff_Marker_Image);
	OverpaintGray(ho_ImageCleared, ho_Diff_Handle_Image);
	OverpaintGray(ho_ImageCleared, ho_Diff_Hole_Image);
	Threshold(ho_ImageCleared, &ho_Regions1, 13, 215);
	DilationRectangle1(ho_Regions1, &ho_Regions1, 2, 7);
	ErosionRectangle1(ho_Regions1, &ho_Regions1, 2, 7);
	Connection(ho_Regions1, &ho_Regions1);
	SelectShape(ho_Regions1, &ho_Regions1, "height", "and", 0, 70);
	SelectShape(ho_Regions1, &ho_Regions1, "area", "and", 50.33, 1000);
	//CountObj(ho_Regions1, &hv_GNum);
	//CountObj(ho_SelectedRegions, &hv_RNum);
	//if (0 != (hv_GNum != 0))
	//{
	//	if (0 != (hv_RNum != 0))
	//	{
	//		PaintRegion(ho_Regions1, ho_Image, &ho_ImageResult, 255, "fill");
	//		PaintRegion(ho_SelectedRegions, ho_ImageResult, &ho_ImageResult, 255, "fill");
	//	}
	//	else
	//	{
	//		PaintRegion(ho_Regions1, ho_Image, &ho_ImageResult, 255, "fill");
	//	}
	//}
	//else
	//{
	//	if (0 != (hv_RNum != 0))
	//	{
	//		PaintRegion(ho_SelectedRegions, ho_Image, &ho_ImageResult, 255, "fill");
	//	}
	//	else
	//	{
	//		ho_ImageResult = ho_Image;
	//	}
	//}
	PaintRegion(ho_Regions1, ho_Image, &ho_ImageResult, 255, "fill");
	PaintRegion(ho_SelectedRegions, ho_ImageResult, &ho_ImageResult, 255, "fill");
	QString filename = QString("C:/Users/Administrator/Desktop/result%1.png").arg(index);
	WriteImage(ho_ImageResult, "png", 0, filename.toStdString().data());
	index++;
	QImage Image;
	Image.load(filename.toStdString().data());
	//QImage Image = Hobject2QImage(ho_ImageResult);
	return Image;
}