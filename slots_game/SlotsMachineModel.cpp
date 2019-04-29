#include "SlotsMachineModel.h"



SlotsMachineModel::SlotsMachineModel(int money, int bet)
{
	srand(time(NULL));
	this->bet = bet;
	this->balance = money;
	//36;209, 65; 66;67; 252;64;61;251
	for (size_t i = 0; i < 3; i++)
	{
		bar[i].push(36);
		bar[i].push(209);
		bar[i].push(65);
		bar[i].push(66);
		bar[i].push(252);
		bar[i].push(67);
		bar[i].push(64);
		bar[i].push(61);
		bar[i].push(251);	
	}
}

bool SlotsMachineModel::game()
{
	if (this->balance < this->bet)
		return false;
	this->balance -= this->bet;
	rollBars();
	balance += bet * getCoef();
	return true;
}

void SlotsMachineModel::setBet(int bet)
{
	this->bet = bet;
	if (bet<0)
	{
		bet = 0;
	}
}

void SlotsMachineModel::addBalance(int balance)
{
	if (balance<0)
	{
		balance = 0;
	}
	this->balance += balance;
}

char SlotsMachineModel::operator[](int index) const
{
	return bar[index].front();
}

void SlotsMachineModel::rollBars()
{
	int r = 27 + rand() % 28;
	for (size_t i = 0; i < r; i++)
		bar[0].pop(false);
	int g = 27 + rand() % 28;
	for (size_t i = 0; i < g; i++)
		bar[1].pop(false);
	int d = 27 + rand() % 28;
	for (size_t i = 0; i < d; i++)
		bar[2].pop(false);

}

int SlotsMachineModel::getCoef()
{
	bar[0].front();
	bar[1].front();
	bar[2].front();
	int coef = 0;
	if (bar[0].front() == bar[1].front() || bar[1].front() == bar[2].front())
		coef = 2;
	if (bar[0].front() == bar[1].front() && bar[1].front() == bar[2].front())
		coef = 10;
	if (bar[0].front() == bar[1].front() && bar[1].front() == bar[2].front() && bar[0].front()=='$' )
		coef = 50;
	return coef;
}
