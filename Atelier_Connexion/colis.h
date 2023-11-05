#ifndef COLIS_H
#define COLIS_H
#include"QString"
#include <QSqlQueryModel>

class Colis
{
private:
    int Id_colis;
    float poids,volume;
    QString etat;//casse ou non


public:
    Colis();
    Colis(int,float,float,QString);
    int get_id();
    float get_poids();
   float get_volume();
     QString get_etat();


    void set_id(int);
    void set_poids(float);
  void set_valume(float);
     void set_etat(QString);


    bool ajouter();
bool supprimer(int);
QSqlQueryModel * afficher();
bool modifierColis();
};


#endif // COLIS_H