#include "ordercell.h"



void OrderCell::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        OrderInformation *informationFrame = new OrderInformation();
        informationFrame->setData(this->model);
        informationFrame->exec();
    }
}

void OrderCell::mouseMoveEvent(QMouseEvent *e)
{
    setMouseTracking(true);
    if ( e->globalPos() == QCursor::pos()) {
        qDebug() << "OK";
    }
}

void OrderCell::enterEvent(QEvent *e)
{
        QPropertyAnimation *animation = new QPropertyAnimation(this,"size");
        animation->setDuration(100);
        animation->setEndValue(this->size() + QSize(15,15));
        animation->start();

}

void OrderCell::leaveEvent(QEvent *event)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"size");
    animation->setDuration(100);
    animation->setEndValue(this->size() - QSize(15,15));

    animation->start();

}

void OrderCell::setName(QString name)
{
    this->nameLabel->setText(name);
}

void OrderCell::setPrice(int price)
{
    this->priceLabel->setText(QString::number(price));
}

void OrderCell::setRaiting(int raiting)
{
    QPixmap *pixmap;
    switch (raiting) {
    case 1:
        pixmap = new QPixmap(":/new/prefix1/resourses/Stars/one star.png");
        this->raitingLabel->setPixmap(*pixmap);
        break;
    case 2:
        pixmap = new QPixmap(":/new/prefix1/resourses/Stars/two star.png");
        this->raitingLabel->setPixmap(*pixmap);
        break;
    case 3:
        pixmap = new QPixmap(":/new/prefix1/resourses/Stars/three.png");
        this->raitingLabel->setPixmap(*pixmap);
         break;
    case 4:
        pixmap = new QPixmap(":/new/prefix1/resourses/Stars/four star.png");
        this->raitingLabel->setPixmap(*pixmap);
         break;
    case 5:
        pixmap = new QPixmap("::/new/prefix1/resourses/Stars/fith star.png");
        this->raitingLabel->setPixmap(*pixmap);
         break;
    default:
        break;


    }
}

void OrderCell::setOrderImage(QString imageLink)
{
    QPixmap *pixmap = new QPixmap(imageLink);
    this->orderImage->setPixmap(*pixmap);
}

int OrderCell::getIndex()
{
    return index;
}

void OrderCell::setIndex(const int index)
{
    this->index = index;
}

OrderCell::OrderCell()
{    
    setTopFrameStyle();
    setImageLabelStyle();
    setBottomFrameStyle();
    setCellStyle();
}

void OrderCell::setTopFrameStyle()
{
    QHBoxLayout *topFrameHLayout = new QHBoxLayout();
    topFrameHLayout->setSpacing(4);
    topFrameHLayout->setMargin(5);

    // TOP FRAME
    topFrame = new QFrame();
    topFrame->setObjectName("topFrame");
    topFrame->setStyleSheet(
                            "background-color:  #00C7FF;"
                            "border-top-left-radius: 10px;"
                            "border-top-right-radius: 10px;");
    topFrame->setMinimumSize(QSize(260,45));
    topFrame->setMaximumSize(QSize(280,45));
    topFrame->setLayout(topFrameHLayout);

    // NAME LABEL
    nameLabel = new QLabel();
    nameLabel->setText("Стейк из семги");
    nameLabel->setFont(QFont(QFont("SF Pro Rounded", 22,50,false)));
    nameLabel->setMinimumHeight(18);
    nameLabel->setStyleSheet("color: rgb(34,54,65);");
    topFrameHLayout->addWidget(nameLabel);

    // RAITIG LABEL
    raitingLabel = new QLabel();
    QPixmap pixmap = QPixmap(":/new/prefix1/resourses/Stars/fith star.png");
    raitingLabel->setPixmap(pixmap);
    raitingLabel->setMaximumHeight(20);
    raitingLabel->setMaximumWidth(100);
    topFrameHLayout->addWidget(raitingLabel);
    topFrameHLayout->setSpacing(2);
}

void OrderCell::setImageLabelStyle()
{
    // MIDDLE
    // ORDER IMAGE
    orderImage = new QLabel();

    QPixmap imagePixmap = QPixmap(":/new/prefix2/resourses/OrderImages/steik.jpg");
    orderImage->setAlignment(Qt::AlignCenter);
    orderImage->setPixmap(imagePixmap);
}

void OrderCell::setBottomFrameStyle()
{
    QVBoxLayout *bottomFrameVLayout = new QVBoxLayout();
    bottomFrameVLayout->setAlignment(Qt::AlignCenter);
    bottomFrameVLayout->setMargin(2);
    // Bottom FRAME
    bottomFrame = new QFrame();
    bottomFrame->setStyleSheet("background-color: #FFBEBE;"
                               "border-radius: 10px;");
    bottomFrame->setMinimumSize(QSize(260,70));
    bottomFrame->setMaximumSize(QSize(280,70));
    bottomFrame->setLayout(bottomFrameVLayout);

    // PRICE LABEL
    priceLabel = new QLabel();
    priceLabel->setStyleSheet("QLabel {"
                              "color: #868686;"
                              "}");
    priceLabel->setAlignment(Qt::AlignCenter);
    priceLabel->setFont(QFont("SF Pro Rounded", 18, 37, false));
    //priceLabel->setText("1200 руб");

    // BUTTON
    addOrdersButton = new QPushButton();
    addOrdersButton->setFont(QFont("SF Pro Rounded", 24, 45, false));
    addOrdersButton->setText("Добавить в заказ");
    addOrdersButton->setMinimumSize(QSize(215, 34));
    addOrdersButton->setMaximumSize(QSize(215, 34));
    addOrdersButton->setStyleSheet("QPushButton{"
                                   "background-color: rgb(59,112,255);"
                                   "border-style: solid;"
                                   "border-width: 0px;"
                                   "border-radius: 17;"
                                   "}");
    // Bottom layout
    bottomFrameVLayout->addWidget(priceLabel);
    bottomFrameVLayout->addWidget(addOrdersButton);
    bottomFrameVLayout->setSpacing(5);
}
void OrderCell::setCellStyle()
{
    QVBoxLayout *verticalLayoutCell = new QVBoxLayout();
    verticalLayoutCell->setAlignment(Qt::AlignBottom);
    verticalLayoutCell->setMargin(0);

    setLayout(verticalLayoutCell);

    verticalLayoutCell->addWidget(topFrame);
    verticalLayoutCell->addWidget(orderImage);
    verticalLayoutCell->addWidget(bottomFrame);
    verticalLayoutCell->setStretch(0,0);
    verticalLayoutCell->setStretch(1,3);
    verticalLayoutCell->setStretch(2,0);
    verticalLayoutCell->setSpacing(0);


    setObjectName("cell");
    setMinimumSize(QSize(260,280));
    setMaximumSize(QSize(280,300));


    setStyleSheet("#cell {"
                  "background-color:rgb(255,255,255);"
                  "border-style: none;"
                  "border-width: 2px;"
                  "border-color:rgb(54,64,46);"
                  "border-radius: 20px;"
                  "}"
                  "#cell:hover {"
                  "background-color: rgb(255,255,255);"
                  "border-style: none;"
                  "border-width: 2px;"
                  "border-color:rgb(54,64,46);"
                  "border-radius: 20px;"
                  "}");
}
