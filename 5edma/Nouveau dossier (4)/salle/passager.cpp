#include "passager.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDate>

#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
passager::passager()
{



cin=0; num=0; age=0;nom="";prenom="";
}

passager::passager(int i,int n,int a,QString no,QString pr)
{
   cin=i;
   num=n;
   age=a;
   nom=no;
   prenom=pr;

}
int passager::getcin(){return cin;}
int passager::getnum(){return num;}
int passager::getage(){return age;}
QString passager::getnom(){return nom;}
QString passager::getprenom(){return prenom;}


void passager::setcin(int cin){this->cin=cin;}
void passager::setnum(int num){this->num=num;}
void passager::setage(int age){this->age=age;}
void passager::setnom(QString nom){this->nom=nom;}
void passager::setprenom(QString prenom){this->prenom=prenom;}




bool passager::ajouter()
{


QSqlQuery query;
QString id_string= QString::number(cin);
query.prepare("INSERT INTO passager (id,num,age,nom,prenom) "
              "VALUES (:id, :num, :age, :nom,:prenom)");

 query.bindValue(":cin", cin); //remplir CIN2 dans CIN1
 query.bindValue(":num", num);
  query.bindValue(":age", age);
 query.bindValue(":nom",nom);
 query.bindValue(":prenom",prenom);




return query.exec();

}
QSqlQueryModel * passager::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from passager");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("num"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("age"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prenom"));


    return  model;

}


bool passager::supprimer(int cin)
{

    QSqlQuery query;
    QString res=QString::number(cin);
    query.prepare("DELETE FROM passager WHERE cin= :cin");
    query.bindValue(":cin",res);
    return query.exec();

}
bool passager::modifierpassager(int id, int num, QString nom, QString prenom)

{



    QSqlQuery query;

    query.prepare("update passager set num=:num,nom=:nom,prenom=:prenom where id=:id");

    query.bindValue(":id",id);
    query.bindValue(":num",num);

    query.bindValue(":nom",nom);

    query.bindValue(":prenom",prenom);



    return query.exec();



}






//Trie Par id
QSqlQueryModel * passager::trierpassagerParid()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM passager order by id ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par prenom
QSqlQueryModel * passager::trierpassagerParprenom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM passager order by prenom ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par num
QSqlQueryModel * passager::trierpassagerParnum()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM passager order by num ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


//-------------------------------------------------------------------------

QSqlQueryModel * passager::Recherche(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM passager WHERE (ID LIKE '%"+a+"%' OR num LIKE '%"+a+"%' OR prenom LIKE '%"+a+"%' OR nom LIKE '%"+a+"%' ) ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("num"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));


    return model;
}

















