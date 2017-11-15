/********************************************************************************
** Form generated from reading UI file 'system.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEM_H
#define UI_SYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_System
{
public:
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;

    void setupUi(QDialog *System)
    {
        if (System->objectName().isEmpty())
            System->setObjectName(QStringLiteral("System"));
        System->resize(149, 103);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Detection/Resources/10.png"), QSize(), QIcon::Normal, QIcon::Off);
        System->setWindowIcon(icon);
        checkBox = new QCheckBox(System);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(30, 20, 91, 16));
        checkBox_2 = new QCheckBox(System);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(30, 50, 91, 16));
        checkBox_3 = new QCheckBox(System);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(30, 80, 91, 16));

        retranslateUi(System);

        QMetaObject::connectSlotsByName(System);
    } // setupUi

    void retranslateUi(QDialog *System)
    {
        System->setWindowTitle(QApplication::translate("System", "\347\263\273\347\273\237\350\256\276\347\275\256", 0));
        checkBox->setText(QApplication::translate("System", "\346\230\276\347\244\272\346\250\241\346\235\277ROI", 0));
        checkBox_2->setText(QApplication::translate("System", "\346\240\207\350\256\260\347\274\272\351\231\267", 0));
        checkBox_3->setText(QApplication::translate("System", "\345\215\225\346\234\272\346\243\200\346\265\213", 0));
    } // retranslateUi

};

namespace Ui {
    class System: public Ui_System {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEM_H
