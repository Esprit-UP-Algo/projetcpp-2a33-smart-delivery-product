#include "connection.h"
#include <QSqlQueryModel>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Zied");//inserer nom de l'utilisateur
    db.setPassword("ziedalimi31");//inserer mot de passe de cet utilisateur

    if (db.open())
    test=true;






    return  test;
}
