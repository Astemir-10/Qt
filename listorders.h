#ifndef LISTORDERS_H
#define LISTORDERS_H

#include <QDialog>

namespace Ui {
class ListOrders;
}

class ListOrders : public QDialog
{
    Q_OBJECT

public:
    explicit ListOrders(QWidget *parent = nullptr);
    ~ListOrders();

private:
    Ui::ListOrders *ui;
};

#endif // LISTORDERS_H
