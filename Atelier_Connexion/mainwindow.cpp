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
#include<QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QApplication>
#include <QWidget>

#include <QtCharts/QBarSeries>
#include <QtCharts>
#include <QtSql>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QApplication>
#include <QPushButton>
#include <QIcon>
#include <QItemDelegate>
#include <QPainter>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QPushButton>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->quickWidget_MapView->setSource(QUrl(QString("qrc:/QmlMap.qml")));
    ui->quickWidget_MapView->show();

    auto Obje = ui->quickWidget_MapView->rootObject();
    //start position bta3 il map
    connect(this ,SIGNAL(setCenterPosition(QVariant,QVariant)), Obje ,SLOT(setCenterPosition(QVariant,QVariant)));
    //position bta3 il marking
     connect(this ,SIGNAL(setLocationMarking(QVariant,QVariant)), Obje ,SLOT(setLocationMarking(QVariant,QVariant)));

    emit setCenterPosition( 36.8065,10.1815);
     emit setLocationMarking( 36.8065,10.1815);
     QIcon icon("C:/Users/zied/Desktop/ProjetCpp/delete-icon.png");
      QIcon iconPdf("C:/Users/zied/Desktop/ProjetCpp/PDF-icon.png"); // Replace with the actual path to your icon file
    ui->stat->setIcon(icon);
 ui->DE->setIcon(icon);
 ui->pdf->setIcon(iconPdf);
    ui->tab_c->setModel(Ctmp.afficher());
    Colis colis;



}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_ajouter_clicked()
{
     int id;
     bool isInt;
     id=ui->le->text().toInt(&isInt);
     if (!isInt) {

         QMessageBox::warning(this, "Invalid Input", "Please enter a valid integer for ID.");
         return;
     }
     float poids;
     bool isFloat;
     poids=ui->poids->text().toFloat(&isFloat);
     if (!isFloat) {

         QMessageBox::warning(this, "Invalid Input", "Please enter a valid float for Poids.");
         return;
     }

     float volume;
      volume=ui->volume->text().toFloat(&isFloat);
      if (!isFloat) {

          QMessageBox::warning(this, "Invalid Input", "Please enter a valid float for Volume.");
          return;
      }
      QString etat;
    etat=ui->etat->text();
    if (etat != "casse" && etat != "non casse") {

        QMessageBox::warning(this, "Invalid Input", "Please enter either 'casse' or 'non casse' for etat.");
        return;
    }


    Colis C(id,poids,volume,etat);

     bool test=C.ajouter();
     if(test)
     {
            ui->tab_c->setModel(C.afficher());

              ui->tab_ajout->setModel(C.afficher());

         QMessageBox::information(nullptr, QObject::tr("database is open"),
                     QObject::tr("connection successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

 }
     else
         QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                     QObject::tr("connection failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     ui->le->clear();
     ui->poids->clear();
     ui->volume->clear();
       ui->etat->clear();


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

/*void MainWindow::on_mod_clicked()
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
}*/

void MainWindow::on_aff_clicked()
{
    Colis C;
       ui->tab_c->setModel(C.afficher());
}

void MainWindow::on_tri_clicked()
{
    Colis C;
    QSqlQueryModel MyModel;
    ui->tab_c->setModel(C.sortDatabaseById());
   /* if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Update effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_c->setModel(C.afficher());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("Update non effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);*/
}

void MainWindow::on_Rech_clicked()
{
    int id;
    Colis c;
    //id=ui->Rech_l->text().toInt();

    c.displayItemDetails(id) ;

}

void MainWindow::on_mod1_clicked()
{
    int id;
    id=ui->le->text().toInt();

    float poids;
    poids=ui->poids->text().toFloat();

    float volume;
     volume=ui->volume->text().toFloat();
     QString etat;
   etat=ui->etat->text();



         Colis C(id, poids, volume, etat);

        bool test=C.modifierColis() ;

       if (test)
       {
           QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("Update effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_ajout->setModel(C.afficher());
       }
       else
           QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                    QObject::tr("Update non effectué\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_tri_p_clicked()
{
    Colis C;
    QSqlQueryModel MyModel;
    ui->tab_c->setModel(C.sortDatabaseByPoids());
}

void MainWindow::on_tri_volume_clicked()
{
    Colis C;
    QSqlQueryModel MyModel;
    ui->tab_c->setModel(C.sortDatabaseByVolume());
}

void MainWindow::on_tri_b_clicked()
{
    // Get the selected item from the combo box
       QString selectedOption = ui->combo->currentText();
       Colis C;
       if (selectedOption == "id") {

           //QSqlQueryModel MyModel;
           ui->tab_c->setModel(C.sortDatabaseById());
           } else if (selectedOption == "poids") {
           QSqlQueryModel MyModel;
           ui->tab_c->setModel(C.sortDatabaseByPoids());
           } else if (selectedOption == "volume") {
           QSqlQueryModel MyModel;
           ui->tab_c->setModel(C.sortDatabaseByVolume());
           }

       // Print the selected option
     //  qDebug() << "Selected Option: " << selectedOption;

       // You can also update a label with the selected option if needed
       // ui->label->setText("Selected Option:
}

void MainWindow::on_Rech_3_textChanged(const QString &arg1)
{

        Colis C;
                          QString IDC=ui->Rech_3->text();
                         ui->tab_ajout->setModel(C.rechercher(IDC));
                        ui->tab_ajout->clearSelection();

                  if (arg1.isEmpty() && ui->Rech_3->hasFocus() && !ui->Rech_3->hasSelectedText()) {
                      ui->Rech->setToolTip("Entrez l'id à rechercher");
                  }

}

void MainWindow::on_pdf_clicked()
{
    Colis C;
     QMainWindow pdfWindow;
        if (C.exportDataToPDF(ui->tab_ajout)) {

            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Update effectué\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
            pdfWindow.setWindowTitle("PDF Viewer");
               pdfWindow.setGeometry(100, 100, 800, 600);
               QDesktopServices::openUrl(QUrl::fromLocalFile("colis_report.pdf"));

              // QWebEngineView *pdfView = new QWebEngineView(&pdfWindow);
             //  pdfView->setUrl(QUrl::fromLocalFile("colis_report.pdf")); // Load the PDF file

        } else {
            // Handle export failure
        }
}

/*void MainWindow::on_stat_clicked()
{
    Colis colis; // Create an instance of the Colis class


 //QWidget *chartWidget =colis.createColisCharts();
   //ui->stats->setModel(chartWidget);

 if (chartWidget) {
     // Do something with chartWidget
     // Create a new window for the chart
         QMainWindow chartWindow;
         chartWindow.setCentralWidget(chartWidget);

         // Set the window properties (title, size, etc.)
         chartWindow.setWindowTitle("Chart Window");
         chartWindow.setGeometry(100, 100, 800, 600);

         // Show the chart window
         chartWindow.show();

 } else {
     // Handle the case where chartWidget is not found
 }

 QPdfWriter pdf("C:/FINANCE/colis.pdf");
           QPainter painter(&pdf);


                                    int i = 4000;

                                    painter.setFont(QFont("Bodoni MT", 18));
                                    painter.drawRect(0,3000,6300,2600);
                                    painter.setPen(Qt::black);
                                    painter.drawText(200,1900,"LISTE DES FACTURES");

                                    painter.drawRect(0,3000,9600,500);
                                    painter.setPen(Qt::black);
                                    painter.setFont(QFont("Arial", 10));

                                    painter.drawText(100,3000,"ID");
                                    painter.drawText(1500,3000,"POIDS");
                                    painter.drawText(3500,3000,"VOLUME");
                                    painter.drawText(6000,3000,"ETAT");

                                    QString  value=ui->Rech_3->text();
                                    QSqlQuery query;
                                    query.prepare("select * from FINANCE where (FACTURE_ID LIKE '%"+value+"%')");
                                    query.exec();
                                    while (query.next())
                                    {
                                        painter.drawText(100,i,query.value(0).toString());
                                        painter.drawText(1500,i,query.value(1).toString());
                                        painter.drawText(3500,i,query.value(2).toString());
                                        painter.drawText(6000,i,query.value(3).toString());
                                        painter.drawText(7000,i,query.value(4).toString());
                                        painter.drawText(8500,i,query.value(5).toString());
                                        i = i +1000;
                                    }

                                    int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                                    if (reponse == QMessageBox::Yes)
                                    {
                                        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/FINANCE/facture.pdf"));
                                        painter.end();
                                    }
                                    if (reponse == QMessageBox::No)
                                    {
                                        painter.end();
                                    }


}*/



void MainWindow::on_stat_clicked()
{
    Colis c;
   int num=c.cassenum();
   QString numst = QString::number(num);
   int num2=c.casseNonnum();
   QString num2st = QString::number(num2);
    ui->num1->setText(numst +":non casse est :" + num2st);
    // Call the function to create the pie chart
    QChartView *chartView = c.createPieChart();

    // Set up your UI to include the chart view
    ui->verticalLayout->addWidget(chartView);

    // Call the function to create the pie chart
    QChartView *chartView1 = c.createPieChartPoids();

    // Set up your UI to include the chart view
    ui->verticalLayout_3->addWidget(chartView1);



}
