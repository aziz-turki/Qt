#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projets");
db.setUserName("razi");//inserer nom de l'utilisateur
db.setPassword("razi");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
