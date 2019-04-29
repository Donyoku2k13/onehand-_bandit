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
		cout << "Добро пожаловать в игру!\n";
		cout << "Загрузка";
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
				cout << "Недостаточно средств\n"
				<< "Внесите баланс или измените ставку!\n";
			win = model.getBalance() - win;
			break;
		case 2:
			changeBetMenu();
			break;
		case 3:
			addMoneyMenu();
			break;
		case 4:
			cout << "Ваш выигрыш составляет " << model.getBalance()
				<< " euro\n";
			cout << "До свидания\n";
			break;
		default:
			cout << "Ошибка! Попробуйте снова!\n";
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
	cout << "Ваш баланс: "<<model.getBalance()<<"  euro\n";
	cout << "Ваша ставка: "<<model.getBet()<<"  euro\n";
	cout << "1.Сыграть\n";
	cout << "2.Изменить ставку\n";
	cout << "3.Добавить баланс\n";
	cout << "4.Выйти из игры\n";
}

void SlotsMachineConsol::addMoneyMenu()
{
	system("cls");
	cout << "Ваш баланс равен " << model.getBalance() << "euro\n";
	cout << "Внесите деньги\n";
	int m;
	cin >> m;
	model.addBalance(m);
	cout << "Транзакция завершена успешно\n";
}

void SlotsMachineConsol::changeBetMenu()
{
	system("cls");
	cout << "Ваш баланс равен " << model.getBalance() << "euro\n";
	cout << "Ваша ставка: \n"<<model.getBet();
	cout << "\nВведите ставку: \n";
	int b;
	cin >> b;
	model.setBet(b);
	cout << "Ставка установленна\n";
}

void SlotsMachineConsol::coeffsMenu()
{
	cout << "Справка:\n";
	cout << "Коэффицент при 2 слотах рядом: 2\n";
	cout << "Коэффицент при 3 слотах рядом: 10\n";
	cout << "Jackpot при $$$ слотах :50 \n";
}



