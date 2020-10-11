#pragma once
#include <sstream>
#include <fstream>
using namespace std;

class Company
{
	string fullName, gender;
	float salary;
	/*ФИО, пол, оклад*/
protected:
	float wage = 0; //Полная зарплата
public:
	virtual void CalculateSalary() = 0; //Виртуальная функция расчёта полной зарплаты
	virtual void Work(int work) = 0; //Виртуальная функция добавления работы
	virtual string GetWork() = 0; //Виртуальная функция получения количества выполненной работы
	virtual string Serialize() = 0;
	virtual float GetIncSalary() = 0; //Виртуальная функция получения повышенной ставки за час
	virtual float GetNorm() = 0; //Виртуальная функция получения нормы часов
	virtual float GetPercent() = 0; //Виртуальная функция получения процента за продажу
	friend ostream &operator << (ostream &out, Company &worker); //Дружественный перегруженный оператор вывода
	//Конструктор с параметрами, конструктор по-умолчанию
	Company(string _fullName = "", string _gender = "", float _salary = 0) :
		fullName(_fullName), gender(_gender), salary(_salary) {}

	static void SimulateWork(int day, vector<Company *> &workers)
	{
		srand(time(0));
		cout << "\nСИМУЛЯЦИЯ НАЧАЛАСЬ\n";
		for (int i = 1; i <= day; i++)
		{
			cout << "День " << i << endl;
			for (auto *it : workers) it->Work(1 + rand() % 10);
			if (i % 15 == 0)
			{
				cout << "ДЕНЬ РАСЧЁТА ЗАРПЛАТЫ\n";
				for (auto *it : workers) it->CalculateSalary();
			}
			for (auto *it : workers) cout << *it;			
		}
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

	//static vector<Company *> DeserializeVector()
	//{
	//	fstream fs;
	//	fs.open("serialize.txt", ios::in | ios::binary);
	//	for (string temp; getline(fs, temp, end_of_struct);)
	//	{
	//		
	//	}
	//	fs.close();
	//}
};

ostream &operator << (ostream &out, Company &worker)
{
	out	<<	"ФИО: "				 << worker.GetName() <<
			", пол: "			 << worker.GetGender() <<
			", тип: "			 << worker.GetWork() <<
			", зарплата: "		 << worker.GetSalary() <<
			", общая зарплата: " << worker.GetWage() << endl;
	return out;
}