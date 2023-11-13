#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "client.h"
#include "magasin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_supprimer_clicked();

    void on_tableView_client_clicked(const QModelIndex &index);

    void on_pushButton_modifier_clicked();

    void on_lineEdit_recherche_textChanged();

    void on_comboBox_tri_activated();

    void on_pushButton_login_clicked();

    void on_pushButton_statestique_clicked();


    void on_pushButton_reset_clicked();

    void on_pushButton_PDF_clicked();

    void on_pushButton_AjouterM_clicked();

    void on_pushButton_AfficherM_clicked();

    void on_pushButton_ModifierM_clicked();

    void on_pushButton_SupprimerM_clicked();

    void on_tableView_magasin_clicked(const QModelIndex &index);

    void on_comboBox_TriMagasin_activated();

    void on_lineEdit_recherchemagasin_textChanged();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_excel_clicked();

    void on_pushButton_page_client_clicked();

    void on_pushButton_page_magasin_clicked();

    void on_pushButton_retour_client_clicked();

    void on_pushButton_retour_magasin_clicked();

private:
    Ui::MainWindow *ui;
    client C;
    magasin M;
};

#endif // MAINWINDOW_H
