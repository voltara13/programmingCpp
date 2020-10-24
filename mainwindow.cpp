#include"mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);//связывание формы и объекта MainWindow
    //установка валидаторов на поля ввода (см. [2])
    //используйте те названия, которые вы дали виджетам!
    ui->lineEditMax->setValidator(new QDoubleValidator());
    ui->lineEditMin->setValidator(new QDoubleValidator());
    ui->spinBox->setValue(1);
    //сигнал, несущий текст, соединяется со слотом, этот текст выводящим
    connect(this,SIGNAL(sendText(QString)),ui->plainTextEdit,
            SLOT(setPlainText(QString)));
    srand(QTime::currentTime().second());//инициализация генератора случайных чисел
}
void MainWindow::generate()
{
    bool notError=true;
    double min = ui->lineEditMin->text().toDouble(&notError);
    if(!notError) {//если нет ошибки преобразования строки в число
        emit sendText(tr("Invalid minimum value!"));
        return;
    }
    double max = ui->lineEditMax->text().toDouble(&notError);
    if(!notError) {
        emit sendText(tr("Invalid maximum value!"));
        return;
    }
    QString result;//в Qt есть также класс QStringBuilder, в более сложных случаях или для повышения
    //быстродействия лучше использовать его
    for(int i=0;i<ui->spinBox->value();i++) {
        result.append(QString::number((static_cast<double>(rand()
                                                           )/RAND_MAX)*
                                      (max-min)+min)+"\n");
        //QString::number преобразует число в строку
    }
    emit sendText(result);
}
MainWindow::~MainWindow()
{
    delete ui;//в конструкторе MainWindow память под объект ui выделяется явно оператором new, поэтому в деструкторе память обязательно нужно освободить
}
