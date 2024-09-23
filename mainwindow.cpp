#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enseignant_manager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , enseignantManager(dbManager)  // Instanciation de EnseignantManager avec dbManager
    , matiereManager(dbManager)
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
    if (enseignantManager.addEnseignant(matricule, nom, prenom, tauxHoraire)) {
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

        // Créer la table Enseignant si elle n'existe pas déjà
        if (enseignantManager.createTable()) {
            qDebug() << "Table created or already exists.";
        } else {
            qDebug() << "Failed to create table.";
        }
    } else {
        qDebug() << "Failed to connect to the database.";
    }
}
