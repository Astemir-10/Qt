#include "listorders.h"
#include "ui_listorders.h"

ListOrders::ListOrders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOrders)
{
    ui->setupUi(this);
}

ListOrders::~ListOrders()
{
    delete ui;
}
