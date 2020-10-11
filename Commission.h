﻿#pragma once
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
		percent{ _percent } {}

	void Work(int sales) //Функция добавления продаж
	{
		this->work += sales;
	}

	void CalculateSalary() //Функция расчёта зарплаты и обнуления выполненной работы
	{
		wage += GetSalary() + GetSalary() * work * percent / 100;
		work = 0;
	}

	string GetWork() //Функция вовзрата количества продаж
	{
		return "комиссионный, продажи: " + to_string(work);
	}

	string Serialize()
	{
		stringstream ss;
		ss << "type=" << "c" << ';'
			<< "fullName=" << GetName() << ';'
			<< "gender=" << GetGender() << ';'
			<< "salary=" << GetSalary() << ';'
			<< "percent=" << GetPercent() << ';';
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