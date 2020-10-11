#pragma once

using namespace std;

class Hourly
{
	string fullName, gender; //ФИО, пол
	float hour = 0, salary = 0, incSalary = 0, norm = 0, wage = 0;
	/*Количество отработанных часов, 
	зарплата в час, повышенная зарплата в час
	норма часов, общая зарплата*/
public:
	//Конструктор с параметрами, конструктор по-умолчанию
	Hourly(string _fullName = "", 
		string _gender = "",
		float _salary = 0, 
		float _incSalary = 0, 
		float _norm = 0) :
		fullName{_fullName}, gender{_gender}, salary{_salary}, incSalary{_incSalary}, norm{_norm} {}

	void Work(float hour) //Функция добавления количества отработанных часов
	{
		this->hour += hour;
	}

	float GetWork() //Функция возврата количества часов
	{
		return hour;
	}

	float GetWage() //Функция возврата общей зарплаты
	{
		return wage;
	}

	float CalculateSalary() //Функция расчёта и возврата зарплаты
	{
		wage += (hour <= norm ? hour * salary : norm * salary + (hour - norm) * incSalary);
		hour = 0;
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