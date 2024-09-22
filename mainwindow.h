#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void VERIFICATION_DATABASE();
    void clearFields();

private:
    Ui::MainWindow *ui;
    DatabaseManager dbManager; // Assurez-vous que dbManager est déclaré ici
};

#endif // MAINWINDOW_H
