#include "clients.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include<QSqlError>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Clients::Clients()
{
     IDC =0 ;
     nomc="" ;
     prenomc="";
     adressec="";
     emailc="";
     numc=0;
     nb_commande=0;
}

Clients::Clients(int IDC, QString nomc, QString prenomc, QString adressec, QString emailc,int numc, int nb_commande)
{
    this->IDC=IDC ;
    this->nomc=nomc ;
    this->prenomc=prenomc ;
    this->adressec=adressec ;
    this->emailc=emailc ;
    this->numc=numc ;
    this->nb_commande=nb_commande;

}

int Clients::getIDC(){return IDC ;}
QString Clients::getnomc(){return nomc;}
QString Clients::getprenomc(){return prenomc ;}
QString Clients::getadressec(){return adressec;}
QString Clients::getemailc(){return emailc;}
int Clients::getnumc(){return numc;}
int Clients::getnb_commande(){return nb_commande;}


void Clients::setIDC(int IDC){ this->IDC=IDC ;}
void Clients::setnomc(QString nomc){this->nomc=nomc;}
void Clients::setprenomc(QString prenomc){this->prenomc=prenomc;}
void Clients::setadressec(QString adressec){this->adressec=adressec;}
void Clients::setemailc(QString emailc){this->emailc=emailc;}
void Clients::setnumc(int numc){this->numc=numc;}
void Clients::setnb_commande(int nb_commande){this->nb_commande=nb_commande;}

bool Clients::ajouter()
{
  //  bool test= false ;
    QSqlQuery query;
    QString IDC_string= QString::number(IDC);
    QString numc_string= QString::number(numc);
    QString nb_commande_string= QString::number(nb_commande);

         query.prepare("INSERT INTO clients (IDC, NOMC, PRENOMC, ADRESSEC,EMAILC, NUMEROC, NB_COM ) "
                       "VALUES (:IDC, :NOMC, :PRENOMC, :ADRESSEC, :EMAILC, :NUMEROC, :NB_COM )");
         query.bindValue(":IDC",IDC_string);
         query.bindValue(":NOMC", nomc);
         query.bindValue(":PRENOMC", prenomc);
         query.bindValue(":ADRESSEC", adressec);
         query.bindValue(":EMAILC", emailc);
         query.bindValue(":NUMEROC", numc_string);
         query.bindValue(":NB_COM", nb_commande_string);

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
      model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nombre de commande"));

  return model;
}



bool Clients::modifier(){

      QSqlQuery query;
          QString IDC_string=QString::number(IDC);
          QString numc_string=QString::number(numc);
          QString nb_commande_string= QString::number(nb_commande);

            query.prepare ("UPDATE clients SET  NOMC=:nomc, PRENOMC=:prenomc, ADRESSEC=:adressec, EMAILC=:emailc ,NUMEROC=:numc, NB_COM=:NB_COM  where IDC=:IDC ");

            query.bindValue(":IDC",IDC_string);
            query.bindValue(":nomc", nomc);
            query.bindValue(":prenomc", prenomc);
            query.bindValue(":adressec", adressec);
            query.bindValue(":emailc", emailc);
            query.bindValue(":numc", numc_string);
            query.bindValue(":NB_COM", nb_commande_string);

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

QSqlQueryModel * Clients::triClients(QString tri)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    if(tri == "par defaut")
    {
        model->setQuery("SELECT * FROM clients ");
    }
    else if (tri == "ID")
    {
        model->setQuery("SELECT * FROM clients ORDER BY IDC");
    }
    else if (tri == "NOM")
    {
        model->setQuery("SELECT * FROM clients ORDER BY NOMC");
    }
    else if (tri == "PRENOM")
        {
            model->setQuery("SELECT * FROM clients ORDER BY PRENOMC");
        }
    else if (tri == "ADRESSE")
        {
            model->setQuery("SELECT * FROM clients ORDER BY ADRESSEC");
        }
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nombre de commande"));

    return model;

}




