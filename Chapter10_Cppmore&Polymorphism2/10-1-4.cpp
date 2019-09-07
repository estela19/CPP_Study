#include<iostream>
#include<vector>

class Shape {
protected:
	double _width, _height;

public:
	Shape(double width, double height) : _width(width), _height(height) {};
	virtual void getArea() = 0;
};

class Triangle : public Shape {
public:
	Triangle(double width, double height) : Shape(width, height) {};

	void getArea() {
		std::cout << _width * _height / 2 << "\n";
	}

};

class Rectangle : public Shape {
public:
	Rectangle(double width, double height) : Shape(width, height) {};

	void getArea() {
		std::cout << _width * _height << "\n";
	}
};

int main() {
	std::vector<Shape*> vec;
	double height, width;
	
	std::cin >> width >> height;
	vec.push_back(new Triangle(width, height));

	std::cin >> width >> height;
	vec.push_back(new Rectangle(width, height));

	int i;
	for (i = 0; i < 2; i++) {
		vec[i]->getArea();
		delete vec[i];
	}

	vec.clear();
}