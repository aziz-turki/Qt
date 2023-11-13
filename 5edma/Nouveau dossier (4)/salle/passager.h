#ifndef passager_H
#define passager_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class passager
{
public:
    passager();


    passager(int,int,int,QString,QString);


            int getcin();
            int getnum();
            int getage();
              QString getnom();
            QString getprenom();


                 void getcin(int);

                 void getnum(int);
                  void getage(int);
                 void getnom(QString);

                 void getprenom(QString);


                 void setcin(int);
                 void setnum(int);
                 void setage(int);
                        void setnom(QString);
                        void setprenom(QString);

                 bool ajouter();
                        QSqlQueryModel * afficher();
                        bool supprimer(int);
                        bool modifierSalle(int cin,int num,int age,QString nom,QString prenom);
                       int chercherSalle(int cin);
                       QSqlQueryModel * trierpassagerParicin();
                       QSqlQueryModel * trierpassagerParnom();
                       QSqlQueryModel * trierSalleParnum();
                        QSqlQueryModel * Recherche(QString);




                               QSqlQueryModel* rechercher(QString place);






                    private:
                        int cin,num,age;
                        QString nom,prenom;
};

#endif // SALLE_H
