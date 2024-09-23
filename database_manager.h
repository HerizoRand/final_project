#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCoreApplication>

class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();

    bool connectDatabase();
    // Getter pour la connexion à la base de données
    QSqlDatabase& getConnection();

private:
    QSqlDatabase DB_Connection;
};

#endif // DATABASE_MANAGER_H
