#include "magasin.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

magasin::magasin()
{
   reference=0; type=""; nom=" "; quantite=0 ;

}
magasin::magasin(int reference ,QString type,QString nom,int quantite)
{
    this->reference=reference;
    this->type=type;
    this->nom=nom;
    this->quantite=quantite;
}

int magasin::getreference(){return reference;}
QString magasin::gettype(){return type;}
QString magasin::getnom(){return nom;}
int magasin::getquantite(){return quantite;}




void magasin::setreference(int reference){this->reference=reference;}
void magasin::settype(QString type){this->type=type;}
void magasin::setnom(QString nom){this->nom=nom;}
void magasin::setquantite(int quantite){this->quantite=quantite;}




/******************************************************************************************************************/

/*******************************************CRUDS*****************************************************/


bool magasin::ajoutermagasin()
{

     QSqlQuery query;
     query.prepare("INSERT INTO MAGASIN (REFERENCE ,TYPE, NOM , QUANTITE) "
                   "VALUES (:reference,:type, :nom, :quantite)");// prparation de requette
     query.bindValue(":reference", reference); //remplir CIN2 dans CIN1
     query.bindValue(":type", type); //remplir CIN2 dans CIN1
     query.bindValue(":nom", nom);
     query.bindValue(":quantite",quantite);
     return query.exec();

}



/******************************************************************************************************************/

/******************************************************************************************************************/


QSqlQueryModel* magasin::affichermagasin()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM MAGASIN ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));//nom entite
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));

     return model;
}


/******************************************************************************************************************/

/******************************************************************************************************************/


bool magasin::supprimermagasin(int reference)
{
    QSqlQuery query;
    query.prepare(" Delete from MAGASIN where reference=:reference ");
    query.bindValue(":reference",reference);

    return query.exec();
}


/******************************************************************************************************************/

/******************************************************************************************************************/


bool magasin::supprimerTout()
{
    QSqlQuery query;
    query.prepare("delete from MAGASIN ");
    return query.exec();
}


/******************************************************************************************************************/

/******************************************************************************************************************/


bool magasin::modifiermagasin(int reference,QString type,QString nom,int quantite)
{

    QSqlQuery query;
    query.prepare("update MAGASIN set type=:type,nom=:nom,quantite=:quantite where reference=:reference");
    query.bindValue(":reference",reference);
    query.bindValue(":type",type);
    query.bindValue(":nom",nom);
    query.bindValue(":quantite",quantite);
    return query.exec();

}




/******************************************************************************************************************************************/

/****************************************Metiers*******************************************************/


QSqlQueryModel* magasin::Recherchemagasin(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM magasin WHERE reference LIKE '"+recherche+"%' OR type LIKE '"+recherche+"%' OR nom LIKE '"+recherche+"%'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));

return model;
}



QSqlQueryModel * magasin::triermagasinParType()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM MAGASIN order by type ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


QSqlQueryModel * magasin::triermagasinParNom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM MAGASIN order by nom ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}



QSqlQueryModel * magasin::triermagasinParQuantite()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM MAGASIN order by quantite ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}
