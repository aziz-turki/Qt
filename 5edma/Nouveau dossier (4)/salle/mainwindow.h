#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_ajouter_salle_clicked();

    void on_Push_Button_Afficher_2_clicked();

    void on_supprimer_salle_clicked();

    void on_modifier_salle_clicked();

    void on_imprimer_clicked();

    void on_pushButton_17_clicked();

    void on_trier_salle_activated();

    void on_rechercher_salle_textChanged(const QString &arg1);

    void on_fichier_xl_clicked();

    void on_salleAfich_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
