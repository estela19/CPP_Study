#include<iostream>
#include<malloc.h>

void sort(int* num, int n);
void Swap(int& a, int& b);

int main() {
	int n;
	std::cin >> n;

	int* num = (int*)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++) {
		std::cin >> num[i];
	}

	sort(num, n);

	for (i = 0; i < n; i++) {
		std::cout << num[i] << ' ';
	}
}

void sort(int* num, int n) {
	int now = 0;
	int now_val;
	int i, j;
	for (now = 1; now < n; now++) {
		now_val = num[now];
		for (i = now - 1; i >= 0; i--) {
			if (num[i] > now_val)
				Swap(num[i], num[i + 1]);
		}
	}
}

void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}