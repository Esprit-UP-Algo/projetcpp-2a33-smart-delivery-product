#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"colis.h"
#include <QMainWindow>
#include <QSqlQueryModel>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_B_ajouter_clicked();



    void on_supp_clicked();

    void on_mod_clicked();

private:
    Ui::MainWindow *ui;
    Colis Ctmp;
};

#endif // MAINWINDOW_H
