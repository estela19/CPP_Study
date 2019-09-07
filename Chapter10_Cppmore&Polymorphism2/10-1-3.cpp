#include<iostream>
#include<vector>

class B {
public:
	virtual ~B() {};
};

class C : public B {
public:
	void test_C() {
		std::cout << "C::test_C()" << std::endl;
	}
};

class D : public B {
public:
	void test_D() {
		std::cout << "D::test_D()" << std::endl;
	}
};

int main() {
	std::vector<B*> vec;
	char type;

	while (true) {
		std::cin >> type;

		if (type == 'B') {
			vec.push_back(new B);
		}
		else if (type == 'C') {
			vec.push_back(new C);
		}
		else if (type == 'D') {
			vec.push_back(new D);
		}
		else if (type == '0') {
			break;
		}
	}

	int i;
	int len = vec.size();
	for (i = 0; i < len; i++) {
		if (dynamic_cast<C*>(vec[i]) != nullptr) {
			dynamic_cast<C*>(vec[i])->test_C();
		}
		else if (dynamic_cast<D*>(vec[i]) != nullptr) {
			dynamic_cast<D*>(vec[i])->test_D();
		}
		
		delete vec[i];
	}

	vec.clear();
}