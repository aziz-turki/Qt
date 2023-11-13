#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextStream>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include"notification.h"

#include <QDate>
#include <QTextDocument>

#include<QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>

#include"passager.h"


 salle s;
     notification N;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    ui->salleAfich->setModel(s.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_salle_clicked()
{
    int id=ui->le_id->text().toInt(); //convertir en entier
      int num=ui->le_num->text().toInt();
      QString bloc=ui->le_bloc->text();
      QString place=ui->le_place->text();

      salle s(id,num,bloc,place);

      bool test=s.ajouter();
      if(test)
      {

  N.notification_ajoutsalle();
          ui->salleAfich->setModel( s.afficher());
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n"
                                             "click cancel to exit."),QMessageBox::Cancel);
          QString nomFile ="Historique";
                       QFile file("C:/Users/razis/OneDrive/Bureau/Nouveau dossier (4)/salle/"+nomFile+".txt");
                       QString finalmsg="fichier ajouter avec succes";
                        if(!file.exists()){
                        finalmsg="fichier cree avec succes";
                        }
                       file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);



                       QTextStream txt(&file);
                         QString d_info = QDateTime::currentDateTime().toString();

                       QString message2=d_info+" - Un salle a été ajoutée avec un id:  "+ place +"\n";
                       txt << message2;

      }
      else  QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                     QObject::tr("ajout non effectue\n"
                                                 "click cancel to exit."),QMessageBox::Cancel);
      ui->le_id->clear();
      ui->le_num->clear();
      ui->le_bloc->clear();
       ui->le_place->clear();

}


void MainWindow::on_Push_Button_Afficher_2_clicked()
{
           ui->salleAfich->setModel(s.afficher());
}

