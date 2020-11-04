#pragma once
#include "company.h"
using namespace std;

class hourly : public company
{
	int hour = 0;
	float incSalary = 0, norm = 0;
	/*Количество отработанных часов,
	повышенная зарплата в час
	норма часов*/
public:
	//Конструктор с параметрами, конструктор по-умолчанию
	hourly(string _fullName = "",
	       string _gender = "",
	       float _salary = 0,
	       float _incSalary = 0,
	       float _norm = 0) :
		company(_fullName, _gender, _salary),
		incSalary{_incSalary}, norm{_norm}
	{
	}

	void Work(int hour) override
	//Функция добавления часов
	{
		this->hour += hour;
	}

	void CalculateSalary() override
	//Функция расчёта зарплаты и обнуления выполненной работы
	{
		wage += (hour <= norm ? hour * GetSalary() : norm * GetSalary() + (hour - norm) * incSalary);
		hour = 0;
	}

	string GetWork() override
	//Функция возврата количества часов
	{
		return "почасовой, часы: " + to_string(hour);
	}

	string Serialize() override
	//Функция сериализации
	{
		stringstream ss;
		ss << "type=" << "h" << ';'
			<< "fullName=" << GetName() << ';'
			<< "gender=" << GetGender() << ';'
			<< "salary=" << GetSalary() << ';'
			<< "incSalary=" << incSalary << ';'
			<< "norm=" << norm << ';';
		return ss.str();
	}

	void Change(QListWidget *listWidget, int r) override
	{
		QDialog *d = new QDialog(listWidget);
		QFormLayout *box = new QFormLayout;
		QLineEdit *lineEditName = new QLineEdit(QString::fromStdString(fullName), d);
		QLineEdit *lineEditGender = new QLineEdit(QString::fromStdString(gender), d);
		QLineEdit *lineEditSalary = new QLineEdit(QString::number(salary), d);
		QLineEdit *lineEditIncSalary = new QLineEdit(QString::number(incSalary), d);
		QLineEdit *lineEditNorm = new QLineEdit(QString::number(norm), d);
		QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
		QObject::connect(buttonBox, SIGNAL(accepted()), d, SLOT(accept()));
		lineEditSalary->setValidator(new QDoubleValidator());
		lineEditIncSalary->setValidator(new QDoubleValidator());
		lineEditNorm->setValidator(new QDoubleValidator());
		d->setWindowTitle(QTranslator::tr("Введите данные работника"));
		d->setWindowFlags(Qt::Drawer);
		box->addRow(QTranslator::tr("ФИО:"), lineEditName);
		box->addRow(QTranslator::tr("Пол:"), lineEditGender);
		box->addRow(QTranslator::tr("Ставка за час:"), lineEditSalary);
		box->addRow(QTranslator::tr("Повыш. ставка за час:"), lineEditIncSalary);
		box->addRow(QTranslator::tr("Норма часов:"), lineEditNorm);
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
			incSalary = lineEditIncSalary->text().toDouble();
			norm = lineEditNorm->text().toDouble();
			listWidget->insertItem(r, lineEditName->text());
			listWidget->setCurrentRow(r);
		}
	}
};
