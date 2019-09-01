#include<iostream>


struct pair {
	int x;
	int y;
};

class circle {
public:
	circle(int x, int y, int r);
	pair point;
	int rad;
	void func() {
		std::cout << "area : " << rad * rad * 3.14 << ", perimeter : " << rad * 3.14;
	}
};

class square {
public:
	square(int lx, int ly, int rx, int ry);
	pair lu;
	pair rd;
	void func() {
		int height = lu.y - rd.y;
		int width = rd.x - lu.x;
		std::cout << "area : " << height * width << ", perimeter : " << (width + height) * 2;
	}
};

circle::circle(int x, int y, int r) {
	point.x = x;
	point.y = y;
	rad = r;
}

square::square(int lx, int ly, int rx, int ry) {
	lu.x = lx;
	lu.y = ly;
	rd.x = rx;
	rd.y = ry;
}

int main() {
	char shape;

	std::cout << "shape?" << '\n';
	std::cin >> shape;

	if (shape == 'C') {
		int x, y, r;
		std::cin >> x >> y >> r;

		circle obj(x, y, r);
		obj.func();
	}

	else if (shape == 'R') {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		square obj(a, b, c, d);
		obj.func();
	}
}