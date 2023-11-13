#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_afficher_clicked();

    void on_pushButton_Ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_lineEdit_recherche_cursorPositionChanged();

    void on_comboBox_activated();

    void on_pushButton_statestique_clicked();

    void on_pushButton_PDF_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_QRcode_clicked();

    void on_pushButton_camera_clicked();

    void on_pushButton_whattsap_clicked();

private:
    Ui::MainWindow *ui;
    produit p;
    QTcpSocket*mSocket;
};
#endif // MAINWINDOW_H
