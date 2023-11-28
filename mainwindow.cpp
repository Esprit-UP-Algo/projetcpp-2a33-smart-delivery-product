#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vehicule.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QRegExp>
#include <QPainter>
#include <QtCharts>
#include<QChartView>
#include<QBarSet>
#include<QBarSeries>
#include<QDebug>
#include<QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->le_reference->setValidator(new QIntValidator(0,999999,this));
    ui->tab_vehicule->setModel(S.afficher());
    connect(ui->pb_Maintenance, &QPushButton::clicked, this, &MainWindow::on_pb_Maintenance_clicked);

    QBarSet *set0 = new QBarSet("VEHICULE DISPONIBLE");

        QBarSet *set1 = new QBarSet("VEHICULE NON DISPONIBLE ");

        * set0 << 40<<100 ; //hedheya el bar loula tnajem tabdel el valeur 40

        * set1 << 50<<100  ;

        QBarSeries *series = new QBarSeries();

        series->append(set0);

        series->append(set1);

        QChart *chart = new QChart();

        chart->addSeries(series);

        chart->setTitle("VEHICULE");

        chart->setAnimationOptions(QChart:: SeriesAnimations);

        chart->resize(450,300); //tbadel el kobr mtaa el stat selon el label



        QStringList categories;

        categories << " Statistique des Vehicules " ; //Selon estat mteek kifeh

        QBarCategoryAxis *axis = new QBarCategoryAxis();

        axis->append(categories);

        chart->createDefaultAxes();

        chart->setAxisX(axis,series);



        QChartView *chartView = new QChartView(chart);

        chartView->setParent(ui->stat);
    //w hotha fi label el kol
    //w hedheya hotha f mainwindow.cpp taht
     //(ui->setupUi(this);)

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
     int immatricule=ui->l_immatricule->text().toInt();
     QString marque=ui->l_marque->text();
     QString modele=ui->l_modele->text();
     int kilometrage=ui->l_kilo->text().toInt();
     int maintenance=ui->l_maintenance->text().toInt();
     int capabilite=ui->l_capa->text().toInt();
     vehicule S(immatricule,marque,modele,kilometrage,maintenance,capabilite);
     bool test=S.ajouter();
    QMessageBox msgBox;
     if(test )
     {
         msgBox.setText("Ajout avec succes.");
         ui->tab_vehicule->setModel(S.afficher());
     }
     else
         msgBox.setText("Echec d'ajout.");
         msgBox.exec();
}
void MainWindow::on_pb_supp_clicked()
{
    vehicule S1;
    S1.setImmatricule(ui->l_immatricule_supp->text().toInt());
    bool test=S1.supprimer(S1.getImmatricule());
   QMessageBox msgBox;
   if (test)
      {
          QMessageBox::information(nullptr, QObject::tr("ok"),
                                   QObject::tr("Update effectué\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tab_vehicule->setModel(S.afficher());
      }
      else
          QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                   QObject::tr("Update non effectué\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

    /* if(test!=true)
    {
        msgBox.setText("Suppression avec succes.");
        ui->tab_vehicule->setModel(S.afficher());
    }
    else
        msgBox.setText("Echec de supprimer.");
        msgBox.exec();*/
}
void MainWindow::on_pb_modifier_clicked()
{
     int immatricule=ui->l_immatricule->text().toInt();
     QString marque=ui->l_marque->text();
     QString modele=ui->l_modele->text();
     int kilometrage=ui->l_kilo->text().toInt();
     int maintenance=ui->l_maintenance->text().toInt();
     int capabilite=ui->l_capa->text().toInt();
            vehicule S(immatricule,marque,modele,kilometrage,maintenance,capabilite);
            bool test=S.modifier();
            QMessageBox msgBox;
            if (test)
               {
                   QMessageBox::information(nullptr, QObject::tr("ok"),
                                            QObject::tr("Update effectué\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);
                   ui->tab_vehicule->setModel(S.afficher());
               }
               else
                   QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                            QObject::tr("Update non effectué\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

           /*  if(test!=true )
             {
                 msgBox.setText("Modification avec succes.");
                 ui->tab_vehicule->setModel(S.afficher());
             }
             else
                 msgBox.setText("Echec de Modification.");
                 msgBox.exec(); */
}




void MainWindow::on_combobox_tri_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "par defaut") {

           ui->tab_vehicule->setModel(S.trivehicule(arg1));

   } else if (arg1 == "immatricule") {

           ui->tab_vehicule->setModel(S.trivehicule(arg1));

   } else if (arg1 == "marque") {

           ui->tab_vehicule->setModel(S.trivehicule(arg1));

   } else if (arg1 == "modele") {

            ui->tab_vehicule->setModel(S.trivehicule(arg1));

   }else if (arg1 == "kilometrage") {

        ui->tab_vehicule->setModel(S.trivehicule(arg1));

}
}

void MainWindow::on_pb_Maintenance_clicked() {
    QString immatricule = ui->l_immatricule_Maintenance->text();
    bool estPret = S.Maintenance();
    if (estPret) {
            ui->resultat_Maintenance->setText("Le véhicule est prêt à être utilisé.");
        } else {
            ui->resultat_Maintenance->setText("Le véhicule nécessite une maintenance.");
        }

}

void MainWindow::on_pb_recherche_clicked()
{
        int immatricule = ui->l_immatricule_rech->text().toInt();

vehicule vehicule;
QSqlQuery query = vehicule.rechercher_immatricule(immatricule);

        if (query.exec() && query.next()) {
           qDebug() << "azerty";
            ui->tab_vehicule_rech->setColumnCount(query.record().count());
            for (int i = 0; i < query.record().count(); i++) {
                QTableWidgetItem *headerItem = new QTableWidgetItem(query.record().fieldName(i));
                ui->tab_vehicule_rech->setHorizontalHeaderItem(i, headerItem);
            }

            // Remplir les données trouvées dans le QTableWidget
            ui->tab_vehicule_rech->setRowCount(0);
            do {
                int row = ui->tab_vehicule_rech->rowCount();
                ui->tab_vehicule_rech->insertRow(row);
                for (int col = 0; col < query.record().count(); col++) {
                    QTableWidgetItem *item = new QTableWidgetItem(query.value(col).toString());
                    ui->tab_vehicule_rech->setItem(row, col, item);
                }
            } while (query.next());
        }


}

void MainWindow::on_pb_pdf_clicked()
{

    QPdfWriter pdf("C:/projet_pdf/pdf");
    int i = 4000;
    QPainter painter(&pdf);
    QString strStream;

    QTextStream out(&strStream);
    painter.setPen(Qt::red);
    painter.setFont(QFont("Time New Roman", 25));
    painter.drawText(3000,1400,"Liste Des Vehicules");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Time New Roman", 7));
    painter.setPen(Qt::darkCyan);
    painter.drawRect(100,100,9400,2500);
    painter.drawRect(100,3000,9400,500);
    painter.setPen(Qt::black);
    painter.drawText(300,3300," immatricule");
    painter.drawText(1300,3300,"marque");
    painter.drawText(2300,3300,"modele");
    painter.drawText(3300,3300,"kilometrage");
    painter.drawText(4300,3300,"maintenance");
    painter.drawText(5300,3300,"capabilite");
    painter.setPen(Qt::darkCyan);
    painter.drawRect(100,3000,9400,9000);
    painter.setPen(Qt::black);
    QSqlQuery query;
    query.prepare("select * from GS_vehicule");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(1300,i,query.value(1).toString());
        painter.drawText(2300,i,query.value(2).toString());
        painter.drawText(3300,i,query.value(3).toString());
        painter.drawText(4300,i,query.value(4).toString());
        painter.drawText(5300,i,query.value(5).toString());
        i +=350;
    }
        QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
        QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}
