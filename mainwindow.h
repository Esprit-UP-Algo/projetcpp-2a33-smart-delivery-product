#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "vehicule.h"
#include <QMainWindow>

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
    void on_pb_ajouter_clicked();
    void on_pb_supp_clicked();
    void on_pb_modifier_clicked();
    void on_pb_recherche_clicked();
    void on_pb_pdf_clicked();
    void on_pb_Maintenance_clicked(); // Déclaration de la fonction pour vérifier l'état de maintenance


    void on_combobox_tri_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    vehicule S;
};

#endif // MAINWINDOW_H
