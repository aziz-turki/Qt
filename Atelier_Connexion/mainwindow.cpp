#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QMessageBox>
#include "client.h"
#include <QApplication>
#include <QPixmap>

#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include<QtCharts>

#include<QPieSlice >
#include<QPieSeries>
#include<QPrinter>
#include <QFileDialog>
#include<QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);


    /*********************************************************************/

    ui->lineEdit_CIN->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_numtel->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_age->setValidator(new QIntValidator(0, 99, this));
    ui->lineEdit_nom->setMaxLength(8);
    ui->lineEdit_prenom->setMaxLength(8);
    ui->lineEdit_email->setMaxLength(8);
    ui->lineEdit_adress->setMaxLength(8);


    /*********************************************************************/

    ui->lineEdit_reference->setValidator(new QIntValidator(0, 99999999, this));
    ui->lineEdit_quantite->setValidator(new QIntValidator(0, 999, this));
    ui->lineEdit_nomp->setMaxLength(8);
}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_page_client_clicked()
{
        ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_page_magasin_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_retour_client_clicked()
{
       ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_retour_magasin_clicked()
{
       ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ajouter_clicked()
{
        int CIN=ui->lineEdit_CIN->text().toInt(); //convertir en entier
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        QString sexe=ui->comboBox_sexe->currentText();
        int age=ui->lineEdit_age->text().toInt();
        int num_tel=ui->lineEdit_numtel->text().toInt();
        QString email=ui->lineEdit_email->text();
        QString adress=ui->lineEdit_adress->text();
        client C(CIN,nom,prenom,sexe,age,num_tel,email,adress);
            bool test=C.ajouterclient();
            if(test)
                  {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                                QObject::tr("ajout successful.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
                                 ui->tableView_client->setModel(C.afficherclient());
                  }
                                else
                                    QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                                QObject::tr("ajout failed.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);

                 ui->lineEdit_CIN->clear();
                 ui->lineEdit_nom->clear();
                 ui->lineEdit_prenom->clear();
                 ui->comboBox_sexe->setCurrentIndex(0);
                 ui->lineEdit_age->clear();
                 ui->lineEdit_numtel->clear();
                 ui->lineEdit_email->clear();
                 ui->lineEdit_adress->clear();
    }




void MainWindow::on_pushButton_afficher_clicked()
{
    ui->tableView_client->setModel(C.afficherclient());
}

void MainWindow::on_pushButton_supprimer_clicked()
{


        client C1;
        C1.setCIN(ui->lineEdit_CIN->text().toInt());
        bool test=C1.supprimerclient(C1.getCIN());
        QMessageBox msgBox;
        if (ui->lineEdit_CIN->text()=="")
        {
            QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                               QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
        }
        else if (test)
        {
            QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                               QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
            ui->tableView_client->setModel(C.afficherclient());
        }
        ui->lineEdit_CIN->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->comboBox_sexe->setCurrentIndex(0);
        ui->lineEdit_age->clear();
        ui->lineEdit_numtel->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_adress->clear();
    }

void MainWindow::on_pushButton_reset_clicked()
{
    client C1;
    bool test=C1.supprimerTout();
    QMessageBox msgBox;
         if(test)
          {    QMessageBox::information(nullptr, QObject::tr("Reset avec succes"),
                                        QObject::tr("Reset successful.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
                         ui->tableView_client->setModel(C.afficherclient());
          }
                        else
                            QMessageBox::critical(nullptr, QObject::tr("Reset errer"),
                                        QObject::tr("Reset failed.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_modifier_clicked()
{

        int CIN=ui->lineEdit_CIN->text().toInt(); //convertir en entier
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
        QString sexe=ui->comboBox_sexe->currentText();
        int age=ui->lineEdit_age->text().toInt();
        int num_tel=ui->lineEdit_numtel->text().toInt();
        QString email=ui->lineEdit_email->text();
        QString adress=ui->lineEdit_adress->text();
        client C(CIN,nom,prenom,sexe,age,num_tel,email,adress);

        bool test=C.modifierclient(C.getCIN(),C.getnom(),C.getprenom(),C.getsexe(),C.getage(),C.getnum_tel(),C.getemail(),C.getadress());

        QMessageBox msgBox;

        if ((ui->lineEdit_CIN->text()==0),(ui->lineEdit_nom->text()==""),(ui->lineEdit_prenom->text()==""),(ui->comboBox_sexe->currentText()==""),(ui->lineEdit_numtel->text()==0),(ui->lineEdit_email->text()==""),(ui->lineEdit_adress->text()==""))
        {
            QMessageBox::critical(this, QObject::tr("Modification Errer"),
                               QObject::tr("Echec de Modification!!!\n""Veuillez remplir tous le champs"), QMessageBox::Cancel);

        }
        else if(test)
        {
            QMessageBox::information(this, QObject::tr("Modification Succes"),
                               QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
            ui->tableView_client->setModel(C.afficherclient());

        }
        ui->lineEdit_CIN->clear();
        ui->lineEdit_nom->clear();
        ui->lineEdit_prenom->clear();
        ui->comboBox_sexe->setCurrentIndex(0);
        ui->lineEdit_age->clear();
        ui->lineEdit_numtel->clear();
        ui->lineEdit_email->clear();
        ui->lineEdit_adress->clear();
    }





void MainWindow::on_tableView_client_clicked(const QModelIndex &index)
{
        ui->lineEdit_CIN->setText(ui->tableView_client->model()->data(ui->tableView_client->model()->index(index.row(),0)).toString());
        ui->lineEdit_nom->setText(ui->tableView_client->model()->data(ui->tableView_client->model()->index(index.row(),1)).toString());
        ui->lineEdit_prenom->setText(ui->tableView_client->model()->data(ui->tableView_client->model()->index(index.row(),2)).toString());
        ui->comboBox_sexe->setCurrentText(ui->tableView_client->model()->data(ui->tableView_client->model()->index(index.row(),3)).toString());
        ui->lineEdit_age->setText(ui->tableView_client->model()->data(ui->tableView_client->model()->index(index.row(),5)).toString());
        ui->lineEdit_numtel->setText(ui->tableView_client->model()->data(ui->tableView_client->model()->index(index.row(),5)).toString());
        ui->lineEdit_email->setText(ui->tableView_client->model()->data(ui->tableView_client->model()->index(index.row(),6)).toString());
        ui->lineEdit_adress->setText(ui->tableView_client->model()->data(ui->tableView_client->model()->index(index.row(),7)).toString());
}



void MainWindow::on_lineEdit_recherche_textChanged()
{

    QString rech=ui->lineEdit_recherche->text();
    ui->tableView_client->setModel(C.Rechercheclient(rech));
}







void MainWindow::on_comboBox_tri_activated()
{
    if(ui->comboBox_tri->currentText()=="Tri par CIN Montant")
    {
        ui->tableView_client->setModel(C.trierclientParCIN_M());

    }else if(ui->comboBox_tri->currentText()=="Tri par Nom")
    {
        ui->tableView_client->setModel(C.trierclientParNom());
    }else
    {
        ui->tableView_client->setModel(C.trierclientParAge());
    }
}




void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
           QString password = ui->lineEdit_password->text();

           if ((username == "admin" && password == "admin")||(username == "malek" && password == "malek")) {
               QMessageBox::information(this, "Login", "Username and password are correct");
            ui->stackedWidget->setCurrentIndex(1);


           }
           else {
               QMessageBox::warning(this, "Login", "Username and password are not correct");
           }
           ui->lineEdit_username->clear();
           ui->lineEdit_password->clear();
}




void MainWindow::on_pushButton_statestique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                     model->setQuery("select * from CLIENT where AGE < 30 ");
                     float age=model->rowCount();
                     model->setQuery("select * from CLIENT where AGE  between 30 and 40 ");
                     float agee=model->rowCount();
                     model->setQuery("select * from CLIENT where AGE > 40 ");
                     float ageee=model->rowCount();
                     float total=age+agee+ageee;
                     QString a=QString("moins de 30 ans "+QString::number((age*100)/total,'f',2)+"%" );
                     QString b=QString("entre 30 et 40 Ans"+QString::number((agee*100)/total,'f',2)+"%" );
                     QString c=QString("+40 Ans"+QString::number((ageee*100)/total,'f',2)+"%" );
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
                     chart->setTitle("Pourcentage Par Age :Nombre Des Client "+ QString::number(total));
                     chart->legend()->hide();
                     // Used to display the chart
                     QChartView *chartView = new QChartView(chart);
                     chartView->setRenderHint(QPainter::Antialiasing);
                     chartView->resize(1000,500);
                     chartView->show();



}




void MainWindow::on_pushButton_PDF_clicked()
{

    QPdfWriter pdf("C:\\Users\\Malek kh\\Desktop\\PDF_Client.pdf");

   QPainter painter(&pdf);
   int i = 4000;
          painter.setPen(Qt::red);
          painter.setFont(QFont("Time New Roman", 25));
          painter.drawText(3000,1400,"Liste Des Clients");
          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          painter.drawRect(100,3000,9400,500);
          painter.setFont(QFont("Time New Roman", 9));
          painter.drawText(400,3300,"CIN");
          painter.drawText(1350,3300,"Nom");
          painter.drawText(2200,3300,"Prenom");
          painter.drawText(3400,3300,"Sexe");
          painter.drawText(4400,3300,"Age");
          painter.drawText(6200,3300,"Numero de Tel");
          painter.drawText(7600,3300,"Email");
          painter.drawText(8500,3300,"Adress");
          painter.drawRect(100,3000,9400,9000);

          QSqlQuery query;
          query.prepare("select * from CLIENT");
          query.exec();
          while (query.next())
          {
              painter.drawText(400,i,query.value(0).toString());
              painter.drawText(1350,i,query.value(1).toString());
              painter.drawText(2300,i,query.value(2).toString());
              painter.drawText(3400,i,query.value(3).toString());
              painter.drawText(4400,i,query.value(4).toString());
              painter.drawText(6200,i,query.value(5).toString());
              painter.drawText(7600,i,query.value(6).toString());
              painter.drawText(8500,i,query.value(7).toString());


             i = i + 350;
          }
          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
          QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}



/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/



void MainWindow::on_pushButton_AjouterM_clicked()
{
            int reference=ui->lineEdit_reference->text().toInt(); //convertir en entier
            QString type=ui->comboBox_type->currentText();
            QString nom=ui->lineEdit_nomp->text();
            int quantite=ui->lineEdit_quantite->text().toInt();
            magasin M(reference,type,nom,quantite);
                bool test=M.ajoutermagasin();
                if(test)
                      {    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                                                    QObject::tr("ajout successful.\n"
                                                                "Click Cancel to exit."), QMessageBox::Cancel);
                                     ui->tableView_magasin->setModel(M.affichermagasin());
                      }
                                    else
                                        QMessageBox::critical(nullptr, QObject::tr("Ajout errer"),
                                                    QObject::tr("ajout failed.\n"
                                                                "Click Cancel to exit."), QMessageBox::Cancel);

                     ui->lineEdit_reference->clear();
                     ui->comboBox_type->setCurrentIndex(0);
                     ui->lineEdit_nomp->clear();
                     ui->lineEdit_quantite->clear();


}

void MainWindow::on_pushButton_AfficherM_clicked()
{
    ui->tableView_magasin->setModel(M.affichermagasin());
}



void MainWindow::on_pushButton_SupprimerM_clicked()
{

    magasin M1;
    M1.setreference(ui->lineEdit_reference->text().toInt());
    bool test=M1.supprimermagasin(M1.getreference());
    QMessageBox msgBox;
    if (ui->lineEdit_reference->text()=="")
    {
        QMessageBox::critical(this, QObject::tr("Suppression Errer"),
                           QObject::tr("Echec de Suppression!!!\n""Veuillez remplir la label de CIN"), QMessageBox::Cancel);
    }
    else if (test)
    {
        QMessageBox::information(this, QObject::tr("Suppression avec Succes"),
                           QObject::tr("Suppression avec succes"), QMessageBox::Cancel);
        ui->tableView_magasin->setModel(M.affichermagasin());
    }

    ui->lineEdit_reference->clear();
    ui->comboBox_type->setCurrentIndex(0);
    ui->lineEdit_nomp->clear();
    ui->lineEdit_quantite->clear();
}



void MainWindow::on_pushButton_ModifierM_clicked()
{

    int reference=ui->lineEdit_reference->text().toInt(); //convertir en entier
    QString type=ui->comboBox_type->currentText();
    QString nom=ui->lineEdit_nomp->text();
    int quantite=ui->lineEdit_quantite->text().toInt();
    magasin M(reference,type,nom,quantite);

    bool test=M.modifiermagasin(M.getreference(),M.gettype(),M.getnom(),M.getquantite());

    QMessageBox msgBox;

    if ((ui->lineEdit_reference->text()==0),(ui->comboBox_type->currentText()==""),(ui->lineEdit_nomp->text()==""),(ui->lineEdit_quantite->text()==0))
    {
        QMessageBox::critical(this, QObject::tr("Modification Errer"),
                           QObject::tr("Echec de Modification!!!\n""Veuillez remplir tous le champs"), QMessageBox::Cancel);

    }
    else if(test)
    {
        QMessageBox::information(this, QObject::tr("Modification Succes"),
                           QObject::tr("Modifications avec Succes"), QMessageBox::Cancel);
        ui->tableView_magasin->setModel(M.affichermagasin());

    }
    ui->lineEdit_reference->clear();
    ui->comboBox_type->setCurrentIndex(0);
    ui->lineEdit_nomp->clear();
    ui->lineEdit_quantite->clear();
}


void MainWindow::on_tableView_magasin_clicked(const QModelIndex &index)
{
    ui->lineEdit_reference->setText(ui->tableView_magasin->model()->data(ui->tableView_magasin->model()->index(index.row(),0)).toString());
    ui->comboBox_type->setCurrentText(ui->tableView_magasin->model()->data(ui->tableView_magasin->model()->index(index.row(),1)).toString());
    ui->lineEdit_nomp->setText(ui->tableView_magasin->model()->data(ui->tableView_magasin->model()->index(index.row(),2)).toString());
    ui->lineEdit_quantite->setText(ui->tableView_magasin->model()->data(ui->tableView_magasin->model()->index(index.row(),3)).toString());

}



void MainWindow::on_comboBox_TriMagasin_activated()
{
    if(ui->comboBox_TriMagasin->currentText()=="Tri par Type")
    {
        ui->tableView_magasin->setModel(M.triermagasinParType());

    }else if(ui->comboBox_TriMagasin->currentText()=="Tri par Nom")
    {
        ui->tableView_magasin->setModel(M.triermagasinParNom());
    }else
    {
        ui->tableView_magasin->setModel(M.triermagasinParQuantite());
    }
}

void MainWindow::on_lineEdit_recherchemagasin_textChanged()
{

    QString rech=ui->lineEdit_recherchemagasin->text();
    ui->tableView_magasin->setModel(M.Recherchemagasin(rech));
}

void MainWindow::on_pushButton_imprimer_clicked()
{

        QString strStream;
                        QTextStream out(&strStream);

                        const int rowCount = ui->tableView_magasin->model()->rowCount();
                        const int columnCount = ui->tableView_magasin->model()->columnCount();
                        QString TT = QDateTime::currentDateTime().toString();
                        out <<"<html>\n"
                              "<head>\n"
                               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            << "<title>ERP - COMmANDE LIST<title>\n "
                            << "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"
                               "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                               +"<img src=C:\\Users\\asus\\Desktop\\pdf\\logo_projet />"
                               "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  Produits ****** </strong></h1>"


                            "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                              "</br> </br>";
                        // headers
                        out << "<thead><tr bgcolor=#d6e5ff>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView_magasin->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tableView_magasin->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr>";
                            for (int column = 0; column < columnCount; column++) {
                                if (!ui->tableView_magasin->isColumnHidden(column)) {
                                    QString data =ui->tableView_magasin->model()->data(ui->tableView_magasin->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table>\n"
                            "</body>\n"
                            "</html>\n";

                        QTextDocument *document = new QTextDocument();
                        document->setHtml(strStream);

                        QPrinter printer;

                        QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                        if (dialog->exec() == QDialog::Accepted) {
                            document->print(&printer);
                        }

                        delete document;


}

void MainWindow::on_pushButton_excel_clicked()
{
        QString nomFile="fichier excel ";
            QMessageBox msg;
            if(!nomFile.length()){

                msg.setText("entrer le nom du fichier");
                msg.exec();
            }
            else{
            QFile file("C:/Users/Malek kh/Desktop/"+nomFile+".csv");
            QString finalmsg="fichier modifie avec succes";
             if(!file.exists()){
             finalmsg="fichier cree avec succes";
             }
            file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);

            QTextStream txt(&file);
            txt<<"Reference \t\t  Type    \t\t Nom   \t\t  Quantite       \n";

            for(int i=0;i<5;i++){

            QString reference= ui->tableView_magasin->model()->index(i,0).data().toString();
            QString type= ui->tableView_magasin->model()->index(i,1).data().toString();
            QString nom= ui->tableView_magasin->model()->index(i,2).data().toString();
            QString quantite= ui->tableView_magasin->model()->index(i,3).data().toString();

            if(reference.length()){

            txt<< "'"+ reference +"' \t \t \t ";
            txt<< "'"+ type +"' \t \t \t";
            txt<< "'"+ nom +"' \t \t \t";
            txt<< "'"+ quantite +"' \t \t \t \n";
            }
            }
            msg.setText(finalmsg);
            msg.exec();
            file.close();
            }

}


