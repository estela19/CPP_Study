#include<iostream>
#include<string>
#define root2 1.414

class Shape {
public:
	Shape() : _x(0), _y(0), _brush(' '), _perimeter(0), _area(0), _canv(NULL){};
	Shape(int x, int y, char brush) : _x(x), _y(y), _brush(brush), _canv(NULL) {};

	double GetArea();
	int GetPerimeter();
	void Draw(int canvas_width, int canvas_height);
	void MakeCanvas(int canvas_width, int canvas_height);
	void print();

protected:
	int _x;
	int _y;
	int _perimeter;
	double _area;
	char _brush;
	int** _canv;
};

double Shape::GetArea() {
	return _area;
}

int Shape::GetPerimeter() {
	return _perimeter;
}

void Shape::MakeCanvas(int canvas_width, int canvas_height) {
	_canv = new int* [canvas_height]();
	int i, j;
	for (i = 0; i < canvas_height; i++) {
		_canv[i] = new int[canvas_width]();
	}
}


void Shape::Draw(int canvas_width, int canvas_height) {
	std::cout << "Area: " << _area << "\n";
	std::cout << "Perimeter: " << _perimeter << "\n";

	int i, j;
	std::cout << " ";
	for (i = 0; i < 10; i++) {
		std::cout << i;
	}
	std::cout << "\n";

	for (i = 0; i < 10; i++) {
		std::cout << i;
		for (j = 0; j < 10; j++) {
			if (_canv[j][i] == 0) {
				std::cout << ".";
			}

			else if (_canv[j][i] == 1) {
				std::cout << _brush;
			}
		}
		std::cout << "\n";
	}
}

void Shape::print() {
	std::cout << "Area: " << GetArea() << "\n";
	std::cout << "Perimeter: " << GetPerimeter() << "\n";
}

class Rect:public Shape {
private:
	int _height;
	int _width;

public:
	Rect() : Shape(), _height(0), _width(0){};
	Rect(int x, int y, char brush, int height, int width) :Shape(x, y, brush), _height(height), _width(width) {
		_area = height * width;
		_perimeter = 2 * (height + width);
	};

	void Fill(int canv_height, int canv_width);
	
};

void Rect::Fill(int canv_height, int canv_width) {
	int i, j;
	for (i = 0; i < _width; i++) {
		for (j = 0; j < _height; j++) {
			if (_x + i < canv_width && _y + j < canv_height) {
				_canv[_x + i][_y + j] = 1;
			}
		}
	}
}

class Square : public Shape {
private:
	int _width;

public:
	Square() : Shape(), _width(0) {};
	Square(int x, int y, char brush, int width) : Shape(x, y, brush), _width(width) {
		_area = _width * _width;
		_perimeter = 4 * _width;

	};
	void Fill(int canv_height, int canv_width);

};

void Square::Fill(int canv_height, int canv_width) {
	int i, j;
	for (i = 0; i < _width; i++) {
		for (j = 0; j < _width; j++) {
			if (_x + i < canv_width && _y + j < canv_height) {
				_canv[_x + i][_y + j] = 1;
			}
		}
	}
}

class Diamond : public Shape {
private:
	int _distance;

public:
	Diamond() : Shape(), _distance(0) {};
	Diamond(int x, int y, char brush, int distance) :Shape(x, y, brush), _distance(distance) {
		_area = 2 * _distance * _distance;
		_perimeter = root2 * _distance * 4;

	};

	void Fill(int canv_height, int canv_width);
};

void Diamond::Fill(int canv_width, int canv_height) {
	int i, j;
	for (i = 0; i <= _distance; i++) {
		for (j = -i; j <= +i; j++) {
			if (_x + i < canv_width && _y + j < canv_height) {
				_canv[_x + j][_y + i] = 1;
			}
		}
	}

	for (i = _distance - 1; i >= 0; i--) {
		for (j = -i; j <= +i; j++) {
			if (_x + i < canv_width && _y + j < canv_height) {
				_canv[_x + j][_y + _distance + (_distance - i)] = 1;
			}
		}
	}
}

int main() {
	int canv_height, canv_width;
	std::string input;

	std::cin >> canv_height >> canv_width;

	while (true) {
		std::getline(std::cin, input);

		if (input.find("rect") == 0) {
			int x = atoi(input.substr(5).c_str());
			int y = atoi(input.substr(7).c_str());
			int height = atoi(input.substr(9).c_str());
			int width = atoi(input.substr(11).c_str());
			char brush = *input.substr(13).c_str();

			Rect obj(x, y, brush, height, width);
			obj.MakeCanvas(canv_height, canv_width);
			obj.Fill(canv_height, canv_width);
			obj.Draw(canv_height, canv_width);
		}

		else if (input.find("diamond") == 0) {
			int x = atoi(input.substr(8).c_str());
			int y = atoi(input.substr(10).c_str());
			int width = atoi(input.substr(12).c_str());
			char brush = *input.substr(14).c_str();

			Diamond obj(x, y, brush, width);
			obj.MakeCanvas(canv_height, canv_width);
			obj.Fill(canv_height, canv_width);
			obj.Draw(canv_height, canv_width);
		}

		else if (input.find("square") == 0) {
			int x = atoi(input.substr(7).c_str());
			int y = atoi(input.substr(9).c_str());
			int distance = atoi(input.substr(11).c_str());
			char brush = *input.substr(13).c_str();

			Square obj(x, y, brush, distance);
			obj.MakeCanvas(canv_height, canv_width);
			obj.Fill(canv_height, canv_width);
			obj.Draw(canv_height, canv_width);
		}

		else if (input.find("quit") == 0) {
			break;
		}
	}


}