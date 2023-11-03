#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"clients.h"
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

    void on_pushButton_5_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_Update_clicked();

    void on_pb_Clear_clicked();

private:
    Ui::MainWindow *ui;
    Clients C ;
};
#endif // MAINWINDOW_H
