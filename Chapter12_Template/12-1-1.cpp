#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

template<class T>
class MyContainer {
public:
	MyContainer() : n_elements(0), obj_arr(nullptr) {};
	MyContainer(int n) : n_elements(n), obj_arr(new T[n]) {};
	~MyContainer() { delete[] obj_arr; };

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

template<class T>
bool MyVector<T>::empty()const {
	if (n_emements == 0) {
		return true;
	}
	
	else {
		return false;
	}
}

template<class T>
void MyVector<T>::reserve(int new_cap) {
	T* new_ptr = new T[new_cap];
	int i;
	for (i = 0; i < n_elements; i++) {
		new_ptr[i] = obj_arr[i];
	}
	delete[] obj_arr;
	obj_arr = &new_ptr[0];
	capacity = new_cap;
}

template<class T>
T& MyVector<T>::front() {
	return obj_arr[0];
}

template<class T>
T& MyVector<T>::back() {
	return obj_arr[n_elements];
}

template<class T>
T& MyVector<T>::at(const int idx) {
	if (idx > n_elements || 0 > idx) {
		std::cout << "invalid index\n";
		return NULL;
	}

	else {
		return obj_arr[idx];
	}
}

template<class T>
const T& MyVector<T>::at(const int idx)const {
	if (idx > n_elements || 0 > idx) {
		std::cout << "invalid index\n";
		return NULL;
	}

	else {
		return obj_arr[idx];
	}
}

template<class T>
T& MyVector<T>::operator[](const int idx) {
	return obj_arr[idx];
}

template<class T>
const T& MyVector<T>::operator[](const int idx)const {
	return obj_arr[idx];
}

template<class T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& rhs) {
	MyVector<T> result;
	result.capacity = capacity + rhs.capacity;
	result.n_elements = n_elements + rhs.n_elements;
	T* result.obj_arr = new T[size];
	int i;
	for (i = 0; i < n_elements; i++) {
		result.obj_arr[i] = obj_arr[i];
	}
	for (i = 0; i < rhs.n_elements; i++){
		result.obj_arr[i + n_elements] = rhs.obj_arr[i];
	}
	return result;
}

template<class T>
MyVector<T>& MyVector<T>::operator= (const MyVector<T>& rhs) {
	capacity = rhs.capacity;
	n_elements = rhs.n_elements;

	if (obj_arr != nullptr) {
		T* new_arr = new T[capacity];
		int i;
		for (i = 0; i < capacity; i++) {
			new_arr[i] = obj_arr[i];
		}
		delete[] obj_arr;
	}
	new_arr = &obj_arr[0];

}

template <class T>
void print_vector(const MyVector<T>* v) {
	if (v->size() > 0) {
		std::cout << v->at(0);
		for (int i = 1; i < v->size(); ++i) std::cout << ", " << v->at(i);
		std::cout << endl;
	}
}

template <class T>
int run(vector<MyVector<T>* >& vectors) {
	std::string cmd;
	int vid;

	while (true) {
		std::cin >> cmd;

		if (cmd == "quit") {
			break;
		}
		else if (cmd == "new") {
			int capacity;
			std::cin >> capacity;

			vectors.push_back(new MyVector<T>(capacity));
		}
		else if (cmd == "dump") {
			int tvid = 0;
			for (auto& v : vectors) {
				std::cout << tvid++ << ", " << v->size() << ", " << v->max_size() << endl;
			}
		}
		else if (cmd == "add") {
			T new_item;
			std::cin >> vid >> new_item;

			vectors.at(vid)->push_back(new_item);
			print_vector(vectors.at(vid));
		}
		else if (cmd == "pop") {
			std::cin >> vid;

			vectors.at(vid)->pop_back();
			print_vector(vectors.at(vid));
		}
		else if (cmd == "clear") {
			std::cin >> vid;
			vectors.at(vid)->clear();
			print_vector(vectors.at(vid));
		}
		else if (cmd == "join") {
			int vid2;
			std::cin >> vid >> vid2;

			auto new_vec = *(vectors.at(vid)) + *(vectors.at(vid2));
			print_vector(&new_vec);
		}
	}

	return 0;
}

int main() {
	string vtype;
	std::cin >> vtype;

	vector<MyVector<int>* > int_vectors;
	vector<MyVector<double>* > double_vectors;
	vector<MyVector<string>* > string_vectors;

	return (vtype == "int") ? run(int_vectors) : (vtype == "double") ? run(double_vectors) : run(string_vectors);
}
