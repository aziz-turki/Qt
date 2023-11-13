/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QLabel *label_24;
    QLabel *recherche;
    QLineEdit *le_id;
    QLineEdit *le_num;
    QLineEdit *rechercher_salle;
    QComboBox *trier_salle;
    QLineEdit *le_place;
    QLabel *label_25;
    QLabel *label_22;
    QLineEdit *le_bloc;
    QPushButton *Push_Button_Afficher_2;
    QLabel *bloc;
    QPushButton *imprimer;
    QPushButton *modifier_salle;
    QLabel *label_26;
    QPushButton *supprimer_salle;
    QTableView *salleAfich;
    QLineEdit *fichier;
    QPushButton *ajouter_salle;
    QPushButton *fichier_xl;
    QPushButton *pushButton_17;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(835, 691);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(-10, 10, 1151, 741));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_24 = new QLabel(page_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(20, 160, 61, 21));
        label_24->setStyleSheet(QLatin1String("font: 75 14pt \"MS Shell Dlg 2\";\n"
""));
        recherche = new QLabel(page_2);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(60, 270, 111, 31));
        recherche->setStyleSheet(QStringLiteral("font: 75 14pt \"MS Shell Dlg 2\";"));
        le_id = new QLineEdit(page_2);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(80, 160, 121, 31));
        le_num = new QLineEdit(page_2);
        le_num->setObjectName(QStringLiteral("le_num"));
        le_num->setGeometry(QRect(420, 200, 111, 31));
        rechercher_salle = new QLineEdit(page_2);
        rechercher_salle->setObjectName(QStringLiteral("rechercher_salle"));
        rechercher_salle->setGeometry(QRect(170, 270, 113, 31));
        trier_salle = new QComboBox(page_2);
        trier_salle->setObjectName(QStringLiteral("trier_salle"));
        trier_salle->setGeometry(QRect(310, 270, 111, 31));
        le_place = new QLineEdit(page_2);
        le_place->setObjectName(QStringLiteral("le_place"));
        le_place->setGeometry(QRect(420, 160, 111, 31));
        le_place->setStyleSheet(QStringLiteral(""));
        label_25 = new QLabel(page_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(260, 200, 161, 31));
        label_25->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        label_22 = new QLabel(page_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(180, 40, 411, 61));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(90);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(label_22->sizePolicy().hasHeightForWidth());
        label_22->setSizePolicy(sizePolicy);
        label_22->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(28);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_22->setFont(font);
        label_22->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);\n"
"\n"
"font: 75 28pt \"MS Shell Dlg 2\";"));
        le_bloc = new QLineEdit(page_2);
        le_bloc->setObjectName(QStringLiteral("le_bloc"));
        le_bloc->setGeometry(QRect(80, 210, 121, 31));
        Push_Button_Afficher_2 = new QPushButton(page_2);
        Push_Button_Afficher_2->setObjectName(QStringLiteral("Push_Button_Afficher_2"));
        Push_Button_Afficher_2->setGeometry(QRect(570, 330, 91, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        Push_Button_Afficher_2->setFont(font1);
        bloc = new QLabel(page_2);
        bloc->setObjectName(QStringLiteral("bloc"));
        bloc->setGeometry(QRect(20, 210, 61, 31));
        bloc->setStyleSheet(QStringLiteral("font: 75 14pt \"MS Shell Dlg 2\";"));
        imprimer = new QPushButton(page_2);
        imprimer->setObjectName(QStringLiteral("imprimer"));
        imprimer->setGeometry(QRect(570, 540, 91, 31));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        imprimer->setFont(font2);
        modifier_salle = new QPushButton(page_2);
        modifier_salle->setObjectName(QStringLiteral("modifier_salle"));
        modifier_salle->setGeometry(QRect(570, 440, 91, 31));
        modifier_salle->setFont(font1);
        label_26 = new QLabel(page_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(260, 160, 91, 31));
        label_26->setStyleSheet(QLatin1String("font: 75 14pt \"MS Shell Dlg 2\";\n"
""));
        supprimer_salle = new QPushButton(page_2);
        supprimer_salle->setObjectName(QStringLiteral("supprimer_salle"));
        supprimer_salle->setGeometry(QRect(570, 490, 91, 31));
        supprimer_salle->setFont(font1);
        salleAfich = new QTableView(page_2);
        salleAfich->setObjectName(QStringLiteral("salleAfich"));
        salleAfich->setGeometry(QRect(40, 320, 511, 251));
        salleAfich->setStyleSheet(QStringLiteral(""));
        fichier = new QLineEdit(page_2);
        fichier->setObjectName(QStringLiteral("fichier"));
        fichier->setGeometry(QRect(670, 271, 113, 31));
        ajouter_salle = new QPushButton(page_2);
        ajouter_salle->setObjectName(QStringLiteral("ajouter_salle"));
        ajouter_salle->setGeometry(QRect(570, 390, 91, 31));
        ajouter_salle->setFont(font1);
        fichier_xl = new QPushButton(page_2);
        fichier_xl->setObjectName(QStringLiteral("fichier_xl"));
        fichier_xl->setGeometry(QRect(570, 270, 91, 31));
        fichier_xl->setFont(font1);
        pushButton_17 = new QPushButton(page_2);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(450, 270, 91, 31));
        pushButton_17->setFont(font1);
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 835, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);
        Push_Button_Afficher_2->setDefault(true);
        imprimer->setDefault(true);
        modifier_salle->setDefault(true);
        supprimer_salle->setDefault(true);
        ajouter_salle->setDefault(true);
        fichier_xl->setDefault(true);
        pushButton_17->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "Id:", Q_NULLPTR));
        recherche->setText(QApplication::translate("MainWindow", "recherche:", Q_NULLPTR));
        le_id->setText(QString());
        trier_salle->clear();
        trier_salle->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Trier", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tri Par ID", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tri Par bloc", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tri Par num", Q_NULLPTR)
        );
        label_25->setText(QApplication::translate("MainWindow", "Nombre de salle :", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "GESTION DE SALLE ", Q_NULLPTR));
        Push_Button_Afficher_2->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        bloc->setText(QApplication::translate("MainWindow", "Bloc :", Q_NULLPTR));
        imprimer->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
        modifier_salle->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "place :", Q_NULLPTR));
        supprimer_salle->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        ajouter_salle->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        fichier_xl->setText(QApplication::translate("MainWindow", "Fichier xl", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
