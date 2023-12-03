#ifndef FEEDBACK_H
#define FEEDBACK_H
#include<QSqlQueryModel>
#include "QString.h"

class FeedBack
{
private:
    int IDF ;
    int rating ;
    QString delivery ;
    QString communication ;
    QString etat ;
    int res ;




public:
    FeedBack();
    FeedBack(int ,int ,QString,QString,QString,int);
    bool ajout_FeedBack() ;

    int compteretat1();
    int compteretat2();
    float compteretatiiii();

    QSqlQueryModel* afficher();


};

#endif // FEEDBACK_H
