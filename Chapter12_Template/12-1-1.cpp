#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

template<class T>
class MyContainer {
public:
	MyContainer() : n_elements(0), obj_arr(nullptr) {};
	MyContainer(int n) : n_elements(n), obj_arr(new T[n]) {};
	~MyContainer() : n_elements(0) { delete[] obj_arr; };

	void clear();
	int size()const;

protected:
	T* obj_arr;
	int n_elements;
};

template<class T>
void MyContainer<T>::clear() {
	int i;
	for (i = 0; i < n_elements; i++) {
		obj_arr[i] = NULL;
	}
	n_elements = 0;
}

template<class T>
int MyContainer<T>::size()const {
	return n_elements;
}

template<class T>
class MyVector : public MyContainer<T> {
public:
	MyVector() : MyContainer(), capacity(0) {};
	MyVector(int n) : MyContainer(n), capacity(n) {};

	MyVector<T>& operator = (const MyVector<T>& rhs);

	bool empty()const;
	int max_size()const;

	void reserve(int new_cap);
	void push_back(T obj);
	void pop_back();
	T& front();
	T& back();
	T& at(const int idx);
	const T& at(const int idx)const;
	T& operator[](const int idx);
	const T& operator[](const int idx)const;

	MyVector<T>operator+(const MyVector<T>& rhs);

private:
	int capacity;
};

template<class T>
int MyVector<T>::max_size()const {
	return capacity;
}

template<class T>
void MyVector<T>::push_back(T obj) {
	int new_size = std::max(1, 2 * capacity);
	if (n_elements == capacity) {
		T* new_arr = new T[new_size];
		int i;
		for (i = 0; i < n_elements; i++) {
			new_arr[i] = obj_arr[i];
		}
		delete[] obj_arr;
		obj_arr = &new_arr[0];
	}

	obj_arr[n_elements] = obj;
	n_elements++;
}

template<class T>
void MyVector<T>::pop_back() {
	new_arr[size()] == NULL;
	n_elements--;
}