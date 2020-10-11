#pragma once
#include "Company.h"
using namespace std;

class Hourly : public Company
{
	int hour = 0;
	float incSalary = 0, norm = 0;
	/*Количество отработанных часов,
	повышенная зарплата в час
	норма часов*/
public:
	//Конструктор с параметрами, конструктор по-умолчанию
	Hourly(string _fullName = "",
		string _gender = "",
		float _salary = 0,
		float _incSalary = 0,
		float _norm = 0) :
		Company(_fullName, _gender, _salary),
		incSalary{ _incSalary }, norm{ _norm } {}

	void Work(int hour) //Функция добавления часов
	{
		this->hour += hour;
	}

	void CalculateSalary() //Функция расчёта зарплаты и обнуления выполненной работы
	{
		wage += (hour <= norm ? hour * GetSalary() : norm * GetSalary() + (hour - norm) * incSalary);
		hour = 0;
	}

	string GetWork() //Функция возврата количества часов
	{
		return "почасовой, часы: " + to_string(hour);
	}

	string Serialize() //Функция сериализации
	{
		stringstream ss;
		ss	<< "type="		<< "h"			<< ';'
			<< "fullName="	<< GetName()	<< ';'
			<< "gender="	<< GetGender()	<< ';'
			<< "salary="	<< GetSalary()	<< ';'
			<< "incSalary="	<< incSalary	<< ';'
			<< "norm="		<< norm			<< ';';
		return ss.str();
	}
};

