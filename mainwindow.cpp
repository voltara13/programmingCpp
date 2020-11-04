#include "mainwindow.h"

mainwindow::mainwindow(QWidget* parent)
	: QWidget(parent)
{
	QVBoxLayout* vbox = new QVBoxLayout;
	vbox->setSpacing(10);

	QHBoxLayout* hbox = new QHBoxLayout(this);

	listWidget = new QListWidget(this);

	addButton = new QPushButton(tr("Добавить работника"), this);
	renameButton = new QPushButton(tr("Изменить работника"), this);
	modelingButton = new QPushButton(tr("Провести моделирование"), this);
	removeButton = new QPushButton(tr("Удалить работника"), this);
	cleanButton = new QPushButton(tr("Удалить всех работников"), this);
	serializeButton = new QPushButton(tr("Сериализация"), this);
	deserializeButton = new QPushButton(tr("Десериализация"), this);

	vbox->setSpacing(3);
	vbox->addStretch(1);
	vbox->addWidget(addButton);
	vbox->addWidget(renameButton);
	vbox->addWidget(modelingButton);
	vbox->addWidget(removeButton);
	vbox->addWidget(cleanButton);
	vbox->addWidget(serializeButton);
	vbox->addWidget(deserializeButton);
	vbox->addStretch(1);

	hbox->addWidget(listWidget);
	hbox->addSpacing(15);
	hbox->addLayout(vbox);

	connect(addButton, &QPushButton::clicked, this, &mainwindow::addItem);
	connect(renameButton, &QPushButton::clicked, this, &mainwindow::changeItem);
	connect(modelingButton, &QPushButton::clicked, this, &mainwindow::modeling);
	connect(removeButton, &QPushButton::clicked, this, &mainwindow::removeItem);
	connect(cleanButton, &QPushButton::clicked, this, &mainwindow::clearItems);
	connect(serializeButton, &QPushButton::clicked, this, &mainwindow::serialize);
	connect(deserializeButton, &QPushButton::clicked, this, &mainwindow::deserialize);

	setLayout(hbox);
}

company *mainwindow::deserializeHourly(const string &data)
{
	company *worker = nullptr;
	string fullName, gender;
	float salary, incSalary, norm;
	stringstream ss(data);
	for (string token; getline(ss, token, ';');)
	{
		size_t found = token.find('=');
		string tag = token.substr(0, found);
		string value = token.substr(found + 1, token.length());

		if (tag == "fullName") fullName = value;
		else if (tag == "gender") gender = value;
		else if (tag == "salary") salary = atof(value.c_str());
		else if (tag == "incSalary") incSalary = atof(value.c_str());
		else if (tag == "norm") norm = atof(value.c_str());
	}
	worker = new hourly(fullName, gender, salary, incSalary, norm);
	listWidget->addItem(QString::fromStdString(fullName));
	int r = listWidget->count() - 1;
	listWidget->setCurrentRow(r);
	return worker;
}

company *mainwindow::deserializeCommission(const string &data)
{
	company *worker = nullptr;
	string fullName, gender;
	float salary, percent;
	stringstream ss(data);
	for (string token; getline(ss, token, ';');)
	{
		size_t found = token.find('=');
		string tag = token.substr(0, found);
		string value = token.substr(found + 1, token.length());

		if (tag == "fullName") fullName = value;
		else if (tag == "gender") gender = value;
		else if (tag == "salary") salary = atof(value.c_str());
		else if (tag == "percent") percent = atof(value.c_str());
	}
	worker = new commission(fullName, gender, salary, percent);
	listWidget->addItem(QString::fromStdString(fullName));
	int r = listWidget->count() - 1;
	listWidget->setCurrentRow(r);
	return worker;
}

void mainwindow::addItem()
{
	QDialog *d = new QDialog();
	QVBoxLayout *vbox = new QVBoxLayout;
	QRadioButton *radioButton = new QRadioButton("Часовой", d);
	QRadioButton *radioButton2 = new QRadioButton("Комиссионный", d);
	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok, d);
	
	connect(buttonBox, SIGNAL(accepted()), d, SLOT(accept()));
	d->setWindowTitle("Выберите тип");
	d->setWindowFlags(Qt::Drawer);
	vbox->addWidget(radioButton);
	vbox->addWidget(radioButton2);
	vbox->addWidget(buttonBox);
	d->setLayout(vbox);
	
	bool result = d->exec();
	if (result == QDialog::Accepted)
	{
		if (radioButton->isChecked()) addItemHourlyDialog();
		if (radioButton2->isChecked()) addItemCommissionDialog();
	}
}

void mainwindow::addItemHourlyDialog()
{
	company *worker = nullptr;
	QDialog *d = new QDialog(this);
	QFormLayout *box = new QFormLayout;
	QLineEdit *lineEditName = new QLineEdit(d);
	QLineEdit *lineEditGender = new QLineEdit(d);
	QLineEdit *lineEditSalary = new QLineEdit(d);
	QLineEdit *lineEditIncSalary = new QLineEdit(d);
	QLineEdit *lineEditNorm = new QLineEdit(d);
	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
	
	connect(buttonBox, SIGNAL(accepted()), d, SLOT(accept()));
	lineEditSalary->setValidator(new QDoubleValidator());
	lineEditIncSalary->setValidator(new QDoubleValidator());
	lineEditNorm->setValidator(new QDoubleValidator());
	d->setWindowTitle(tr("Введите данные работника"));
	d->setWindowFlags(Qt::Drawer);
	box->addRow(tr("ФИО:"), lineEditName);
	box->addRow(tr("Пол:"), lineEditGender);
	box->addRow(tr("Ставка за час:"), lineEditSalary);
	box->addRow(tr("Повыш. ставка за час:"), lineEditIncSalary);
	box->addRow(tr("Норма часов:"), lineEditNorm);
	box->addRow(buttonBox);
	d->setLayout(box);

	int result = d->exec();
	if (result == QDialog::Accepted)
	{
		bool notError = true;
		string fullName = lineEditName->text().toStdString();
		string gender = lineEditGender->text().toStdString();
		double salary = lineEditSalary->text().toDouble();
		double incSalary = lineEditIncSalary->text().toDouble();
		double norm = lineEditNorm->text().toDouble();
		worker = new hourly(fullName, gender, salary, incSalary, norm);
		companyWorkers.push_back(worker);
		listWidget->addItem(lineEditName->text());
		int r = listWidget->count() - 1;
		listWidget->setCurrentRow(r);
	}
}

