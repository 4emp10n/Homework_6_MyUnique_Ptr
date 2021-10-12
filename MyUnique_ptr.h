#include <iostream>

template<class T>
class MyUnique_ptr
{
    private:
    T* m_ptr;
    public:
    explicit MyUnique_ptr(T* ptr = nullptr): m_ptr(ptr){};
    MyUnique_ptr(MyUnique_ptr& uptr) = delete;
    MyUnique_ptr(MyUnique_ptr&& uptr);
    T*operator ->(){ return this->m_ptr;}
    T& operator*() { return *(this->m_ptr);}
    void operator=(MyUnique_ptr&& uptr);
    ~MyUnique_ptr()
    {
        if ( m_ptr != nullptr)
        {
            delete m_ptr;
        }
    }
};

template<class T>
MyUnique_ptr<T>::MyUnique_ptr (MyUnique_ptr&& uptr)
{
    m_ptr = uptr.m_ptr;
    uptr.m_ptr = nullptr;
}

template<class T>
void MyUnique_ptr<T>::operator=(MyUnique_ptr&& uptr) // move assignment
{
	if (m_ptr != nullptr) delete m_ptr;

	m_ptr = uptr.m_ptr;
	uptr.m_ptr = nullptr;
}