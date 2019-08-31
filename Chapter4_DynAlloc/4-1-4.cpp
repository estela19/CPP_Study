#include<iostream>
#include<string>
#include<malloc.h>

int main() {
	int n;
	int len = 0;
	int* arr;

	std::cin >> n;
	arr = (int*)malloc(n * sizeof(int));

	int i;
	for (i = 0; i < n; i++) {
		arr[i] = i;
	}

	for (i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}
}