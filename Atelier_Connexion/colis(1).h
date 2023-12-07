#ifndef COLIS_H
#define COLIS_H
#include"QString"
#include <QSqlQueryModel>
#include<QtSql>
#include"mainclients.h"
#include <QTableWidget>
#include <QTextOption>
#include <QtCharts/QBarSeries>
#include <QtCharts>
#include <QtSql>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
using namespace std;
class Colis
{
private:
    int Id_colis;
    float poids,volume;
    QString etat;//casse ou non
    QString test;
     QString pdfFilePath;
       QPieSeries *pieSeries;
     QBarSeries *barSeries;
     QChartView *pieChartView;
     QChartView *barChartView;

public:
     //pieSeries = new QPieSeries();
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
QSqlQueryModel *  sortDatabaseById();
void displayItemDetails(int id) ;
QSqlQueryModel *  sortDatabaseByPoids();
QSqlQueryModel *  sortDatabaseByVolume();
QSqlQueryModel* rechercher(QString test);
QSqlQueryModel* rechercherpoids(QString test);
QSqlQueryModel* rechercherVolume(QString test);
  void exportDataToPDF();
    void exportDataToPDF_par_coli(QString id);
 //  QWidget* createColisCharts();
  int cassenum();
   int casseNonnum();
    QChartView* createPieChart();
     QChartView* createPieChartPoids();
      QChartView *valume();
       bool ajouter_tmp(float);
       QSqlQueryModel * afficher_tmp();
        QChartView* createPieChart_TMP();

};


#endif // COLIS_H
