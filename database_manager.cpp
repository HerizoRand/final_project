#include "database_manager.h"

DatabaseManager::DatabaseManager()
{
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName(QCoreApplication::applicationDirPath() + "/bd.db");
}

DatabaseManager::~DatabaseManager()
{
    if (DB_Connection.isOpen()) {
        DB_Connection.close();
    }
}

bool DatabaseManager::connectDatabase()
{
    if (!DB_Connection.isOpen()) {
        return DB_Connection.open();
    }
    return true;
}

bool DatabaseManager::createTable()
{
    QSqlQuery query(DB_Connection);
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

bool DatabaseManager::addEnseignant(int matricule, const QString &nom, const QString &prenom, int tauxHoraire)
{
    QSqlQuery query(DB_Connection);
    query.prepare("INSERT INTO Enseignant(matricule, nom, prenom, tauxHoraire) "
                  "VALUES(:matricule, :nom, :prenom, :tauxHoraire)");
    query.bindValue(":matricule", matricule);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tauxHoraire", tauxHoraire);

    return query.exec();
}

bool DatabaseManager::updateEnseignant(int matricule, const QString &nom, const QString &prenom, int tauxHoraire)
{
    QSqlQuery query(DB_Connection);
    query.prepare("UPDATE Enseignant SET nom = :nom, prenom = :prenom, tauxHoraire = :tauxHoraire "
                  "WHERE matricule = :matricule");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tauxHoraire", tauxHoraire);
    query.bindValue(":matricule", matricule);

    return query.exec();
}

bool DatabaseManager::deleteEnseignant(int matricule)
{
    QSqlQuery query(DB_Connection);
    query.prepare("DELETE FROM Enseignant WHERE matricule = :matricule");
    query.bindValue(":matricule", matricule);

    return query.exec();
}

QSqlDatabase& DatabaseManager::getConnection()
{
    return DB_Connection;
}
