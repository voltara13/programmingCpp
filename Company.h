#pragma once
#include <sstream>
#include <fstream>
using namespace std;

class Company
{
	string fullName, gender;
	float salary;
	/*ФИО, пол, оклад*/
	static const char end_of_struct = '^';
protected:
	float wage = 0; //Полная зарплата
public:
	virtual void CalculateSalary() = 0; //Виртуальная функция расчёта полной зарплаты
	virtual void Work(int work) = 0; //Виртуальная функция добавления работы
	virtual string GetWork() = 0; //Виртуальная функция получения количества выполненной работы
	virtual string serialize() = 0;
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

    //Company *deserialize_h(const string &data)
    //{
    //    Company *worker = nullptr;
    //    string fullName, gender;
    //    float salary, incSalary, norm;
    //    stringstream ss(data);
    //    for (string token; getline(ss, token, end_of_tag);)
    //    {
    //        size_t found = token.find('=');
    //        string tag = token.substr(0, found);
    //        string value = token.substr(found + 1, token.length());

    //        if (tag == "fullName") fullName = value;
    //        else if (tag == "gender") gender = value;
    //        else if (tag == "salary") salary = atof(value.c_str());
    //        else if (tag == "incSalary") incSalary = atof(value.c_str());
    //        else if (tag == "norm") norm = atof(value.c_str());
    //    }
    //    worker = new Hourly(fullName, gender, salary, incSalary, norm);
    //    return worker;
    //}

    //Company *deserialize_c(const string &data)
    //{
    //    Company *worker = nullptr;
    //    string fullName, gender;
    //    float salary, percent;
    //    stringstream ss(data);
    //    for (string token; getline(ss, token, end_of_tag);)
    //    {
    //        size_t found = token.find('=');
    //        string tag = token.substr(0, found);
    //        string value = token.substr(found + 1, token.length());

    //        if (tag == "fullName") fullName = value;
    //        else if (tag == "gender") gender = value;
    //        else if (tag == "salary") salary = atof(value.c_str());
    //        else if (tag == "percent") percent = atof(value.c_str());
    //    }
    //    worker = new Commission(fullName, gender, salary, percent);
    //    return worker;
    //}

    static void serialize_vector(vector<Company *> &workers)
    {
        fstream fs("serialize.txt", ios::app | ios::binary);
        for (auto *it : workers) fs << it->serialize() << end_of_struct;
        fs.close();

    }
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