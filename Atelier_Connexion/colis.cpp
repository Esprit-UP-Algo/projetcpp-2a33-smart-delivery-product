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
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("POIDS"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("VOLUME"));
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ETAT"));
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
   /*if (query.exec()) {
       while (query.next()) {
           // Process each row of data here
           int id = query.value(0).toInt();
           // Retrieve other columns as needed
           int poids = query.value(1).toInt();
           int volume = query.value(2).toInt();
           QString etat = query.value(3).toString();

           // Perform actions with the retrieved data
           qDebug() << "ID: " << id;
           qDebug() << "POIDS: " << poids;
           qDebug() << "VOLUME: " << volume;
           qDebug() << "ETAT: " << etat;
       }
   } else {
       qWarning() << "Query failed: " << query.lastError().text();
   }*/
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
