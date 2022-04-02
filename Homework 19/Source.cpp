#include<iostream>
#include<algorithm>
#include"Vector.h"
#include"Unique_ptr.h"
/*
1. Напишите шаблонную функцию f(), складывающую элементы одного вектора vector<T> с элементами другого такого вектора например,
f(vl, v2) должна выполнять суммирование vl[i] += v2[i] для каждого элемента vl.
10. Реализуйте простой класс unique_Ptr, содержащий только конструктор, деструктор, операторы -> и *, а также функцию release(). 
В частности, не пытайтесь реализовать присваивание или копирующий конструктор.
*/

class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}
	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};

template<typename T>
void foo(Vector<T>& vec1, Vector<T>& vec2)
{
	for (int i = 0; i < vec1.Size(); i++)
	{
		vec1[i] += vec2[i];
	}

}
int main()
{
	Vector<int>vec1{ 3,3,3,3,3 };
	Vector<int>vec2{ 4,4,4,4,4 };
	foo(vec1, vec2);
	for (int i = 0; i < vec1.Size(); ++i)
	{
		std::cout << vec1[i] << " ";
	}
	std::cout << std::endl;
	Unique_ptr<A>ptr(new A);
	return 0;
}