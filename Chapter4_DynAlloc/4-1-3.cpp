#include<iostream>
#include<string>
#define pi 3.141592

double getCirclePerimeter(double r);
double getCircleArea(double r);

int main() {
	double r;
	std::cin >> r;
	std::cout << "Perimeter:" << getCirclePerimeter(r) << '\n' << "Area:" << getCircleArea(r);
}

double getCirclePerimeter(double r) {
	return 2 * pi * r;
}

double getCircleArea(double r) {
	return pi * r * r;
}