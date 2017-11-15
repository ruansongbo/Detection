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
	splash->show();    //显示图片
	Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
	QFont ft;
	ft.setPointSize(14);
	ft.setBold(true);
	splash->setFont(ft);
	splash->showMessage(QStringLiteral("载入中..."),
		topRight, Qt::white);    //显示启动信息
	_sleep(3 * 1000);
	Detection w;
 	w.show();
	splash->finish(&w);    //图片一直显示到mainWin加载完成
	delete splash;    //释放空间，节省内存
	return a.exec();
}
