#ifndef ORDERCELL_H
#define ORDERCELL_H
#include "orderinformation.h"
#include "ordermodel.h"
#include <QMainWindow>
#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPixmap>
#include <QBitmap>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QRect>
#include <QCursor>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QFont>





class OrderCell: public QWidget
{
private:
    int index;

    QRect oldRect;

    QFrame *topFrame;
    QLabel *nameLabel;
    QLabel *raitingLabel;

    QLabel *orderImage;

    QFrame *bottomFrame;
    QLabel *priceLabel;
    QPushButton *addOrdersButton;


    void setCellStyle();
    void setTopFrameStyle();
    void setImageLabelStyle();
    void setBottomFrameStyle();


public slots:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void enterEvent (QEvent *e );
    void leaveEvent ( QEvent * event );

    void setName(QString name);
    void setPrice(int price);
    void setRaiting(int raiting);
    void setOrderImage(QString imageLink);




public:
    OrderModel model;


    int getIndex();
    void setIndex(const int index);
    OrderCell();
};

#endif // ORDERCELL_H




