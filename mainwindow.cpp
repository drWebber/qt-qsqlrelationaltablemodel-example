#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    personsModel = new PersonsModel(this);
    personsModel->select();
    ui->personsView->setModel(personsModel);
    ui->personsView->horizontalHeader()->setSectionResizeMode(
                QHeaderView::ResizeToContents);
    ui->personsView->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_refresh_clicked()
{
    personsModel->select();
}

void MainWindow::on_changePerson_clicked()
{
    QModelIndex index = ui->personsView->currentIndex();
    Person person = personsModel->personAt(ui->personsView->currentIndex());
    person.setName(ui->name->text());

    personsModel->save(index.row(), person);
}

void MainWindow::on_create_clicked()
{
    QString name = ui->name->text();
    Person person = Person().setName(name)
            .setEmail(name.toLower() + "@gmail.com")
            .setStatus(Person::UNEMPLOYED);
    personsModel->create(person);
}

void MainWindow::on_remove_clicked()
{
    QModelIndex index = ui->personsView->currentIndex();
    personsModel->remove(index);
}

void MainWindow::on_unemployedPersons_clicked()
{
    personsModel->queryUnemployed();
}

void MainWindow::on_allPersons_clicked()
{
    personsModel->queryAll();
}

void MainWindow::on_employedPersons_clicked()
{
    personsModel->queryEmployed();
}
