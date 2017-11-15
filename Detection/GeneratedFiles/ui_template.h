/********************************************************************************
** Form generated from reading UI file 'template.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLATE_H
#define UI_TEMPLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Template
{
public:
    QTableWidget *tableWidget;
    QLabel *label;
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QComboBox *comboBox;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Template)
    {
        if (Template->objectName().isEmpty())
            Template->setObjectName(QStringLiteral("Template"));
        Template->resize(509, 414);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Detection/Resources/15.png"), QSize(), QIcon::Normal, QIcon::Off);
        Template->setWindowIcon(icon);
        tableWidget = new QTableWidget(Template);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 13)
            tableWidget->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem15);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 30, 381, 381));
        label = new QLabel(Template);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 10, 54, 16));
        groupBox = new QGroupBox(Template);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(390, 30, 111, 71));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 30, 75, 23));
        groupBox_2 = new QGroupBox(Template);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(390, 130, 111, 71));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 30, 91, 22));
        groupBox_3 = new QGroupBox(Template);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(390, 230, 111, 161));
        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(20, 30, 75, 23));
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 90, 75, 23));
        pushButton_5 = new QPushButton(groupBox_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 120, 75, 23));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 60, 75, 23));

        retranslateUi(Template);

        QMetaObject::connectSlotsByName(Template);
    } // setupUi

    void retranslateUi(QDialog *Template)
    {
        Template->setWindowTitle(QApplication::translate("Template", "\346\250\241\346\235\277\350\256\276\347\275\256", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Template", "ROI\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Template", "ROI\344\275\215\347\275\256", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Template", "ROI\345\244\247\345\260\217", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Template", "ROI[1]", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Template", "ROI[2]", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Template", "ROI[3]", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("Template", "ROI[4]", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("Template", "ROI[5]", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("Template", "ROI[6]", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("Template", "ROI[7]", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("Template", "ROI[8]", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("Template", "ROI[9]", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem12->setText(QApplication::translate("Template", "ROI[10]", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem13->setText(QApplication::translate("Template", "ROI[11]", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem14->setText(QApplication::translate("Template", "ROI[12]", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem15->setText(QApplication::translate("Template", "ROI[13]", 0));
        label->setText(QApplication::translate("Template", "ROI\345\210\227\350\241\250", 0));
        groupBox->setTitle(QApplication::translate("Template", "\346\250\241\346\235\277\346\223\215\344\275\234", 0));
        pushButton->setText(QApplication::translate("Template", "\345\257\274\345\205\245\346\250\241\347\211\210", 0));
        groupBox_2->setTitle(QApplication::translate("Template", "ROI\347\261\273\345\236\213", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Template", "\346\234\272\346\237\234\346\243\261\350\276\271", 0)
         << QApplication::translate("Template", "\345\215\260\345\210\267\345\225\206\346\240\207", 0)
         << QApplication::translate("Template", "\350\236\272\344\270\235\351\223\206\351\222\211", 0)
        );
        groupBox_3->setTitle(QApplication::translate("Template", "ROI\346\223\215\344\275\234", 0));
        pushButton_6->setText(QApplication::translate("Template", "\346\267\273\345\212\240", 0));
        pushButton_4->setText(QApplication::translate("Template", "\347\274\251\345\260\217", 0));
        pushButton_5->setText(QApplication::translate("Template", "\346\222\244\351\224\200", 0));
        pushButton_3->setText(QApplication::translate("Template", "\346\224\276\345\244\247", 0));
    } // retranslateUi

};

namespace Ui {
    class Template: public Ui_Template {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLATE_H
