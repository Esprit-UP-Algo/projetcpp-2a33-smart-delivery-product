#include "colis.h"
#include"QString"
#include"QSqlQuery"
#include"QtDebug"
#include <QSqlQueryModel>
#include <iostream>

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
