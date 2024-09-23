#ifndef ENSEIGNANT_MANAGER_H
#define ENSEIGNANT_MANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>

class DatabaseManager; // Déclaration avant l'utilisation

/* -- Enseignant Manager -- */
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

/* -- Matiere Manager -- */
class MatiereManager
{
public:
    MatiereManager(DatabaseManager& dbManager);
    bool createTable();
    bool addMatiere(int code, const QString &designation, int volumeHoraire);
    bool updateMatiere(int code, const QString &designation, int volumeHoraire);
    bool deleteMatiere(int code);

private:
    DatabaseManager& dbManager; // Référence à DatabaseManager
};

#endif // ENSEIGNANT_MANAGER_H
