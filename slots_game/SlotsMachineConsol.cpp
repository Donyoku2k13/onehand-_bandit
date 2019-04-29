#include "SlotsMachineConsol.h"



SlotsMachineConsol::SlotsMachineConsol()
	:model(0,0)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int r = 5 + rand() % 6;
	int x = 0;
	for (size_t i = 0; i < r; i++)
	{
		cout << "����� ���������� � ����!\n";
		cout << "��������";
		for (size_t i = 0; i < x; i++)
		{
			cout << ".";
		}
		Sleep(500);
		x++;
		if (x == 4) x = 0;
		system("cls");
	}

}

void SlotsMachineConsol::start()
{
	system("cls");
	addMoneyMenu();
	pause();
	changeBetMenu();
	pause();
	int choice = 0;
	int win = 0;
	while (choice != 4) {
		mainMenu((win < 0) ? 0 : win);
		cin >> choice;
		switch (choice)
		{
		case 1:
			win = model.getBalance();
			if (!model.game())
				cout << "������������ �������\n"
				<< "������� ������ ��� �������� ������!\n";
			win = model.getBalance() - win;
			break;
		case 2:
			changeBetMenu();
			break;
		case 3:
			addMoneyMenu();
			break;
		case 4:
			cout << "��� ������� ���������� " << model.getBalance()
				<< " euro\n";
			cout << "�� ��������\n";
			break;
		default:
			cout << "������! ���������� �����!\n";
			break;
		}
		pause();
	}
}

void SlotsMachineConsol::mainMenu()
{
	system("cls");
	cout << "-------------------------------\n\n";
	cout << "\t\t" << model[0] << "  " << model[1] << "  " << model[2] << "  \n";
	cout << "\n\n-------------------------------\n\n";
	cout << "��� ������: "<<model.getBalance()<<"  euro\n";
	cout << "���� ������: "<<model.getBet()<<"  euro\n";
	cout << "1.�������\n";
	cout << "2.�������� ������\n";
	cout << "3.�������� ������\n";
	cout << "4.����� �� ����\n";
}

void SlotsMachineConsol::addMoneyMenu()
{
	system("cls");
	cout << "��� ������ ����� " << model.getBalance() << "euro\n";
	cout << "������� ������\n";
	int m;
	cin >> m;
	model.addBalance(m);
	cout << "���������� ��������� �������\n";
}

void SlotsMachineConsol::changeBetMenu()
{
	system("cls");
	cout << "��� ������ ����� " << model.getBalance() << "euro\n";
	cout << "���� ������: \n"<<model.getBet();
	cout << "\n������� ������: \n";
	int b;
	cin >> b;
	model.setBet(b);
	cout << "������ ������������\n";
}

void SlotsMachineConsol::coeffsMenu()
{
	cout << "�������:\n";
	cout << "���������� ��� 2 ������ �����: 2\n";
	cout << "���������� ��� 3 ������ �����: 10\n";
	cout << "Jackpot ��� $$$ ������ :50 \n";
}



