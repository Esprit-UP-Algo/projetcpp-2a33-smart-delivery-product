#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"clients.h"
#include <QMainWindow>
#include "feedback.h"


#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts>
#include <QPieSlice>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_5_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_Update_clicked();

    void on_pb_Clear_clicked();

   // void on_pb_rechercher_clicked();

    void on_x_chercher_textChanged(const QString &arg1);


    void on_comboBox_tri_zii_currentIndexChanged(const QString &arg1);

    void on_pb_pdf_clicked();

    void on_pb_fidelite_clicked();

    void update_Clients_StatisticsChart();

    void clearClients_StatisticsChart();


    void on_statistique_tabBarClicked(int index);

    void on_pb_FeedBack_clicked();

    void stat();

private:
    Ui::MainWindow *ui;
    Clients C ;
    FeedBack F ;
     QChartView *ClientsStatisticsChartView;
};
#endif // MAINWINDOW_H
