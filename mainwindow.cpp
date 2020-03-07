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


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click()
{
    qDebug() << "Clicked";
}





void MainWindow::on_myOrders_clicked()
{
    ListOrders *listOrders = new ListOrders();
    listOrders->exec();
}

void MainWindow::on_meatCategory_clicked()
{
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
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_veganCategory_clicked()
{
    CollectionLayout *veganLayout = new CollectionLayout();

    QVector<OrderModel> *elements = new QVector<OrderModel>();

    OrderModel el1 = OrderModel();
    el1.name = "Что то веган";
    el1.price = 1000;
    el1.raiting = 1;
    el1.imageLink = ":/new/prefix2/resourses/OrderImages/krilya.jpg";
    el1.description = "Совсем не вкусно";
    el1.ingredients = "Инградиенты";

    OrderModel el2 = OrderModel();
    el2.name = "Что то для веган";
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
        veganLayout->addElement(item, it);
    }
    ui->scrollAreaVegan->setLayout(veganLayout);
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_salatsCategory_clicked()
{
    CollectionLayout *salatLayout = new CollectionLayout();

    QVector<OrderModel> *elements = new QVector<OrderModel>();

    OrderModel el1 = OrderModel();
    el1.name = "какой  то салат";
    el1.price = 1000;
    el1.raiting = 1;
    el1.imageLink = ":/new/prefix2/resourses/OrderImages/krilya.jpg";
    el1.description = "Совсем не вкусно";
    el1.ingredients = "Инградиенты";

    OrderModel el2 = OrderModel();
    el2.name = "Что то для веган";
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
        salatLayout->addElement(item, it);
    }
    ui->scrollAreaSalats->setLayout(salatLayout);
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_desertsCategory_clicked()
{
    CollectionLayout *desertLayout = new CollectionLayout();

    QVector<OrderModel> *elements = new QVector<OrderModel>();

    OrderModel el1 = OrderModel();
    el1.name = "Это десерт";
    el1.price = 1000;
    el1.raiting = 1;
    el1.imageLink = ":/new/prefix2/resourses/OrderImages/krilya.jpg";
    el1.description = "Совсем не вкусно";
    el1.ingredients = "Инградиенты";

    OrderModel el2 = OrderModel();
    el2.name = "Что то для веган";
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
        desertLayout->addElement(item, it);
    }
    ui->scrollAreaDeserts->setLayout(desertLayout);
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_napitkiCategory_clicked()
{
    CollectionLayout *napitokLayout = new CollectionLayout();

    QVector<OrderModel> *elements = new QVector<OrderModel>();

    OrderModel el1 = OrderModel();
    el1.name = "тут напитки";
    el1.price = 1000;
    el1.raiting = 1;
    el1.imageLink = ":/new/prefix2/resourses/OrderImages/krilya.jpg";
    el1.description = "Совсем не вкусно";
    el1.ingredients = "Инградиенты";

    OrderModel el2 = OrderModel();
    el2.name = "Что то для веган";
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
        napitokLayout->addElement(item, it);
    }
    ui->scrollAreaNapitki->setLayout(napitokLayout);
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_barCategory_clicked()
{
    CollectionLayout *barLayout = new CollectionLayout();

    QVector<OrderModel> *elements = new QVector<OrderModel>();

    OrderModel el1 = OrderModel();
    el1.name = "Что то бар";
    el1.price = 1000;
    el1.raiting = 1;
    el1.imageLink = ":/new/prefix2/resourses/OrderImages/krilya.jpg";
    el1.description = "Совсем не вкусно";
    el1.ingredients = "Инградиенты";

    OrderModel el2 = OrderModel();
    el2.name = "Что то для веган";
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
        barLayout->addElement(item, it);
    }
    ui->scrollAreaBar->setLayout(barLayout);
    ui->stackedWidget->setCurrentIndex(5);
}
