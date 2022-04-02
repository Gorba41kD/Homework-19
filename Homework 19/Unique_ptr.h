#pragma once
template<typename T>
class Unique_ptr
{
private:
	T* m_pointer;
public:
	Unique_ptr() : m_pointer(nullptr)
	{
	}
	Unique_ptr(T* pointer) : m_pointer(pointer)
	{

	}
	Unique_ptr(Unique_ptr&& ref) noexcept
	{
		m_pointer = ref.m_pointer;
		ref.m_pointer = nullptr;
	}
	Unique_ptr& operator =(Unique_ptr&& ref) noexcept
	{
		if (*this == &ref)
		{
			return *this;
		}
		m_pointer = ref.m_pointer;
		ref.m_pointer = nullptr;
		return *this;
	}
	Unique_ptr(const Unique_ptr&) = delete;
	Unique_ptr& operator =(const Unique_ptr&) = delete;
	T* operator ->()
	{
		return m_pointer;
	}
	T& operator *()
	{
		return *m_pointer;
	}
	~Unique_ptr()
	{
		delete m_pointer;
	}
};