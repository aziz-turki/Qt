#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

client::client()
{
    CIN=0; nom=" "; prenom=" "; sexe=" "; age=0 ; num_tel=0; email=" "; adress= " ";

}
client::client(int CIN,QString nom,QString prenom,QString sexe,int age,int num_tel,QString email, QString adress)
{
    this->CIN=CIN;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->age=age;
    this->num_tel=num_tel;
    this->email=email;
    this->adress=adress;
}


int client::getCIN(){return CIN;}
QString client::getnom(){return nom;}
QString client::getprenom(){return prenom;}
QString client::getsexe(){return sexe;}
int client::getage(){return age;}
int client::getnum_tel(){return num_tel;}
QString client::getemail(){return email;}
QString client::getadress(){return adress;}




void client::setCIN(int CIN){this->CIN=CIN;}
void client::setnom(QString nom){this->nom=nom;}
void client::setprenom(QString prenom){this->prenom=prenom;}
void client::setsexe(QString sexe){this->sexe=sexe;}
void client::setage(int age){this->age=age;}
void client::setnum_tel(int num_tel){this->num_tel=num_tel;}
void client::setemail(QString email){this->email=email;}
void client::setadress(QString adress){this->adress=adress;}




/******************************************************************************************************************/

/*******************************************CRUDS*****************************************************/


bool client::ajouterclient()
{

     QSqlQuery query;
     query.prepare("INSERT INTO CLIENT (CIN, NOM, PRENOM ,SEXE, AGE, NUM_TEL, EMAIL, ADRESS) "
                   "VALUES (:CIN, :nom, :prenom, :sexe, :age, :num_tel, :email, :adress)");// prparation de requette
     query.bindValue(":CIN", CIN); //remplir CIN2 dans CIN1
     query.bindValue(":nom", nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":sexe",sexe);
     query.bindValue(":age",age );
     query.bindValue(":num_tel",num_tel);
     query.bindValue(":email",email);
     query.bindValue(":adress",adress);
     return query.exec();

}



/******************************************************************************************************************/

/******************************************************************************************************************/


QSqlQueryModel* client::afficherclient()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM CLIENT ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));//nom entite
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("adress"));

     return model;
}


/******************************************************************************************************************/

/******************************************************************************************************************/


bool client::supprimerclient(int CIN)
{
    QSqlQuery query;
    query.prepare(" Delete from CLIENT where CIN=:CIN ");
    query.bindValue(":CIN",CIN);

    return query.exec();
}



/******************************************************************************************************************/


bool client::modifierclient(int CIN,QString nom,QString prenom,QString sexe,int age,int num_tel,QString email,QString adress)
{

    QSqlQuery query;
    query.prepare("update CLIENT set nom=:nom,prenom=:prenom,sexe=:sexe,age=:age,num_tel=:num_tel,email=:email,adress=:adress where CIN=:CIN");
    query.bindValue(":CIN",CIN);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":sexe",sexe);
    query.bindValue(":age",age);
    query.bindValue(":num_tel",num_tel);
    query.bindValue(":email",email);
    query.bindValue(":adress",adress);
    return query.exec();

}




/******************************************************************************************************************************************/

/****************************************Metiers*******************************************************/



QSqlQueryModel* client::Rechercheclient(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM client WHERE CIN LIKE '"+recherche+"%' OR nom LIKE '"+recherche+"%' OR prenom LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("sexe"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("num_tel"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("email"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("adress"));

return model;
}

/******************************************************************************************************************/

/******************************************************************************************************************/


bool client::supprimerTout()
{
    QSqlQuery query;
    query.prepare("delete from CLIENT ");
    return query.exec();
}



/******************************************************************************************************************/

/******************************************************************************************************************/


//Trie Par CIN m
QSqlQueryModel * client::trierclientParCIN_M()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM CLIENT order by CIN ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


//Trie Par Nom
QSqlQueryModel * client::trierclientParNom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM CLIENT order by nom ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}



QSqlQueryModel * client::trierclientParAge()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM CLIENT order by age ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


