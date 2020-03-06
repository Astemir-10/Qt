#ifndef ORDERINFORMATION_H
#define ORDERINFORMATION_H

#include <QDialog>
#include "ordermodel.h"
namespace Ui {
class OrderInformation;
}

class OrderInformation : public QDialog
{
    Q_OBJECT

public:
    explicit OrderInformation(QWidget *parent = nullptr);
    ~OrderInformation();
    void setData(OrderModel model);
    void removeAll();
    QString getStarsLink(int raiting);

private:
    Ui::OrderInformation *ui;
};

#endif // ORDERINFORMATION_H
