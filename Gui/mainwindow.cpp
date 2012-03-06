#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //edt = new QSchedule();

    /*QScrollArea *scroll = new QScrollArea;
    scroll->setWidget(edt);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(scroll);
    ui->centralWidget->setLayout(layout);*/

    QDate date = QDate::currentDate();

    ui->edt->setDate(date);
    
    QObject::connect(ui->calendarWidget, SIGNAL(clicked(QDate)), this, SLOT(changeDate(QDate)));
    QObject::connect(ui->addTimeSlotButton, SIGNAL(clicked()), this, SLOT(openEditTimeSlot())); 
}

void MainWindow::addTimeSlot() {
    /*ui->edt->addTimeSlot(ui->calendarWidget->selectedDate(), ui->timeEdit->time().hour(), ui->timeEdit->time().minute(), ui->lineEdit_2->text().toInt(),
                     "TD", "salle 008", "S32I010 Bases de donnees 2", "MEKAOUCHE, Abdelouahab", "602");*/
}

void MainWindow::removeTimeSlot() {
    //ui->edt->removeTimeSlot(ui->lineEdit->text().toInt());
}

void MainWindow::changeDate(QDate date) {
    ui->edt->setDate(date);
}

void MainWindow::openEditTimeSlot() {
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
