#ifndef SYSTEM_H
#define SYSTEM_H

#include <QDialog>

namespace Ui {
class System;
}

class System : public QDialog
{
    Q_OBJECT

public:
    explicit System(QWidget *parent = 0);
    ~System();

private:
    Ui::System *ui;
};

#endif // SYSTEM_H
