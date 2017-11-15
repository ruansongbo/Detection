/********************************************************************************
** Form generated from reading UI file 'parameter.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETER_H
#define UI_PARAMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Parameter
{
public:
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QDialog *Parameter)
    {
        if (Parameter->objectName().isEmpty())
            Parameter->setObjectName(QStringLiteral("Parameter"));
        Parameter->resize(283, 43);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Detection/Resources/6.png"), QSize(), QIcon::Normal, QIcon::Off);
        Parameter->setWindowIcon(icon);
        horizontalSlider = new QSlider(Parameter);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(110, 10, 160, 21));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(Parameter);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 91, 21));

        retranslateUi(Parameter);

        QMetaObject::connectSlotsByName(Parameter);
    } // setupUi

    void retranslateUi(QDialog *Parameter)
    {
        Parameter->setWindowTitle(QApplication::translate("Parameter", "\345\217\202\346\225\260\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("Parameter", "\347\274\272\351\231\267\346\243\200\346\265\213\347\201\265\346\225\217\345\272\246", 0));
    } // retranslateUi

};

namespace Ui {
    class Parameter: public Ui_Parameter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETER_H
