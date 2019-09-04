#include<iostream>
#include<vector>

class Animal {
protected:
	std::string _name;
	int _age;

public:
	Animal(std::string name, int age) : _name(name), _age(age) {};
	virtual void PrintInfo() {};
};


class Zebra : public Animal {
private:
	int _numStripes;

public:
	Zebra(std::string name, int age, int stripes) : Animal(name, age), _numStripes(stripes) {};
	void PrintInfo();
};

void Zebra::PrintInfo() {
	std::cout << "Zebra, Name: " << _name << ", Age: " << _age << ", Number of stripes: " << _numStripes << "\n";
}

class Cat : public Animal {
private:
	std::string _favoriteToy;

public:
	Cat(std::string name, int age, std::string toy) : Animal(name, age), _favoriteToy(toy) {};
	void PrintInfo();
};

void Cat::PrintInfo() {
	std::cout << "Cat, Name: " << _name << ", Age: " << _age << ", Favorite toy: " << _favoriteToy << "\n";
}

int main() {
	std::vector<Animal*> vec;
	char type;
	int flag = 0;

	while (true) {
		std::string name;
		int age;
		int stripe;
		std::string toy;
		std::cin >> type;

		switch (type) {
		case('z'):
			std::cin >> name >> age >> stripe;
			vec.push_back(new Zebra(name, age, stripe));
			break;

		case('c'):
			std::cin >> name >> age >> toy;
			vec.push_back(new Cat(name, age, toy));
			break;

		case('0'):
			flag = 1;
			break;
		}

		if (flag == 1) {
			break;
		}
	}

	int i;
	int len = vec.size();
	for (i = 0; i < len; i++) {
		vec[i]->PrintInfo();
	}

	for (i = 0; i < len; i++) {
		delete vec[i];
	}

}