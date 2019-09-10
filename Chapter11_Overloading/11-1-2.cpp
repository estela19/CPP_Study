#include<iostream>
#include<string>
#include<vector>

class MyString {
private:
	int len;
	char* a = nullptr;

public:
	MyString() : len(0), a(nullptr) {};
	MyString(MyString& my_string) { *this = my_string; }
	~MyString() {
		if (a != nullptr) {
			delete[] a;
			len = 0;
		}
	}

	MyString& operator = (const MyString& b) {
		len = b.len;
		if (a != nullptr) {
			delete[] a;
			a = nullptr;
		} 
		a = new char[len];
		int i;
		for (i = 0; i < len; i++) {
			a[i] = b.a[i];
		}
		return *this;
	}

	MyString operator + (const MyString& b) {
		MyString result;
		result.len = len + b.len;
		result.a = new char[result.len];
		int i;
		for (i = 0; i < len; i++) {
			result.a[i] = a[i];
		}
		for (i = len; i < result.len; i++) {
			result.a[i] = b.a[i-len];
		}
		return result;
	}

	MyString operator * (const int b) {
		MyString result;
		result.len = len * b;
		result.a = new char[result.len];
		int i, j;
		for (j = 0; j < b; j++) {
			for (i = 0; i < len; i++) {
				result.a[i + j*len] = a[i % len];
			}
		}
		return result;
	}

	friend std::ostream& operator << (std::ostream& out, const MyString& b) {
		int i;
		for (i = 0; i < b.len; i++) {
			out << b.a[i];
		}
		out << "\n";
		return out;
	};

	friend std::istream& operator >> (std::istream& in, MyString& b) {
		std::string str;
		in >> str;
		b.len = str.length();
		b.a = new char[b.len];
		int i;
		for (i = 0; i < b.len; i++) {
			b.a[i] = str[i];
		}
		return in;
	};

};

int main() {
	MyString a, b, result, c[2];
	std::string str;
	std::string input;

	std::cout << "enter a\n";
	std::cin >> a;
	std::cout << "enter b\n";
	std::cin >> b;
	while (true) {
		std::cin >> input;

		if (input.find("quit") == 0) {
			break;
		}

		if (input.find("+") == 1) {
			if (input.find("a") == 0) {
				if (input.find("a") == 2) {
					result = a + a;
				}

				else if (input.find("b") == 2) {
					result = a + b;
				}
			}

			else if(input.find("b") == 0) {
				if (input.find("a") == 2) {
					result = b + a;
				}

				else if (input.find("b") == 2) {
					result = b + b;
				}
			} 

		}

		else if (input.find("*") == 1) {
			int num = stoi(input.substr(2, 1));
			if (input.find("a") == 0) {
				result = a * num;
			}

			else if (input.find("b") == 0) {
				result = b * num;
			}
		}

		std::cout << result;
	}
}
