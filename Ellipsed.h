#pragma once
#include <iostream>
using namespace std;
#include <windows.h>
#include <time.h>
#include <conio.h>

class Ellipsed
{
	int max;
	int current;
	int *wait;
	char name[25];
	int money;
	char masForCombination[3];

public:
	void setName(char *name);
	char *getName();
	void setMoney(int money);
	int getMoney();
	void rules();
	void add(int v);
	bool isFull();
	bool isEmpty();
	int extract();
	void result(int firstRand , int index);
	void beforeStart();
	void show();
	void game();
	void menu();
	void chekCombination();
	Ellipsed(int m);
	~Ellipsed();
};

