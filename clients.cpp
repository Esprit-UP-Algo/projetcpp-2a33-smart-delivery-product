#include "clients.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>

Clients::Clients()
{
     IDC =0 ;
     nomc="" ;
     prenomc="";
     adressec="";
     emailc="";
     numc=0;
}

Clients::Clients(int IDC, QString nomc, QString prenomc, QString adressec, QString emailc,int numc)
{
    this->IDC=IDC ;
    this->nomc=nomc ;
    this->prenomc=prenomc ;
    this->adressec=adressec ;
    this->emailc=emailc ;
    this->numc=numc ;

}

int Clients::getIDC(){return IDC ;}
QString Clients::getnomc(){return nomc;}
QString Clients::getprenomc(){return prenomc ;}
QString Clients::getadressec(){return adressec;}
QString Clients::getemailc(){return emailc;}
int Clients::getnumc(){return numc;}

void Clients::setIDC(int IDC){ this->IDC=IDC ;}
void Clients::setnomc(QString nomc){this->nomc=nomc;}
void Clients::setprenomc(QString prenomc){this->prenomc=prenomc;}
void Clients::setadressec(QString adressec){this->adressec=adressec;}
void Clients::setemailc(QString emailc){this->emailc=emailc;}
void Clients::setnumc(int numc){this->numc=numc;}


bool Clients::ajouter()
{
  //  bool test= false ;
    QSqlQuery query;
    QString IDC_string= QString::number(IDC);
    QString numc_string= QString::number(numc);
         query.prepare("INSERT INTO clients (IDC, NOMC, PRENOMC, ADRESSEC,EMAILC, NUMEROC ) "
                       "VALUES (:IDC, :NOMC, :PRENOMC, :ADRESSEC, :EMAILC, :NUMEROC )");
         query.bindValue(":IDC",IDC_string);
         query.bindValue(":NOMC", nomc);
         query.bindValue(":PRENOMC", prenomc);
         query.bindValue(":ADRESSEC", adressec);
         query.bindValue(":EMAILC", emailc);
         query.bindValue(":NUMEROC", numc_string);


         return query.exec();

}



bool Clients::supprimer(int ID)
{
    QSqlQuery query;
          query.prepare("Delete FROM clients where IDC=:ID");
          query.bindValue(0, ID);

         return query.exec();
}

QSqlQueryModel* Clients::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

      model->setQuery("SELECT* FROM clients");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
      model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
      model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numéro"));
  return model;
}



bool Clients::modifier(){

      QSqlQuery query;
          QString IDC_string=QString::number(IDC);
          QString numc_string=QString::number(numc);

            query.prepare ("UPDATE clients SET  NOMC=:nomc, PRENOMC=:prenomc, ADRESSEC=:adressec, EMAILC=:emailc ,NUMEROC=:numc  where IDC=:IDC ");

            query.bindValue(":IDC",IDC_string);
            query.bindValue(":nomc", nomc);
            query.bindValue(":prenomc", prenomc);
            query.bindValue(":adressec", adressec);
            query.bindValue(":emailc", emailc);
            query.bindValue(":numc", numc_string);



              return query.exec();

  }



/*******'existance de ID***********/

bool Clients::idExists(const int &IDC)
{
    QSqlQuery query;
    query.prepare("SELECT IDC FROM clients WHERE IDC=:IDC");
    query.bindValue(":IDC", IDC);

    if (query.exec() && query.next())
    {
        // If a row is fetched, the ID exists in the database.
        return true;
    }

    // If no rows were fetched, the ID does not exist.
    return false;
}










