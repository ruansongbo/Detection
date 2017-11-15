#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>

namespace Ui {
class Connection;
}

class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = 0);
    ~Connection();

private:
    Ui::Connection *ui;
};

#endif // CONNECTION_H
