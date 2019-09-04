#include<iostream>
#include<vector>

class A {
private:
	int* memberA = nullptr;

public:
	A(int tmp) :memberA(new int) {
		*memberA = tmp;
		std::cout << "new memberA" << "\n";
	}
	 ~A() {
		delete memberA;
		std::cout << "delete memberA" << "\n";
	}

	virtual void print();
};

void A::print() {
	std::cout << "*memberA " << *memberA << "\n";
}

class B : public A {
private:
	double* memberB;

public:
	B(double tmp) : memberB(new double), A(1) {
		*memberB = tmp;
		std::cout << "new memberB" << "\n";
	}
	 ~B() {
		delete memberB;
		std::cout << "delete memberB" << "\n";
	}

	virtual void print();
};

void B::print() {
	A::print();
	std::cout << "*memberB "<< *memberB << "\n";
}

class C : public B {
private:
	std::string* memberC;

public:
	C(std::string tmp) : memberC(new std::string), B(1.1) {
		*memberC = tmp;
		std::cout << "new memberC" << "\n";
	}
	 ~C() {
		delete memberC;
		std::cout << "delete memberC" << "\n";
	}

	virtual void print();
};

void C::print() {
	B::print();
	std::cout << "*memberC " << *memberC << "\n";
}

int main() {
	std::vector<A*> vec;
	int a = 0;
	double b = 0;
	std::string c;

	std::cin >> a >> b >> c;

	vec.push_back(new A(a));
	vec.push_back(new B(b));
	vec.push_back(new C(c));

	int i;
	for (i = 0; i < 3; i++) {
		vec[i]->print();
	}

	for (i = 0; i < 3; i++) {
		delete vec[i];
	}
	vec.clear();
}