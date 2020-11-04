#pragma once
#include <QApplication>
#include <QInputDialog>
#include <QRadioButton>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QListWidget>
#include <QPlainTextEdit>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "hourly.h"
#include "commission.h"

class mainwindow : public QWidget
{
Q_OBJECT

public:
	mainwindow(QWidget* parent = nullptr);
private slots:
	void addItem();
	void addItemHourlyDialog();
	void addItemCommissionDialog();
	void changeItem();
	void modeling();
	void removeItem();
	void clearItems();
	void generate();
	void serialize();
	void deserialize();
signals:
	void sendText(QString);
private:
	company *deserializeHourly(const string &data);
	company *deserializeCommission(const string &data);
	vector<company *> companyWorkers;
	QListWidget* listWidget;
	QPushButton* addButton;
	QPushButton* renameButton;
	QPushButton* modelingButton;
	QPushButton* removeButton;
	QPushButton* cleanButton;
	QPushButton* serializeButton;
	QPushButton* deserializeButton;
	QSpinBox* spinDay;
};
