#ifndef ENSEIGNANT_MANAGER_H
#define ENSEIGNANT_MANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>

class DatabaseManager; // Déclaration avant l'utilisation

class EnseignantManager
{
public:
    EnseignantManager(DatabaseManager& dbManager);
    bool createTable();
    bool addEnseignant(int matricule, const QString &nom, const QString &prenom, int tauxHoraire);
    bool updateEnseignant(int matricule, const QString &nom, const QString &prenom, int tauxHoraire);
    bool deleteEnseignant(int matricule);

private:
    DatabaseManager& dbManager; // Référence à DatabaseManager
};

#endif // ENSEIGNANT_MANAGER_H
