#ifndef CLIENTS_H
#define CLIENTS_H
#include<QSqlQueryModel>
#include "QString.h"

class Clients
{
private:
    int IDC ;
    QString nomc ;
    QString prenomc ;
    QString adressec ;
    QString emailc ;
    int numc ;

public:
    Clients();
    Clients(int, QString, QString, QString, QString,int);
    int getIDC();
    QString getnomc();
    QString getprenomc();
    QString getadressec();
    QString getemailc();
    int getnumc();

    void setIDC(int);
    void setnomc(QString);
    void setprenomc(QString);
    void setadressec(QString);
    void setemailc(QString);
    void setnumc(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool idExists(const int & IDC);
    bool supprimer(int);
    bool modifier();





};

#endif // CLIENTS_H
