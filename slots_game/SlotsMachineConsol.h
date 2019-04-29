#pragma once
#include <iostream>
#include <string>
#include"SlotsMachineModel.h"
#include <Windows.h>
using namespace std;
class SlotsMachineConsol
{
	SlotsMachineModel model;

public:
	SlotsMachineConsol();
	void start();
	void mainMenu();
	void addMoneyMenu();
	void changeBetMenu();
	void coeffsMenu();
	void pause()const { system("pause"); }
};

