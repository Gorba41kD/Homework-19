#pragma once
template<typename T>
class Vector
{
private:
	T* elem;
	int m_size;
	int m_space;
public:
	Vector() : elem(nullptr), m_size(0), m_space(0)
	{
	}
	Vector(std::initializer_list<T> lst) : m_size(lst.size()), m_space(lst.size()), elem(new T[lst.size()])
	{
		std::copy(lst.begin(), lst.end(), elem);
	}
	explicit Vector(int size) : m_size(size), elem(new T[size]), m_space(size)
	{
		for (int i = 0; i < m_size; ++i)
		{
			elem[i] = 0;
		}
	}
	int Size() const { return m_size; }
	int Capasity()const { return m_space; }
	void Reserve(int newAlloc)
	{
		if (newAlloc <= m_space) { return; };
		T* newElem = new T[newAlloc];
		for (int i = 0; i < m_size; ++i)
		{
			newElem[i] = elem[i];
		}
		delete[]elem;
		elem = newElem;
		m_space = newAlloc;
	}
	void Resize(int size)
	{
		Reserve(size);
		for (int i = m_size; i < size; i++)
		{
			elem[i] = T();
		}
		m_size = size;
	}
	void PushBack(const T& value)
	{
		if (m_space == 0)
		{
			Reserve(8);
		}
		else if (m_size = m_space)
		{
			Reserve(m_space * 2);
		}
		elem[m_size] = value;
		m_size++;
	}
	T& operator[](int i)
	{
		return elem[i];
	}
	T& operator[](int i) const
	{
		return elem[i];
	}
	~Vector()
	{
		delete[] elem;
	}
};
