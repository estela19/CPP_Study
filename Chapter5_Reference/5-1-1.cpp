#include<iostream>
#include<string>

void swap(int& n1, int& n2);
void swap(std::string& s1, std::string& s2);

int main() {
	int n1, n2;
	std::string s1, s2;

	std::cin >> n1 >> n2 >> s1 >> s2;
	std::cout << "n1 : " << n1 << ", n2 : " << n2 << ", s1 : " << s1 << ", s2 : " << s2 << '\n';
	swap(n1, n2);
	swap(s1, s2);
	std::cout << "n1 : " << n1 << ", n2 : " << n2 << ", s1 : " << s1 << ", s2 : " << s2 << '\n';
}

void swap(int& n1, int& n2) {
	int tmp = n1;
	n1 = n2;
	n2 = tmp;
}

void swap(std::string& s1, std::string& s2) {
	std::string tmp = s1;
	s1 = s2;
	s2 = tmp;
}