void mainwindow::addItemCommissionDialog()
{
	company *worker = nullptr;
	QDialog *d = new QDialog(this);
	QFormLayout *box = new QFormLayout;
	QLineEdit *lineEditName = new QLineEdit(d);
	QLineEdit *lineEditGender = new QLineEdit(d);
	QLineEdit *lineEditSalary = new QLineEdit(d);
	QLineEdit *lineEditPercent = new QLineEdit(d);
	
	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
	connect(buttonBox, SIGNAL(accepted()), d, SLOT(accept()));
	lineEditSalary->setValidator(new QDoubleValidator());
	lineEditPercent->setValidator(new QDoubleValidator());
	d->setWindowTitle(tr("Введите данные работника"));
	d->setWindowFlags(Qt::Drawer);
	box->addRow(tr("ФИО:"), lineEditName);
	box->addRow(tr("Пол:"), lineEditGender);
	box->addRow(tr("Оклад:"), lineEditSalary);
	box->addRow(tr("Процент за продажу:"), lineEditPercent);
	box->addRow(buttonBox);
	d->setLayout(box);

	int result = d->exec();
	if (result == QDialog::Accepted)
	{
		bool notError = true;
		string fullName = lineEditName->text().toStdString();
		string gender = lineEditGender->text().toStdString();
		double salary = lineEditSalary->text().toDouble();;
		double percent = lineEditPercent->text().toDouble();
		worker = new commission(fullName, gender, salary, percent);
		companyWorkers.push_back(worker);
		listWidget->addItem(lineEditName->text());
		int r = listWidget->count() - 1;
		listWidget->setCurrentRow(r);
	}
}

void mainwindow::changeItem()
{
	companyWorkers[listWidget->currentRow()]->Change(listWidget, listWidget->currentRow());
}

void mainwindow::modeling()
{
	QDialog *d = new QDialog(this);
	QHBoxLayout *hbox = new QHBoxLayout(d);
	QVBoxLayout *vbox = new QVBoxLayout;
	QFormLayout *box = new QFormLayout;
	QPlainTextEdit *plainTextEdit = new QPlainTextEdit(d);
	QPushButton *modelButton = new QPushButton(tr("Моделирование"), this);
	
	spinDay = new QSpinBox(d);
	spinDay->setMaximum(999);
	spinDay->setValue(1);
	plainTextEdit->setReadOnly(true);
	d->setWindowTitle(tr("Моделирование предприятия"));
	d->setWindowFlags(Qt::Drawer);
	box->addRow(tr("Количество дней:"), spinDay);
	vbox->addLayout(box);
	vbox->addWidget(modelButton);
	vbox->addStretch(1);
	hbox->addWidget(plainTextEdit);
	hbox->addLayout(vbox);
	d->setLayout(vbox);
	connect(modelButton, SIGNAL(clicked()), this, SLOT(generate()));
	connect(this, SIGNAL(sendText(QString)), plainTextEdit, SLOT(setPlainText(QString)));
	d->exec();
}

void mainwindow::generate()
{
	stringstream ss;
	ss << "\nСИМУЛЯЦИЯ НАЧАЛАСЬ\n";
	for (int i = 1; i <= spinDay->value(); i++)
	{
		ss << "День " << i << endl;
		for (auto *it : companyWorkers) it->Work(1 + rand() % 10);
		if (i % 15 == 0)
		{
			ss << "ДЕНЬ РАСЧЁТА ЗАРПЛАТЫ\n";
			for (auto *it : companyWorkers) it->CalculateSalary();
		}
		for (auto *it : companyWorkers) ss << it->Print();
	}
	emit sendText(QString::fromStdString(ss.str()));
}

void mainwindow::removeItem()
{
	int r = listWidget->currentRow();

	if (r != -1)
	{
		QListWidgetItem *item = listWidget->takeItem(r);
		companyWorkers.erase(companyWorkers.cbegin() + r);
		delete item;
	}
}

void mainwindow::clearItems()
{
	if (listWidget->count() != 0)
	{
		listWidget->clear();
		for (auto pObj = companyWorkers.begin(); pObj != companyWorkers.end(); ++pObj)
			delete *pObj;
		companyWorkers.clear();
	}
}

void mainwindow::serialize()
{
	fstream fs("serialize.bin", ios::app | ios::binary);
	for (auto *it : companyWorkers) fs << it->Serialize() << "^\n";
	fs.close();
}

void mainwindow::deserialize()
{
	fstream fs;
	fs.open("serialize.bin", ios::in | ios::binary);
	for (string temp; getline(fs, temp, '^');)
	{
		if (temp[temp.find('=') + 1] == 'h') companyWorkers.push_back(deserializeHourly(temp));
		else if (temp[temp.find('=') + 1] == 'c') companyWorkers.push_back(deserializeCommission(temp));
	}
	fs.close();
}