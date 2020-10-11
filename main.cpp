#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "Hourly.h"
#include "Commission.h"
using namespace std;

/*Создаём два глобальных вектора с работниками 
двух разных классов: почасовой оплатой труда
и с коммиссионной*/

vector<Hourly> hourlyWorkers;
vector<Commission> commissionWorkers;

bool Check() //Функция проверки списков на пустоту
{
	if (hourlyWorkers.size() || commissionWorkers.size()) return true;

	else
	{
		cout << "Не добавлено ни одного работника. Списки пусты\n";
		return false;
	}
}

void PutList() //Функция вывода обоих списков
{
	if (!Check()) return;

	if (hourlyWorkers.size())
	{
		cout << "\nПочасовые работники:\n";
		for (int i = 0; i < hourlyWorkers.size(); ++i)
			cout << i + 1 << ". " << hourlyWorkers[i].GetName() <<
			", часы: " << hourlyWorkers[i].GetWork() <<
			", зарплата: " << hourlyWorkers[i].GetWage() <<
			", пол: " << hourlyWorkers[i].GetGender() << endl;
	}

	if (commissionWorkers.size())
	{
		cout << "\nКоммиссионные работники:\n";
		for (int i = 0; i < commissionWorkers.size(); ++i)
			cout << i + 1 << ". " << commissionWorkers[i].GetName() <<
			", продажи: " << commissionWorkers[i].GetWork() <<
			", зарплата: " << commissionWorkers[i].GetWage() << 
			", пол: " << commissionWorkers[i].GetGender() << endl;
	}

	cout << endl;
}

void Change() //Функция добавления часов/продаж работникам
{
	if (!Check()) return;
	PutList();
	int ans;
	float work;

	cout << "Выберите тип работника:\n" <<
		"1 - Почасовой\n" <<
		"2 - Комиссионный\n" <<
		"ВВОД: ";

	cin >> ans;

	switch (ans)
	{
	case 1:
		cout << "\nВведите номер работника: ";
		cin >> ans;
		cout << "Введите количество добавляемых часов: ";
		cin >> work;
		hourlyWorkers[ans - 1].Work(work);
		break;

	case 2:
		cout << "\nВведите номер работника: ";
		cin >> ans;
		cout << "Введите количество добавляемых продаж: ";
		cin >> work;
		commissionWorkers[ans - 1].Sell(work);
		break;

	default:
		cout << "Выбран неверный вариант. Попробуйте ещё раз.\n";
	}
}

void CalculateWage() //Функция расчёта зарплаты
{
	if (!Check()) return;
	PutList();
	int ans;

	cout << "Выберите тип работника:\n" <<
		"1 - Почасовой\n" <<
		"2 - Комиссионный\n" <<
		"ВВОД: ";

	while (true)
	{
		cin >> ans;
		switch (ans)
		{
		case 1:
			cout << "\nВведите номер работника: ";
			cin >> ans;
			hourlyWorkers[ans - 1].CalculateSalary();
			return;

		case 2:
			cout << "\nВведите номер работника: ";
			cin >> ans;
			commissionWorkers[ans - 1].CalculateSalary();
			return;

		default:
			cout << "Выбран неверный вариант. Попробуйте ещё раз.\n";
		}
	}
}

void AddWorker() //Функция добавления нового работника
{
	string fullName, gender;
	float salary, incSalary, percent, norm;
	cout << "Введите ФИО работника: ";
	/*Игнорируем символ новой строки
	чтобы была возможность нормально считать
	фразу из потока ввода*/
	cin.ignore(32767, '\n');
	getline(cin, fullName);
	cout << "Введите пол работника: ";
	cin >> gender;
	int ans;

	cout << "Выберите тип работника:\n" <<
		"1 - Почасовой\n" <<
		"2 - Комиссионный\n" <<
		"ВВОД: ";

	while (true)
	{
		cin >> ans;
		switch (ans)
		{
		case 1:
			cout << "Введите ставку за час: ";
			cin >> salary;
			cout << "Введите повышенную ставку за час: ";
			cin >> incSalary;
			cout << "Введите норму часов: ";
			cin >> norm;
			hourlyWorkers.push_back(Hourly(fullName, gender, salary, incSalary, norm));
			return;

		case 2:
			cout << "Введите фиксированный оклад: ";
			cin >> salary;
			cout << "Введите процент за каждую продажу: ";
			cin >> percent;
			commissionWorkers.push_back(Commission(fullName, gender, salary, percent));
			return;

		default:
			cout << "Выбран неверный вариант. Попробуйте ещё раз.\n";
		}
	}
}

void Menu() //Функция селектора меню
{
	int ans;
	while (true)
	{
		cout << "\nСИСТЕМА РАСЧЁТА ЗАРПЛАТЫ\n\n" <<
			"Введите:\n" <<
			"1 - Чтобы добавить работника\n" <<
			"2 - Чтобы вывести список работников\n" <<
			"3 - Чтобы добавить работнику часы/продажи\n" <<
			"4 - Чтобы расчитать зарплату работнику\n" <<
			"0 - Чтобы выйти из программы\n" <<
			"ВВОД: ";

		cin >> ans;

		switch (ans)
		{
		case 1:
			AddWorker();
			break;
		case 2:
			PutList();
			break;
		case 3:
			Change();
			break;
		case 4:
			CalculateWage();
			break;
		case 0:
			exit(0);
		default:
			cout << "Выбран неверный вариант. Попробуйте ещё раз";
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu();
	return 0;
}
