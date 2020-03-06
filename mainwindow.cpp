#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ordermodel.h"
#include <QString>
#include <QTextStream>
#include <QDebug>
#include <QPushButton>
#include <QScrollArea>
#include <QGridLayout>
#include <QSize>
#include <QSpacerItem>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<OrderModel> *elements = new QVector<OrderModel>();

    OrderModel el1 = OrderModel();
    el1.name = "Шашлык";
    el1.price = 1000;
    el1.raiting = 1;
    el1.imageLink = ":/new/prefix2/resourses/OrderImages/krilya.jpg";
    el1.description = "Очень вкусно";
    el1.ingredients = "Инградиенты";

    OrderModel el2 = OrderModel();
    el2.name = "Борщ";
    el2.price = 1000;
    el2.raiting = 2;
    el2.imageLink = ":/new/prefix2/resourses/OrderImages/katleta.jpeg";
    el2.description = "Очень вкусно";
    el2.ingredients = "Инградиенты";

    OrderModel el3 = OrderModel();
    el3.name = "Картошка";
    el3.price = 1000;
    el3.raiting = 3;
    el3.imageLink = ":/new/prefix2/resourses/OrderImages/kartoshka.jpg";
    el3.description = "Очень вкусно";
    el3.ingredients = "Инградиенты";

    OrderModel el4 = OrderModel();
    el4.name = "Курица";
    el4.raiting = 4;
    el4.price = 1000;
    el4.imageLink = ":/new/prefix2/resourses/OrderImages/grudka.jpg";
    el4.description = "Очень вкусно";
    el4.ingredients = "Инградиенты";

    elements->append(el1);
    elements->append(el2);
    elements->append(el3);
    elements->append(el4);

    for (auto it : *elements) {
        OrderCell *item = new OrderCell();
        item->setName(it.name);
        item->setPrice(it.price);
        item->setRaiting(it.raiting);
        item->setOrderImage(it.imageLink);
        collectionLayout->addElement(item, it);
    }
    ui->scrollAreaWidgetContents->setLayout(collectionLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click()
{
    qDebug() << "Clicked";
}



void MainWindow::on_widget_customContextMenuRequested(const QPoint &pos)
{

}

void MainWindow::on_groupBox_clicked()
{
     qDebug() << "Clicked";
}

void MainWindow::on_pushButton_clicked()
{
    ListOrders *d = new ListOrders();
    d->exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    collectionLayout->removeAll();
}
