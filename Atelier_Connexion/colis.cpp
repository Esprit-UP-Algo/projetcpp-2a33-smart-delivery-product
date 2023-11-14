#include "colis.h"
#include"QString"
#include"QSqlQuery"
#include"QtDebug"
#include <QSqlQueryModel>
#include <iostream>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>

#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>

#include <QLabel>
#include <QTableWidget>
#include <QTextOption>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <QtCharts/QBarSeries>
#include <QtCharts>
#include <QtSql>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
using namespace std;
Colis::Colis()
{
Id_colis=0;
poids=0;
volume=0;
etat=" ";//false: non casse,true: casse

}
Colis::Colis(int Id_colis,float poids,float volume,QString etat)
{
    this->Id_colis=Id_colis;
    this->poids=poids;
    this->volume=volume;
    this->etat=etat;

}

int Colis::get_id(){return Id_colis;}
float Colis::get_poids(){return poids;}
float Colis::get_volume(){return volume;}

/*QString Colis::get_etat(){return etat;}*/


void Colis::set_id(int Id_colis){this->Id_colis=Id_colis;}

void Colis::set_poids(float poids){this->poids=poids;}
void Colis::set_valume(float volume){this->volume=volume;}
/*
void Colis::set_etat(QString etat){this->etat=etat;}*/
bool Colis::ajouter()
{


    QSqlQuery query;

   QString poids_string=QString::number((poids));
    QString volume_string=QString::number((volume));
    query.prepare("INSERT INTO COLIS (ID ,POIDS,VOLUME,ETAT) "
                  "VALUES (:id, :poids, :volume, :etat)");
    query.bindValue(":id", Id_colis);
    query.bindValue(":poids", poids_string);
    query.bindValue(":volume", volume_string);

    query.bindValue(":etat", etat);

    return query.exec();


}
bool Colis::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from COLIS where ID= :id");
    query.bindValue(":id",res);

    return query.exec();
}
QSqlQueryModel * Colis::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("select * from colis");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("POIDS"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("VOLUME"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ETAT"));

    return model;
}
bool Colis::modifierColis()
{
    QSqlQuery query;

    QString poids_string=QString::number((poids));
     QString volume_string=QString::number((volume));
           query.prepare("UPDATE colis SET   POIDS=:poids,VOLUME=:volume,ETAT=:etat WHERE ID=:id");

           query.bindValue(":id", Id_colis);
           query.bindValue(":poids", poids_string);
           query.bindValue(":volume", volume_string);
           query.bindValue(":etat", etat);





           return query.exec();

}


QSqlQueryModel *  Colis::sortDatabaseById() {
    QSqlQuery query;
  // query.prepare("SELECT * FROM colis ORDER BY ID");
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM colis ORDER BY ID");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("VOLUME"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));

       return model;

}
QSqlQueryModel* Colis::rechercher(QString test)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM COLIS WHERE ID LIKE :test");
    query.bindValue(":test", "%" + test + "%");
    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("VOLUME"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));

    } else {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError().text();
    }
    return model;
}


