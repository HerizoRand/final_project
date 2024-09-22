#include "enseignant_manager.h"
#include "database_manager.h"

EnseignantManager::EnseignantManager(DatabaseManager& dbManager) : dbManager(dbManager)
{
}

bool EnseignantManager::createTable() {
    return dbManager.createTable();
}

bool EnseignantManager::addEnseignant(int matricule, const QString &nom, const QString &prenom, int tauxHoraire) {
    return dbManager.addEnseignant(matricule, nom, prenom, tauxHoraire);
}

bool EnseignantManager::updateEnseignant(int matricule, const QString &nom, const QString &prenom, int tauxHoraire) {
    return dbManager.updateEnseignant(matricule, nom, prenom, tauxHoraire);
}

bool EnseignantManager::deleteEnseignant(int matricule) {
    return dbManager.deleteEnseignant(matricule);
}
