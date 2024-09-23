#include "enseignant_manager.h"
#include "database_manager.h"

EnseignantManager::EnseignantManager(DatabaseManager& dbManager) : dbManager(dbManager)
{
}

MatiereManager::MatiereManager(DatabaseManager& dbManager) : dbManager(dbManager)
{
}

/* ---- Enseignant Manager ---- */
bool EnseignantManager::createTable()
{
    QSqlQuery query(dbManager.getConnection());  // Utiliser la connexion de DatabaseManager
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS Enseignant ("
                               "matricule INTEGER PRIMARY KEY, "
                               "nom TEXT, "
                               "prenom TEXT, "
                               "tauxHoraire INTEGER)";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating table:" << query.lastError().text();
        return false;
    }
    return true;
}

bool EnseignantManager::addEnseignant(int matricule, const QString &nom, const QString &prenom, int tauxHoraire) {
    QSqlQuery query(dbManager.getConnection());
    query.prepare("INSERT INTO Enseignant(matricule, nom, prenom, tauxHoraire) "
                  "VALUES(:matricule, :nom, :prenom, :tauxHoraire)");
    query.bindValue(":matricule", matricule);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tauxHoraire", tauxHoraire);

    return query.exec();
}

bool EnseignantManager::updateEnseignant(int matricule, const QString &nom, const QString &prenom, int tauxHoraire) {
    QSqlQuery query(dbManager.getConnection());
    query.prepare("UPDATE Enseignant SET nom = :nom, prenom = :prenom, tauxHoraire = :tauxHoraire "
                  "WHERE matricule = :matricule");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tauxHoraire", tauxHoraire);
    query.bindValue(":matricule", matricule);

    return query.exec();
}

bool EnseignantManager::deleteEnseignant(int matricule) {
    QSqlQuery query(dbManager.getConnection());
    query.prepare("DELETE FROM Enseignant WHERE matricule = :matricule");
    query.bindValue(":matricule", matricule);

    return query.exec();
}


/* ---- Matiere Manager ---- */
bool MatiereManager::createTable()
{
    QSqlQuery query(dbManager.getConnection());
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS Matiere ("
                               "code INTEGER PRIMARY KEY, "
                               "designation TEXT, "
                               "volumeHoraire INTEGER)";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error creating Matiere table:" << query.lastError().text();
        return false;
    }
    return true;
}

bool MatiereManager::addMatiere(int code, const QString &designation, int volumeHoraire) {
    QSqlQuery query(dbManager.getConnection());
    query.prepare("INSERT INTO Matiere(code, designation, volumeHoraire) "
                  "VALUES(:code, :designation, :volumeHoraire)");
    query.bindValue(":code", code);
    query.bindValue(":designation", designation);
    query.bindValue(":volumeHoraire", volumeHoraire);

    return query.exec();
}

bool MatiereManager::updateMatiere(int code, const QString &designation, int volumeHoraire) {
    QSqlQuery query(dbManager.getConnection());
    query.prepare("UPDATE Matiere SET designation = :designation, volumeHoraire = :volumeHoraire "
                  "WHERE code = :code");
    query.bindValue(":code", code);
    query.bindValue(":designation", designation);
    query.bindValue(":volumeHoraire", volumeHoraire);

    return query.exec();
}

bool MatiereManager::deleteMatiere(int code) {
    QSqlQuery query(dbManager.getConnection());
    query.prepare("DELETE FROM Matiere WHERE code = :code");
    query.bindValue(":code", code);

    return query.exec();
}

