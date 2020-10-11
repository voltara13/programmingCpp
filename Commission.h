#pragma once
#include "Company.h"
using namespace std;

class Commission : public Company
{
	int work = 0;
	float percent = 0;
	/*Количество продаж,
	процент с одной продажи*/
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

	string GetWork() //Функция вовзрата количества продаж
	{
		return "комиссионный, продажи: " + to_string(work);
	}

	void CalculateSalary() //Функция расчёта зарплаты и обнуления выполненной работы
	{
		wage += GetSalary() + work * GetSalary() * percent;
		work = 0;
	}
};