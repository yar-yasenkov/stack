#include <cstring>
#include <iostream>


template <typename T>
class allocator
{
protected:
    allocator(size_t size = 0);
    ~allocator();
    auto swap(allocator & other) -> void;
    
    allocator(allocator const &) = delete;
    auto operator =(allocator const &) -> allocator & = delete;
    
    T * ptr_;
    size_t size_;
    size_t count_;
};

template <typename T>
allocator<T>::allocator(size_t size):size_(size),count_(0)
{
	if (size==0)
	{
		ptr_=nullptr;
	}
	else
	{
		ptr_=operator new(size*sizeof(T));
	}
}

template<typename T> /*noexcept*/
allocator<T>::~allocator() {
	delete ptr_;
}
	
template<typename T> /*noexcept*/
auto allocator<T>::swap(allocator & other) -> void {
	std::swap(ptr_, other.ptr_);
	std::swap(count_, other.count_);
	std::swap(size_, other.size_);
}

template <typename T>
class stack : protected allocator<T>
{
public:
	stack();/*noexcept*/
	stack(const stack &);/*strong*/
	~stack();/*noexcept*/	
	stack & operator=(const stack &);/*strong*/
	size_t count() const;/*noexcept*/
	void push(T const &);/*strong*/
	void pop();/*strong*/
	T& top();/*strong*/
	bool empty() const;/*noexcept*/
//private:
	//T * array_;
	//size_t array_size_;
	//size_t count_;
};

template <typename T>
auto new_copy(const T * source,  size_t new_size,size_t current_size) -> T*/*strong*/
{
        T * new_array = new T[new_size];
	try
	{
		std::copy(source, source + current_size, new_array);
	}
	catch(...)
	{
		delete []new_array;
		throw;
	}
	return new_array;
};


template <typename T>/*noexcept*/
stack<T>::stack() : allocator<T>()
{};

template <typename T>/*strong*/
stack<T>::stack(const stack & obj):allocator<T>(obj.count_)
{
	allocator<T>::size_ = obj.size_;
	allocator<T>::ptr_ = new_copy(obj.ptr_,obj.size_,obj.count_);

};

template <typename T>
stack<T>::~stack()/*noexcept*/
{
};

template <typename T>
stack<T> & stack<T>::operator=(const stack & st)/*strong*/
{
	if (this != &st)
	{
		(stack(st)).swap(*this);
	}
	return *this;
}

template <typename T>
size_t  stack<T>::count() const/*noexcept*/
{
	return allocator<T>::count_;
};

template <typename T>
void stack<T>::push(T const &value)/*strong*/
{
	if (allocator<T>::size_ == allocator<T>::count_)
	{
	        int size=allocator<T>::size_*2+(allocator<T>::size_ == 0);
		T * array_new=new_copy(allocator<T>::ptr_,size,allocator<T>::count_);
		delete[] allocator<T>::ptr_;
		allocator<T>::ptr_ = array_new;
		allocator<T>::size_=size;
	}
		allocator<T>::ptr_[allocator<T>::count_] = value;
		++allocator<T>::count_;
};

template <typename T>
void stack<T>::pop()/*strong*/
{
	if (allocator<T>::count_ == 0)
	{
		throw "out of stack";
	}
	--allocator<T>::count_;
};

template <typename T>
T &stack<T>::top()/*strong*/
{
	if (allocator<T>::count_ == 0)
	{
		throw "out of stack";
	}
	return allocator<T>::ptr_[allocator<T>::count_-1];	
}

template <typename T>/*noexcept*/
bool stack<T>::empty() const
{
	return(allocator<T>::count_ == 0);
}

