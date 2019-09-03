#include<iostream>
#include<string>

class Number {
protected:
	int _num;

public:
	Number() { _num = 0; };
	Number(int num) { _num = num; };
	void setNumber(int num);
	int getNumber();

};

void Number::setNumber(int num) {
	_num = num;
}

int Number::getNumber() {
	return _num;
}

class Square : public Number {
public:
	int getSquare();
};

int Square::getSquare() {
	return _num * _num;
}

class Cube : public Square {
public:
	int getCube();
};

int Cube::getCube() {
	return _num * _num * _num;
}

int main() {
	std::string type;
	int num;

	while (true) {
		std::cin >> type;

		if (type.find("quit") == 0) {
			break;
		}

		std::cin >> num;

		if (type.find("number") == 0) {
			Number obj;
			obj.setNumber(num);
			std::cout << "getNumber() : " << obj.getNumber() << "\n";
		}
		else if (type.find("square") == 0) {
			Square obj;
			obj.setNumber(num);
			std::cout << "getNumber() : " << obj.getNumber() << "\n";
			std::cout << "getSquare() : " << obj.getSquare() << "\n";
		}
		else if (type.find("cube") == 0) {
			Cube obj;
			obj.setNumber(num);
			std::cout << "getNumber() : " << obj.getNumber() << "\n";
			std::cout << "getSquare() : " << obj.getSquare() << "\n";
			std::cout << "getCube() : " << obj.getCube() << "\n";
		}

	}
}