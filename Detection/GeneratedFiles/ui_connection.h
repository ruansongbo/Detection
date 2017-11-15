/********************************************************************************
** Form generated from reading UI file 'connection.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTION_H
#define UI_CONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Connection
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *Connection)
    {
        if (Connection->objectName().isEmpty())
            Connection->setObjectName(QStringLiteral("Connection"));
        Connection->resize(282, 41);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Detection/Resources/5.png"), QSize(), QIcon::Normal, QIcon::Off);
        Connection->setWindowIcon(icon);
        label = new QLabel(Connection);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 54, 20));
        lineEdit = new QLineEdit(Connection);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(80, 10, 101, 21));
        pushButton = new QPushButton(Connection);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 10, 75, 23));

        retranslateUi(Connection);

        QMetaObject::connectSlotsByName(Connection);
    } // setupUi

    void retranslateUi(QDialog *Connection)
    {
        Connection->setWindowTitle(QApplication::translate("Connection", "\350\277\236\346\216\245\350\256\276\347\275\256", 0));
        label->setText(QApplication::translate("Connection", "\344\270\273\346\234\272IP\357\274\232", 0));
        lineEdit->setText(QApplication::translate("Connection", "192.255.255.255", 0));
        pushButton->setText(QApplication::translate("Connection", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class Connection: public Ui_Connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTION_H
