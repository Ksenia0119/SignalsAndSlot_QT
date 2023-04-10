//@author Мальцева К.В

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
     // Подключаем к кнопкам слоты
    // Подключение сигнала от кнопки calculateButton к слоту calculate
    connect(ui->calculateButton, SIGNAL(clicked()), this, SLOT(calculate()));
    // Подключение сигнала от кнопки clearButton к слоту clear
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clear()));


    // Соединяем сигнал и слот

     connect(this,&MainWindow::resultReady,this,&MainWindow::slotMessage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculate()
{
    // Получаем значения с формы
    double salary = ui->plainTextEdit_salary->toPlainText().toDouble();
    double taxRate = ui->plainTextEdit_tax->toPlainText().toDouble();

    // Считаем зп после налога
    double salaryAfterTax = salary * (1 - (taxRate / 100));


    // Оповещаем о готовности результата вычислений
        emit resultReady(salaryAfterTax);


    // Выводим результат
    //ui->outputLabel->setText("Зарплата с вычетом налога составит: " + QString::number(salaryAfterTax));
}

void MainWindow::slotMessage(double  salaryAfterTax)
{

    ui->textEdit->append("Зарплата с вычетом налога составит: " + QString::number(salaryAfterTax));
}
void MainWindow::clear()
{
    // Очищаем
    ui->plainTextEdit_salary->clear();
    ui->plainTextEdit_tax->clear();
    ui->outputLabel->clear();
    ui->textEdit->clear();
}
