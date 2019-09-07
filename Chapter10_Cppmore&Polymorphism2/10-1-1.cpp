#include<iostream>
#include<vector>

class A {
public:
	virtual void test1();
	virtual void test2() = 0;
};

void A::test1() {
	std::cout << "A::test1()" << "\n";
}

class B : public A {
public:
	void test2();
};

void B::test2() {
	std::cout << "B::test2()" << "\n";
}


class C : public A {
	void test1();
	void test2();
};

void C::test1() {
	std::cout << "C::test1()" << "\n";
}

void C::test2() {
	std::cout << "C::test2()" << "\n";
}

class BB : public B {
public:
	void test1();
};

void BB::test1() {
	std::cout << "BB::test1()" << "\n";
}

int main() {
	std::vector<A*> vec;
	std::string type;

	while (true) {
		std::cin >> type;
		
		if (type.find("C") == 0) {
			vec.push_back(new C);
		}

		else if (type.find("BB") == 0) {
			vec.push_back(new BB);
		}

		else if (type.find("B") == 0) {
			vec.push_back(new B);
		}

		else if (type.find("0") == 0) {
			break;
		}
	}

	int i;
	int len = vec.size();
	for (i = 0; i < len; i++) {
		vec[i]->test1();
		vec[i]->test2();
		delete vec[i];
	}
}