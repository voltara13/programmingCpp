#pragma once
#include "Company.h"
using namespace std;

class Commission : public Company
{
	int work = 0;
	float percent = 0;
	/*Количество продаж,
	процент с одной продажи*/
	const char end_of_tag = ';';
public:
	//Конструктор с параметрами, конструктор по-умолчанию
	Commission(string _fullName = "",
		string _gender = "",
		float _salary = 0,
		float _percent = 0) :
		Company(_fullName, _gender, _salary),
		percent{ _percent / 100 } {}

	void Work(int sales) //Функция добавления продаж
	{
		this->work += sales;
	}

	void CalculateSalary() //Функция расчёта зарплаты и обнуления выполненной работы
	{
		wage += GetSalary() + work * GetSalary() * percent;
		work = 0;
	}

	string GetWork() //Функция вовзрата количества продаж
	{
		return "комиссионный, продажи: " + to_string(work);
	}

	string serialize()
	{
		stringstream ss;
		ss << "type=" << "c" << end_of_tag
			<< "fullName=" << GetName() << end_of_tag
			<< "gender=" << GetGender() << end_of_tag
			<< "salary=" << GetSalary() << end_of_tag
			<< "percent=" << GetPercent() << end_of_tag;
		return ss.str();
	}

	float GetPercent()
	{
		return percent;
	}

	float GetIncSalary()
	{
		return 0;
	}

	float GetNorm()
	{
		return 0;
	}
};