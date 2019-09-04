#include<iostream>
#include<vector>

class A {
public:
	virtual std::string getTypeInfo() {
		std::string str = "This is an instance of class A";
		return str;
	}
};

class B : public A {
public:
	virtual std::string getTypeInfo() {
		std::string str = "This is an instance of class B";
		return str;
	}
};

class C : public B {
public:
	virtual std::string getTypeInfo() {
		std::string str = "This is an instance of class C";
		return str;
	}
};

void printObjectTypeInfo1(A* object) {
	std::cout << object->getTypeInfo() << "\n";
}

void printObjectTypeInfo2(A& object) {
	std::cout << object.getTypeInfo() << "\n";
}

int main() {
	std::vector<A*> vec;
	vec.push_back(new A);
	vec.push_back(new B);
	vec.push_back(new C);

	int i;
	for (i = 0; i < 3; i++) {
		printObjectTypeInfo1(vec[i]);
		printObjectTypeInfo2(*vec[i]);
		delete[] vec[i];
	}
}