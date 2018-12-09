#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <model/personsmodel.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_refresh_clicked();

    void on_changePerson_clicked();

    void on_create_clicked();

    void on_remove_clicked();

    void on_unemployedPersons_clicked();

    void on_allPersons_clicked();

    void on_employedPersons_clicked();

private:
    Ui::MainWindow *ui;
    PersonsModel *personsModel;
};

#endif // MAINWINDOW_H
