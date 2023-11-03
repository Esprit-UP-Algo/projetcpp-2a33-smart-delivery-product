#include "connection.h"
#include<QSqlDatabase>

Connection::Connection()
{

}

bool Connection::createconnection()
{
    QSqlDatabase   db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("skander");//inserer nom de l'utilisateur
    db.setPassword("esprit23");//inserer mot de passe de cet utilisateur

    if(db.open()) test=true;

    return test ;
}

 void Connection::closeconnection() {db.close();}

