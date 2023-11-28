#ifndef VEHICULE_H
#define VEHICULE_H


#include <QMainWindow>
#include <QObject>
#include <QtSql>
#include <QSharedDataPointer>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
class vehicule
{

public:
    vehicule();
    vehicule(int immatricule,QString marque , QString modele, int kilometrage , int maintenance ,  int capabilite );
    int getImmatricule();
    QString getMarque();
    QString getModele();
    int getKilometrage();
    int getMaintenance();
    int getCapabilite();

    void setImmatricule(int immatricule);
    void setMarque(QString marque);
    void setModele(QString modele);
    void setKilometrage(int kilometrage);
    void setMaintenance(int maintenance);
    void setCapabilite(int Capabilite);

    bool ajouter ();
    QSqlQueryModel * afficher ();
    bool supprimer (int);
    bool modifier();
    bool Maintenance();
    QSqlQueryModel *trivehicule(QString tri);
     QSqlQuery rechercher_immatricule(int immatricule );
private:
    int immatricule;
    QString marque, modele;
    int kilometrage,maintenance,capabilite;
    QString resultat_Maintenance;


};


#endif // VEHICULE_H
