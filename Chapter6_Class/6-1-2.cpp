#include<iostream>
#include<functional>

class account {
public:
	int ID;
	int deposit;
	account() {
		ID = -1;
		deposit = 0;
	}
};

class master_account {
public:
	int account_num;
	account ac[10];
	master_account() {
		account_num = 0;
	}

	void Add_money(int ID);
	void Sub_money(int ID);
	void Give_money(int from, int to);
};

void New_account(master_account*);
int ID_check(master_account* master);

void master_account::Add_money(int ID) {
	int put_money;
	std::cin >> put_money;
	if (ac[ID].deposit + put_money > 100) {
		std::cout << "limit!" << '\n';
	}
	else {
		ac[ID].deposit += put_money;
		std::cout << "Success: Deposit to user " << ID << ' ' << ac[ID].deposit << '\n';
	}
}

void master_account::Sub_money(int ID) {
	int take_money;
	std::cin >> take_money;
	if (ac[ID].deposit - take_money < 0) {
		std::cout << "limit!" << '\n';
	}
	else {
		ac[ID].deposit -= take_money;
		std::cout << "Success: Deposit to user " << ID << ' ' << ac[ID].deposit << '\n';
	}
}

void master_account::Give_money(int from, int to) {
	int give_money;
	std::cin >> give_money;
	if (ac[from].deposit - give_money < 0 || ac[to].deposit + give_money > 100) {
		std::cout << "limit!" << '\n';
	}
	else {
		ac[from].deposit -= give_money;
		ac[to].deposit += give_money;
		std::cout << "Success: Transfer from user " << from << "to user " << to << ' ' << "give_money" << "\n";
		std::cout << "Balance of user " << from << ":" << ac[from].deposit << "\n";
		std::cout << "Balance of user " << to << ":" << ac[to].deposit << "\n";
	}
}

int main() {
	master_account master;
	char tmp;
	int flag = 0;
	while (1) {
		std::cout << "Job?" << '\n';
		std::cin >> tmp;

		switch (tmp) {
			int ID;

		case('N'):
			New_account(&master);
			break;

		case('D'):
			ID = ID_check(&master);
			if (ID == -1) break;
			else {
				master.Add_money(ID);
				break;
			}

		case('W'):
			ID = ID_check(&master);
			if (ID == -1) break;
			else {
				master.Sub_money(ID);
				break;
			}

		case('T'):
			int ID_1, ID_2;
			ID_1 = ID_check(&master);
			ID_2 = ID_check(&master);
			if (ID_1 == -1 || ID_2 == -1) break;
			else {
				master.Give_money(ID_1, ID_2);
				break;
			}

		case('Q'):
			flag = 1;
			break;
		}

		if (flag == 1)
			break;
	}
}

void New_account(master_account* master) {
	master->account_num++;

	if (master->account_num > 9) {
		std::cout << "You have too much account" << '\n';
	}

	else {
		account ac;
		master->ac[master->account_num] = ac;
		std::cout << "Account for user " << master->account_num << " resgistered" << '\n';
		std::cout << "Balance of user " << master->account_num << ": 0" << '\n';
	}
}

int ID_check(master_account* master) {
	int ID;
	std::cin >> ID;
	if (ID < 0 && ID > master->account_num) {
		std::cout << "Account does not exist\n";
		return -1;
	}
	else {
		return ID;
	}
}