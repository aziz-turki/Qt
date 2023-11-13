#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQueryModel>
//CRUDS
class client

{
public:
    client();
    client(int,QString,QString,QString,int,int,QString,QString);
    int getCIN();
    QString getnom();
    QString getprenom();
    QString getsexe();
    int getage();
    int getnum_tel();
    QString getemail();
    QString getadress();



    void setCIN(int);
    void setnom(QString);
    void setprenom(QString);
    void setsexe(QString);
    void setage(int);
    void setnum_tel(int);
    void setemail(QString);
    void setadress(QString);



    bool ajouterclient();
    QSqlQueryModel* afficherclient();
    bool supprimerclient(int);
    bool supprimerTout();
    bool modifierclient(int,QString,QString,QString,int,int,QString,QString);
    QSqlQueryModel* Rechercheclient(QString);
    QSqlQueryModel * trierclientParCIN_M();
    QSqlQueryModel * trierclientParNom();
    QSqlQueryModel * trierclientParAge();

private:
    int CIN,num_tel,age;
    QString nom,prenom,sexe,email,adress;

};


#endif // CLIENT_H
