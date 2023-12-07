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
#include <QPrinter>
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

#include <iostream>
#include <random>
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
 //***************************************************

bool Colis::ajouter()
{


    QSqlQuery query;


    QString poids_string=QString::number((poids));
        QString volume_string=QString::number((volume));
    // Retrieve the generated idl from the sequence


    // Insert into the Colis table
    query.prepare("INSERT INTO COLIS (ID, POIDS, VOLUME, ETAT) "
                  "VALUES (:id, :poids, :volume, :etat)");

    query.bindValue(":id", Id_colis);
    query.bindValue(":poids", poids_string);
    query.bindValue(":volume", volume_string);
    query.bindValue(":etat", etat);







    // Execute the Colis insert query
    bool colisInsertSuccess = query.exec();

    if (!colisInsertSuccess) {
        qDebug() << "Colis insert failed:" << query.lastError().text();
        return false;
    }

    return true;




}
 //***************************************************]

bool Colis::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from COLIS where ID= :id");
    query.bindValue(":id",res);

    return query.exec();
}
 //***************************************************
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
 //***************************************************
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

 //***************************************************
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
 //***************************************************
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


//***************************************************
QSqlQueryModel* Colis::rechercherpoids(QString test)
{
   QSqlQueryModel *model = new QSqlQueryModel();
   QSqlQuery query;
   query.prepare("SELECT * FROM COLIS WHERE poids LIKE :test");
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

//***************************************************
QSqlQueryModel* Colis::rechercherVolume(QString test)
{
   QSqlQueryModel *model = new QSqlQueryModel();
   QSqlQuery query;
   query.prepare("SELECT * FROM COLIS WHERE poids LIKE :test");
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



 //***************************************************
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
 //***************************************************
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
 //***************************************************
QSqlQueryModel *  Colis::sortDatabaseByVolume()
{
    QSqlQuery query;

   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM colis ORDER BY VOLUME");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("POIDS"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("VOLUME"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
       return model;
}
 //***************************************************
void Colis::exportDataToPDF()
{
    QSqlQuery query("SELECT id, poids, volume, etat FROM colis");

            // Create a PDF file

            QString fileName = QFileDialog::getSaveFileName(nullptr, "Save PDF", "", "PDF Files (*.pdf)");


    QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setOutputFileName(fileName);

      QPainter painter;
       painter.begin(&printer);

       // Add content to the PDF
       QTextDocument document;

       document.setPlainText("  \t\tListe des Colis \n\n");

       // Add header row
       QString header = QString("%1\t%2\t%3\t%4").arg("ID").arg("Poids").arg("Volume").arg("Etat");
       document.setPlainText(document.toPlainText()+"   \t" + header + "\n\n");

       while (query.next()) {
           QString data = QString("%1\t%2\t%3\t%4")
                              .arg(query.value("id").toString())
                              .arg(query.value("poids").toString())
                              .arg(query.value("volume").toString())
                              .arg(query.value("etat").toString());

           document.setPlainText(document.toPlainText() +"   \t"+ data + "\n");
            document.setPlainText(document.toPlainText()+ "\n");
       }

       // Draw the document to the painter
       document.setDefaultTextOption(QTextOption(Qt::AlignCenter));

      document.drawContents(&painter);


       painter.end();

       qDebug() << "PDF generated successfully!";
   }
//**********************************************************
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
void Colis::exportDataToPDF_par_coli(QString id)
{
    QSqlQuery query;

            // Get Colis ID from the user (you need to implement this part)


            // Create a PDF file
            QString fileName = QFileDialog::getSaveFileName(nullptr, "Save PDF", "", "PDF Files (*.pdf)");


       query.prepare("SELECT ID, POIDS, VOLUME, ETAT FROM colis WHERE ID = :id");









                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName(fileName);

                QPainter painter;
                painter.begin(&printer);

                // Add content to the PDF
                QTextDocument document;
                document.setDefaultTextOption(QTextOption(Qt::AlignCenter)); // Set text alignment to center
                document.setPlainText(QString("Colis Information for ID :"+id+"\n"));

                // Add header row
                QString header = QString("%1\t%2\t%3\t%4").arg("ID").arg("Poids").arg("Volume").arg("Etat");
                document.setPlainText(document.toPlainText() + header + "\n");

                // Retrieve data for the specified ID
                query.prepare("SELECT id, poids, volume, etat FROM colis WHERE id = :colisID");
                query.bindValue(":colisID", id);

                if (query.exec() && query.next()) {
                    QString data = QString("%1\t%2\t%3\t%4")
                                       .arg(query.value("id").toString())
                                       .arg(query.value("poids").toString())
                                       .arg(query.value("volume").toString())
                                       .arg(query.value("etat").toString());

                    document.setPlainText(document.toPlainText() + data + "\n");

                    // Draw the document to the painter
                    document.drawContents(&painter);
                    painter.end();

                    qDebug() << "PDF generated successfully!";
                } else {
                    qDebug() << "Error retrieving data for Colis ID" << id << ":" << query.lastError().text();
                }




   }
 //***************************************************
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
   //***************************************************
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






   //***************************************************




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
series->setLabelsVisible();
     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->chart()->setAnimationOptions(QChart::AllAnimations);
     chartView->chart()->legend()->hide();
     return chartView;
 }
 //***************************************************
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
        if(poids>=0&&poids<=20)
        {
            poids1++;
        }
        else if(poids>20&&poids<100)
        {
            poids2++;
        }
        else if(poids>100&&poids<200)
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
     QPieSlice *casseSlice = series->append("0-2 KG", poids1);
     casseSlice->setLabel(QString("0-2 KG: %1").arg(poids1));
 }

 if (poids2 >=0)
 {
     QPieSlice *nonCasseSlice = series->append("2-10 KG", poids2);
     nonCasseSlice->setLabel(QString("2-10 KG: %1").arg(poids2));
}
 if (poids3>=0)
 {
     QPieSlice *nonCasseSlice = series->append("10-20 KG", poids3);
     nonCasseSlice->setLabel(QString("10-20 KG: %1").arg(poids2));
}
 if (poids4>=0)
 {
     QPieSlice *nonCasseSlice = series->append("20-40 KG", poids4);
     nonCasseSlice->setLabel(QString("20-40 KG: %1").arg(poids4));
}
/*
      series->append("", poids1);
       series->append("", poids2);
       series->append("10-20 KG", poids3);
        series->append("20-40 KG", poids4);*/



     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Etat Distribution");
