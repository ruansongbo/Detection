#ifndef DETECTION_H
#define DETECTION_H

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "qpixmap.h"
#include "qpainter.h"
#include "qtimer.h"
#include "camera.h"

class Detection : public QMainWindow
{
	Q_OBJECT

public:
	Detection(QWidget *parent = 0);
	~Detection();
private:
	Ui::DetectionClass ui;
	//void paintEvent(QPaintEvent*);
	void paintEventNG();
	void paintEventOK();
	QPainter *paint;
	QTimer *camtimer;
	Camera *CameraWin;
private slots:
	void camera_set();
	void template_set();
	void paramter_set();
	void connection_set();
	void system_set();
	void history_display();
	void dis_image();
	void timerUpDate();
	void detection();
};

#endif // DETECTION_H
