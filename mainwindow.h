#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ordercell.h"
#include "collectionlayout.h"
#include "orderinformation.h"
#include "listorders.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void click();

    void on_myOrders_clicked();


    void on_veganCategory_clicked();

    void on_meatCategory_clicked();

    void on_salatsCategory_clicked();

    void on_desertsCategory_clicked();

    void on_napitkiCategory_clicked();

    void on_barCategory_clicked();

private:
    CollectionLayout *collectionLayout = new CollectionLayout();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
