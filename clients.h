#ifndef CLIENTS_H
#define CLIENTS_H
#include<QSqlQueryModel>
#include "QString.h"
#include <QtCharts/QChartView>
#include <QtCharts>

class Clients
{
private:
    int IDC ;
    QString nomc ;
    QString prenomc ;
    QString adressec ;
    QString emailc ;
    int numc ;
    int nb_commande ;
    QString test ;

public:
    Clients();
    Clients(int, QString, QString, QString, QString,int, int);
    int getIDC();
    QString getnomc();
    QString getprenomc();
    QString getadressec();
    QString getemailc();
    int getnumc();
    int getnb_commande();

    void setIDC(int);
    void setnomc(QString);
    void setprenomc(QString);
    void setadressec(QString);
    void setemailc(QString);
    void setnumc(int);
    void setnb_commande(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool idExists(const int & IDC);
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * triClients(QString tri);

    QSqlQueryModel *tri();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel * tri_adresse();

    QSqlQueryModel * rechercher(QString);

    double calculerSommePrix(int id_fid);
    void Fidelite(int id_fid,double seuil);

    QMap<QString, int> getClients_Statistics();
    // QSqlQueryModel * rechercherClients(QString chaine);

int compteretat1();
int compteretat0();


};

#endif // CLIENTS_H
