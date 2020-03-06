#include "orderinformation.h"
#include "ui_orderinformation.h"

OrderInformation::OrderInformation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderInformation)
{
    ui->setupUi(this);

}

OrderInformation::~OrderInformation()
{
    delete ui;
}

void OrderInformation::setData(OrderModel model)
{
    ui->nameLabel->setText(model.name);
    QPixmap pixmap = QPixmap(model.imageLink);
    ui->imageLabel->setPixmap(pixmap);
    ui->priceLabel->setText(QString::number(model.price));
    ui->descriptionLabel->setText(model.description);
    ui->ingredients->setText(model.ingredients);
    QPixmap pixmap2 = QPixmap(getStarsLink(model.raiting));
    ui->raitingLabel->setPixmap(pixmap2);


}

void OrderInformation::removeAll()
{

}

QString OrderInformation::getStarsLink(int raiting) {
    switch (raiting) {
    case 1:
        return ":/new/prefix1/resourses/Stars/one star.png";
    case 2:
        return  ":/new/prefix1/resourses/Stars/two star.png";
    case 3:
        return ":/new/prefix1/resourses/Stars/three.png";
    case 4:
        return ":/new/prefix1/resourses/Stars/four star.png";
    case 5:
        return ":/new/prefix1/resourses/Stars/fith star.png";
    default:
        return "";
    }
}
