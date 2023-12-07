#include "commande.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "mainwindow.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QtSql>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QTextDocument>
#include <QPrinter>

commande::commande()
{

}

commande::~commande()
{

}

commande::commande(int id_colis, int prix, QDate datee, QString produit, QString etat)
{
    this->id_commende = id_colis;
    this->prix = prix;
    this->datee = datee;
    this->produit = produit;
    this->etat = etat;
}

bool commande::ajouter()
{
    QSqlQuery q;
     // QString id_string=QString::number((id_colis));
 //  QString id_prix=QString::number((prix));

       q.prepare("INSERT INTO COMMANDES (ID,DATEC,PRODUIT,ETAT,PRIX) VALUES (:ID,  :DATEC, :PRODUIT, :ETAT,:PRIX)");
       q.bindValue(":ID", id_commende);
        q.bindValue(":DATEC", datee);
     q.bindValue(":PRODUIT", produit);
        q.bindValue(":ETAT", etat);

   q.bindValue(":PRIX", prix);

       return q.exec();
}

QSqlQueryModel* commande::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM COMMANDES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEC"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRODUIT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));

    return model;
}

bool commande::supprimer(int id)
{
    QSqlQuery q;
    q.prepare("DELETE FROM COMMANDES WHERE ID = :ID");
    q.bindValue(":ID", id);

    return q.exec();
}

bool commande::modifier()
{
    QSqlQuery update_query;
    update_query.prepare("UPDATE COMMANDES SET PRIX = :PRIX, DATEC = :DATEC, PRODUIT = :PRODUIT, ETAT = :ETAT WHERE ID = :ID");
    update_query.bindValue(":ID", id_commende);
    update_query.bindValue(":PRIX", prix);
    update_query.bindValue(":DATEC", datee);
    update_query.bindValue(":PRODUIT", produit);
    update_query.bindValue(":ETAT", etat);

    return update_query.exec();
}
QSqlTableModel* commande::getSortedModel()
{
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("COMMANDES");
    model->setSort(0, Qt::AscendingOrder);
    model->select();
    return model;
}


commande* commande::chercherParId(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM COMMANDES WHERE ID = :ID");
    query.bindValue(":ID", id);

    if (query.exec() && query.first()) {
        int id_colis = query.value("ID").toInt();
        int prix = query.value("PRIX").toInt();
        QDate datee = query.value("DATEC").toDate();
        QString produit = query.value("PRODUIT").toString();
        QString etat = query.value("ETAT").toString();
       // QString idclient = query.value("IDCLIENT").toString();

        commande* cmd = new commande(id_colis, prix, datee, produit, etat );
        return cmd;
    } else {
        return nullptr; // Retourner nullptr si la commande n'est pas trouvée
    }
}


QMap<QString, double> commande::pourcentagesParTrancheDePrix()
{
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM COMMANDES");
    query.first();
    int totalCommandes = query.value(0).toInt();

    QMap<QString, double> pourcentages;

    // Tranche de prix < 50
    query.exec("SELECT COUNT(*) FROM COMMANDES WHERE PRIX < 50");
    query.first();
    int prixMoins50 = query.value(0).toInt();
    pourcentages["Moins de 50"] = (static_cast<double>(prixMoins50) / totalCommandes) * 100;

    // Tranche de prix entre 50 et 100
    query.exec("SELECT COUNT(*) FROM COMMANDES WHERE PRIX >= 50 AND PRIX < 100");
    query.first();
    int prix50a100 = query.value(0).toInt();
    pourcentages["Entre 50 et 100"] = (static_cast<double>(prix50a100) / totalCommandes) * 100;

    // Tranche de prix >= 100
    query.exec("SELECT COUNT(*) FROM COMMANDES WHERE PRIX >= 100");
    query.first();
    int prixPlus100 = query.value(0).toInt();
    pourcentages["Plus de 100"] = (static_cast<double>(prixPlus100) / totalCommandes) * 100;

    return pourcentages;
}
QString commande::creerContenuFacture() const
{
    // Implémentez la logique pour créer le contenu spécifique de la facture
    // Utilisez les membres de la classe pour obtenir les données nécessaires
    return QString("ID : %1\nPRIX : %2\nDATEC : %3\nPRODUIT : %4\nETAT : %5")
            .arg(id_commende)
            .arg(prix)
            .arg(datee.toString("yyyy-MM-dd"))
            .arg(produit)
            .arg(etat);
}
