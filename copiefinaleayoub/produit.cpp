#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>


produit::produit()
{
id_magasin=0; nom_magasin=" "; num_article=0; nom_article=" "; prix_article=0; nombre_article=0;
}


produit::produit(int id_magasin,QString nom_magasin ,int num_article,QString nom_article,int prix_article,int nombre_article)
{
    this->id_magasin=id_magasin;
    this->nom_magasin=nom_magasin;
    this->num_article=num_article;
    this->nom_article=nom_article;
    this->prix_article=prix_article;
    this->nombre_article=nombre_article;
}


int produit::getidmagasin(){return id_magasin;}
QString produit::getnommagasin(){return nom_magasin;}
int produit::getnumarticle(){return num_article;}
QString produit::getnomarticle(){return nom_article;}
int produit::getprixarticle(){return prix_article;}
int produit::getnombrearticle(){return nombre_article;}


void produit::setidmagasin(int id_magasin){this->id_magasin=id_magasin;}
void produit::setnommagasin(QString nom_magasin){this->nom_magasin=nom_magasin;}
void produit::setnumarticle(int num_article){this->num_article=num_article;}
void produit::setnomarticle(QString nom_article){this->nom_article=nom_article;}
void produit::setprixarticle(int prix_article){this->prix_article=prix_article;}
void produit::setnombrearticle(int nombre_article){this->nombre_article=nombre_article;}



/*******************************************CRUDS*****************************************************/



bool produit::ajouterproduit()
{

     QSqlQuery query;
     query.prepare("INSERT INTO PRODUIT (id_magasin, nom_magasin, num_article ,nom_article, prix_article, nombre_article) "
                   "VALUES (:id_magasin, :nom_magasin, :num_article, :nom_article, :prix_article, :nombre_article)");// prparation de requette
     query.bindValue(":id_magasin", id_magasin); // id2 dans id1
     query.bindValue(":nom_magasin", nom_magasin);
     query.bindValue(":num_article",num_article);
     query.bindValue(":nom_article",nom_article);
     query.bindValue(":prix_article",prix_article );
     query.bindValue(":nombre_article",nombre_article);
     return query.exec();

}



/***********************************************************************************************/


QSqlQueryModel* produit::afficherproduit()
{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM produit ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_magasin"));//nom entite
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_magasin"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_article"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_article"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_article"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre_article"));

     return model;

}


/***********************************************************************************************/


bool produit::supprimerproduit(int id_magasin)
{
    QSqlQuery query;
    query.prepare(" Delete from PRODUIT where id_magasin=:id_magasin ");
    query.bindValue(":id_magasin",id_magasin);

    return query.exec();
}






/***********************************************************************************************/



bool produit::modifierEmploye(int id_magasin, QString nom_magasin, int num_article, QString nom_article, int prix_article, int nombre_article)
{

    QSqlQuery query;
    query.prepare("update PRODUIT set nom_magasin=:nom_magasin,num_article=:num_article,nom_article=:nom_article,prix_article=:prix_article,nombre_article=:nombre_article where id_magasin=:id_magasin");
    query.bindValue(":id_magasin",id_magasin);
    query.bindValue(":nom_magasin",nom_magasin);
    query.bindValue(":num_article",num_article);
    query.bindValue(":nom_article",nom_article);
    query.bindValue(":prix_article",prix_article);
    query.bindValue(":nombre_article",nombre_article);
    return query.exec();

}



QSqlQueryModel* produit::RechercheArticle(QString recherche)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT * FROM produit WHERE id_magasin LIKE '"+recherche+"%' OR nom_magasin LIKE '"+recherche+"%' OR num_article LIKE '"+recherche+"%' OR nom_article LIKE '"+recherche+"%' OR prix_article LIKE '"+recherche+"%' OR nombre_article LIKE '"+recherche+"%' ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_magasin"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_magasin"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("num_article"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_article"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_article"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("nombre_article"));

return model;
}


/***********************************************************************************************/


QSqlQueryModel * produit::trierProduitparnumArticle()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM PRODUIT order by num_article ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

QSqlQueryModel * produit::trierProduitparnomArticle()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM PRODUIT order by nom_article ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}


QSqlQueryModel * produit::trierProduitparprixArticle()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM PRODUIT order by prix_article ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

