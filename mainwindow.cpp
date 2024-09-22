#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connexion à la base de données
    VERIFICATION_DATABASE();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int matricule = ui->matricule->text().toInt();
    int tauxHoraire = ui->tauxHoraire->text().toInt();
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();

    // Ajout d'un enseignant
    if (dbManager.addEnseignant(matricule, nom, prenom, tauxHoraire)) {
        qDebug() << "Enseignant successfully added.";
        clearFields();
    } else {
        qDebug() << "Failed to add enseignant.";
    }
}
void MainWindow::clearFields()
{
    // Vide les champs de texte
    ui->matricule->clear();
    ui->tauxHoraire->clear();
    ui->nom->clear();
    ui->prenom->clear();
}

void MainWindow::VERIFICATION_DATABASE()
{
    if (dbManager.connectDatabase()) {
        qDebug() << "Database connected successfully.";

        // Créer la table si elle n'existe pas déjà
        if (dbManager.createTable()) {
            qDebug() << "Table created or already exists.";
        } else {
            qDebug() << "Failed to create table.";
        }
    } else {
        qDebug() << "Failed to connect to the database.";
    }
}
