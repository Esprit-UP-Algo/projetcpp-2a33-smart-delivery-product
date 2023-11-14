#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"colis.h"
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QPushButton>


#include<QVariant>
#include<QtCore>
#include<QtGui>
#include<QtQuick>
#include <QVariant>
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

    void on_aff_clicked();

    void on_tri_clicked();

    void on_Rech_clicked();

    void on_mod1_clicked();

    void on_tri_p_clicked();

    void on_tri_volume_clicked();

    void on_tri_b_clicked();

    void on_Rech_3_textChanged(const QString &arg1);

    void on_pdf_clicked();

    void on_stat_clicked();

private:
    Ui::MainWindow *ui;
    Colis Ctmp;
 signals:
   void setCenterPosition(QVariant,QVariant);
    void setLocationMarking(QVariant,QVariant);
};


#endif // MAINWINDOW_H
