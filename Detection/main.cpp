#include "detection.h"
#include <QtWidgets/QApplication>
#include <qsplashscreen.h>
#include <iostream>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QSplashScreen *splash = new QSplashScreen;
	QImage Loading;
	Loading.load("ss.jpg");
	QImage LoadingImg = Loading.scaled(QSize(886,346) , Qt::KeepAspectRatio, Qt::SmoothTransformation);
	splash->setPixmap(QPixmap::fromImage(LoadingImg));
	splash->show();    //��ʾͼƬ
	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
	QFont ft;
	ft.setPointSize(14);
	ft.setBold(true);
	splash->setFont(ft);
	splash->showMessage(QStringLiteral("������..."),
		topRight, Qt::white);    //��ʾ������Ϣ
	_sleep(3 * 1000);
	Detection w;
 	w.show();
	splash->finish(&w);    //ͼƬһֱ��ʾ��mainWin�������
	delete splash;    //�ͷſռ䣬��ʡ�ڴ�
	return a.exec();
}
