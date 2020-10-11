#pragma once

using namespace std;

class Commission
{
	string fullName, gender; //ФИО, пол
	int sales = 0; //Количество продаж
	float salary = 0, percent = 0, wage = 0;
	/*Постоянная ставка, процент с продаж,
	общая зарплата*/
public:
	//Конструктор с параметрами, конструктор по-умолчанию
	Commission(string _fullName = "", 
		string _gender = "",
		float _salary = 0, 
		float _percent = 0) : 
		fullName{_fullName}, gender{_gender }, salary{_salary}, percent{_percent / 100} {}

	void Sell(int sales) //Функция добавления продаж
	{
		this->sales += sales;
	}

	int GetWork() //Функция вовзрата количества продаж
	{
		return sales;
	}

	float CalculateSalary() //Функция расчёта и возврата зарплаты
	{
		wage += salary + sales * salary * percent;
		sales = 0;
		return wage;
	}

	float GetWage() //Функция возврата общей зарплаты
	{
		return wage;
	}

	string GetName() //Функция возврата ФИО
	{
		return fullName;
	}

	string GetGender() //Функция возврата пола
	{
		return gender;
	}
};