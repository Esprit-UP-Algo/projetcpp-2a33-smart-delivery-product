#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"colis.h"
#include"QString"
#include"vehicule.h"
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
#include<QPrinter>
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
#include"location.h"
#include"arduino.h"
#include <QTimer>
#include "clients.h"
#include "mainclients.h"
#include "style.h"
#include <QLabel>
#include <QMovie>
#include"qgiflabel.h"
#include <QIcon>
#include"commande.h"
#include<QIntValidator>
#include"feedback.h"
//livreur
#include"livreur.h"
#include <QMessageBox>
#include "qpainter.h"
#include "qpdfwriter.h"
#include <QTextTableFormat>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include "qcustomplot.h"
#include "QMessageBox"
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
      applyStyles(ui);
setWindowTitle("DEFAST");

//feedback_statt();



QPixmap imagePixmap("C:/Users/zied/Desktop/ProjetCpp/logo_pro-removebg-preview.png"); // Replace with the actual path to your image file

// Set the image on the QLabel
ui->logo_label->setPixmap(imagePixmap);

// Set the aspect ratio mode to maintain the aspect ratio of the image
ui->logo_label->setScaledContents(true);
//
//livreur
//livreur
QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label_livreur()));//arduino
ui->tableView_livreur->setModel(L.afficher()); // Rafraîchir la vue
ui->comboBox_supp_livreur->setModel(L.afficher());
ui->comboBox_modi_livreur->setModel(L.afficher());
MainWindow::makePlot();
   /* emit setCenterPosition( 36.8065,10.1815);
     emit setLocationMarking( 36.8065,10.1815);*/
     QIcon icon("C:/Users/zied/Desktop/ProjetCpp/delete-icon.png");
      QIcon iconPdf("C:/Users/zied/Desktop/ProjetCpp/PDF-icon.png"); // Replace with the actual path to your icon file
//**************************stat balkis
//******************

//******************
      ui->tab_Clients->setModel(C.afficher());
      ui->tab_FeedBack->setModel(F.afficher());
 //ui->DE->setIcon(icon);

 ui->pdf->setIcon(iconPdf);
    ui->tab_c->setModel(Ctmp.afficher());
    Colis colis;
ui->go_back->hide();



   // *************ARDUINO**********************

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
//***************************************************


vehicule S;
       Clients C;
     //  ui->setupUi(this);
      // ui->le_IDC->setValidator(new QIntValidator(0,9999999,this));


       ClientsStatisticsChartView = nullptr;

#include <QIcon>

// ...

QPushButton *myButton = new QPushButton("Click me", this);

// Assuming you have an icon file named "icon.png" in your resources or project directory
QIcon icon2("C:/Users/zied/Desktop/ProjetCpp/menu-icon.png");

ui->go_back->setIcon(icon2);

// You can also set an icon size if needed
ui->go_back->setIconSize(QSize(70, 70));

       //code client
       ui->le_IDC->setValidator(new QIntValidator(0,9999999,this));
       ui->tab_Clients->setModel(C.afficher());

       QLabel* logoLabel = new QLabel;
       QPixmap logoPixmap("C:/Users/zied/Desktop/ProjetCpp/logo_pro-removebg-preview.png");

       // Set the pixmap on the QLabel
       logoLabel->setPixmap(logoPixmap);

       // Set the aspect ratio mode to maintain the aspect ratio of the image
       logoLabel->setScaledContents(true);

       // Set other properties if needed
       // ...

       // Add the QLabel to the existing layout or parent widget directly
      // ui->logo_label->addWidget(logoLabel);



}





MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_ajouter_clicked()
{



     int id;
     bool isInt;
     Location l;
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
 ui->tab_vehicule->setModel(S.afficher());
      QString etat = ui->combo_etat->currentText();

      if (etat == "casse") {
           etat="casse";
          } else if (etat == "non casse") {
            etat="non casse";
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


bool test1=l.ajouter_loc(id);
if(test1)
{
    QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("connection successful zied.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("connection failed alimi.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


     ui->le->clear();
     ui->poids->clear();
     ui->volume->clear();
       //ui->etat->clear();



}



void MainWindow::on_supp_clicked()
{
    QModelIndexList selectedIndexes = ui->tab_c->selectionModel()->selectedIndexes();

   // int id=ui->supp_2->text().toInt();


    if (!selectedIndexes.isEmpty()) {
           // Assuming the ID is in the first column (column 0) of the selected row
           int selectedRow = selectedIndexes.at(0).row();
           int id = ui->tab_c->model()->data(ui->tab_c->model()->index(selectedRow, 0)).toInt();

           // Call the supprimer function with the selected ID
           bool test = Ctmp.supprimer(id);

           if (test) {
               ui->tab_c->setModel(Ctmp.afficher());
               QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectuee\n""Click Cancel to exit."), QMessageBox::Cancel);
           } else {
               QMessageBox::critical(nullptr, QObject::tr("OK"), QObject::tr("Suppression non effectuee\n""Click Cancel to exit."), QMessageBox::Cancel);
           }
       } else {
           // Inform the user that no row is selected
           QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("Veuillez sélectionner une ligne à supprimer."), QMessageBox::Ok);
       }


}

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
   //etat=ui->etat->text();



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

  }


void MainWindow::on_Rech_3_textChanged(const QString &arg1)
{

    Colis C;

    QString selectedOption = ui->combo_4->currentText();
    if (selectedOption == "id") {

        QString IDC=ui->Rech_3->text();
       ui->tab_ajout->setModel(C.rechercher(IDC));
      ui->tab_ajout->clearSelection();

if (arg1.isEmpty() && ui->Rech_3->hasFocus() && !ui->Rech_3->hasSelectedText()) {
    //ui->Rech->setToolTip("Entrez l'id à rechercher");
}

        } else if (selectedOption == "poids") {


        QString IDC=ui->Rech_3->text();
       ui->tab_ajout->setModel(C. rechercherpoids(IDC));
      ui->tab_ajout->clearSelection();}

if (arg1.isEmpty() && ui->Rech_3->hasFocus() && !ui->Rech_3->hasSelectedText()) {
   // ui->Rech->setToolTip("Entrez l'id à rechercher");

        } else if (selectedOption == "volume") {
    QString IDC=ui->Rech_3->text();
   ui->tab_ajout->setModel(C. rechercherVolume(IDC));
  ui->tab_ajout->clearSelection();}

if (arg1.isEmpty() && ui->Rech_3->hasFocus() && !ui->Rech_3->hasSelectedText()) {
//ui->Rech->setToolTip("Entrez l'id à rechercher");

        }



}

void MainWindow::on_pdf_clicked()
{

     int id=ui->pdf_bar->text().toInt();
QString    strid=  QString::number(id);
    // Get the selected item from the combo box
       QString selectedOption = ui->combo_2->currentText();
       Colis C;
       if (selectedOption == "liste des colis") {
              C.exportDataToPDF();
           //QSqlQueryModel MyModel;

           }
       else if (selectedOption == "coli") {

           C.exportDataToPDF_par_coli(strid);
           }







}





void MainWindow::on_stat_clicked()
{

    QLayoutItem* item;
       while ((item =ui->verticalLayout ->takeAt(0)) != nullptr) {
           delete item->widget();
           delete item;
       }
QVBoxLayout *verticalLayout = new QVBoxLayout();

    Colis c;

    QString selectedOption = ui->combo_3->currentText();
    Colis C;
    if (selectedOption == "etat") {

        // Call the function to create the pie chart
        QChartView *chartView = c.createPieChart();

        // Set up your UI to include the chart view
        ui->verticalLayout->addWidget(chartView);
        } else if (selectedOption == "poids") {
        // Call the function to create the pie chart
        QChartView *chartView1 = c.createPieChartPoids();

        // Set up your UI to include the chart view
        ui->verticalLayout->addWidget(chartView1);
        } else if (selectedOption == "volume") {
        // Call the function to create the pie chart
        QChartView *chartView2 = c.valume();

        // Set up your UI to include the chart view
        ui->verticalLayout->addWidget(chartView2);

        }






    //



   // Delete the layout item
 }




void MainWindow::on_stat_2_clicked()
{
  /* // QString num2st = QString::number(num2);
    QLayoutItem* item;
       while ((item =ui->verticalLayout ->takeAt(0)) != nullptr) {
           delete item->widget();
           delete item;
       }
QVBoxLayout *verticalLayout = new QVBoxLayout();


    while ((ui->verticalLayout_5->takeAt(0)) != nullptr) {
        delete ui->verticalLayout_5->widget();  // Delete the widget
        delete ui->verticalLayout_5;}
    while ((ui->verticalLayout_3->takeAt(0)) != nullptr) {
        delete ui->verticalLayout_3->widget();  // Delete the widget
        delete ui->verticalLayout_3;}*/
}

void MainWindow::on_stat_3_clicked()
{
    // QString num2st = QString::number(num2);
    QLayoutItem* item;
       while ((item =ui->verticalLayout ->takeAt(0)) != nullptr) {
           delete item->widget();
           delete item;
       }
QVBoxLayout *verticalLayout = new QVBoxLayout();


   /*  while ((ui->verticalLayout_5->takeAt(0)) != nullptr) {
         delete ui->verticalLayout_5->widget();  // Delete the widget
         delete ui->verticalLayout_5;}
     while ((ui->verticalLayout_3->takeAt(0)) != nullptr) {
         delete ui->verticalLayout_3->widget();  // Delete the widget
         delete ui->verticalLayout_3;}*/
}

void MainWindow::on_location_clicked()
{
    ui->quickWidget_MapView->setSource(QUrl(QString("qrc:/QmlMap.qml")));
    ui->quickWidget_MapView->show();

    auto Obje = ui->quickWidget_MapView->rootObject();
    //start position bta3 il map
    connect(this ,SIGNAL(setCenterPosition(QVariant,QVariant)), Obje ,SLOT(setCenterPosition(QVariant,QVariant)));
    //position bta3 il marking
     connect(this ,SIGNAL(setLocationMarking(QVariant,QVariant)), Obje ,SLOT(setLocationMarking(QVariant,QVariant)));

    int userId;
    userId=ui->location_2->text().toInt();
    //ui->MAPA->setText((QString::number(userId)));

   float longi;
         float  lati;
//query.prepare("SELECT * FROM COLIS WHERE poids LIKE :test");

          QSqlQuery   query("SELECT * FROM LOCATION WHERE IDL LIKE :userId");
        query.bindValue(":userId", userId);
              // int did=query.value("idl").toInt();
               longi=  query.value("longitude").toFloat();
                lati=  query.value("latitude").toFloat();
           //    ui->MAPA->setText(QString::number(lati));
               if(userId==1)
               {
                longi=36.8065;
                        lati=10.1815;
               }
              else if(userId==2)
               {
                longi=36.8588;
                        lati=10.3231;
               }
               else if(userId==3)
                {
                 longi=36.8000;
                         lati=10.1808;
                }
               else if(userId==4)
               {
                   longi=36.3969;
                           lati=10.6128;
               }
               else if(userId==5)
               {
                   longi=33.5331;
                           lati=9.9457;
               }
               else if(userId==32)
               {
                   longi=35.6784;
                           lati=10.0965;
               }

    emit setCenterPosition(longi, lati);
     emit setLocationMarking( longi,lati);

}

void MainWindow::on_add_clicked()
{


        QString userText = ui->doadd->text();
        QString button1_style=
                "QPushButton {"
                   "    background-color: #3498db;"  // Background color
                   "    color: #ffffff;"              // Text color
                   "    padding: 5px 10px;"           // Padding around text
                   "    font-size: 20px;"             // Font size
                   "    border: 1px solid #2980b9;"   // Border color
                   "    border-radius: 5px;"          // Border radius for rounded corners
                   "}"
                   ""
                   "QPushButton:hover {"
                   "    background-color: #2980b9;"  // Background color on hover
                   "    border: 1px solid #3498db;"   // Border color on hover
                   "}"
                   ""
                   "QPushButton:pressed {"
                   "    background-color: #1f618d;"  // Background color when pressed
                   "    border: 1px solid #2980b9;"   // Border color when pressed
                   "}";
           QPushButton *displayLabel = new QPushButton(userText);
       ui->v1->addWidget(displayLabel);
displayLabel->setStyleSheet(button1_style);
           displayLabel->show();

           QObject::connect(displayLabel, &QPushButton::clicked, this, [this, displayLabel]() {
               if (ui->v1->indexOf(displayLabel) != -1) {
                   QString button2_style =
                       "QPushButton {"
                       "    background-color: #00B49D;"       // New background color
                       "    color: #ffffff;"                  // Text color
                       "    padding: 5px 10px;"
                       "    font-size: 20px;"
                       "    border: 1px solid #00B49D;"       // New border color
                       "    border-radius: 5px;"
                       "}"
                       ""
                       "QPushButton:hover {"
                       "    background-color: #007E76;"       // New background color on hover
                       "    border: 1px solid #007E76;"       // New border color on hover
                       "}"
                       ""
                       "QPushButton:pressed {"
                       "    background-color: #00584F;"       // New background color when pressed
                       "    border: 1px solid #00584F;"       // New border color when pressed
                       "}";
                   ui->v1->removeWidget(displayLabel);  // Remove the button from the current layout
                   ui->v2->addWidget(displayLabel);
                   displayLabel->setStyleSheet(button2_style);// Add the button to the second layout (v2)
               } else if (ui->v2->indexOf(displayLabel) != -1) {QString button3_style="QPushButton {"
                                                                                      "    background-color: #7D0000;"       // New background color
                                                                                      "    color: #ffffff;"                  // Text color
                                                                                      "    padding: 5px 10px;"
                                                                                      "    font-size: 20px;"
                                                                                      "    border: 1px solid #7D0000;"       // New border color
                                                                                      "    border-radius: 5px;"
                                                                                      "}"
                                                                                      ""
                                                                                      "QPushButton:hover {"
                                                                                      "    background-color: #590000;"       // New background color on hover
                                                                                      "    border: 1px solid #590000;"       // New border color on hover
                                                                                      "}"
                                                                                      ""
                                                                                      "QPushButton:pressed {"
                                                                                      "    background-color: #400000;"       // New background color when pressed
                                                                                      "    border: 1px solid #400000;"       // New border color when pressed
                                                                                      "}";
                   ui->v2->removeWidget(displayLabel);  // Remove the button from the current layout (v2)
                   ui->v3->addWidget(displayLabel);
                   displayLabel->setStyleSheet(button3_style);// Add the button to the third layout (v3)
               }



           });


}
void MainWindow::afficherPosition(QString latitude, QString longitude)
{
    qDebug() << Q_FUNC_INFO << latitude << longitude;
    //ui->positionLatitude->setText(QString::fromUtf8("%1").arg(latitude.toDouble(), 0, 'f', 5));
   // ui->positionLongitude->setText(QString::fromUtf8("%1").arg(longitude.toDouble(), 0, 'f', 5));
    ui->editLatitude->setText(QString::fromUtf8("%1").arg(latitude.toDouble(), 0, 'f', 5));
    ui->editLongitude->setText(QString::fromUtf8("%1").arg(longitude.toDouble(), 0, 'f', 5));
}

void MainWindow::afficherInformations(QString adresse, QString coordonnee)
{
    qDebug() << Q_FUNC_INFO << adresse << coordonnee;
    ui->labelInformations->setText("Informations : " + adresse);
}
void MainWindow::on_location_3_clicked()
{
    QQuickItem *item7 = ui->quickWidget_MapView->rootObject();
        QObject *object = item7->findChild<QObject *>("indicateurPosition");
        QString latitude = ui->editLatitude->text();
        QString longitude = ui->editLongitude->text();

        afficherPosition(latitude,longitude);
        if(object != nullptr)
        {
            qDebug() << Q_FUNC_INFO << latitude << longitude;
            QMetaObject::invokeMethod(object, "aller", Q_ARG(QVariant, latitude), Q_ARG(QVariant, longitude));
        }
}
//**********************************

/*void MainWindow::on_pushButton_6_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_pushButton_4_clicked()
{
      A.write_to_arduino("0");  //envoyer 0 à arduino
}

void MainWindow::on_pushButton_clicked()
{
     A.write_to_arduino("2");   //envoyer 2 à arduino
}

void MainWindow::on_pushButton_3_clicked()
{
     A.write_to_arduino("3");  //envoyer 3 à arduino
}*/


void MainWindow::on_pushButton_clicked()
{

//createPieChart_TMP()
Colis c;
    QChartView *chartView1 = c.createPieChart_TMP();

    // Set up your UI to include the chart view
    ui->verticalLayout_2->addWidget(chartView1);
     //envoyer 2 à arduino
}


void MainWindow::on_pushButton_2_clicked()
{
      A.write_to_arduino("3");  //envoyer 3 à arduino
}

void MainWindow::on_pushButton_3_clicked()
{
          A.write_to_arduino("0");
}

void MainWindow::on_pushButton_4_clicked()
{
A.write_to_arduino("2");
}


void MainWindow::on_tmp_clicked()
{
    Colis c;
    bool test;
 A.write_to_arduino("4");
    // Create an instance of the Arduino class

QByteArray byteArray= A.read_from_arduino() ;

       // Process the response
       qDebug() <<  A.read_from_arduino();
     bool conversionOk;
//QLocale::setDefault(QLocale(QLocale::English));
     byteArray = byteArray.trimmed();
       double myDouble = byteArray.toDouble(&conversionOk);

       if (conversionOk) {
           qDebug() << "Converted value: " << myDouble;
       } else {
           qDebug() << "Conversion to double failed";
       }

         test=c.ajouter_tmp(myDouble);
       if(myDouble>=25)
       {
           A.write_to_arduino("1");
       }
       else
       {
           A.write_to_arduino("2");
       }

        qDebug() <<myDouble;
       // Display the received data directly on tmp_aff
        QString volume_string=QString::number((myDouble));
       ui->tmp_aff->setText(volume_string);

}

void MainWindow::update_label()
{
   // data=A.read_from_arduino();

    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void MainWindow::on_aff_tmp_clicked()
{
    Colis C;
       ui->tab_c_2->setModel(C.afficher_tmp());
}


//************************************** clients code ******************************************
//**************************** skander ****************************************************



void MainWindow::feedback_statt()
{
     qDebug() << "Updating Clients Statistics Chart feedback_stat";
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

             categories << " RATING " ; //Selon etat mteek kifeh

             QBarCategoryAxis *axis = new QBarCategoryAxis();

             axis->append(categories);

             chart->createDefaultAxes();

             chart->setAxisX(axis,series);



             QChartView *chartView = new QChartView(chart);

             chartView->setParent(ui->feedback_stat);
             chartView->setGeometry(430, 255, 450, 250);
             chartView->show();

}


void MainWindow::stat()
{
    qDebug() << "Updating Clients Statistics Chart label 26";

     QBarSet *set0 = new QBarSet("Client satisfait");

             QBarSet *set1 = new QBarSet("Client non satisfait ");
           //  float calculmoy=F.compteretatiiii();

             int countEtat0 = C.compteretat0();
                 int countEtat1 = C.compteretat1();
                 * set0 <<countEtat1<<5 ; //hedheya el bar loula tnajem tabdel el valeur 40
                 * set1 << countEtat0<<5;
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




void MainWindow::on_ajout_clients_clicked()
{
    int IDC=ui->le_IDC->text().toInt();
    QString nomc=ui->le_nomc->text();
    QString prenomc=ui->le_prenomc->text();
    QString adressec=ui->le_adressec->text();
    QString emailc=ui->le_emailc->text();
    int numc=ui->le_numeroc->text().toInt();
    int nb_commande=ui->le_nb_commande->text().toInt();
    Clients C(IDC,nomc,prenomc,  adressec,  emailc, numc, nb_commande);

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

void MainWindow::on_pb_Update_clicked()
{
    int IDC=ui->le_IDC->text().toInt();
    QString nomc=ui->le_nomc->text();
    QString prenomc=ui->le_prenomc->text();
    QString adressec=ui->le_adressec->text();
    QString emailc=ui->le_emailc->text();
    int numc=ui->le_numeroc->text().toInt();
    int nb_commande=ui->le_nb_commande->text().toInt();


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

void MainWindow::on_x_chercher_textChanged(const QString &arg1)
{
    Clients C;
    if (arg1!="")
        ui->tab_Clients->setModel(C.rechercher(arg1));
    else {
        ui->tab_Clients->setModel(C.rechercher(arg1));

    }

//     ui->tab_Clients->clearSelection();
}

void MainWindow::on_comboBox_tri_zii_activated(const QString &arg1)
{
    Clients C;
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

void MainWindow::on_pb_supprimer_clicked()
{
    Clients C;
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
void MainWindow::on_client_tab_tabBarClicked(int index)
{

    int statisticsTabIndex = ui->client_tab->indexOf(ui->stat_2);
    int stattabindex = ui->client_tab->indexOf(ui->statFB);
    int stattab_feedback_index = ui->client_tab->indexOf(ui->feedback_stat);
ui->tab_Clients->setModel(C.afficher());

ui->tab_Clients_2->setModel(C.afficher());

    if (index == stattabindex) {
        stat();
    }

    if (index == stattab_feedback_index) {
        feedback_statt();
        ui->tab_FeedBack->setModel(F.afficher());
    }
    if (index == statisticsTabIndex) {
        update_Clients_StatisticsChart();
    } else {
        clearClients_StatisticsChart();
        qDebug() << "vghxbqjknsx";
    }

}
void MainWindow::update_Clients_StatisticsChart()
{
    Clients C;
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

    //clearClients_StatisticsChart();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition par nombre de commande ");
    chart->setBackgroundBrush(QBrush(QColor("#F5F5DC")));
    chart->setAnimationOptions(QChart:: SeriesAnimations);


    ClientsStatisticsChartView = new QChartView(chart);
    ClientsStatisticsChartView->setRenderHint(QPainter::Antialiasing);
    ClientsStatisticsChartView->setParent(ui->stat_2);
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



void MainWindow::on_pb_fidelite_clicked()
{
    // Appel de la fonction appliquerPromotion avec la valeur seuil de votre choix

       C.Fidelite(ui->id_fidele->text().toInt(),200);
       QMessageBox::information(nullptr,QObject::tr("Reduction Client"),
       QObject::tr("Reduction faite avec success.\n"
                   ""),QMessageBox::Ok);

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

// **************************  balkiss  code  *****************************

void MainWindow::on_ajouter_vehicule_clicked()
{
    int immatricule=ui->l_immatricule->text().toInt();
    QString marque=ui->l_marque->text();
    QString modele=ui->l_modele->text();
    int kilometrage=ui->l_kilo->text().toInt();
    int maintenance=ui->l_maintenance->text().toInt();
    int capabilite=ui->l_capa->text().toInt();
    vehicule S(immatricule,marque,modele,kilometrage,maintenance,capabilite);
    ui->tab_vehicule->setModel(S.afficher());
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

void MainWindow::on_modifier_vehicule_clicked()
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

              }
              else
                  QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                           QObject::tr("Update non effectué\n"
                                                       "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_supp_veh_clicked()
{
    QModelIndexList selectedIndexes = ui->tab_vehicule->selectionModel()->selectedIndexes();




        if (!selectedIndexes.isEmpty()) {
               // Assuming the ID is in the first column (column 0) of the selected row
               int selectedRow = selectedIndexes.at(0).row();
               int id = ui->tab_vehicule->model()->data(ui->tab_vehicule->model()->index(selectedRow, 0)).toInt();

               // Call the supprimer function with the selected ID
               bool test = S.supprimer(id);

               if (test) {
                  ui->tab_vehicule->setModel(S.afficher());
                   QMessageBox::information(nullptr, QObject::tr("OK"), QObject::tr("Suppression effectuee\n""Click Cancel to exit."), QMessageBox::Cancel);
               } else {
                   QMessageBox::critical(nullptr, QObject::tr("OK"), QObject::tr("Suppression non effectuee\n""Click Cancel to exit."), QMessageBox::Cancel);
               }
           } else {
               // Inform the user that no row is selected
               QMessageBox::warning(nullptr, QObject::tr("Warning"), QObject::tr("Veuillez sélectionner une ligne à supprimer."), QMessageBox::Ok);
           }
}

void MainWindow::on_cher_veh_textChanged(const QString &arg1)
{

        if (arg1!="")
            ui->tab_vehicule->setModel(S.rechercher(arg1));
        else {
            ui->tab_vehicule->setModel(S.rechercher(arg1));

        }


}

void MainWindow::on_stat_veh_clicked()
{
    QChartView *chartView2 = S.kilo();

    // Set up your UI to include the chart view
    ui->verticalLayout_veh->addWidget(chartView2);
}

void MainWindow::on_menu_clicked()
{


       // Hide the QListWidget
    //   ui->listWidget->hide();
       ui->clients->hide();
       ui->vehicule->hide();
       ui->livreurs->hide();
       ui->commandes->hide();
       ui->B_ajouter_2->hide();
        ui->menu->hide();
         ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_go_back_clicked()
{

    // Load the image from file


     ui->stackedWidget->setCurrentIndex(5);
        ui->go_back->hide();



}
void MainWindow::on_B_ajouter_2_clicked()
{
    int newIndex = 0;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
      QString image="C:/Users/zied/Desktop/ProjetCpp/rendez_vous.gif";
       QGifLabel *gifLabel1 = new QGifLabel(this);
       gifLabel1->setGif(image);
       gifLabel1->setGifSize(600, 600);
       gifLabel1->setGifAlignment(Qt::AlignCenter);

       ui->image->setMovie(gifLabel1->movie());

       gifLabel1->movie()->start();

         QString gifFilePath = "C:/Users/zied/Desktop/ProjetCpp/giphy.gif";

            // Create an instance of QGifLabel and set the GIF
            QGifLabel *gifLabel = new QGifLabel(this);
             gifLabel->setGif(gifFilePath);
           gifLabel->setGifSize(300, 250);
           gifLabel->setGifAlignment(Qt::AlignCenter);



            // Replace ui->yourGifLabel with the actual name of your QLabel
          ui->image_2->setMovie(gifLabel->movie());

          gifLabel->movie()->start();

}

void MainWindow::on_clients_clicked()
{
    int newIndex = 1;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
}

void MainWindow::on_vehicule_clicked()
{
    int newIndex = 2;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
}

void MainWindow::on_menu1_clicked()
{
    int newIndex = 0;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
      QString image="C:/Users/zied/Desktop/ProjetCpp/rendez_vous.gif";
       QGifLabel *gifLabel1 = new QGifLabel(this);
       gifLabel1->setGif(image);
       gifLabel1->setGifSize(600, 600);
       gifLabel1->setGifAlignment(Qt::AlignCenter);

       ui->image->setMovie(gifLabel1->movie());

       gifLabel1->movie()->start();

         QString gifFilePath = "C:/Users/zied/Desktop/ProjetCpp/giphy.gif";

            // Create an instance of QGifLabel and set the GIF
            QGifLabel *gifLabel = new QGifLabel(this);
             gifLabel->setGif(gifFilePath);
           gifLabel->setGifSize(300, 250);
           gifLabel->setGifAlignment(Qt::AlignCenter);


           // Set the index of the widget you want to switch to

            // Replace ui->yourGifLabel with the actual name of your QLabel
          ui->image_2->setMovie(gifLabel->movie());

          gifLabel->movie()->start();
             ui->go_back->show();
}

void MainWindow::on_menu2_clicked()
{
    int newIndex = 1;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
         ui->go_back->show();
}

void MainWindow::on_menu4_clicked()
{
    int newIndex = 2;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
         ui->go_back->show();
}

void MainWindow::on_menu5_clicked()
{
  //  ui->page_6->hide();
   // ui->page_5->show();
    int newIndex = 4;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
      ui->go_back->show();
}

void MainWindow::on_menu3_clicked()
{
    int newIndex = 3;  // Set the index of the widget you want to switch to
      ui->stackedWidget->setCurrentIndex(newIndex);
       ui->B_ajouter_2->hide();
       ui->go_back->show();

}

void MainWindow::on_pb_commander_3_clicked()
{

    // Récupérer les valeurs des champs du formulaire
     int id = ui->lineEdit_id_3->text().toInt();
      QDate date = ui->dateEdit_7->date();
        QString produit = ui->lineEdit_produit_3->text();
         QString etat = ui->lineEdit_etat_3->text();
    int prix = ui->lineEdit_17->text().toInt();






    // Créer un objet de type commande avec les valeurs récupérées
    commande cmd(id, prix, date, produit, etat);

    // Ajouter la nouvelle commande dans la base de données
    bool ajout = cmd.ajouter();

    if (ajout) {
        QMessageBox::information(this, "Succès", "Commande ajoutée avec succès!");
        // Actualiser l'affichage de la liste des commandes
        ui->tableView_5->setModel(c.afficher());
        ui->tableView_5->setModel(c.getSortedModel());
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de la commande!");
    }
}

void MainWindow::on_pb_modifier_3_clicked()
{
    // Récupérer les valeurs des champs du formulaire
    int prix = ui->lineEdit_17->text().toInt();
    int id = ui->lineEdit_18->text().toInt();
    QString produit = ui->lineEdit_19->text();
    QString etat = ui->lineEdit_20->text();
    QDate date = ui->dateEdit_8->date();

    // Créer un objet de type commande avec les valeurs récupérées
    commande cmd(id, prix, date, produit, etat);

    // Modifier la commande dans la base de données
    bool modif = cmd.modifier();

    if (modif) {
        QMessageBox::information(this, "Succès", "Commande modifiée avec succès!");
        // Actualiser l'affichage de la liste des commandes
        ui->tableView_5->setModel(c.afficher());
        ui->tableView_5->setModel(c.getSortedModel());
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification de la commande!");
    }
}

void MainWindow::on_pb_rechercher_3_clicked()
{
    // Récupérer l'ID de la commande à rechercher depuis le champ d'ID
    int id = ui->lineEdit_idrecherche_3->text().toInt();

    // Chercher la commande dans la base de données
    commande* cmd = c.chercherParId(id);

    if (cmd) {
        // Afficher les détails de la commande trouvée dans les champs correspondants
        ui->lineEdit_22->setText(QString::number(cmd->getPrix()));
        ui->lineEdit_23->setText(QString::number(cmd->getIdColis()));
        ui->lineEdit_24->setText(cmd->getProduit());
        ui->lineEdit_idrecherche_8->setText(cmd->getEtat());
        ui->dateEdit_9->setDate(cmd->getDatee());

        // Vous pouvez ajouter d'autres champs si nécessaire (idclient, etc.)

        delete cmd; // N'oubliez pas de libérer la mémoire allouée
    } else {
        QMessageBox::information(this, "Information", "Commande non trouvée!");
    }
}
void MainWindow::afficherStatistiques()
{
    // Récupérer les pourcentages par tranche de prix
    QMap<QString, double> pourcentages = c.pourcentagesParTrancheDePrix();

    // Créer un modèle de tableau
    QStandardItemModel *model = new QStandardItemModel();

    // Ajouter des en-têtes au modèle
    model->setHorizontalHeaderItem(0, new QStandardItem("Tranche de Prix"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Pourcentage"));

    // Ajouter les données au modèle
    int row = 0;
    for (auto it = pourcentages.begin(); it != pourcentages.end(); ++it) {
        model->setItem(row, 0, new QStandardItem(it.key()));
        model->setItem(row, 1, new QStandardItem(QString::number(it.value())));
        row++;
    }

    // Afficher le modèle dans le QTableView
    ui->tableView_6->setModel(model);
}


void MainWindow::on_pb_afficherStatistiques_3_clicked()
{
    afficherStatistiques();
}
void MainWindow::genererPDF()
{
    // Récupérer l'ID de la commande à rechercher depuis le champ d'ID
    int id_commande = ui->lineEdit_22->text().toInt();

    // Chercher la commande dans la base de données
    commande* cmd = commande::chercherParId(id_commande);

    if (cmd) {
        QString nomFichier = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "Fichiers PDF (*.pdf)");

        if (!nomFichier.isEmpty()) {
            QPrinter printer(QPrinter::HighResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName(nomFichier);

            QPainter painter(&printer);
            // Utiliser la fonction creerContenuFacture pour obtenir le contenu spécifique de la commande
            painter.drawText(1000, 1000, cmd->creerContenuFacture());
        }

        // Libérer la mémoire allouée pour la commande
        delete cmd;
    } else {
        QMessageBox::information(this, "Information", "Commande non trouvée!");
    }
}



//livreur

void MainWindow::on_pdf_livreur_clicked()
{
    QPdfWriter pdf("mypdf_livreur.pdf");
    QPainter painter(&pdf);  // dessiner du texte et des rectangles sur le PDF.
    int i = 4000;
    painter.setPen(Qt::darkBlue);
    painter.setFont(QFont("Arial", 25, QFont::Bold));
    int pageWidth = pdf.width();

    int textWidth = painter.fontMetrics().width("Liste Des Livreurs");
    int xPosition = (pageWidth - textWidth) / 2;

    painter.drawText(xPosition, 1400, "Liste Des Livreurs");  // permet de dessiner du texte à la position spécifiée (x, y).
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 15));
    painter.drawRect(100, 100, 9400, 2500);  // avec la largeur et la hauteur données.
    painter.drawRect(100, 3000, 9400, 500);

    painter.setFont(QFont("Arial", 9, QFont::Bold));
    painter.drawText(400, 3300, "IDLIV");
    painter.drawText(1000, 3300, "NOMLIV");
    painter.drawText(2200, 3300, "PRENOMLIV");
    painter.drawText(3900, 3300, "NUMEROLIV");

    painter.drawRect(100, 3000, 9400, 9000);

    QSqlQuery query;
    query.prepare("SELECT * FROM LIVREURS");
    query.exec();

    while (query.next())  // parcourt les résultats de la requête.
    {
                  painter.setPen(Qt::black);
                  painter.setFont(QFont("Arial", 9));
                  painter.drawText(400, i, query.value("IDLIV").toString());
                  painter.drawText(1000, i, query.value("NOMLIV").toString());
                  painter.drawText(2200, i, query.value("PRENOMLIV").toString());
                  painter.drawText(3900, i, query.value("NUMEROLIV").toString());

                  i = i + 350; //  créer un espace suffisant entre les lignes du tableau pour un meilleur aperçu.
    }

    QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                             QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}
void MainWindow::makePlot() {
    // Retrieve data from the database
    QSqlQuery query("SELECT IDLIV, SCORE FROM LIVREURS ORDER BY SCORE DESC"); //on prend le score d'un livreur selon son id , puis on fait la comparaison entre les livreurs selon le score en ordre descendant
//custom plot : bibliotheque externe de statistiques
//on declare deux attributs pour stocker les données a partir de la base de donnees
    QVector<double> livreursIds;
    QVector<double> scores;

    while (query.next()) {
                  //on stocke les valeurs a partir de la base de données dans ces deux variables

                  int livreurId = query.value(0).toInt();
                  double score = query.value(1).toDouble();
                  livreursIds.push_back(static_cast<double>(livreurId));
                  scores.push_back(score);
    }

    if (livreursIds.isEmpty() || scores.isEmpty()) {
                  //controle saisie , si il n y a pas de id's ou des score dans la bd on n'affiche rien
                  qDebug() << "No data retrieved from the database.";
                  return;
    }

    // Create the plot using retrieved data:
    QCPBars *bars = new QCPBars(ui->customPlot_livreur->xAxis, ui->customPlot_livreur->yAxis);
    bars->setData(livreursIds, scores); // on ecrit id sur l'axe des x et score sur l'axe des y

    // Customize plot appearance:
    ui->customPlot_livreur->xAxis->setLabel("Livreur ID");
    ui->customPlot_livreur->yAxis->setLabel("Score");
    ui->customPlot_livreur->xAxis->setRange(0.5, livreursIds.size() + 0.5);
    ui->customPlot_livreur->yAxis->setRange(0, *std::max_element(scores.constBegin(), scores.constEnd()) + 1);
    ui->customPlot_livreur->replot();
}



void MainWindow :: update_label_livreur()
{
    bool test;
    data=A.read_from_arduino(); //lit les données depuis l'Arduino
    QString m="";
   m=m+data;
   // QChar=data.right(1).at(0);
qDebug()<<data;
    if(m.endsWith("D"))
       {
        qDebug()<<"m="<<m<<endl;
           qDebug() << "ref=" << ref;
           QMessageBox::information(nullptr, QObject::tr("la carte a été detecté"),
                       QObject::tr("bienvenue "), QMessageBox::Ok);
           QSqlQuery query;


           query.prepare("SELECT * FROM LIVREURS WHERE REFERENCE = :ref");//sql
           query.bindValue(":ref", ref);  //comparaison bch ya9ef fel ligne li ya9a fiha reference=:ref

           if (query.exec() && query.next())
           {
               int IDLIV= query.value(0).toInt();//id men base de donne w9tly refernece = ref(code el carta)
               test=true;

//mise a jour du du presence iwaly present w9t IDLIV=:IDLIVE
               query.prepare("UPDATE LIVREURS SET PRESENCE=:PRESENCE WHERE IDLIV=:IDLIV");
               query.bindValue(":IDLIV",IDLIV);
               query.bindValue(":PRESENCE","PRESENT");
qDebug()<<IDLIV<<endl;

ui->tableView_livreur->setModel(L.afficher());

               QMessageBox::information(nullptr, QObject::tr(""),
                           QObject::tr("bienvenue "), QMessageBox::Cancel);
           }
           else
           {
               test=false;
           }

           ref.clear();
       }
       else if(!(data[0]=='\r' || data[0]=='\n'))
       {

           ref=ref+data[0];
       }
}

void MainWindow::on_pb_ajouter_livreur_clicked()
{

        // Réinitialisez les messages d'erreur
        ui->lblErreurId_livreur->setText("");
        ui->lblErreurNom_livreur->setText("");
        ui->lblErreurPrenom_livreur->setText("");
        ui->lblErreurNumTel_livreur->setText("");

        // Récupérez les valeurs des champs
        QString NOMLIV = ui->le_nom_livreur->text();
        QString PRENOMLIV = ui->le_prenom_livreur->text();
        QString strIdLivreur = ui->le_id_livreur->text();
        int IDLIV = strIdLivreur.toInt();
        QString strNumeroLivreur = ui->le_num_livreur->text();
        int NUMEROLIV = strNumeroLivreur.toInt();
        double SCORE;

        // Validez les champs d'entrée
        bool isValid = true;

        if (strIdLivreur.isEmpty()) {
            ui->lblErreurId_livreur->setText("<font color='red'>ID Livreur ne peut pas être vide!!!!</font>");
            isValid = false;
        }

        if (NOMLIV.isEmpty()) {
            ui->lblErreurNom_livreur->setText("<font color='red'>Nom livreur ne peut pas être vide!!!</font>");
            isValid = false;
        }

        if (PRENOMLIV.isEmpty()) {
            ui->lblErreurPrenom_livreur->setText("<font color='red'>Prenom livreur ne peut pas être vide!!!</font>");
            isValid = false;
        }

        if (strNumeroLivreur.isEmpty()) {
            ui->lblErreurNumTel_livreur->setText("<font color='red'>Numero de telephone ne peut pas être vide!!!</font>");
            isValid = false;
        }
        // Vérifiez l'existence de l'ID Livreur dans la base de données
        QSqlQuery checkQuery;
        checkQuery.prepare("SELECT IDLIV FROM Livreurs WHERE IDLIV = :IDLIV");
        checkQuery.bindValue(":IDLIV", IDLIV);

        if (checkQuery.exec() && checkQuery.next()) {
            ui->lblErreurId_livreur->setText("<font color='red'>ID Livreur existe déjà!!!!</font>");
            isValid = false;
        }



             if (isValid) {
                 // Si l'entrée est valide et que l'ID n'existe pas, procédez à l'ajout de l'activité
                 Livreur L(IDLIV,NOMLIV,PRENOMLIV,NUMEROLIV,SCORE);

                 QSqlQuery query;
                 bool test = L.ajouter();
                 if (test) {
                     ui->tableView_livreur->setModel(L.afficher()); // Rafraîchir la vue
                     ui->comboBox_supp_livreur->setModel(L.afficher());
                     ui->comboBox_modi_livreur->setModel(L.afficher());

                     QMessageBox::information(nullptr, QObject::tr("Ajout Livreur"),
                         QObject::tr("Livreur ajoutée avec succès.\n"
                                     "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);



                 } else {
                     QMessageBox::critical(nullptr, QObject::tr("Ajout Livreur"),
                         QObject::tr("Erreur lors de l'ajout de Livreur.\n"
                                     "Cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
                 }
             } else {
                 // Gérez l'erreur d'entrée invalide ou d'ID existant
             }


}

void MainWindow::on_pb_supp_livreur_clicked()
{

        // Récupérer l'ID de la commande à supprimer depuis le champ d'ID
        int id = ui->comboBox_supp_livreur->currentText().toInt();

        // Supprimer la commande de la base de données
        bool supprime = L.supprimer(id);

        if (supprime) {
            QMessageBox::information(this, "Succès", "Commande supprimée avec succès!");
            // Actualiser l'affichage de la liste des commandes
            ui->tableView_livreur->setModel(L.afficher());
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression de la commande!");
        }


}

void MainWindow::on_pb_modifier_livreur_clicked()
{

        // Récupérez les valeurs des champs
        QString NOMLIV = ui->le_nom2_livreur->text();
        QString PRENOMLIV = ui->le_prenom2_livreur->text();
        QString strIdLivreur = ui->comboBox_modi_livreur->currentText();
        int IDLIV = strIdLivreur.toInt();
        QString strNumeroLivreur = ui->le_num2_livreur->text();
        int NUMEROLIV = strNumeroLivreur.toInt();
        double SCORE;

        Livreur L(IDLIV,NOMLIV,PRENOMLIV,NUMEROLIV,SCORE);

        QSqlQuery query;

        bool test = L.modifier(); // Modifiez le livreur existant

        if (test) {
            ui->tableView_livreur->setModel(L.afficher()); // Rafraîchir la vue
            ui->comboBox_supp_livreur->setModel(L.afficher());
            ui->comboBox_modi_livreur->setModel(L.afficher());

            QMessageBox::information(nullptr, QObject::tr("Modifier Livreur"),
                QObject::tr("Livreur modifié.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Modifier Livreur"),
                QObject::tr("Erreur lors de la modification du livreur.\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        }



}

void MainWindow::on_valider_livreur_clicked()
{
   {
            QString IDLIV=ui->comboBox_modi_livreur->currentText();
                      QSqlQuery query;
                      query.prepare("select * from Livreurs where IDLIV='"+IDLIV+"'");
                      if (query.exec())
                      {
                       while (query.next())
                       {


                           ui->le_nom2_livreur->setText(query.value(1).toString());
                           ui->le_num2_livreur->setText(query.value(3).toString());
                           ui->le_prenom2_livreur->setText(query.value(2).toString());
                       }
                      }

    }

}

void MainWindow::on_reset_livreur_clicked()
{

        ui->comboBox_modi_livreur->clear();
        ui->le_nom2_livreur->clear();
        ui->le_num2_livreur->clear();
        ui->le_prenom2_livreur->clear();


}

void MainWindow::on_btnTriAsc_livreur_clicked()
{

        Livreur l;
        ui->tableView_livreur->setModel(l.triAE());


}

void MainWindow::on_pushButton_4_livreur_clicked()
{

        Livreur l;
        ui->tableView_livreur->setModel(L.triDE());
    }

void MainWindow::on_btnRech_livreur_clicked()
{

        QString NOMLIV=ui->rechnom_livreur->text();
        int IDLIV=ui->rechid_livreur->text().toInt();
        QString PRENOMLIV=ui->rechnumero_livreur->text();

        ui->tableView_livreur->setModel(L.chercher_livreur(NOMLIV,PRENOMLIV,IDLIV));


}

void MainWindow::on_calculscore_livreur_clicked()
{
    int taux = ui->lineEditTaux_livreur->text().toInt();
    int nbrLivs = ui->lineEditNbrLivs_livreur->text().toInt();
    int id = ui->lineEditId_livreur->text().toInt();

    if (!L.checkIfIdExists(QString::number(id))) {
                  QMessageBox::warning(this, "Erreur", "L'ID n'existe pas dans la base de données.");
    } else {
                  double score = static_cast<double>(nbrLivs * taux / 100 );
                  QMessageBox::information(this, "Score", "Le score est : " + QString::number(score));

                  // Appeler la fonction pour mettre à jour le score dans la base de données
                  L.modifierScore(id, score);
                  makePlot();

    }
}

void MainWindow::on_ConfirmationButton_3_livreur_clicked()
{

    // Récupérez l'ID du livreur et l'état de la case à cocher
    int IDLIV = ui->lineEdit_15_livreur->text().toInt();
    QString ETATLIV = ui->lineEdit_16_livreur->text();


        // Vérifiez si l'ID existe dans la base de données
        if (!L.checkIfIdExists(QString::number(IDLIV))) {
                  QMessageBox::warning(this, "Erreur", "L'ID n'existe pas dans la base de données.");


    } else {
                      QMessageBox::information(this, "Confirmation", "Opération confirmée avec succès.");
                  L.setCheckBoxValue(IDLIV,ETATLIV);
                  ui->tableView_livreur->setModel(L.afficher());
    }
}


void MainWindow::on_retour_menu_livreur_clicked()
{


}

