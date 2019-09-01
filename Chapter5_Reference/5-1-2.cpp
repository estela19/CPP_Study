#include<iostream>

int main(int argc, char** argv) {
	int i;
	for (i = 0; i < *argv[2]; i++) {
		std::cout << argv[1] << "\n";
	}

	return 0;
}