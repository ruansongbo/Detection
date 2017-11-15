/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectionClass
{
public:
    QAction *actioncamera;
    QAction *actiontemplate;
    QAction *actionparameter;
    QAction *actionconnection;
    QAction *actionsystem;
    QAction *actionhistory;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label_3;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *masterlabel;
    QGroupBox *groupBox_4;
    QLabel *Lsenlabel;
    QLabel *Rsenlabel;
    QLabel *label_17;
    QLabel *label_16;
    QGroupBox *groupBox_5;
    QLabel *resultlabel;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DetectionClass)
    {
        if (DetectionClass->objectName().isEmpty())
            DetectionClass->setObjectName(QStringLiteral("DetectionClass"));
        DetectionClass->resize(1140, 759);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Detection/Resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        DetectionClass->setWindowIcon(icon);
        actioncamera = new QAction(DetectionClass);
        actioncamera->setObjectName(QStringLiteral("actioncamera"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Detection/Resources/14.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncamera->setIcon(icon1);
        actiontemplate = new QAction(DetectionClass);
        actiontemplate->setObjectName(QStringLiteral("actiontemplate"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Detection/Resources/15.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiontemplate->setIcon(icon2);
        actionparameter = new QAction(DetectionClass);
        actionparameter->setObjectName(QStringLiteral("actionparameter"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Detection/Resources/6.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionparameter->setIcon(icon3);
        actionconnection = new QAction(DetectionClass);
        actionconnection->setObjectName(QStringLiteral("actionconnection"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Detection/Resources/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionconnection->setIcon(icon4);
        actionsystem = new QAction(DetectionClass);
        actionsystem->setObjectName(QStringLiteral("actionsystem"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Detection/Resources/10.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionsystem->setIcon(icon5);
        actionhistory = new QAction(DetectionClass);
        actionhistory->setObjectName(QStringLiteral("actionhistory"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Detection/Resources/4.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionhistory->setIcon(icon6);
        centralWidget = new QWidget(DetectionClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1010, 540, 111, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Detection/Resources/12.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon7);
        pushButton->setIconSize(QSize(48, 48));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 491, 691));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox->setFont(font1);
        groupBox->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 471, 651));
        QFont font2;
        font2.setPointSize(24);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(1000, 300, 131, 71));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        groupBox_3->setFont(font3);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 30, 81, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        label_7->setFont(font4);
        masterlabel = new QLabel(groupBox_3);
        masterlabel->setObjectName(QStringLiteral("masterlabel"));
        masterlabel->setGeometry(QRect(90, 30, 31, 31));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(1000, 190, 131, 101));
        groupBox_4->setFont(font3);
        Lsenlabel = new QLabel(groupBox_4);
        Lsenlabel->setObjectName(QStringLiteral("Lsenlabel"));
        Lsenlabel->setGeometry(QRect(90, 30, 31, 31));
        Rsenlabel = new QLabel(groupBox_4);
        Rsenlabel->setObjectName(QStringLiteral("Rsenlabel"));
        Rsenlabel->setGeometry(QRect(90, 60, 31, 31));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 60, 81, 31));
        label_17->setFont(font4);
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 30, 81, 31));
        label_16->setFont(font4);
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(1000, 380, 131, 111));
        groupBox_5->setFont(font3);
        resultlabel = new QLabel(groupBox_5);
        resultlabel->setObjectName(QStringLiteral("resultlabel"));
        resultlabel->setGeometry(QRect(40, 40, 51, 51));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(500, 10, 491, 691));
        groupBox_2->setFont(font1);
        groupBox_2->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 471, 651));
        DetectionClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DetectionClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DetectionClass->setStatusBar(statusBar);
        toolBar = new QToolBar(DetectionClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        DetectionClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actioncamera);
        toolBar->addSeparator();
        toolBar->addAction(actiontemplate);
        toolBar->addSeparator();
        toolBar->addAction(actionparameter);
        toolBar->addSeparator();
        toolBar->addAction(actionconnection);
        toolBar->addSeparator();
        toolBar->addAction(actionsystem);
        toolBar->addSeparator();
        toolBar->addAction(actionhistory);

        retranslateUi(DetectionClass);
        QObject::connect(actioncamera, SIGNAL(triggered()), DetectionClass, SLOT(camera_set()));
        QObject::connect(actionconnection, SIGNAL(triggered()), DetectionClass, SLOT(connection_set()));
        QObject::connect(actionhistory, SIGNAL(triggered()), DetectionClass, SLOT(history_display()));
        QObject::connect(actionparameter, SIGNAL(triggered()), DetectionClass, SLOT(paramter_set()));
        QObject::connect(actiontemplate, SIGNAL(triggered()), DetectionClass, SLOT(template_set()));
        QObject::connect(actionsystem, SIGNAL(triggered()), DetectionClass, SLOT(system_set()));
        QObject::connect(pushButton, SIGNAL(clicked()), DetectionClass, SLOT(detection()));

        QMetaObject::connectSlotsByName(DetectionClass);
    } // setupUi

    void retranslateUi(QMainWindow *DetectionClass)
    {
        DetectionClass->setWindowTitle(QApplication::translate("DetectionClass", "\345\244\247\345\260\272\345\257\270\346\234\272\346\237\234\350\241\250\351\235\242\345\267\256\345\274\202\346\231\272\350\203\275\346\243\200\346\265\213\347\263\273\347\273\237", 0));
        actioncamera->setText(QApplication::translate("DetectionClass", "\347\233\270\346\234\272\350\256\276\347\275\256", 0));
        actiontemplate->setText(QApplication::translate("DetectionClass", "\346\250\241\346\235\277\350\256\276\347\275\256", 0));
        actionparameter->setText(QApplication::translate("DetectionClass", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        actionconnection->setText(QApplication::translate("DetectionClass", "\350\277\236\346\216\245\350\256\276\347\275\256", 0));
        actionsystem->setText(QApplication::translate("DetectionClass", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        actionhistory->setText(QApplication::translate("DetectionClass", "\345\216\206\345\217\262\344\277\241\346\201\257", 0));
        pushButton->setText(QApplication::translate("DetectionClass", "\345\276\205\346\243\200\346\265\213", 0));
        groupBox->setTitle(QApplication::translate("DetectionClass", "\345\276\205\346\243\200\346\265\213\345\233\276\345\203\217", 0));
        label_3->setText(QApplication::translate("DetectionClass", "\351\207\207\351\233\206\345\233\276\345\203\217\350\275\275\345\205\245\344\270\255...", 0));
        groupBox_3->setTitle(QApplication::translate("DetectionClass", "\347\275\221\347\273\234\350\277\236\346\216\245\347\212\266\346\200\201", 0));
        label_7->setText(QApplication::translate("DetectionClass", "\344\270\273\346\234\272\351\200\232\350\256\257\357\274\232", 0));
        masterlabel->setText(QString());
        groupBox_4->setTitle(QApplication::translate("DetectionClass", "\346\234\272\346\237\234\344\275\215\347\275\256\347\212\266\346\200\201", 0));
        Lsenlabel->setText(QString());
        Rsenlabel->setText(QString());
        label_17->setText(QApplication::translate("DetectionClass", "\345\217\263\344\274\240\346\204\237\345\231\250\357\274\232", 0));
        label_16->setText(QApplication::translate("DetectionClass", "\345\267\246\344\274\240\346\204\237\345\231\250\357\274\232", 0));
        groupBox_5->setTitle(QApplication::translate("DetectionClass", "\347\274\272\351\231\267\346\243\200\346\265\213\347\273\223\346\236\234", 0));
        resultlabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("DetectionClass", "\346\250\241\346\235\277\345\233\276\345\203\217", 0));
        label_4->setText(QString());
        toolBar->setWindowTitle(QApplication::translate("DetectionClass", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class DetectionClass: public Ui_DetectionClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
