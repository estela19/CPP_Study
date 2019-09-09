#include<iostream>
#include<string>
#include<vector>

class MyVector {
private:
	int max_num;
	double* a;

public:
	MyVector() : max_num(0), a(nullptr) {};
	MyVector(int max_num) : max_num(max_num), a(new double[max_num]) {};
	MyVector(const MyVector &other) : MyVector()
	{
		*this = other;
	}

	MyVector(MyVector&& other) : MyVector()
	{
		*this = std::move(other);
	}

	~MyVector() {
		if (a != nullptr)
			delete[] a;
	};

	MyVector& operator =(MyVector&& b)
	{
		max_num = b.max_num;
		a = b.a;

		b.max_num = 0;
		b.a = nullptr;

		return *this;
	}

	MyVector& operator = (const MyVector& b) {
		// ���� ���߱�(�̹� ������ ��ŵ)
		if (max_num != b.max_num)
		{
			// ���̰� �ٸ��� �ϴ� �� ���� ����(���ٸ� ��ŵ)
			if (a != nullptr) {
				delete[] a;
				a = nullptr;
			}

			// ��������� �� ���� ������ �Ѵٸ� �� ���� ����(�ᱹ 0ĭ �� �Ŷ�� ��ŵ)
			if (b.max_num != 0) {
				a = new double[b.max_num];
			}

			// �غ� �� ������ ���� ���� ���߾� ��
			max_num = b.max_num;
		}

		int i;
		for (i = 0; i < max_num; i++) {
			a[i] = b.a[i];
		}
		return *this;
	};

	MyVector operator+(const MyVector& b) const {
		
		MyVector v(max_num);
		int i;
		for (i = 0; i < max_num; i++) {
			v.a[i] = a[i] + b.a[i];
		}

		return v;
	};

	MyVector operator-(const MyVector& b) const {
		MyVector v(max_num);
		int i;
		for (i = 0; i < max_num; i++) {
			v.a[i] = a[i] - b.a[i];
		}
		return v;
	};

	MyVector operator+(int b) const {
		MyVector v(max_num);
		int i;
		for (i = 0; i < max_num; i++) {
			v.a[i] = a[i] + b;
		}
		return v;
	};

	MyVector operator-(int b) const {
		MyVector v(max_num);
		int i;
		for (i = 0; i < max_num; i++) {
			v.a[i] = a[i] - b;
		}
		return v;
	}

	friend std::ostream& operator << (std::ostream& out, const MyVector& b) {
		int i;
		for (i = 0; i < b.GetMaxnum(); i++) {
			out << b.a[i] << " ";
		}
		out << "\n";
		return out;
	};

	friend std::istream& operator >> (std::istream& in, const MyVector& b) {
		int i;
		for (i = 0; i < b.GetMaxnum(); i++) {
			in >> b.a[i];
		}
		return in;
	};

	int GetMaxnum() const { return max_num; }

};

int main() {
	int max_num;
	std::cin >> max_num;
	MyVector a(max_num);
	MyVector b(max_num);

	std::cout << "enter a" << "\n";
	std::cin >> a;
	std::cout << "enter b" << "\n";
	std::cin >> b;

	while (true) {
		MyVector result(max_num);
		std::string input;
		std::cin >> input;
		
		if (input.find("quit") == 0) {
			break;
		}

		if (input.find("+") == 1) {
			if (input.find("a") == 0 && input.find("b") == 2) {
				result = a + b;
			}
			else if (input.find("a") == 0) {
				std::string num = input.substr(2);
				result = a + std::stoi(num);
			}
			else if (input.find("b" == 0)) {
				std::string num = input.substr(2);
				result = b + std::stoi(num);
			}
		}

		else if (input.find("-") == 1) {
			if (input.find("a") == 0 && input.find("b") == 2) {
				result = a - b;
			}
			else if (input.find("b") == 0 && input.find("a") == 2) {
				result = b - a;
			}
			else if (input.find("a") == 0) {
				std::string num = input.substr(2);
				result = a - std::stoi(num);
			}
			else if (input.find("b" == 0)) {
				std::string num = input.substr(2);
				result = b - std::stoi(num);
			}
		}

		std::cout << result;
		input.clear();
	}
}