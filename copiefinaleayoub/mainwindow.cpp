#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include "widget.h"

#include<QPieSlice >
#include<QPieSeries>
#include<QPrinter>
#include <QFileDialog>
#include<QPrintDialog>

#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QtCharts>
#include <QDebug>
#include <QMessageBox>
#include "QIntValidator"
#include <QDateEdit>
#include <QPlainTextEdit>
#include <QPrinter>
//#include <QPrinterInfo>
//#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QGuiApplication>
//#include <QQmlApplicationEngine>
#include <QTcpSocket>
//#include <QQuickItem>
#include <QSystemTrayIcon>
#include <QIntValidator>

#include"qrcode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //chat
        mSocket=new QTcpSocket(this);
            mSocket->connectToHost("localhost",2000);
            if (mSocket->waitForConnected(3000))
            {
                ui->plainTextEdit->appendPlainText("se connecter correctement");
            }
            else
            {
                ui->plainTextEdit->appendPlainText("connected");
            }
            connect(mSocket,SIGNAL(readyRead()),this,SLOT(leer()));
            // fin chat
}

MainWindow::~MainWindow()
{
    delete ui;
}

/******************************* CRUD******************************/


void MainWindow::on_pushButton_afficher_clicked()
{
        ui->tableView->setModel(p.afficherproduit());


}

