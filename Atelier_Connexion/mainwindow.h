#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"colis.h"
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QPushButton>
#include"clients.h"
#include"mainclients.h"
#include"arduino.h"
#include<QVariant>
#include<QtCore>
#include<QtGui>
#include<QtQuick>
#include <QVariant>
#include"vehicule.h"
#include"commande.h"
#include"feedback.h"
#include "livreur.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_B_ajouter_clicked();



    void on_supp_clicked();

//    void on_mod_clicked();

    void on_aff_clicked();

    void on_tri_clicked();

    void on_Rech_clicked();

    void on_mod1_clicked();

    void on_tri_p_clicked();

    void on_tri_volume_clicked();

    void on_tri_b_clicked();

    void on_Rech_3_textChanged(const QString &arg1);

    void on_pdf_clicked();

    void on_stat_clicked();

    void on_stat_2_clicked();

    void on_stat_3_clicked();

    void on_location_clicked();

    void on_add_clicked();

    void on_location_3_clicked();

void afficherPosition(QString latitude, QString longitude);
void afficherInformations(QString adresse, QString coordonnee);


void on_pushButton_clicked();

void on_pushButton_2_clicked();

void on_pushButton_3_clicked();

void on_pushButton_4_clicked();
 void update_label();
 void on_tmp_clicked();

 void on_aff_tmp_clicked();

 void on_B_ajouter_2_clicked();

 void on_clients_clicked();

 void on_ajout_clients_clicked();

 void on_pb_Update_clicked();

 void on_x_chercher_textChanged(const QString &arg1);

 void on_comboBox_tri_zii_activated(const QString &arg1);

 void on_pb_pdf_clicked();
 void stat();
 void feedback_statt();
 void on_pb_FeedBack_clicked();
 void on_pb_fidelite_clicked();

 void on_pb_supprimer_clicked();

 void on_client_tab_tabBarClicked(int index);
     void update_Clients_StatisticsChart();

         void clearClients_StatisticsChart();
         void on_vehicule_clicked();

         void on_ajouter_vehicule_clicked();

         void on_modifier_vehicule_clicked();

         void on_supp_veh_clicked();

         void on_cher_veh_textChanged(const QString &arg1);

         void on_stat_veh_clicked();

         void on_menu_clicked();

         void on_go_back_clicked();

         void on_menu1_clicked();

         void on_menu2_clicked();

         void on_menu4_clicked();

         void on_menu5_clicked();

         void on_menu3_clicked();

         void on_pb_commander_3_clicked();

         void on_pb_modifier_3_clicked();

         void on_pb_rechercher_3_clicked();
         void afficherStatistiques();

         void on_pb_afficherStatistiques_3_clicked();

void genererPDF();
//void on_pb_supprimer_4_clicked();

//livreur








//void on_pushButton_2_livreur_clicked();

void on_pdf_livreur_clicked();
void makePlot();




void  update_label_livreur();
void on_pb_ajouter_livreur_clicked();

void on_pb_supp_livreur_clicked();

void on_pb_modifier_livreur_clicked();

void on_valider_livreur_clicked();

void on_reset_livreur_clicked();

void on_btnTriAsc_livreur_clicked();

void on_pushButton_4_livreur_clicked();

void on_btnRech_livreur_clicked();

void on_calculscore_livreur_clicked();

void on_ConfirmationButton_3_livreur_clicked();

void on_retour_menu_livreur_clicked();

private:
    Ui::MainWindow *ui;
    Colis Ctmp;
    vehicule S;
    QByteArray data;
    Arduino A;
    commande c;
    FeedBack F ;
    Clients C;
     QChartView *ClientsStatisticsChartView;
      Livreur L;
       QString ref;


 signals:
   void setCenterPosition(QVariant,QVariant);
    void setLocationMarking(QVariant,QVariant);
};


#endif // MAINWINDOW_H
