#pragma once
#include "company.h"
using namespace std;

class commission : public company
{
	int work = 0;
	float percent = 0;
	/*Количество продаж,
	процент с одной продажи*/
public:
	//Конструктор с параметрами, конструктор по-умолчанию
	commission(string _fullName = "",
	           string _gender = "",
	           float _salary = 0,
	           float _percent = 0) :
		company(_fullName, _gender, _salary),
		percent{_percent}
	{
	}

	void Work(int sales) override
	//Функция добавления продаж
	{
		this->work += sales;
	}

	void CalculateSalary() override
	//Функция расчёта зарплаты и обнуления выполненной работы
	{
		wage += GetSalary() + GetSalary() * work * percent / 100;
		work = 0;
	}

	string GetWork() override
	//Функция вовзрата количества продаж
	{
		return "комиссионный, продажи: " + to_string(work);
	}

	string Serialize() override
	//Функция сериализации
	{
		stringstream ss;
		ss << "type=" << "c" << ';'
			<< "fullName=" << GetName() << ';'
			<< "gender=" << GetGender() << ';'
			<< "salary=" << GetSalary() << ';'
			<< "percent=" << percent << ';';
		return ss.str();
	}

	void Change(QListWidget *listWidget, int r) override
	{
		QDialog *d = new QDialog(listWidget);
		QFormLayout *box = new QFormLayout;
		QLineEdit *lineEditName = new QLineEdit(QString::fromStdString(fullName), d);
		QLineEdit *lineEditGender = new QLineEdit(QString::fromStdString(gender), d);
		QLineEdit *lineEditSalary = new QLineEdit(QString::number(salary), d);
		QLineEdit *lineEditPercent = new QLineEdit(QString::number(percent), d);
		QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
		QObject::connect(buttonBox, SIGNAL(accepted()), d, SLOT(accept()));
		lineEditSalary->setValidator(new QDoubleValidator());
		lineEditPercent->setValidator(new QDoubleValidator());
		d->setWindowTitle(QTranslator::tr("Введите данные работника"));
		d->setWindowFlags(Qt::Drawer);
		box->addRow(QTranslator::tr("ФИО:"), lineEditName);
		box->addRow(QTranslator::tr("Пол:"), lineEditGender);
		box->addRow(QTranslator::tr("Оклад:"), lineEditSalary);
		box->addRow(QTranslator::tr("Процент за продажу:"), lineEditPercent);
		box->addRow(buttonBox);
		d->setLayout(box);

		int result = d->exec();
		if (result == QDialog::Accepted && !lineEditName->text().isEmpty())
		{
			QListWidgetItem *item = listWidget->takeItem(r);
			delete item;
			fullName = lineEditName->text().toStdString();
			gender = lineEditGender->text().toStdString();
			salary = lineEditSalary->text().toDouble();;
			percent = lineEditPercent->text().toDouble();
			listWidget->insertItem(r, lineEditName->text());
			listWidget->setCurrentRow(r);
		}
	}
};
