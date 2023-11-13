#ifndef MAGASIN_H
#define MAGASIN_H


#include <QString>
#include <QSqlQueryModel>


class magasin

{
public:
    magasin();
    magasin(int,QString,QString,int);
    int getreference();
    QString gettype();
    QString getnom();
    int getquantite();


    void setreference(int);
    void settype(QString);
    void setnom(QString);
    void setquantite(int);



    bool ajoutermagasin();
    QSqlQueryModel* affichermagasin();
    bool supprimermagasin(int);
    bool supprimerTout();
    bool modifiermagasin(int,QString,QString,int);
    QSqlQueryModel* Recherchemagasin(QString);
    QSqlQueryModel * triermagasinParType();
    QSqlQueryModel * triermagasinParNom();
    QSqlQueryModel * triermagasinParQuantite();

private:
    int quantite,reference;
    QString type,nom;

};

#endif // MAGASIN_H
