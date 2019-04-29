#pragma once
#include"cycleQueue.h"
#include <ctime>

using namespace std;

class SlotsMachineModel
{
	cycleQueue<char> bar[3];
	int balance;
	int bet;
public:
	SlotsMachineModel(int money, int bet);
	bool game();
	//setters&getters
	void setBet(int bet);
	void addBalance(int balance);
	int getBalance()const { return balance; }
	int getBet()const { return bet; }
	char operator[](int index)const;
private:
	void rollBars();
	int getCoef();

};


