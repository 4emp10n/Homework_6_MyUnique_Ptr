#include <iostream>

template<class T>
class MyUnique_ptr
{
    private:
    T* m_ptr;
    public:
    explicit MyUnique_ptr(T* ptr = nullptr): m_ptr(ptr){}
    MyUnique_ptr(MyUnique_ptr& uptr) = delete;
    MyUnique_ptr(MyUnique_ptr&& uptr);
    T*operator ->(){ return this->m_ptr;}
    T& operator*() { return *(this->ptr);}
};