#include "feedback.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QSqlError>
#include "mainwindow.h"
#include "ui_mainwindow.h"

FeedBack::FeedBack()
{
     IDF =0;
     rating=0 ;
     delivery="" ;
     communication="" ;
     etat="" ;
     res =0;

}

FeedBack::FeedBack(int IDF ,int rating ,QString delivery,QString communication,QString etat,int res)
{
    this->IDF=IDF ;
    this->rating=rating ;
    this->delivery=delivery;
    this->communication=communication ;
    this->etat=etat ;
    this->res=res ;
}


bool FeedBack::ajout_FeedBack()
{
    QSqlQuery query;
    QString IDF_string= QString::number(IDF);
    QString rating_string= QString::number(rating);
    QString res_string= QString::number(res);

         query.prepare("INSERT INTO FEEDBACK (IDF, RATING, DELIVERY, COMMUNICATION,PACKAGING, RESOLUTION ) "
                       "VALUES (:IDF, :rating, :delivery, :communication, :etat, :res )");
         query.bindValue(":IDF",IDF_string);
         query.bindValue(":rating", rating_string);
         query.bindValue(":delivery", delivery);
         query.bindValue(":communication", communication);
         query.bindValue(":etat", etat);
         query.bindValue(":res", res_string);

         return query.exec();
}


QSqlQueryModel* FeedBack::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

      model->setQuery("SELECT* FROM FEEDBACK");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numéro"));

  return model;
}


int FeedBack::compteretat1()
{
    int etat1;
    QSqlQuery query;
    query.exec("SELECT SUM(RATING) FROM FEEDBACK ");
       query.next();
      etat1 = query.value(0).toInt();
qDebug() <<"etattt"<<etat1;
        return etat1;
}

int FeedBack::compteretat2()
{
    int somme;
    QSqlQuery query;
    query.exec("SELECT count(*) FROM FEEDBACK ");
       query.next();
      somme = query.value(0).toInt();
   /*  int ratingsum= compteretat1();
     float moyenne = static_cast<float>(somme)/ratingsum *100 ;
*/
      qDebug() <<"som"<<somme;
        return somme;
}


float FeedBack::compteretatiiii()
{
    QSqlQuery query;
    int somme=compteretat2();

     int ratingsum= compteretat1();
     float moyenne = static_cast<float>(somme)/ratingsum *100 ;
qDebug() <<moyenne;
        return moyenne;
}
