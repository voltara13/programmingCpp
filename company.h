#pragma once
using namespace std;

class company
{
protected:
	string fullName, gender;
	float salary;
	float wage = 0;
	/*ФИО, пол, оклад, полная зарплата*/
public:
	virtual void CalculateSalary() = 0; //Виртуальная функция расчета полной зарплаты
	virtual void Work(int work) = 0; //Виртуальная функция добавления работы
	virtual void Change(QListWidget *listWidget, int r) = 0;
	virtual string GetWork() = 0; //Виртуальная функция получения количества выполненной работы
	virtual string Serialize() = 0; //Виртуальная функция сериализации
	//Конструктор с параметрами, конструктор по-умолчанию
	company(string _fullName = "", string _gender = "", float _salary = 0) :
		fullName(_fullName), gender(_gender), salary(_salary)
	{
	}

	string GetName() //Функция возврата ФИО
	{
		return fullName;
	}

	string GetGender() //Функция возврата пола
	{
		return gender;
	}

	float GetSalary() //Функция возврата зарплаты
	{
		return salary;
	}

	float GetWage() //Функция возврата общей зарплаты
	{
		return wage;
	}

	string Print()
	{
		stringstream out;
		out << "ФИО: " << GetName() <<
			", пол: " << GetGender() <<
			", тип: " << GetWork() <<
			", зарплата: " << GetSalary() <<
			", общая зарплата: " << GetWage() << endl;
		return out.str();
	}	
};