#ifndef PRODUIT_H
#define PRODUIT_H

#include <QString>
#include <QSqlQueryModel>


class produit

{
public:
    produit();
    produit(int,QString,int,QString,int,int);


    int getidmagasin();
    QString getnommagasin();
    int getnumarticle();
    QString getnomarticle();
    int getprixarticle();
    int getnombrearticle();



    void setidmagasin(int);
    void setnommagasin(QString);
    void setnumarticle(int);
    void setnomarticle(QString);
    void setprixarticle(int);
    void setnombrearticle(int);


    bool ajouterproduit();
    QSqlQueryModel* afficherproduit();
    bool supprimerproduit(int);
    bool modifierEmploye(int,QString,int,QString,int,int);
    QSqlQueryModel* RechercheArticle(QString);
    QSqlQueryModel * trierProduitparnumArticle();
    QSqlQueryModel * trierProduitparnomArticle();
    QSqlQueryModel * trierProduitparprixArticle();


private:
    int id_magasin,num_article,prix_article,nombre_article;
    QString nom_magasin,nom_article;
};


#endif // PRODUIT_H
