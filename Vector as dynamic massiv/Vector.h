#pragma once
#include<ostream>
class Vector {
	double* data = 0;
	int size = 0;
	int capacity = 0;
public:

	Vector();
	Vector(int size);
	Vector(const Vector& Vector);
	~Vector();
	Vector& operator=(const Vector& v);
	void randomFill();
	double erase(int index);
	void insert(double elem, int index);
	friend std::ostream& operator<<(std::ostream& out, const Vector& v);
	void resize(int newSize);
	void push_back(double elem);
	double pop_back();
	double& operator[](int index);
	double operator[](int index) const;
	int lenght() { return size; }
};