#include<iostream>
#include<vector>

class A {
public:
	virtual void test() {
		std::cout << "A::test()" << "\n";
	}
};

class B : public A {
public:
	virtual void test() {
		std::cout << "B::test()" << "\n";
	}
};

class C : public B {
public:
	virtual void test() {
		std::cout << "C::test()" << "\n";
	}
};

int main() {
	std::vector<A*> vec;
	vec.push_back(new A);
	vec.push_back(new B);
	vec.push_back(new C);

	int i;
	for (i = 0; i < 3; i++) {
		vec[i]->test();
		delete[] vec[i];
	}
}