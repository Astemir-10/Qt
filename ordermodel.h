#ifndef ORDERMODEL_H
#define ORDERMODEL_H
#include <QMainWindow>


class OrderModel
{
public:
    QString name;
     QString ingredients;
                QString description;
                int price;
                QString imageLink;
                int raiting;
    OrderModel();
};

#endif // ORDERMODEL_H
