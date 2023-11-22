#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clients.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QSqlQuery>

#include <QTextDocument>
#include <QTextStream>
#include <QDate>
#include <QPrinter>
#include <QPainter>

#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QStandardPaths>
#include<QPdfWriter>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts>
#include <QPieSlice>

#include "feedback.h"


MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent) ,
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_IDC->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_Clients->setModel(C.afficher());
  //  ui->comboBox_supp->setModel(C.afficher());

   //  connect(ui->pb_FeedBack, &QPushButton::clicked, this, &MainWindow::submitFeedback);
    ClientsStatisticsChartView = nullptr;

       //


        QBarSet *set = new QBarSet("average rating");
            float calculmoy=F.compteretatiiii();

                *set <<calculmoy<<100;

            QBarSeries *series = new QBarSeries();

            series->append(set);



            QChart *chart = new QChart();

            chart->addSeries(series);

            chart->setTitle("Clients");

            chart->setAnimationOptions(QChart:: SeriesAnimations);

            chart->resize(450,300); //tbadel el kobr mtaa el stat selon el label
             QStringList categories;

            categories << " rating " ; //Selon estat mteek kifeh

            QBarCategoryAxis *axis = new QBarCategoryAxis();

            axis->append(categories);

            chart->createDefaultAxes();

            chart->setAxisX(axis,series);



            QChartView *chartView = new QChartView(chart);

            chartView->setParent(ui->label_27);




}

MainWindow::~MainWindow()
{
    clearClients_StatisticsChart();
    delete ui;
}

void MainWindow::stat()
{
    qDebug() << "Updating Clients Statistics Chart label 26";

     QBarSet *set0 = new QBarSet("Client satisfait");

             QBarSet *set1 = new QBarSet("Client non satisfait ");
           //  float calculmoy=F.compteretatiiii();

             int countEtat0 = C.compteretat0();
                 int countEtat1 = C.compteretat1();
                 * set0 <<countEtat1<<10 ; //hedheya el bar loula tnajem tabdel el valeur 40
                 * set1 << countEtat0<<10;
             QBarSeries *series = new QBarSeries();


             series->append(set0);

            series->append(set1);

             QChart *chart = new QChart();

             chart->addSeries(series);

             chart->setTitle("Clients");

             chart->setAnimationOptions(QChart:: SeriesAnimations);

             //chart->resize(600,400); //tbadel el kobr mtaa el stat selon el label
            // chart->setGeometry(80, 60, 600, 400);
              QStringList categories;

             categories << " resolution " ; //Selon estat mteek kifeh

             QBarCategoryAxis *axis = new QBarCategoryAxis();

             axis->append(categories);

             chart->createDefaultAxes();

             chart->setAxisX(axis,series);



             QChartView *chartView = new QChartView(chart);

             chartView->setParent(ui->statFB);
             chartView->setGeometry(80, 70, 600, 400);
             chartView->show();

}


void MainWindow::on_pushButton_5_clicked()
{
    int IDC=ui->le_IDC->text().toInt();
    QString nomc=ui->le_nomc->text();
    QString prenomc=ui->le_prenomc->text();
    QString adressec=ui->le_adressec->text();
    QString emailc=ui->le_emailc->text();
    int numc=ui->le_numeroc->text().toInt();
    int nb_commande=ui->le_nb_commande->text().toInt();
    Clients C( IDC,  nomc,  prenomc,  adressec,  emailc, numc, nb_commande);

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
    int IDC=ui->le_IDC->text().toInt();
    QString nomc=ui->le_nomc->text();
    QString prenomc=ui->le_prenomc->text();
    QString adressec=ui->le_adressec->text();
    QString emailc=ui->le_emailc->text();
    int numc=ui->le_numeroc->text().toInt();
    int nb_commande=ui->le_nb_commande->text().toInt();

   /* int IDC=ui->id_Maj->text().toInt();
    QString nomc=ui->nom_Maj->text();
    QString prenomc=ui->prenom_Maj->text();
    QString adressec=ui->adresse_Maj->text();
    QString emailc=ui->email_Maj->text();
    int numc=ui->num_Maj->text().toInt();
    int nb_commande=ui->le_nb_commande->text().toInt();
    */
    Clients C( IDC,  nomc,  prenomc,  adressec,  emailc, numc, nb_commande);

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
        ui->le_nb_commande->clear();

}



void MainWindow::on_x_chercher_textChanged(const QString &arg1)
{

                      if (arg1!="")
                          ui->tab_Clients->setModel(C.rechercher(arg1));
                      else {
                          ui->tab_Clients->setModel(C.rechercher(arg1));

                      }

               //     ui->tab_Clients->clearSelection();
}



void MainWindow::on_comboBox_tri_zii_currentIndexChanged(const QString &arg1)
{
         if (arg1 == "par defaut") {

                ui->tab_Clients->setModel(C.triClients(arg1));

        } else if (arg1 == "ID") {

                ui->tab_Clients->setModel(C.triClients(arg1));

        } else if (arg1 == "NOM") {

                ui->tab_Clients->setModel(C.triClients(arg1));

        } else if (arg1 == "PRENOM") {

                 ui->tab_Clients->setModel(C.triClients(arg1));
        } else if (arg1 == "ADRESSE") {

                  ui->tab_Clients->setModel(C.triClients(arg1));
        }

}





