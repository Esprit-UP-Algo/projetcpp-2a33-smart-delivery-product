#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clients.h"
#include<QMessageBox>
#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_IDC->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_Clients->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    int IDC=ui->le_IDC->text().toInt();
    QString nomc=ui->le_nomc->text();
    QString prenomc=ui->le_prenomc->text();
    QString adressec=ui->le_adressec->text();
    QString emailc=ui->le_emailc->text();
    int numc=ui->le_numeroc->text().toInt();
    Clients C( IDC,  nomc,  prenomc,  adressec,  emailc, numc);

    bool test=C.ajouter() ;
   if (test)
   {
       QMessageBox::information(nullptr, QObject::tr("ok"),
                                QObject::tr("Ajout effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_Clients->setModel(C.afficher());
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                QObject::tr("Ajout non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

}





void MainWindow::on_pb_supprimer_clicked()
{
    QString text_ID = ui->le_IDsupp->text();
int IDC = ui->le_IDsupp->text().toInt();

    if (text_ID.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("Veuillez entrer un identifiant avant de tenter de supprimer."), QMessageBox::Ok);
        return;
    }

    Clients F1;
    F1.setIDC(IDC);

    if (F1.idExists(IDC)) {
        bool test = F1.supprimer(F1.getIDC());

        if (test) {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Suppression avec succès.\nClick Cancel to exit."), QMessageBox::Cancel);
            ui->tab_Clients->setModel(C.afficher()); // Mise à jour
        }
        else {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                QObject::tr("La suppression a échoué.\nClick Cancel to exit."), QMessageBox::Cancel);
        }
    }
    else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
            QObject::tr("L'identifiant n'existe pas."), QMessageBox::Ok);
        return;
    }

}




void MainWindow::on_pb_Update_clicked()
{
    int IDC=ui->id_Maj->text().toInt();
    QString nomc=ui->nom_Maj->text();
    QString prenomc=ui->prenom_Maj->text();
    QString adressec=ui->adresse_Maj->text();
    QString emailc=ui->email_Maj->text();
    int numc=ui->num_Maj->text().toInt();
    Clients C( IDC,  nomc,  prenomc,  adressec,  emailc, numc);

    bool test=C.modifier() ;
   if (test)
   {
       QMessageBox::information(nullptr, QObject::tr("ok"),
                                QObject::tr("Update effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
       ui->tab_Clients->setModel(C.afficher());
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                QObject::tr("Update non effectué\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_Clear_clicked()
{
        ui->le_IDC->clear();
        ui->le_nomc->clear();
        ui->le_prenomc->clear();
        ui->le_adressec->clear();
        ui->le_emailc->clear();
        ui->le_numeroc->clear();

}
