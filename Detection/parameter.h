#ifndef PARAMETER_H
#define PARAMETER_H

#include <QDialog>

namespace Ui {
class Parameter;
}

class Parameter : public QDialog
{
    Q_OBJECT

public:
    explicit Parameter(QWidget *parent = 0);
    ~Parameter();

private:
    Ui::Parameter *ui;
};

#endif // PARAMETER_H
