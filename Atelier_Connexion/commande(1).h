#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlTableModel>

class commande
{
public:
    commande();
    commande(int, int, QDate, QString, QString);
    ~commande();

    QString getEtat() { return etat; }
    QString getProduit() { return produit; }
    int getIdColis() { return id_commende; }
    QString getIdClient() { return idclient; }
    QDate getDatee() { return datee; }
    int getPrix() { return prix; }
    void setDatee(QDate date) { datee = date; }
    void setPrix(int p) { prix = p; }
    void setIdColis(int id) { id_commende = id; }
    void setProduit(QString p) { produit = p; }
    void setEtat(QString e) { etat = e; }
    void setIdClient(QString id) { idclient = id; }

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier();
    QSqlTableModel* getSortedModel();
    static commande* chercherParId(int id); // Déclaration de la fonction de recherche par ID
    static QMap<QString, double> pourcentagesParTrancheDePrix();
    QString creerContenuFacture() const;

private:
    int id_commende;
    int prix;
    QDate datee;
    QString produit;
    QString etat;
    QString idclient;
};

#endif // COMMANDE_H

