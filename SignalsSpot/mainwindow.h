//@author Мальцева К.В

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


//Слот это функция, которая вызывается в ответ на определенный сигнал
signals:
    void resultReady(double salaryAfterTax); /*Сигнал для вывода зарплаты*/


private slots:
    void calculate(); /*Слоты-обработчики нажатий кнопок*/
    void clear();

    void slotMessage(double salaryAfterTax); /*Слот,  вывод на форму зарабатную плату*/
};
#endif // MAINWINDOW_H
