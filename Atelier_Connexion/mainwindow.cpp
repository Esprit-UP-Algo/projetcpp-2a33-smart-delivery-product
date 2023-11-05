#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"colis.h"
#include"QString"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QSqlQueryModel>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_c->setModel(Ctmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_ajouter_clicked()
{
     int id;
     id=ui->le->text().toInt();

     float poids;
     poids=ui->poids->text().toFloat();

     float volume;
      volume=ui->volume->text().toFloat();
      QString etat;
    etat=ui->etat->text();


    Colis C(id,poids,volume,etat);

     bool test=C.ajouter();
     if(test)
     {
            ui->tab_c->setModel(C.afficher());
         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("connection successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("connection failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_supp_clicked()
{
    int id=ui->supp_2->text().toInt();
    bool test=Ctmp.supprimer(id);
    if(test)
    {
           ui->tab_c->setModel(Ctmp.afficher());
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuee\n""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("OK"),QObject::tr("Suppression non effectuee\n""Click Cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::on_mod_clicked()
{
    int id = ui->le_id_modifier->text().toInt();

        float nouveauPoids = ui->nouveau_poids->text().toFloat();
        float nouveauVolume = ui->nouveau_volume->text().toFloat();
        QString nouvelEtat = ui->nouvel_etat->text();
         Colis C(id, nouveauPoids, nouveauVolume, nouvelEtat);

        bool test=C.modifierColis() ;

       if (test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("Update effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_c->setModel(C.afficher());
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                    QObject::tr("Update non effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_aff_clicked()
{
    Colis C;
       ui->tab_c->setModel(C.afficher());
}
