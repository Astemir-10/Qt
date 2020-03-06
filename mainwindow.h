#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ordercell.h"
#include "collectionlayout.h"
#include "orderinformation.h"
#include "listorders.h"
#include "dialog.h"
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

    void on_widget_customContextMenuRequested(const QPoint &pos);

    void on_groupBox_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    CollectionLayout *collectionLayout = new CollectionLayout();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
