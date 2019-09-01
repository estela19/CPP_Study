#include<iostream>

enum FighterStatus {
	Invalid,
	Alive,
	Dead
};

class MinimalFighter {
private:
	int mHp;
	int mPower;
	FighterStatus mStatus;
	void UpdateState(MinimalFighter* _enemy);

public:
	MinimalFighter() :mStatus(FighterStatus::Invalid), mHp(0), mPower(0) {}
	MinimalFighter(int _hp, int _power) :mHp(_hp), mPower(_power) {
		if (_hp > 0) mStatus = FighterStatus::Alive;
		else if (_hp <= 0) mStatus = FighterStatus::Dead;
	}

	int hp()const;
	int power()const;
	FighterStatus status() const;
	void setHp(int _hp);
	void hit(MinimalFighter* _enemy);
	void attack(MinimalFighter* _target);
	void fight(MinimalFighter* _enemy);
};

int MinimalFighter::hp()const {
	return mHp;
}

int MinimalFighter::power()const {
	return mPower;
}

FighterStatus MinimalFighter::status() const {
	return mStatus;
}

void MinimalFighter::setHp(int _hp) {
	mHp = _hp;
}

void MinimalFighter::hit(MinimalFighter* _enemy) {
	mHp -= _enemy->mPower;
	_enemy->mHp -= mPower;
	UpdateState(_enemy);
}

void MinimalFighter::attack(MinimalFighter* _target) {
	_target->mHp -= mPower;
	mPower = 0;
	UpdateState(_target);
}

void MinimalFighter::fight(MinimalFighter* _target) {
	while (_target->mHp != 0 && mHp != 0) {
		mHp -= _target->mPower;
		_target->mHp -= mPower;
	}
	UpdateState(_target);
}

void MinimalFighter::UpdateState(MinimalFighter* _enemy) {
	if (mHp <= 0) mStatus = FighterStatus::Dead;
	else mStatus = FighterStatus::Alive;

	if (_enemy->mHp <= 0) _enemy->mStatus = FighterStatus::Dead;
	else _enemy->mStatus = FighterStatus::Alive;
}

void print(MinimalFighter* player1, MinimalFighter* player2);

int main() {
	int p1_h, p1_p, p2_h, p2_p;
	while (1) {
		char act = -1;
		std::cin >> p1_h >> p1_p >> act >> p2_h >> p2_p;

		MinimalFighter player1(p1_h, p1_p);
		MinimalFighter player2(p2_h, p2_p);

		if (act == -1) break;
		else if (act == 'A') player1.attack(&player2);
		else if (act == 'F') player1.fight(&player2);
		else if (act == 'H') player1.hit(&player2);

		print(&player1, &player2);
	}
}

void print(MinimalFighter* player1, MinimalFighter* player2) {
	if (player1->status() == Alive) {
		std::cout << "H" << player1->hp() << ", P" << player1->power() << " / ";
	}
	else if (player1->status() == Dead) {
		std::cout << "Dead" << " / ";
	}

	if (player2->status() == Alive) {
		std::cout << "H" << player2->hp() << ", P" << player2->power() << "\n";
	}
	else if (player2->status() == Dead) {
		std::cout << "Dead" << "\n";
	}
}