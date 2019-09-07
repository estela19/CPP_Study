#include<iostream>

int main() {
	int a = 10;
	int b = 4;
	double c = static_cast<double>(a);

	std::cout << c / b << std::endl;
	return 0;
}