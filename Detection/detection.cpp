#include "detection.h"
#include "camera.h"
#include "connection.h"
#include "history.h"
#include "parameter.h"
#include "system.h"
#include "template.h"
#include "qobject.h"
#include "QMessageBox.h"


Detection::Detection(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	CameraWin = new Camera(this);
	camtimer = new QTimer(this);
	connect(camtimer, SIGNAL(timeout()), this, SLOT(timerUpDate()));
	QImage OK;
	QImage NG;
	QImage Template;
	//paint->begin(this);
	OK.load("./Resources/OK.png"); //"C:/Users/bb/Desktop/test.jpg");
	NG.load("./Resources/NG.png");
	Template.load("C:/Users/Administrator/Desktop/Template.png");
	QImage OKImg = OK.scaled(ui.masterlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage NGImg = NG.scaled(ui.masterlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage OKImg1 = OK.scaled(ui.resultlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage NGImg1 = NG.scaled(ui.resultlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage TemplateImg = Template.scaled(ui.label_4->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.label_4->setPixmap(QPixmap::fromImage(TemplateImg));
	ui.label_4->show();
	ui.masterlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.masterlabel->show();
	ui.Rsenlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.Rsenlabel->show();
	ui.Lsenlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.Lsenlabel->show();
	ui.resultlabel->setPixmap(QPixmap::fromImage(OKImg1));
	ui.resultlabel->show();
}

Detection::~Detection()
{
}

//void Detection::paintEvent(QPaintEvent*)
//{
//	paint = new QPainter;
//
//	paint->end();
//}
void Detection::camera_set()
{
	CameraWin->tranLabel(ui.label_3);
	CameraWin->setObjectName(QStringLiteral("CameraWin"));
	QObject::connect(CameraWin, SIGNAL(cameraStart()), this, SLOT(dis_image()));
	if (CameraWin->exec())
	{

	}
}
void Detection::dis_image()
{
	camtimer->start(2000);
	QImage Image = CameraWin->getcameradata();
	QMatrix matrix;
	matrix.rotate(90.0);
	Image = Image.transformed(matrix, Qt::FastTransformation);
	QImage ddImage = Image.scaled(ui.label_3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.label_3->setPixmap(QPixmap::fromImage(ddImage));
	ui.label_3->show();
	ui.pushButton->setText(QStringLiteral("开始检测"));
}
void Detection::timerUpDate()
{
	QImage Image = CameraWin->getcameradata();
	QMatrix matrix;
	matrix.rotate(90.0);
	Image = Image.transformed(matrix, Qt::FastTransformation);
	QImage ddImage = Image.scaled(ui.label_3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.label_3->setPixmap(QPixmap::fromImage(ddImage));
	ui.label_3->show();
}
void Detection::template_set()
{
	Template TemplateWin(this);
	if (TemplateWin.exec())
	{

	}
}
void Detection::paramter_set()
{
	Parameter ParameterWin(this);
	if (ParameterWin.exec())
	{

	}
}
void Detection::connection_set()
{
	Connection ConnectionWin(this);
	if (ConnectionWin.exec())
	{

	}
}
void Detection::system_set()
{
	System SystemWin(this);
	if (SystemWin.exec())
	{

	}
}
void Detection::history_display()
{
	History HistoryWin(this);
	if (HistoryWin.exec())
	{

	}
}
void Detection::paintEventNG()
{
	paint = new QPainter;
	QImage OK;
	QImage NG;
	paint->begin(this);
	OK.load("./Resources/OK.png");
	NG.load("./Resources/NG.png");
	QImage OKImg = OK.scaled(ui.masterlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage NGImg = NG.scaled(ui.masterlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage OKImg1 = OK.scaled(ui.resultlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage NGImg1 = NG.scaled(ui.resultlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.masterlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.masterlabel->show();
	ui.Rsenlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.Rsenlabel->show();
	ui.Lsenlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.Lsenlabel->show();
	ui.resultlabel->setPixmap(QPixmap::fromImage(NGImg1));
	ui.resultlabel->show();
	paint->end();
}
void Detection::paintEventOK()
{
	paint = new QPainter;
	QImage OK;
	QImage NG;
	paint->begin(this);
	OK.load("./Resources/OK.png");
	NG.load("./Resources/NG.png");
	QImage OKImg = OK.scaled(ui.masterlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage NGImg = NG.scaled(ui.masterlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage OKImg1 = OK.scaled(ui.resultlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	QImage NGImg1 = NG.scaled(ui.resultlabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.masterlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.masterlabel->show();
	ui.Rsenlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.Rsenlabel->show();
	ui.Lsenlabel->setPixmap(QPixmap::fromImage(OKImg));
	ui.Lsenlabel->show();
	ui.resultlabel->setPixmap(QPixmap::fromImage(OKImg1));
	ui.resultlabel->show();
	paint->end();
}
void Detection::detection()
{
	paintEventOK();
	ui.pushButton->setText(QStringLiteral("检测中..."));
	camtimer->stop();
	QImage Image = CameraWin->detection();
	QImage ddImage = Image.scaled(ui.label_3->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
	ui.label_3->setPixmap(QPixmap::fromImage(ddImage));
	ui.label_3->show();
	ui.pushButton->setText(QStringLiteral("开始检测"));
	paintEventNG();
	QMessageBox::about(NULL, "Message", QStringLiteral("检测完成！"));
}