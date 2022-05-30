#include<iostream>
#include"Vector.h"

int main() {
	Vector a(5), c(3);
	std::cout << "create" << a;
	a.randomFill();
	std::cout << "random fill:" << a;
	c = a;
	std::cout << "operator=: c=" << c;
	a.resize(10);
	std::cout << "resize:" << a;
	a.erase(2);
	std::cout << "erase:" << a;
	a.insert(3, 10);
	std::cout << "insert:" << a;
	a.push_back(-1);
	std::cout << "push back:" << a;
	a[6] = 77;
	std::cout << "operator[]:" << a;
	a.pop_back();
	a.pop_back();
	std::cout << "pop back 2 times:" << a;
	std::cout << "vector lenght:" << a.lenght() << std::endl;
	a.resize(2);
	std::cout << a;
	std::cout << a[2];
	return 0;
}