void MainWindow::on_supprimer_salle_clicked()
{
    bool i;
         int id_del;


         id_del=ui->salleAfich->model()->data(ui->salleAfich->model()->index(ui->salleAfich->currentIndex().row(),0)).toInt();

         i=s.supprimer(id_del);
         if(i)
         {
           N.notification_supprimersalle();
             ui->salleAfich->setModel(s.afficher());
             QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("suppression effectué.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }
         else
            { QMessageBox::critical(nullptr, QObject::tr("not OK"),
                         QObject::tr("problème de suppression.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel); }
}

void MainWindow::on_modifier_salle_clicked()
{
    int id=ui->le_id->text().toInt();
        int num=ui->le_num->text().toInt();
        QString bloc=ui->le_bloc->text();
        QString place=ui->le_place->text();

    salle s(id,num,bloc,place);

            bool test=s.modifierSalle(s.getid(),s.getnum(),s.getbloc(),s.getplace());

            QMessageBox msgBox;

            if(test)
                {
 N.notification_modifiersalle();
                    msgBox.setText("Modification avec succes.");
                    ui->salleAfich->setModel(s.afficher());
                }
            else
                msgBox.setText("Echec de Modification!!!!!!");
                msgBox.exec();
}


void MainWindow::on_imprimer_clicked()
{
    QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->salleAfich->model()->rowCount();
                         const int columnCount = ui->salleAfich->model()->columnCount();
                         QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - COMmANDE LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> ******LISTE  ******"+TT+" </strong></h1>"
                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->salleAfich->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->salleAfich->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->salleAfich->isColumnHidden(column)) {
                                     QString data =ui->salleAfich->model()->data(ui->salleAfich->model()->index(row, column)).toString().simplified();
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


void MainWindow::on_pushButton_17_clicked()
{

    //ui->stackedWidget_2->setCurrentIndex(1);
       QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select * from salle where num < 10 ");
       float place1=model->rowCount();
       model->setQuery("select * from salle where num  between 10 and 20 ");
       float place2=model->rowCount();
       model->setQuery("select * from salle where num > 20 ");
       float place3=model->rowCount();
       float total=place1+place2+place3;

       QString a=QString("inferier 10 place . "+QString::number((place1*100)/total,'f',2)+"%" );
       QString b=QString("entre 10 et 20 place.  "+QString::number((place2*100)/total,'f',2)+"%" );
       QString c=QString("plus de 20 place.   "+QString::number((place3*100)/total,'f',2)+"%" );

       QPieSeries *series = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.
       series->append(a,place1);
       series->append(b,place2);//concatiner 2 chaines
       series->append(c,place3);
       if (place1!=0)
       {QPieSlice *slice = series->slices().at(0);//the percentage the actual slice
           slice->setLabelVisible();
           slice->setPen(QPen(Qt::red));}
       if ( place2!=0)
       {
           // Add label, explode and define brush for 2nd slice
           QPieSlice *slice1 = series->slices().at(1);
           //slice1->setExploded();
           slice1->setLabelVisible();
       }
       if(place3!=0)
       {
           // Add labels to rest of slices
           QPieSlice *slice2 = series->slices().at(2);
           //slice1->setExploded();
           slice2->setLabelVisible();// Sets the label visibility for all contours in the collection
       }
       // Create the chart widget
       QChart *chart = new QChart();
       // Add data to chart with title and hide legend
       chart->addSeries(series); // widget
       chart->setTitle("nombre de place par salle  "+ QString::number(total));
       chart->legend()->hide();
       // Used to display the chart
       QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
       chartView->setRenderHint(QPainter::Antialiasing);
       chartView->resize(1000,500);
       chartView->show();
}


void MainWindow::on_trier_salle_activated()
{
    if (ui->trier_salle->currentText()=="Tri Par ID")
    {
        ui->salleAfich->setModel(s.trierSalleParid());
    }
    else if(ui->trier_salle->currentText()=="Tri Par salle")
    {
        ui->salleAfich->setModel(s.trierSalleParbloc());
    }
    else
    {
        ui->salleAfich->setModel(s.trierSalleParnum());
    }
}

void MainWindow::on_rechercher_salle_textChanged(const QString &arg1)
{
       ui->salleAfich->setModel(s.Recherche(arg1));
}


void MainWindow::on_fichier_xl_clicked()
{
    QString nomFile=ui->fichier->text();
    QMessageBox msg;
    if(!nomFile.length()){

        msg.setText("entrer le nom du fichier");
        msg.exec();
    }
    else{
    QFile file("C:/Users/razis/OneDrive/Bureau/Nouveau dossier (4)/salle/exel"+nomFile+".csv");
    QString finalmsg="fichier modifie avec succes";
     if(!file.exists()){
     finalmsg="fichier cree avec succes";
     }
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream txt(&file);
    for(int i=0;i<100;i++){

    QString id= ui->salleAfich->model()->index(i,0).data().toString();
        QString num= ui->salleAfich->model()->index(i,3).data().toString();
    QString bloc= ui->salleAfich->model()->index(i,1).data().toString();
    QString place= ui->salleAfich->model()->index(i,2).data().toString();


    if(id.length()){

    txt<< "id: '"+ id +"'       ";
    txt<< "'bloc : '"+ num   +"'      ";
    txt<< "'place: '"+ place +"'      ";
    txt<< "'num: '"+ bloc +"' \n";

    }
    }
    msg.setText(finalmsg);
    msg.exec();
    file.close();
    }
}

void MainWindow::on_salleAfich_clicked(const QModelIndex &index)
{

        ui->le_id->setText(ui->salleAfich->model()->data(ui->salleAfich->model()->index(index.row(),0)).toString());
        ui->le_num->setText(ui->salleAfich->model()->data(ui->salleAfich->model()->index(index.row(),1)).toString());
        ui->le_bloc->setText(ui->salleAfich->model()->data(ui->salleAfich->model()->index(index.row(),2)).toString());
        ui->le_place->setText(ui->salleAfich->model()->data(ui->salleAfich->model()->index(index.row(),3)).toString());




}