QSqlQueryModel* Clients::rechercher(QString test)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
model->setQuery("SELECT * from clients WHERE IDC LIKE ('%"+test+"%') OR UPPER(NOMC) LIKE UPPER('%"+test+"%') OR UPPER(PRENOMC) LIKE UPPER('%"+test+"%')");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Numéro"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nombre de commande"));

    return model;
}

double Clients::calculerSommePrix(int id_fid) {
    QSqlQuery query;
    query.prepare("SELECT SUM(prix) FROM COMMANDES WHERE ID_C = :id_fid");
    query.bindValue(":id_fid", id_fid);

    if (query.exec() && query.next()) {
        return query.value(0).toDouble();
    } else {
        qDebug() << "Erreur lors du calcul de la somme des prix pour le client" << id_fid;
        return -1.0;
    }
}


void Clients::Fidelite(int id_fid, double seuil)
{

    double sommePrix = calculerSommePrix(id_fid);

      if (sommePrix < 0) {
          qDebug() << "La promotion ne peut pas être appliquée en raison d'une erreur précédente.";
          return;
      }

      qDebug() << "Somme des prix pour le client" << id_fid << ":" << sommePrix;

      QSqlQuery commandesQuery;
      commandesQuery.prepare("SELECT ID, PRIX FROM COMMANDES WHERE ID_C = :client_id");
      commandesQuery.bindValue(":client_id", id_fid);

      if (!commandesQuery.exec()) {
          qDebug() << "Erreur lors de la récupération des commandes pour le client" << id_fid;
          return;
      }

      while (commandesQuery.next()) {
          int commandeId = commandesQuery.value("ID").toInt();
          double prixCommande = commandesQuery.value("PRIX").toDouble();

          double reduction = prixCommande * 0.1; // amlna 10% remise xd

          QSqlQuery updateQuery;
          updateQuery.prepare("UPDATE COMMANDES SET PRIX = :nouveau_prix WHERE ID = :commande_id");
          updateQuery.bindValue(":nouveau_prix", prixCommande - reduction);
          updateQuery.bindValue(":commande_id", commandeId);

          if (updateQuery.exec()) {
              qDebug() << "Reduction de" << reduction << "appliquee a la commande" << commandeId;
          } else {
              qDebug() << "Erreur lors de la mise à jour du prix dans la base de données pour la commande" << commandeId;
          }
      }

      qDebug() << "Réduction de prix appliquee avec succes a toutes les commandes!";
  }


QMap<QString, int> Clients::getClients_Statistics() {
        QMap<QString, int> statistics;

        QSqlQuery query1;
        query1.prepare("SELECT COUNT(*) AS count FROM clients WHERE NB_COM < 50");
        if (query1.exec()) {
            query1.next();
            statistics["Moins de 50"] = query1.value("count").toInt();
        }

        QSqlQuery query2;
        query2.prepare("SELECT COUNT(*) AS count FROM clients WHERE NB_COM >= 50 AND NB_COM <= 100");
        if (query2.exec()) {
            query2.next();
            statistics["50-100"] = query2.value("count").toInt();
        }

        QSqlQuery query3;
        query3.prepare("SELECT COUNT(*) AS count FROM clients WHERE NB_COM > 100");
        if (query3.exec()) {
            query3.next();
            statistics["Plus de 100"] = query3.value("count").toInt();
        }

        /*else {
            qDebug() << "Error in query (Plus de 100):" << query3.lastError().text();
        } */

        return statistics;
    }

int Clients::compteretat1()
{
    int etat1;
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM FEEDBACK WHERE RESOLUTION = 1");
       query.next();
      etat1 = query.value(0).toInt();
        return etat1;
}
int Clients::compteretat0()
{
    int etat0;
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM FEEDBACK WHERE RESOLUTION = 0");
     query.next();
     etat0 = query.value(0).toInt();
        return etat0;

}













