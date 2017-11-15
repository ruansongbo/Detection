/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include "MyQComboBox.h"
QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QGroupBox *groupBox;
	MyQComboBox *comboBox;
    QLabel *label_6;
    QLabel *label_7;
	MyQComboBox *comboBox_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label;
    QListWidget *listWidget;
    QProgressBar *progressBar;
    QGroupBox *groupBox_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;

    void setupUi(QDialog *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QStringLiteral("Camera"));
        Camera->resize(570, 413);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Detection/Resources/14.png"), QSize(), QIcon::Normal, QIcon::Off);
        Camera->setWindowIcon(icon);
        groupBox = new QGroupBox(Camera);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 211, 211));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comboBox = new MyQComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(80, 20, 121, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 20, 61, 21));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 50, 61, 21));
        comboBox_2 = new MyQComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(80, 49, 86, 20));
        comboBox_2->setEditable(false);
        comboBox_2->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 90, 81, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 120, 91, 21));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 150, 61, 21));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(100, 90, 61, 20));
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(100, 120, 61, 20));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(100, 150, 61, 20));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 90, 21, 21));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(180, 120, 21, 21));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(180, 150, 21, 21));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 180, 75, 23));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(120, 180, 75, 23));
        groupBox_2 = new QGroupBox(Camera);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(230, 20, 331, 351));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 20, 75, 23));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 20, 75, 23));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(170, 20, 75, 23));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(250, 20, 75, 23));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 71, 16));
        listWidget = new QListWidget(groupBox_2);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 70, 311, 271));
        progressBar = new QProgressBar(Camera);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(230, 380, 331, 23));
        progressBar->setValue(24);
        groupBox_3 = new QGroupBox(Camera);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 240, 211, 171));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 101, 21));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 50, 101, 21));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 80, 131, 21));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 110, 131, 21));
        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(60, 140, 75, 23));
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 20, 61, 20));
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 50, 61, 21));
        lineEdit_3 = new QLineEdit(groupBox_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 80, 61, 21));
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 110, 61, 21));

        retranslateUi(Camera);
		QObject::connect(comboBox, SIGNAL(menuPopped()), Camera, SLOT(update_device()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), Camera, SLOT(calibrate_cameras()));
        QObject::connect(comboBox, SIGNAL(activated(int)), Camera, SLOT(selectdevice(int)));
        QObject::connect(lineEdit_5, SIGNAL(textChanged(QString)), Camera, SLOT(addparameters()));
        QObject::connect(lineEdit_6, SIGNAL(textChanged(QString)), Camera, SLOT(addparameters()));
        QObject::connect(lineEdit_7, SIGNAL(textChanged(QString)), Camera, SLOT(addparameters()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), Camera, SLOT(importdata()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), Camera, SLOT(startcamera()));
        QObject::connect(comboBox_2, SIGNAL(activated(int)), Camera, SLOT(changemode(int)));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), Camera, SLOT(addPlatedata()));
        QObject::connect(lineEdit_2, SIGNAL(textChanged(QString)), Camera, SLOT(addPlatedata()));
        QObject::connect(lineEdit_3, SIGNAL(textChanged(QString)), Camera, SLOT(addPlatedata()));
        QObject::connect(lineEdit_4, SIGNAL(textChanged(QString)), Camera, SLOT(addPlatedata()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), Camera, SLOT(importPlatedata()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Camera, SLOT(capture()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Camera, SLOT(addimage()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Camera, SLOT(deletiamage()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Camera, SLOT(deletimage()));

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QDialog *Camera)
    {
        Camera->setWindowTitle(QApplication::translate("Camera", "\347\233\270\346\234\272\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("Camera", "\347\233\270\346\234\272\345\217\202\346\225\260", 0));
        label_6->setText(QApplication::translate("Camera", "\351\200\211\346\213\251\347\233\270\346\234\272\357\274\232", 0));
        label_7->setText(QApplication::translate("Camera", "\347\233\270\346\234\272\346\250\241\345\236\213\357\274\232", 0));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("Camera", "Division", 0)
         << QApplication::translate("Camera", "Polynomial", 0)
        );
        label_8->setText(QApplication::translate("Camera", "\345\215\225\344\270\252\345\203\217\345\205\203\347\232\204\351\253\230\357\274\232", 0));
        label_9->setText(QApplication::translate("Camera", "\345\215\225\344\270\252\345\203\217\345\205\203\347\232\204\345\256\275\357\274\232", 0));
        label_10->setText(QApplication::translate("Camera", "\347\204\246\350\267\235\357\274\232", 0));
        label_11->setText(QApplication::translate("Camera", "\316\274m", 0));
        label_12->setText(QApplication::translate("Camera", "\316\274m", 0));
        label_13->setText(QApplication::translate("Camera", "mm", 0));
        pushButton_7->setText(QApplication::translate("Camera", "\345\257\274\345\205\245\345\217\202\346\225\260", 0));
        pushButton_8->setText(QApplication::translate("Camera", "\346\211\223\345\274\200\347\233\270\346\234\272", 0));
        groupBox_2->setTitle(QApplication::translate("Camera", "\347\233\270\346\234\272\346\240\207\345\256\232", 0));
        pushButton_2->setText(QApplication::translate("Camera", "\351\207\207\351\233\206\345\233\276\347\211\207", 0));
        pushButton_3->setText(QApplication::translate("Camera", "\345\257\274\345\205\245\345\233\276\347\211\207", 0));
        pushButton_4->setText(QApplication::translate("Camera", "\345\210\240\351\231\244\345\233\276\347\211\207", 0));
        pushButton_5->setText(QApplication::translate("Camera", "\345\274\200\345\247\213\346\240\207\345\256\232", 0));
        label->setText(QApplication::translate("Camera", "\345\267\262\351\200\211\346\213\251\345\233\276\347\211\207", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Camera", "1", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Camera", "2", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Camera", "3", 0));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("Camera", "4", 0));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("Camera", "5", 0));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("Camera", "6", 0));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("Camera", "7", 0));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("Camera", "8", 0));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("Camera", "9", 0));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("Camera", "10", 0));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("Camera", "11", 0));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("Camera", "12", 0));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("Camera", "13", 0));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("Camera", "14", 0));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("Camera", "15", 0));
        QListWidgetItem *___qlistwidgetitem15 = listWidget->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("Camera", "16", 0));
        QListWidgetItem *___qlistwidgetitem16 = listWidget->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("Camera", "17", 0));
        QListWidgetItem *___qlistwidgetitem17 = listWidget->item(17);
        ___qlistwidgetitem17->setText(QApplication::translate("Camera", "18", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

        groupBox_3->setTitle(QApplication::translate("Camera", "\346\240\207\345\256\232\346\235\277", 0));
        label_2->setText(QApplication::translate("Camera", "X\346\226\271\345\220\221\346\240\207\345\277\227\347\202\271\346\225\260\351\207\217\357\274\232", 0));
        label_3->setText(QApplication::translate("Camera", "Y\346\226\271\345\220\221\346\240\207\345\277\227\347\202\271\346\225\260\351\207\217\357\274\232", 0));
        label_4->setText(QApplication::translate("Camera", "\346\240\207\345\277\227\347\202\271\350\267\235\347\246\273(mm)\357\274\232", 0));
        label_5->setText(QApplication::translate("Camera", "\346\240\207\345\277\227\347\202\271\347\233\264\345\276\204\344\270\216\350\267\235\347\246\273\346\257\224\345\200\274\357\274\232", 0));
        pushButton_6->setText(QApplication::translate("Camera", "\345\257\274\345\205\245\345\217\202\346\225\260", 0));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
