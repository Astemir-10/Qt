#ifndef COLLECTIONLAYOUT_H
#define COLLECTIONLAYOUT_H
#include "ordercell.h"
#include "ordermodel.h"
#include <QMainWindow>
#include <QGridLayout>
#include <QDebug>
#include <QWidget>
#include <QPair>
#include <QGraphicsEffect>

//struct TestElement {
//    public: QString name;
//            QString ingradients;
//            QString description;
//            int price;
//            QString imageLink;
//            int raiting;
//    private:
//};

class CollectionLayout: public QGridLayout
{
    Q_OBJECT


private:

    QVector<OrderModel> *elements = new QVector<OrderModel>();


public:
    void addElement(OrderCell *element, OrderModel model);
    void removeAll();
    CollectionLayout();
    QVector<int> *items = new QVector<int>();
    QVector<QPair<int, int>> *cellsLocation = new QVector<QPair<int, int>>();


};

#endif // COLLECTIONLAYOUT_H