void  Colis::displayItemDetails(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID, POIDS, VOLUME, ETAT FROM colis WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
           // Create a dialog to display the item details
           QDialog dialog;
           dialog.setWindowTitle("Item Details");

           QVBoxLayout layout(&dialog);
           QLabel* label = new QLabel;

           if (query.next()) {
               int itemId = query.value(0).toInt();
               int poids = query.value(1).toInt();
               int volume = query.value(2).toInt();
               QString etat = query.value(3).toString();

               label->setText(QString("ID: %1\nPOIDS: %2\nVOLUME: %3\nETAT: %4")
                                  .arg(itemId)
                                  .arg(poids)
                                  .arg(volume)
                                  .arg(etat));

               layout.addWidget(label);
           } else {
               QMessageBox::warning(&dialog, "Item Not Found", "Item with ID " + QString::number(id) + " not found.");
               return;
           }

           dialog.exec();
       } else {
           QMessageBox::critical(0, "Query Error", "Query failed: " + query.lastError().text());
       }

}
QSqlQueryModel *  Colis::sortDatabaseByPoids()
{
    QSqlQuery query;
  // query.prepare("SELECT * FROM colis ORDER BY ID");
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM colis ORDER BY POIDS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("VOLUME"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
       return model;

}
QSqlQueryModel *  Colis::sortDatabaseByVolume()
{
    QSqlQuery query;
  // query.prepare("SELECT * FROM colis ORDER BY ID");
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM colis ORDER BY VOLUME");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("VOLUME"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
       return model;
}
bool Colis::exportDataToPDF(QTableView* tableView)
{

    QPdfWriter pdfWriter("colis_report.pdf");
        pdfWriter.setPageSize(QPageSize(QPageSize::A4));
        QPainter painter(&pdfWriter);

        // Start painting the PDF
        painter.begin(&pdfWriter);

        // Render the label's text to the PDF
      //  painter.drawText(100, 100, label->text(), QTextOption(Qt::AlignLeft));

        // Render the table view to the PDF
        tableView->render(&painter);

        // End painting
        painter.end();

        // Set the PDF file path
        pdfFilePath = "colis_report.pdf";

        // Return true if export is successful
        return true;
}
 /*QWidget* Colis::createColisCharts()
 {

     QSqlQuery query("SELECT * FROME COLIS");
 //QPieSlice *pieSlice;


     while (query.next()) {
         QString id = query.value(0).toString();
         double poids = query.value(1).toDouble();
         double volume = query.value(2).toDouble();
         QString etat = query.value(3).toString();

         // Check for valid data and skip if necessary
         if (id.isEmpty() || poids == 0.0 || volume == 0.0) {
             continue;
         }

         // Create a bar set for each attribute
         QBarSet *barSet = new QBarSet("ID: " + id);
         *barSet << poids << volume;

         // Add the bar set to the bar series
         barSeries->append(barSet);

         // Create a pie slice for each etat
         QPieSlice *pieSlice = pieSeries->append(etat, poids);
         pieSlice->setLabel(QString("%1: %2").arg(etat).arg(poids));
     }
     QWidget *widget = new QWidget();
        QVBoxLayout *layout = new QVBoxLayout(widget);
        layout->addWidget(barChartView);
        layout->addWidget(pieChartView);
        QGraphicsScene *scene = new QGraphicsScene();
        //   scene->addItem(pieSlice);

           // Create a view and set the scene
           QGraphicsView *view = new QGraphicsView(scene);

           // Set up the window
           view->setRenderHint(QPainter::Antialiasing, true);
           view->setWindowTitle("Chart Window");
           view->resize(800, 600);

           // Show the window
           view->show();

        // Return the widget
        return widget;

 }*/
  int Colis::cassenum()
  {
      int num=0;
     QSqlQuery query("SELECT ETAT FROM COLIS");
     while (query.next()) {
          QString etat = query.value(0).toString();
          if (etat == "casse") {

             num++;
          }

     }
     return num;
  }
  int Colis::casseNonnum()
  {
      int num=0;
     QSqlQuery query("SELECT ETAT FROM COLIS");
     while (query.next()) {
          QString etat = query.value(0).toString();
          if (etat == "non casse") {

             num++;
          }

     }
     return num;
  }
 QChartView* Colis::createPieChart()
 {

int casseCount = 0;
int nonCasseCount =0;
QPieSeries *series = new QPieSeries();

QSqlQuery query("SELECT ETAT FROM COLIS ");

 while (query.next()) {

        QString etat = query.value(0).toString();
        if(etat=="casse")
        {
            casseCount++;
        }
        else
        {
            nonCasseCount++;
        }}

       if (casseCount >= 0)
       {
           QPieSlice *casseSlice = series->append("Casse", casseCount);
           casseSlice->setLabel(QString("Casse: %1").arg(casseCount));
       }

       if (nonCasseCount >=0)
       {
           QPieSlice *nonCasseSlice = series->append("Non Casse", nonCasseCount);
           nonCasseSlice->setLabel(QString("Non Casse: %1").arg(nonCasseCount));
      }

     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Etat Distribution");

     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);

     return chartView;
 }

 QChartView* Colis::createPieChartPoids()
 {

int poids1 = 0;
int poids2 =0;
int poids3=0;
int poids4=0;
QPieSeries *series = new QPieSeries();

QSqlQuery query("SELECT POIDS FROM COLIS ");

 while (query.next()) {

        int poids = query.value(0).toInt();
        if(poids>0&&poids<2)
        {
            poids1++;
        }
        else if(poids>2&&poids<10)
        {
            poids2++;
        }
        else if(poids>10&&poids<20)
        {
            poids3++;
        }
        else
        {
            poids4++;
        }

 }

       if (poids1 >= 0)
       {
           QPieSlice *casseSlice = series->append("0-2", poids1);
           casseSlice->setLabel(QString("0-2: %1").arg(poids1));
       }

       if (poids2 >=0)
       {
           QPieSlice *nonCasseSlice = series->append("2-10", poids2);
           nonCasseSlice->setLabel(QString("2-10: %1").arg(poids2));
      }
       if (poids3 >=0)
       {
           QPieSlice *nonCasseSlice = series->append("10-20", poids3);
           nonCasseSlice->setLabel(QString("10-20: %1").arg(poids3));
      }
       if (poids4 >=0)
       {
           QPieSlice *nonCasseSlice = series->append("20>", poids4);
           nonCasseSlice->setLabel(QString("20: %1").arg(poids4));
      }
     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Etat Distribution");

     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);

     return chartView;
 }

