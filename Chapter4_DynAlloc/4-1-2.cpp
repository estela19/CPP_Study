#include<iostream>
#include<string>

int add(int a, int b);
std::string add(std::string a, std::string b);

int main() {
	int a, b;
	std::string str1, str2;

	std::cin >> a >> b >> str1 >> str2;
	std::cout << add(a, b) << '\n' << add(str1, str2);
}

int add(int a, int b) {
	return a + b;
}

std::string add(std::string a, std::string b) {
	return a + '-' + b;
}