series->setLabelsVisible();
     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->setRenderHint(QPainter::Antialiasing);
chartView->chart()->setAnimationOptions(QChart::AllAnimations);
chartView->chart()->legend()->hide();
     return chartView;
 }
 //***************************************************
 QChartView *Colis::valume(){
 int volume1 = 0;
 int volume2 =0;
 int volume3=0;
 int volume4=0;


 QSqlQuery query("SELECT VOLUME FROM COLIS ");


 while(query.next())
 {
      int volume = query.value(0).toInt();
         if(volume>=0&&volume<=30)
         {
             volume1++;
         }
         else if(volume>30&&volume<100)
         {
             volume2++;
         }
         else if(volume>100&&volume<200)
         {
             volume3++;
         }
         else
         {
             volume4++;
         }

 }
  QBarSet *set1 = new QBarSet("0-30");
     QBarSet *set2 = new QBarSet("30-100");
     QBarSet *set3 = new QBarSet("100-200");
  QBarSet *set4 = new QBarSet("200+");

     *set1 <<volume1 ;
     *set2 <<NULL << volume2 ;
     *set3 << NULL<< NULL<< volume3 ;
     *set4 << NULL<< NULL<<NULL <<volume4 ;

     QBarSeries *series = new QBarSeries();

     series->append(set1);
     series->append(set2);
     series->append(set3);
 series->append(set4);

   QChart *chart = new QChart();
     chart->addSeries(series);

     chart->setTitle("Statistique volume");

     QStringList cate;
     cate << "0-30" << "30-100" << "100-200"<<"200+";

   QBarCategoryAxis *axis = new QBarCategoryAxis();
     axis->append(cate);
     chart->createDefaultAxes();
     chart->setAxisX(axis,series);
     QChartView *chartView = new QChartView(chart);
  chartView->chart()->setAnimationOptions(QChart::AllAnimations);
     return chartView;
 }
 bool Colis::ajouter_tmp(float tmp)
 {

     QSqlQuery query;


         QString tmp_string=QString::number((tmp));

         // Get the current date and time
            QDateTime currentDateTime = QDateTime::currentDateTime();

            // Convert the date and time to a string
            QString date = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");

         query.prepare("INSERT INTO TEMPERATURE (tmp,datee) "
                          "VALUES (:tmp, :date)");
         query.bindValue(":tmp", tmp_string);
         query.bindValue(":date", currentDateTime);

            // Execute the Colis insert query
            bool colisInsertSuccess = query.exec();

            if (!colisInsertSuccess) {
                qDebug() << "Colis insert failed:" << query.lastError().text();
                return false;
            }

            return true;
 }
   QSqlQueryModel *Colis:: afficher_tmp()
   {
       QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select * from TEMPERATURE");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("date"));
       return model;
   }
   QChartView* Colis::createPieChart_TMP()
   {

  int poids1 = 0;
  int poids2 =0;

  QPieSeries *series = new QPieSeries();

  QSqlQuery query("SELECT TMP FROM TEMPERATURE ");

   while (query.next()) {

          int poids = query.value(0).toInt();
          if(poids>=0&&poids<=25)
          {
              poids1++;
          }
          else if(poids>25)
          {
              poids2++;
          }


   }
   if (poids1 >= 0)
   {
       QPieSlice *casseSlice = series->append("0-2 KG", poids1);
       casseSlice->setLabel(QString("0-25: %1").arg(poids1));
   }

   if (poids2 >=0)
   {
       QPieSlice *nonCasseSlice = series->append("0-25", poids2);
       nonCasseSlice->setLabel(QString("25>: %1").arg(poids2));
  }

  /*
        series->append("", poids1);
         series->append("", poids2);
         series->append("10-20 KG", poids3);
          series->append("20-40 KG", poids4);*/



       QChart *chart = new QChart();
       chart->addSeries(series);
       chart->setTitle("TEMPERATURE");
  series->setLabelsVisible();
       QChartView *chartView = new QChartView(chart);
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->setRenderHint(QPainter::Antialiasing);
  chartView->chart()->setAnimationOptions(QChart::AllAnimations);
  chartView->chart()->legend()->hide();
       return chartView;
   }