void MainWindow::on_pushButton_Ajouter_clicked()
{
       int id_magasin=ui->lineEdit_idmagasin->text().toInt(); //convertir en entier
       QString nom_magasin=ui->lineEdit_nommagasin->text();
       int num_article=ui->lineEdit_NumArticel->text().toInt();
       QString nom_article=ui->lineEdit_nomarticle->text();
       int prix_article=ui->lineEdit_prixarticle->text().toInt();
       int nombre_article=ui->lineEdit_nmbrarticle->text().toInt();
       produit p(id_magasin,nom_magasin,num_article,nom_article,prix_article,nombre_article);
           bool test=p.ajouterproduit();
           if(test)
                 {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                               QObject::tr("ajout successful.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
                                ui->tableView->setModel(p.afficherproduit()); //mise a jour tableau automatique
                 }
                               else
                                   QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                               QObject::tr("ajout failed.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);

            // case vide
                ui->lineEdit_idmagasin->clear();
                ui->lineEdit_nommagasin->clear();
                ui->lineEdit_NumArticel->clear();
                ui->lineEdit_nomarticle->clear();
                ui->lineEdit_prixarticle->clear();
                ui->lineEdit_nmbrarticle->clear();
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    produit p1;
    p1.setidmagasin(ui->lineEdit_idmagasin->text().toInt());
    bool test=p1.supprimerproduit(p1.getidmagasin());
    QMessageBox msgBox;
    if (ui->lineEdit_idmagasin->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                           QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
    }
    else if (test)
    {
        QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                           QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
        ui->tableView->setModel(p.afficherproduit());
    }

    ui->lineEdit_idmagasin->clear();
    ui->lineEdit_nommagasin->clear();
    ui->lineEdit_NumArticel->clear();
    ui->lineEdit_nomarticle->clear();
    ui->lineEdit_prixarticle->clear();
    ui->lineEdit_nmbrarticle->clear();
}

void MainWindow::on_pushButton_modifier_clicked()
{
       int id_magasin=ui->lineEdit_idmagasin->text().toInt(); //convertir en entier
       QString nom_magasin=ui->lineEdit_nommagasin->text();
       int num_article=ui->lineEdit_NumArticel->text().toInt();
       QString nom_article=ui->lineEdit_nomarticle->text();
       int prix_article=ui->lineEdit_prixarticle->text().toInt();
       int nombre_article=ui->lineEdit_nmbrarticle->text().toInt();
       produit p(id_magasin,nom_magasin,num_article,nom_article,prix_article,nombre_article);

       bool test=p.modifierEmploye(p.getidmagasin(),p.getnommagasin(),p.getnumarticle(),p.getnomarticle(),p.getprixarticle(),p.getnombrearticle());

       QMessageBox msgBox;

       if (test)
       {

           QMessageBox::information(this, QObject::tr("Modification Succes"),
                              QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
           ui->tableView->setModel(p.afficherproduit());

       }
       else
       {

           QMessageBox::critical(this, QObject::tr("Modification Errer"),
                              QObject::tr("Echec de Modification!!!\n""Veuillez remplir tous le champs"), QMessageBox::Cancel);
       }


       ui->lineEdit_idmagasin->clear();
       ui->lineEdit_nommagasin->clear();
       ui->lineEdit_NumArticel->clear();
       ui->lineEdit_nomarticle->clear();
       ui->lineEdit_prixarticle->clear();
       ui->lineEdit_nmbrarticle->clear();

}



/*****************************Metiers**********************************/



void MainWindow::on_lineEdit_recherche_cursorPositionChanged()
{
    QString rech=ui->lineEdit_recherche->text();
    ui->tableView->setModel(p.RechercheArticle(rech));

}

void MainWindow::on_comboBox_activated()
{
    if(ui->comboBox->currentText()=="Tri par Num Article")
        {
            ui->tableView->setModel(p.trierProduitparnumArticle());

        }else if(ui->comboBox->currentText()=="Tri par Nom Article")
        {
            ui->tableView->setModel(p.trierProduitparnomArticle());

        }else
        {
            ui->tableView->setModel(p.trierProduitparprixArticle());
        }
}

void MainWindow::on_pushButton_statestique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                        model->setQuery("select * from PRODUIT where prix_article < 100 ");
                        float age=model->rowCount();
                        model->setQuery("select * from PRODUIT where prix_article  between 100 and 1000 ");
                        float agee=model->rowCount();
                        model->setQuery("select * from PRODUIT where prix_article >1000 ");
                        float ageee=model->rowCount();
                        float total=age+agee+ageee;
                        QString a=QString("moins de 100 DT "+QString::number((age*100)/total,'f',2)+"%" );
                        QString b=QString("entre 100 et 1000 DT "+QString::number((agee*100)/total,'f',2)+"%" );
                        QString c=QString("+1000 DT"+QString::number((ageee*100)/total,'f',2)+"%" );
                        QPieSeries *series = new QPieSeries();
                        series->append(a,age);
                        series->append(b,agee);
                        series->append(c,ageee);
                if (age!=0)
                {QPieSlice *slice = series->slices().at(0);
                 slice->setLabelVisible();
                 slice->setPen(QPen());}
                if ( agee!=0)
                {
                         // Add label, explode and define brush for 2nd slice
                         QPieSlice *slice1 = series->slices().at(1);
                         //slice1->setExploded();
                         slice1->setLabelVisible();
                }
                if(ageee!=0)
                {
                         // Add labels to rest of slices
                         QPieSlice *slice2 = series->slices().at(2);
                         //slice1->setExploded();
                         slice2->setLabelVisible();
                }
                        // Create the chart widget
                        QChart *chart = new QChart();
                        // Add data to chart with title and hide legend
                        chart->addSeries(series);
                        chart->setTitle("Pourcentage Par Age :Nombre Des Aimaux "+ QString::number(total));
                        chart->legend()->hide();
                        // Used to display the chart
                        QChartView *chartView = new QChartView(chart);
                        chartView->setRenderHint(QPainter::Antialiasing);
                        chartView->resize(1000,500);
                        chartView->show();




}




void MainWindow::on_pushButton_PDF_clicked()
{
    QPdfWriter pdf("C:\\Users\\octanet\\Desktop\\copiefinaleayoub\\PDF_Article.pdf");

      QPainter painter(&pdf);
      int i = 4000;
             painter.setPen(Qt::red);
             painter.setFont(QFont("Time New Roman", 25));
             painter.drawText(3000,1400,"Liste Des Article");
             painter.setPen(Qt::black);
             painter.setFont(QFont("Time New Roman", 15));
             painter.drawRect(100,3000,9400,500);
             painter.setFont(QFont("Time New Roman", 9));
             painter.drawText(400,3300,"Id Magasin");
             painter.drawText(1350,3300,"Nom Magasin");
             painter.drawText(2600,3300,"Num Article");
             painter.drawText(3800,3300,"Nom Article");
             painter.drawText(4900,3300,"Prix Article");
             painter.drawText(6200,3300,"Nombre Article");
             painter.drawRect(100,3000,9400,9000);

             QSqlQuery query;
             query.prepare("select * from PRODUIT");
             query.exec();
             while (query.next())
             {
                 painter.drawText(400,i,query.value(0).toString());
                 painter.drawText(1450,i,query.value(1).toString());
                 painter.drawText(2800,i,query.value(2).toString());
                 painter.drawText(4000,i,query.value(3).toString());
                 painter.drawText(5100,i,query.value(4).toString());
                 painter.drawText(6400,i,query.value(5).toString());


                i = i + 350;
             }
             QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
             QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_QRcode_clicked()
{
    QString text ="Articles details :"+ ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),1)).toString()
                            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),2)).toString()
                            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),3)).toString()
                            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),4)).toString()
                            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),5)).toString()
                            +" "+ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),6)).toString();
                    //text="user data";
                    using namespace qrcodegen;
                      // Create the QR Code object
                      QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
                      qint32 sz = qr.getSize();
                      QImage im(sz,sz, QImage::Format_RGB32);
                        QRgb black = qRgb(  0,  0,  0);
                        QRgb white = qRgb(255,255,255);
                      for (int y = 0; y < sz; y++)
                        for (int x = 0; x < sz; x++)
                          im.setPixel(x,y,qr.getModule(x, y) ? black : white );
                      ui->qr_code->setPixmap( QPixmap::fromImage(im.scaled(256,256,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );

}

void MainWindow::on_pushButton_camera_clicked()
{

        Widget w ;
        w.setModal(true);
        w.exec();



}

void MainWindow::on_pushButton_whattsap_clicked()
{
    QDesktopServices::openUrl(QUrl("https://wa.me/+21655437246", QUrl::TolerantMode));
}
