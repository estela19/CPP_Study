#include<iostream>

class Rectangle {
public:
	Rectangle(int height, int width) :_height(height), _width(width) {};
	int getWidth() const;
	int getHeight() const;
	int getArea() const;
	int getPerimeter() const;

private:
	int _width;
	int _height;
};

int Rectangle::getWidth()const {
	return _width;
}

int Rectangle::getHeight()const {
	return _height;
}

int Rectangle::getArea()const {
	return _height * _width;
}

int Rectangle::getPerimeter()const {
	return 2 * (_height + _width);
}



class Square :public Rectangle {
public:
	Square(int width) :Rectangle(width, width) {};
	void print() const;
};

void Square::print()const {
	std::cout << getWidth() << "x" << getWidth() << " " << "Square" << "\n";
	std::cout << "Area: " << getArea() << "\n";
	std::cout << "Perimeter: " << getPerimeter() << "\n";
}



class NonSquare :public Rectangle {
public:
	NonSquare(int height, int width) :Rectangle(height, width) {};
	void print() const;
};

void NonSquare::print()const {
	std::cout << getWidth() << "x" << getHeight() << " " << "Square" << "\n";
	std::cout << "Area: " << getArea() << "\n";
	std::cout << "Perimeter: " << getPerimeter() << "\n";
}

int main() {
	std::string shape;

	while (true) {
		std::cin >> shape;

		if (shape.find("nonsquare") == 0) {
			int height, width;
			std::cin >> height >> width;
			NonSquare obj(height, width);
			obj.print();
		}

		else if (shape.find("square") == 0) {
			int width;
			std::cin >> width;
			Square obj(width);
			obj.print();
		}

		else if (shape.find("quit") == 0) {
			break;
		}

		else {
			std::cout << "wrong input!" << "\n";
		}
	}
}