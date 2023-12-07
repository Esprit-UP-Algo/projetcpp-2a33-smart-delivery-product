#ifndef LIVREUR_H
#define LIVREUR_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Livreur
{
public:
    Livreur();
    Livreur(int IDLIV,QString NOMLIV, QString PRENOMLIV, int NUMEROLIV, double SCORE);

        int getid();
        int getnum();
        QString getnom();
          QString getprenom();
          void setid(int);
          void setnum(int);
          void setnom(QString);
          void setprenom(QString);
          bool ajouter();
          void setScore(double score);
          double getScore();

          QSqlQueryModel * afficher();
          bool supprimer(int);
          bool modifier();
          bool checkIfIdExists(QString);
          QSqlQueryModel* chercher_livreur(QString NOMLIV, QString PRENOMLIV,int IDLIV );
          QSqlQueryModel * triAE();
          QSqlQueryModel * triDE();
          void modifierScore(int id, double score);
          void setCheckBoxValue(int IDLIV,QString ETATLIV );

private:
        int  IDLIV,NUMEROLIV;
       QString   NOMLIV,PRENOMLIV;
       double SCORE;

};

#endif // LIVREUR_H
