#include <cstring>
#include <iostream>



template <typename T>
class stack
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
private:
	T * array_;
	size_t array_size_;
	size_t count_;
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
stack<T>::stack() : array_size_(0), count_(0), array_(nullptr)
{};

template <typename T>/*strong*/
stack<T>::stack(const stack & obj):count_(obj.count_),array_size_(obj.array_size_),array_(new_copy(obj.array_,obj.array_size_,obj.count_))
{};

template <typename T>
stack<T>::~stack()/*noexcept*/
{
	delete[] array_;
};

template <typename T>
stack<T> & stack<T>::operator=(const stack & st)/*strong*/
{
	if (this != &st)
	{
		T *pnew=new_copy(st.array_,st.array_size_,st.count_);
		delete[] array_;
		array_size_ = st.array_size_;
		count_ = st.count_;
		array_=pnew;
	}
	return *this;
}

template <typename T>
size_t  stack<T>::count() const/*noexcept*/
{
	return count_;
};

template <typename T>
void stack<T>::push(T const &value)/*strong*/
{
	if (array_size_ == count_)
	{
	        int size=array_size_*2+(array_size_ == 0);
		T * array_new=new_copy(array_,size,count_);
		delete[] array_;
		array_ = array_new;
		array_size_=size;
	}
		array_[count_] = value;
		++count_;
};

template <typename T>
void stack<T>::pop()/*strong*/
{
	if (count_ == 0)
	{
		throw "out of stack";
	}
	--count_;
};

template <typename T>
T &stack<T>::top()/*strong*/
{
	if (count_ == 0)
	{
		throw "out of stack";
	}
	return array_[count_-1];	
}

template <typename T>
bool stack<T>::empty() const
{
	return(count_ == 0)
}

