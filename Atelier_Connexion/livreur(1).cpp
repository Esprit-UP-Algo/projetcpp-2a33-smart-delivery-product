#include "livreur.h"
#include "qsqlerror.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QDebug>
#include <QMessageBox>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QDataStream>
#include <QDialog>
#include <QFile>
#include <QFileDialog>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QDesktopServices>
#include "qpdfwriter.h"
#include <QTextTableFormat>
#include <QDesktopServices>
#include <QVector>
#include <QtSql>
#include <QDebug>
#include <QMap>

Livreur::Livreur()
{
      IDLIV=0;
      NOMLIV="";
      PRENOMLIV="";
      NUMEROLIV=0;
      SCORE=0;
}
Livreur::Livreur(int IDLIV,QString NOMLIV, QString PRENOMLIV, int NUMEROLIV, double SCORE)
{
    this ->IDLIV=IDLIV; this->NOMLIV=NOMLIV; this->PRENOMLIV=PRENOMLIV ; this ->NUMEROLIV=NUMEROLIV; this ->SCORE=SCORE;
}
int Livreur::getid(){return IDLIV;}
QString Livreur::getnom(){return NOMLIV;}
QString Livreur::getprenom(){return PRENOMLIV;}
int Livreur::getnum(){return NUMEROLIV;}
void Livreur::setid(int IDLIV){  this ->IDLIV=IDLIV;}
void Livreur::setnom(QString NOMLIV){this->NOMLIV=NOMLIV;}
void Livreur::setprenom(QString PRENOMLIV){this->PRENOMLIV=PRENOMLIV;}
void Livreur::setnum(int NUMEROLIV){this->NUMEROLIV=NUMEROLIV;}
void Livreur::setScore(double score){this->SCORE = score;}
double Livreur::getScore(){return SCORE;}
bool Livreur::ajouter(){
    bool test = false; // Initialisez à false

    QSqlQuery query;
    query.prepare("INSERT INTO Livreurs (IDLIV, NOMLIV, PRENOMLIV, NUMEROLIV) "
                  "VALUES (:IDLIV, :NOMLIV, :PRENOMLIV, :NUMEROLIV)");
    query.bindValue(":IDLIV", IDLIV);
    query.bindValue(":NOMLIV", NOMLIV);
    query.bindValue(":PRENOMLIV", PRENOMLIV);
    query.bindValue(":NUMEROLIV", NUMEROLIV);

    if (query.exec()) {
        test = true; // Définissez à true si l'ajout est réussi
    }

    return test;
}



QSqlQueryModel * Livreur::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Livreurs");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDLIV"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMLIV"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOMLIV"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NUMEROLIV"));



    return model;
}

bool Livreur::supprimer(int IDLIV)
{
    QSqlQuery query;
        // QString res=ID;
         query.prepare("Delete from Livreurs where IDLIV=:IDLIV");
         query.bindValue(":IDLIV",IDLIV);
         return query.exec();
}

bool Livreur::modifier()
{
    QSqlQuery query;

    query.prepare("UPDATE Livreurs SET IDLIV=:IDLIV,NOMLIV=:NOMLIV, PRENOMLIV=:PRENOMLIV, NUMEROLIV=:NUMEROLIV WHERE IDLIV=:IDLIV");
    query.bindValue(":IDLIV", IDLIV);
    query.bindValue(":NOMLIV", NOMLIV);
    query.bindValue(":PRENOMLIV", PRENOMLIV);
    query.bindValue(":NUMEROLIV", NUMEROLIV);

    return query.exec();
}

bool Livreur::checkIfIdExists(QString IDLIV)
{
    QSqlQuery query;
    query.prepare("SELECT IDLIV FROM Livreurs WHERE IDLIV = :IDLIV");
    query.bindValue(":IDLIV", IDLIV);

    if (query.exec() && query.next()) {
        // The ID exists in the database
        return true;
    } else {
        // The ID does not exist in the database
        return false;
    }
}
QSqlQueryModel* Livreur::chercher_livreur(QString NOMLIV, QString PRENOMLIV,int IDLIV) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM LIVREURS WHERE NOMLIV LIKE :NOMLIV OR PRENOMLIV LIKE :PRENOMLIV OR IDLIV LIKE :IDLIV");// Une requête SQL est une commande utilisée pour interroger ou modifier les données stockées dans une base de données relationnelle.
    query.bindValue(":IDLIV", IDLIV);
    query.bindValue(":NOMLIV", "%" + NOMLIV + "%");
    query.bindValue(":PRENOMLIV", "%" + PRENOMLIV + "%");
    query.exec(); // execution de la requete sql
    model->setQuery(query); // affichage
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDLIV"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOMLIV"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOMLIV"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMEROLIV"));

    return model;
}

QSqlQueryModel * Livreur::triAE()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM LIVREURS ORDER BY IDLIV ASC");
    return model;
}
QSqlQueryModel * Livreur::triDE()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM LIVREURS ORDER BY IDLIV DESC");
    return model;
}
void Livreur::modifierScore(int id, double score)
{
    QSqlQuery query;
    query.prepare("UPDATE LIVREURS SET SCORE = :score WHERE IDLIV = :IDLIV");  // informations du livreur sont mises à jour dans la base de données en utilisant la requête SQL préparée.
    query.bindValue(":score", score);
    query.bindValue(":IDLIV", id);

    if (query.exec()) {
        qDebug() << "Score mis à jour avec succès";
    } else {
        qDebug() << "Erreur lors de la mise à jour du score :" << query.lastError().text();
    }
}
void Livreur::setCheckBoxValue(int IDLIV, QString ETATLIV)
{
    QSqlQuery query;
    query.prepare("UPDATE LIVREURS SET ETATLIV = :ETATLIV WHERE IDLIV = :IDLIV");
    query.bindValue(":ETATLIV", ETATLIV);
    query.bindValue(":IDLIV", IDLIV);

    if (query.exec()) {
        qDebug() << "Mise à jour réussie.";
    } else {
        qDebug() << "Erreur lors de la mise à jour de la base de données:" << query.lastError().text();
    }
}


