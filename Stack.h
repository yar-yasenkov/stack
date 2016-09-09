#include <cstring>


template <typename T>
class stack
{
public:
	stack();
	size_t count() const;
	void push(T const &);
	T pop();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() : array_size_(0), count_(0)
{
	array_ = new T;
};



template <typename T>
size_t  stack<T>::count() const
{
	int result = count_;
	result++;
	return result;
};

template <typename T>
void stack<T>::push(T const &value)
{
	if (array_size_ == count_)
	{
		array_size_++;
		T * array_new;
		array_new = new T[array_size_];
		for (int i = 0; i < array_size_-1 ; i++)
		{
			array_new[i] = array_[i];
		}
		delete[] array_;
		array_new[count_] = value;
		array_ = new T[array_size_];
		for (int i = 0; i < array_size_; i++)
		{
			array_[i] = array_new[i];
		}
		delete[] array_new;
	}
	else
	{
		array_[++count_] = value;
	}
};

template <typename T>
T stack<T>::pop()
{
	if (array_size_ == 0)
	{
		throw "stack does not exist";
	}
	if ((count_ < 0)||(count_>array_size_))
	{
		throw "out of stack";
	}
	T value; 
	value=array_[count_];
	array_[--count_];
	return value;
};

