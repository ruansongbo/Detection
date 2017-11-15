#ifndef CAMERA_H
#define CAMERA_H

#include <QDialog>
#include "HalconCpp.h"
#include "HDevThread.h"
#include <QtWidgets/QLabel>
namespace Ui {
class Camera;
}

class Camera : public QDialog
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();
	void tranLabel(QLabel *main);
	QImage getcameradata();
	QImage detection();
	HalconCpp::HTuple  hv_ValueList;
	QLabel *DisWin;
	int index;

private:
    Ui::Camera *ui;
	bool fileopen;
	bool paramadd;
	bool platefile;
	int capureIndex;
	QString cameramode;
	QList <QString> DeviceBuf;
	QList <QString> DeviceIPBuf;
	QList <QString> ImageFilesList;
	HalconCpp::HTuple CameraParameters;
	HalconCpp::HTuple hv_AcqHandle;
	HalconCpp::HObject ho_Image, cal_Image, ho_Map;
	HalconCpp::HTuple  hv_TmpCtrl_PlateDescription;
private slots:
	void capture();
	void addimage();
	void deletimage();
	void update_device();
	void calibrate_cameras();
	void selectdevice(int index);
	void startcamera();
	void importdata();
	void addparameters();
	void changemode(int mode);
	void importPlatedata();
	void addPlatedata();

signals:
	void cameraStart();
	void cameraStop();
};

#endif // CAMERA_H
