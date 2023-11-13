#include "notification.h"

#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notification_ajoutsalle()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des salle ","nouveau salle est ajouté ",QSystemTrayIcon::Information,15000);
}

void notification::notification_supprimersalle(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des salle ","nouveau salle est supprimé",QSystemTrayIcon::Information,15000);
}


void notification::notification_modifiersalle(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des salle ","nouveau salle est modifié",QSystemTrayIcon::Information,15000);

}

















