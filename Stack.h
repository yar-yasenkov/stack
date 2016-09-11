#include <cstring>


template <typename T>
class stack
{
public:
	stack();
	stack(const stack &);
	~stack();	
	stack & operator=(const stack &);
	size_t count() const;
	void push(T const &);
	T pop();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() : array_size_(0), count_(0), array_(nullptr)
{};

template <typename T>
stack<T>::stack(const stack & obj)
{
	array_size_ = obj.array_size_;
	count_ = obj.count_;
	array_ = new T[array_size_];
	for (int i = 0; i < array_size_; i++)
	{
		array_[i] = obj.array_[i];
	}
}

template <typename T>
stack<T>::~stack()
{
	delete[] array_;
};

template <typename T>
stack<T> & stack<T>::operator=(const stack & st)
{
	std::cout << "=operator" << std::endl;
	if (this != &st)
	{
		delete[] array_;
		array_size_ = st.array_size_;
		count_ = st.count_;
		array_ = new T[array_size_];
		for (int i = 0; i < array_size_; i++)
		{
			array_[i] = st.array_[i];
		}
	}
	return *this;
}

template <typename T>
size_t  stack<T>::count() const
{
	return count_;
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
		array_ = array_new;
		++count_;
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
	if ((count_ <= 0)||(count_>array_size_))
	{
		throw "out of stack";
	}
	return array_[--count_];
};

