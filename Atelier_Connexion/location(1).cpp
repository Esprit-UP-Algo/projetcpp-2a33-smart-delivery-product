#include "location.h"
#include"QString"
#include"QSqlQuery"
#include"QtDebug"
#include <QSqlQueryModel>
#include <iostream>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QDialog>

#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>

#include <QLabel>
#include <QTableWidget>
#include <QTextOption>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>8
#include <QtCharts/QPieSlice>

#include <QtCharts/QBarSeries>
#include <QtCharts>
#include <QtSql>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>

#include <iostream>
#include <random>
Location::Location()
{
idl=0;
latitude=0;
longitude=0;
}
bool Location::ajouter_loc(int colisId)
{
    QSqlQuery query;

    float longitude=33.9200;
    float latitude= 8.1330;
    int idl = colisId;
    QString longs=QString::number((longitude));
    QString lat=QString::number((latitude));



    query.prepare("INSERT INTO LOCATION (idl, longitude, latitude) "
               "VALUES (:idl, :longitude, :latitude)");
   query.bindValue(":idl", idl);
    query.bindValue(":longitude", longs);
    query.bindValue(":latitude", lat);

    // Execute the Colis insert query
    bool colisInsertSuccess = query.exec();

    if (!colisInsertSuccess) {
        qDebug() << "Colis insert failed:" << query.lastError().text();
        return false;
    }

    return true;

}
