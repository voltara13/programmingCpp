#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <ctime>
#include "Hourly.h"
#include "Commission.h"
using namespace std;

#define wrongChoice cerr << "\nВыбран неверный вариант. Попробуйте ещё раз\n";

vector<Company*> companyWorkers;

bool Check() //Функция проверки вектора на пустоту
{
	if (!companyWorkers.empty()) return true;
	cout << "\nНе добавлено ни одного работника. Список пуст\n";
	return false;
}

void Dismiss() //Функция увольнения
{
	int worker;
	while (true)
	{
		cout << "\nВведите номер работника ('0' - Вернуться назад): ";
		cin >> worker;
		if (!worker) return;
		try
		{
			companyWorkers.at(worker - 1);
			companyWorkers.erase(companyWorkers.cbegin() + worker - 1);
		}
		catch (const out_of_range)
		{
			wrongChoice;
			continue;
		}
		cout << "Работник успешно уволен\n";
		break;
	}
}

void AddWorker() //Функция добавления нового работника
{
	string fullName, gender;
	float salary, incSalary, percent, norm;
	int group;
	Company* worker = nullptr;

	cout << "\nВыберите тип работника:\n" <<
		"'1' - Почасовой\n'2' - Комиссионный\n" <<
		"'Другой вариант' - Вернуться назад\nВВОД: ";
	cin >> group;
	if (group != 1 && group != 2) return;
	cout << "Введите ФИО работника: ";
	cin.ignore(32767, '\n');
	/*Игнорируем символ новой строки
	чтобы была возможность нормально считать
	фразу из потока ввода*/
	getline(cin, fullName);
	cout << "Введите пол работника: ";
	cin >> gender;

	switch (group)
	{
	case 1:
		cout << "Введите ставку за час: ";
		cin >> salary;
		cout << "Введите повышенную ставку за час: ";
		cin >> incSalary;
		cout << "Введите норму часов: ";
		cin >> norm;
		worker = new Hourly(fullName, gender, salary, incSalary, norm);
		companyWorkers.push_back(worker);
		break;
	case 2:
		cout << "Введите фиксированный оклад: ";
		cin >> salary;
		cout << "Введите процент за каждую продажу: ";
		cin >> percent;
		worker = new Commission(fullName, gender, salary, percent);
		companyWorkers.push_back(worker);
		break;
	}
}

void PutList() //Функция вывода вектора
{
	for (unsigned int i = 0; i < companyWorkers.size(); ++i)
		cout << i + 1 << ". " << *companyWorkers[i];
}

void SimulateWork() //Функция симуляции работы
{
	int day;
	cout << "Введите количество дней, сколько моделировать работу ('0' - Вернуться назад): ";
	cin >> day;
	if (!day) return;
	Company::SimulateWork(day, companyWorkers);
}

void Menu() //Функция селектора меню
{
	int ans;
	while (true)
	{
		cout << "\nСИСТЕМА РАСЧЁТА ЗАРПЛАТЫ\n\n" <<
			"Введите:\n" <<
			"'1' - Чтобы добавить работника\n" <<
			"'2' - Чтобы вывести список работников\n" <<
			"'3' - Чтобы уволить работника\n" <<
			"'4' - Чтобы смоделировать работу\n" <<
			"'0' - Чтобы выйти из программы\n" <<
			"ВВОД: ";

		cin >> ans;
		if ((ans != 0 && ans != 1) && !Check()) continue;
		switch (ans)
		{
		case 1:
			AddWorker();
			break;
		case 2:
			PutList();
			break;
		case 3:
			Dismiss();
			break;
		case 4:
			SimulateWork();
			break;
		case 0:
			exit(0);
		default:
			wrongChoice;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Menu();
	for (auto pObj = companyWorkers.begin(); pObj != companyWorkers.end(); ++pObj)
		delete *pObj;
	companyWorkers.clear();
	return 0;
}
