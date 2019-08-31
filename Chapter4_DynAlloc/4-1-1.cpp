#include<iostream>
#include<string>

int main() {
	std::string full_str;
	std::string tmp;
	char first = 0;
	char end = 0;
	int size = 0;

	std::cin >> tmp;
	full_str += tmp;
	first = full_str[0];

	std::cin >> tmp;
	full_str += tmp;
	size = full_str.size();
	end = full_str[size - 1];

	std::cout << full_str << '\n' << first << '\n' << end;
}