void MainWindow::on_pb_pdf_clicked()
{

    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            filePath = QDir(filePath).filePath("G_Clients/listeClients.pdf");
            QPdfWriter pdf(filePath);

               QPainter painter(&pdf);
               int i = 4100;
          /* const QImage image("C:/Users/pc/Desktop/image/logo.png");
                           const QPoint imageCoordinates(155,0);
                           int width1 = 1600;
                           int height1 = 1600;
                           QImage img=image.scaled(width1,height1);
                           painter.drawImage(imageCoordinates, img );*/


                      QColor dateColor(0x4a5bcf);
                      painter.setPen(dateColor);

                      painter.setFont(QFont("Montserrat SemiBold", 11));
                      QDate cd = QDate::currentDate();
                      painter.drawText(8400,250,cd.toString("Tunis"));
                      painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

                      QColor titleColor(0x341763);
                      painter.setPen(titleColor);
                      painter.setFont(QFont("Montserrat SemiBold", 25));

                      painter.drawText(3000,2700,"Liste des Clients");

                      painter.setPen(Qt::black);
                      painter.setFont(QFont("Time New Roman", 15));
                      //painter.drawRect(100,100,9400,2500);
                      painter.drawRect(100,3300,9400,500);

                      painter.setFont(QFont("Montserrat SemiBold", 10));

                      painter.drawText(500,3600,"reference");
                      painter.drawText(1700,3600,"nom");
                      painter.drawText(2900,3600,"prenom");
                      painter.drawText(4100,3600,"adresse");
                      painter.drawText(5300,3600,"email");
                      painter.drawText(6500,3600,"numero");
                      painter.drawText(7700,3600,"nb_commande");

                      painter.setFont(QFont("Montserrat", 10));
                      painter.drawRect(100,3300,9400,9000);

                      QSqlQuery query;
                      query.prepare("select * from clients");
                      query.exec();
                      int y=4300;
                      while (query.next())
                      {
                          painter.drawLine(100,y,9490,y);
                          y+=500;
                          painter.drawText(500,i,query.value(0).toString());
                          painter.drawText(1700,i,query.value(1).toString());
                          painter.drawText(2900,i,query.value(2).toString());
                          painter.drawText(4100,i,query.value(3).toString());
                          painter.drawText(5300,i,query.value(4).toString());
                          painter.drawText(6500,i,query.value(5).toString());
                          painter.drawText(7700,i,query.value(6).toString());


                         i = i + 500;
                      }
                      QMessageBox::information(nullptr,QObject::tr("Pdf created"),
                      QObject::tr("File created with seccess.\n"
                                  ""),QMessageBox::Ok);


}


void MainWindow::on_pb_fidelite_clicked()
{
    // Appel de la fonction appliquerPromotion avec la valeur seuil de votre choix

       C.Fidelite(ui->id_fidele->text().toInt(),200);
}






void MainWindow::on_statistique_tabBarClicked(int index)
{
    int statisticsTabIndex = ui->statistique->indexOf(ui->stat);
    int stattabindex = ui->statistique->indexOf(ui->statFB);

    if (index == stattabindex) {
        stat();
    }
    if (index == statisticsTabIndex) {
        update_Clients_StatisticsChart();
    } else {
        clearClients_StatisticsChart();
    }

}


void MainWindow::update_Clients_StatisticsChart()
{
    qDebug() << "Updating Clients Statistics Chart";
    QMap<QString, int> statistics = C.getClients_Statistics();
    int totalClients = 0;

    for (const int &count : statistics.values()) {
        totalClients += count;
    }

    QPieSeries *series = new QPieSeries();
    QStringList colors = {"#55AA00", "#458C68", "#005500"};
    int colorIndex = 0;

    for (const QString &group : statistics.keys()) {
        int count = statistics[group];
        QPieSlice *slice = series->append(group, count);

        slice->setLabel(group + ": " + QString::number(static_cast<double>(count) / totalClients * 100, 'f', 2) + "%");

        if (colorIndex < colors.size()) {
            slice->setBrush(QColor(colors[colorIndex]));
        } else {
            slice->setBrush(QColor(Qt::green));
        }

        colorIndex++;
    }

    clearClients_StatisticsChart();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par nombre de commande ");
    chart->setBackgroundBrush(QBrush(QColor("#F5F5DC")));

    ClientsStatisticsChartView = new QChartView(chart);
    ClientsStatisticsChartView->setRenderHint(QPainter::Antialiasing);
    ClientsStatisticsChartView->setParent(ui->stat);
    ClientsStatisticsChartView->setGeometry(70, 50, 600, 400);

    ClientsStatisticsChartView->show();
}

void MainWindow::clearClients_StatisticsChart()
{
    if (ClientsStatisticsChartView) {
        delete ClientsStatisticsChartView;
        ClientsStatisticsChartView = nullptr;
    }
}












void MainWindow::on_pb_FeedBack_clicked()
{
    int IDF=ui->id_FeedBack->text().toInt();
    int rating=ui->le_rating->text().toInt();
    QString delivery=ui->le_time->text();
    QString communication=ui->le_comu->text();
    QString etat=ui->le_pack->text();
    int res=ui->le_prob->text().toInt();
    FeedBack F ( IDF , rating , delivery, communication, etat, res) ;

    bool test=F.ajout_FeedBack() ;
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




