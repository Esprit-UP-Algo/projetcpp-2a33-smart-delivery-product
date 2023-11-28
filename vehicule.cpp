#include "vehicule.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QtGui>
#include <QtWidgets>

vehicule::vehicule()
{
  immatricule=0;marque="";modele="";kilometrage=0;maintenance=0;capabilite=0;
}
vehicule::vehicule(int immatricule,QString marque, QString modele, int kilometrage, int maintenance, int capabilite){
    this->immatricule=immatricule;
    this->marque=marque;
    this->modele=modele;
    this->kilometrage=kilometrage;
    this->maintenance=maintenance;
    this->capabilite=capabilite;
}
int vehicule::getImmatricule()
{
    return immatricule;
}
QString vehicule:: getMarque()
{
    return marque;
}
QString vehicule:: getModele()
{
    return modele;
}
int vehicule:: getKilometrage()
{
    return kilometrage;
}
int vehicule::getMaintenance()
{
    return maintenance;
}

int vehicule::getCapabilite()
{
    return capabilite;
}


void vehicule::setImmatricule(int immatricule)
{
    this->immatricule=immatricule;
}
void vehicule:: setMarque(QString marque)
{
    this->marque=marque;
}
void vehicule::  setModele(QString modele)
{
   this->modele=modele;
}
void vehicule::setKilometrage(int kilometrage)
{
    this->kilometrage=kilometrage;
}
void vehicule:: setMaintenance(int maintenance)
{
    this->maintenance=maintenance;
}

void vehicule:: setCapabilite(int capabilite)
{
    this->capabilite=capabilite;
}


bool vehicule:: ajouter ()
{
    QSqlQuery query;


    query.prepare("INSERT INTO GS_VEHICULE (IMMATRICULE,MARQUE, MODELE, KILOMETRAGE, MAINTENANCE,CAPABILITE) "
                          "VALUES ( :immatricule,:marque, :modele, :kilometrage, :maintenance, :capabilite)");
    query.bindValue(":immatricule", immatricule);
             query.bindValue(":marque", marque);
             query.bindValue(":modele", modele);
             query.bindValue(":kilometrage", kilometrage);
             query.bindValue(":maintenance", maintenance);
             query.bindValue(":capabilite", capabilite);
            // query.exec();
             return query.exec();

}
bool vehicule :: supprimer(int immatricule)
{
    QSqlQuery query;
    QString immatricule_string= QString::number(immatricule);
              query.prepare("Delete from GS_VEHICULE where IMMATRICULE=:immatricule");
              query.bindValue(":immatricule", immatricule);
              return query.exec();
}
QSqlQueryModel* vehicule::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM GS_VEHICULE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("immatricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("kilometrage"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("maintenance"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("capabilite"));

    return model;



}
bool vehicule::modifier()
{


    QSqlQuery query;
    QString immatricule_string= QString::number(immatricule);
     QString kilometrage_string= QString::number(kilometrage);
      QString maintenance_string= QString::number(maintenance);
       QString capabilite_string= QString::number(capabilite);
         query.prepare("UPDATE GS_VEHICULE SET   MARQUE = :marque , MODELE = :modele, KILOMETRAGE = :kilometrage ,MAINTENANCE = :maintenance ,CAPABILITE = :capabilite where IMMATRICULE = :immatricule");
         query.bindValue(":immatricule", immatricule);
         query.bindValue(":marque", marque);
         query.bindValue(":modele", modele);
         query.bindValue(":kilometrage", kilometrage);
         query.bindValue(":maintenance", maintenance);
         query.bindValue(":capabilite", capabilite);
          bool success = query.exec();
         return success;
}
QSqlQueryModel * vehicule::trivehicule(QString tri)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(tri == "par defaut")
    {
        model->setQuery("SELECT * FROM GS_vehicule ");
    }
    else if (tri == "immatricule")
    {
        model->setQuery("SELECT * FROM GS_vehicule ORDER BY IMMATRICULE");
    }
    else if (tri == "marque")
    {
        model->setQuery("SELECT * FROM GS_vehicule ORDER BY MARQUE");
    }
    else if (tri == "modele")
        {
            model->setQuery("SELECT * FROM GS_vehicule ORDER BY MODELE");
        }
    else if (tri == "kilometrage")
        {
            model->setQuery("SELECT * FROM GS_vehicule ORDER BY KILOMETRAGE");
        }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("immatricule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("modele"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("kilometrage"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("maintenance"));//tr() traduit la chaîne de caractères
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("capabilite")); //setHeaderData()définit l'en-tête de la première colonne du tableau

    return model;

}

QSqlQuery vehicule::rechercher_immatricule(int immatricule ){
    QSqlQuery query;
        query.prepare("SELECT * from GS_vehicule  where IMMATRICULE = :immatricule ");
        query.bindValue(":immatricule", immatricule);

        query.exec();
        return query;
}

bool vehicule::Maintenance()  {
     int limiteKilometrage = 2000; // Limite de kilométrage
     QSqlQuery query;
      query.prepare("SELECT KILOMETRAGE FROM GS_vehicules WHERE IMMATRICULE = ?");
      query.bindValue(0, immatricule);


      if (query.exec() && query.next()) {
          while(query.next()){
             int kilometrage = query.value(0).toInt();

             if (kilometrage <= limiteKilometrage) {
                        // Le véhicule peut être utilisé
                        return true;
                    } else {
                        // Le véhicule nécessite une maintenance
                        return false;
                    }}
                } else {
                    // Erreur lors de l'accès à la base de données ou immatriculation non trouvée
                    return false;}



}
