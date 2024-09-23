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

QSqlDatabase& DatabaseManager::getConnection()
{
    return DB_Connection;
}
