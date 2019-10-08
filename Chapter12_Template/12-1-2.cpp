#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

template<class T>
class MyContainer {
public:
	MyContainer() : n_elements(0), obj_arr(nullptr) {};
	MyContainer(int n) : n_elements(0), obj_arr(new T[n]) {};
	~MyContainer() {};

	void clear();
	int size()const;

protected:
	T* obj_arr;
	int n_elements;
};

template<class T>
void MyContainer<T>::clear() {
	int i;
	n_elements = 0;
}

template<class T>
int MyContainer<T>::size()const {
	return n_elements;
}

template<class T>
class MyVector : public MyContainer<T> {
public:
	MyVector() : MyContainer<T>(), capacity(0) {};
	MyVector(int n) : MyContainer<T>(n), capacity(n) {};

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
	if (this->n_elements == capacity) {
		T* new_arr = new T[new_size];
		int i;
		for (i = 0; i < this->n_elements; i++) {
			new_arr[i] = this->obj_arr[i];
		}
		delete[] this->obj_arr;
		this->obj_arr = &new_arr[0];
		this->capacity = new_size;
	}

	this->obj_arr[this->n_elements] = obj;
	this->n_elements++;
}

template<class T>
void MyVector<T>::pop_back() {
	this->n_elements--;
}

template<class T>
bool MyVector<T>::empty()const {
	if (this->n_emements == 0) {
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
	for (i = 0; i < this->n_elements; i++) {
		new_ptr[i] = this->obj_arr[i];
	}
	delete[] this->obj_arr;
	this->obj_arr = &new_ptr[0];
	capacity = new_cap;
}

template<class T>
T& MyVector<T>::front() {
	return this->obj_arr[0];
}

template<class T>
T& MyVector<T>::back() {
	return this->obj_arr[this->n_elements];
}

template<class T>
T& MyVector<T>::at(const int idx) {
	if (idx > this->n_elements || 0 > idx) {
		std::cout << "invalid index\n";
		return NULL;
	}

	else {
		return this->obj_arr[idx];
	}
}

template<class T>
const T& MyVector<T>::at(const int idx)const {
	if (idx > this->n_elements || 0 > idx) {
		std::cout << "invalid index\n";
		return NULL;
	}

	else {
		return this->obj_arr[idx];
	}
}

template<class T>
T& MyVector<T>::operator[](const int idx) {
	return this->obj_arr[idx];
}

template<class T>
const T& MyVector<T>::operator[](const int idx)const {
	return this->obj_arr[idx];
}

template<class T>
MyVector<T> MyVector<T>::operator+(const MyVector<T>& rhs) {
	MyVector<T> result;
	result.capacity = capacity + rhs.capacity;
	result.n_elements = this->n_elements + rhs.n_elements;
	result.obj_arr = new T[result.capacity];
	int i;
	for (i = 0; i < this->n_elements; i++) {
		result.obj_arr[i] = this->obj_arr[i];
	}
	for (i = 0; i < rhs.n_elements; i++){
		result.obj_arr[i + this->n_elements] = rhs.obj_arr[i];
	}
	return result;
}

template<class T>
MyVector<T>& MyVector<T>::operator= (const MyVector<T>& rhs) {
	this->capacity = rhs.capacity;
	this->n_elements = rhs.n_elements;

	if (this->obj_arr != nullptr) {
		delete[] this->obj_arr;		
	}

	this->obj_arr = new T[capacity];
	int i;
	for (i = 0; i < capacity; i++) {
		this->obj_arr[i] = rhs.obj_arr[i];
	}
	return *this;
}

template <class T>
void print_vector(const MyVector<T>* v) {
	if (v->size() > 0) {
		std::cout << v->at(0);
		for (int i = 1; i < v->size(); ++i) std::cout << ", " << v->at(i);
		std::cout << std::endl;
	}
}

template <class T>
int run(std::vector<MyVector<T>* >& vectors) {
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
				std::cout << tvid++ << ", " << v->size() << ", " << v->max_size() << std::endl;
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
	std::string vtype;
	std::cin >> vtype;

	std::vector<MyVector<int>* > int_vectors;
	std::vector<MyVector<double>* > double_vectors;
	std::vector<MyVector<std::string>* > string_vectors;

	return (vtype == "int") ? run(int_vectors) : (vtype == "double") ? run(double_vectors) : run(string_vectors);
}
