#include<iostream>
#include"Vector.h"
#define CONST 2;

Vector::Vector() {
	size = 0;
	data = 0;
	capacity = size + 1;
}
Vector::Vector(int size = 0) {
	this->size = size;
	this->capacity = (size + 1) * CONST;
	this->data = new double[capacity];
	for (int i = 0; i < capacity; i++) data[i] = 0;
}

Vector::Vector(const Vector& vector) {
	double* tmp = new double[vector.capacity];
	for (int i = 0; i < capacity; i++) {
		if (i < size) tmp[i] = data[i];
		else tmp[i] = 0;
	}
	size = vector.size;
	capacity = vector.capacity;
	delete[] data;
	data = tmp;
}

Vector::~Vector() {
	this->size = 0;
	this->capacity = 0;
	delete[] this->data;
}
void Vector::randomFill() {
	for (int i = 0; i < size; i++) data[i] = rand() % 113;
}

double Vector::erase(int index) {
	double tmp = data[index];
	for (int i = index; i <= size; i++)
		data[i] = data[i + 1];
	size--;
	return tmp;
}
void Vector::insert(double elem, int index) {
	if (capacity <= (size + 1))resize(size + 1);
	for (int i = size; i >= index; i--)
		data[i + 1] = data[i];
	data[index] = elem;
}


void Vector::resize(int newSize) {
	if (newSize < capacity) {
		if (newSize < size) {
			for (int i = newSize; i < size; i++)
				data[i] = 0;
		}
	}
	if (newSize > capacity) {
		capacity = (newSize + 1) * 2;
		double* tmp = new double[capacity];
		for (int i = 0; i < capacity; i++) {
			if (i < size)
				tmp[i] = data[i];
			else tmp[i] = 0;
		}
		delete[] data;
		data = tmp;
	}
	size = newSize;
}
void Vector::push_back(double elem) {
	size++;
	if ((size) >= capacity) resize(size);
	data[size - 1] = elem;

}
double Vector::pop_back() {
	size--;
	double tmp = data[size];
	data[size] = 0;
	return tmp;
}

Vector& Vector::operator=(const Vector& v) {
	if (this != &v) {
		if (v.size != this->size)
			this->resize(v.size);
		for (int i = 0; i < v.size; i++)
			this->data[i] = v.data[i];
	}
	return *this;
}
double& Vector::operator[](int index) {
	if (index < size)return data[index];
	else std::cout << "index out of range.Max index is " << size - 1 << ". Take last element.";
	return data[size - 1];
}
double Vector::operator[](int index) const {
	if (index < size)return data[index];
	else std::cout << "index out of range.Max index is " << size - 1 << ". Last element:";
	return data[size - 1];
}



std::ostream& operator<<(std::ostream& out, const Vector& v) {
	out << "(";
	for (int i = 0; i < v.size; i++) {
		out << v.data[i];
		if ((i + 1) != v.size)
			std::cout << ",";
	}
	std::cout << ")";
	std::cout << std::endl;
	return out;
}