#include "MyVector.h"
#include<iostream>

MyVector::MyVector(int size, int* data)
{
	size_ = size;
	capacity_ = size;
	data_ = new int[capacity_] {};
	for (int i = 0; i < size_; i++)
	{
		data_[i] = data[i];
	}
}

//MyVector::MyVector(const MyVector& other)
//{
//	size_ = other.size_;
//	data_ = new int[size_];
//	for (int i = 0; i < size_; i++)
//	{
//		data_[i] = other.data_[i];
//	}
//}


MyVector::~MyVector()
{
	if (data_)
		delete[]data_;
}

void MyVector::printArr()
{
	for (int i = 0; i < size_; i++)
	{
		std::cout << data_[i]<<"\t";
	}
}

MyVector const& MyVector::operator=(MyVector const& other)
{
	if (this != &other)
	{
			delete[]data_;
			capacity_ = other.capacity_;
			size_ = other.size_;
			data_ = new int[capacity_] {};
			for (int i = 0; i < size_; i++)
			{
				data_[i] = other.data_[i];
			}
		

	}
	return *this;
}

bool const& MyVector::operator==(const MyVector& other)
{
	if (this == &other)
		return 1;
	for (int i = 0; i < size_; i++)
	{
		if (other.data_[i] != data_[i])
			return 0;
	}
	return 1;
}

bool MyVector::empty()
{
	if(capacity_>0)
	return false;
	return true;
}

void MyVector::reserve(int count)
{
	int* tmp = new int[size_];
	for (int i = 0; i < size_; i++)
	{
		tmp[i] = data_[i];
	}
	capacity_ += count;
	delete[]data_;
	data_ = new int[capacity_];
	for (int i = 0; i < size_; i++)
	{
		data_[i] = tmp[i];
	}
}

void MyVector::shrink_to_fit()
{
	int* tmp = new int[size_];
	for (int i = 0; i < size_; i++)
	{
		tmp[i] = data_[i];
	}
	capacity_ =size_;
	delete[]data_;
	data_ = new int[capacity_];
	for (int i = 0; i < size_; i++)
	{
		data_[i] = tmp[i];
	}
}

void MyVector::clear()
{
	delete[]data_;
	size_ = 0;
	capacity_ = 0;
}

void MyVector::insert(int pos, int value, int count)
{
	{
		if (capacity_ < size_ + count)
			this->reserve(count);
		size_ += count;
		int* tmp = new int[size_];
		for (int i = 0; i < pos; i++)
		{
			tmp[i] = data_[i];
		}
		for (int i = pos; i < pos + count; i++)
		{
			tmp[i] = value;
		}
		for (int i = pos + count; i < size_; i++)
		{
			tmp[i] = data_[i - count];
		}
		delete[]data_;
		data_ = new int[capacity_];
		for (int i = 0; i < size_; i++)
		{
			data_[i] = tmp[i];
		}
		delete[]tmp;
	}
}

void MyVector::erase(int begin, int end)
{
	int count = 0;
	int* tmp = new int[size_];
	for (int i = 0; i < size_; i++)
	{
		tmp[i] = data_[i];
	}
	
	delete[]data_;
	data_ = new int[size_ - (end - begin)];
	for (int i = 0; i < size_; i++)
	{
		if (i >= begin && i <= end)
		{
			count++;
			continue;
		}
		data_[i-count] = tmp[i];
	}
	size_ -= (end - begin+1);
}

void MyVector::push_back(int value)
{
	int* tmp = new int[size_+1];
	for (int i = 0; i < size_; i++)
		tmp[i] = data_[i];
	size_ += 1;
	if (capacity_ < size_)
		reserve(1);
	for (int i = 0; i < size_; i++)
	{
		data_[i] = tmp[i];
	}
	data_[size_ - 1] = value;
}

void MyVector::resize(int size)
{
	if (size > capacity_)
		this->reserve(size - capacity_);
	else
	{
		int* tmp = new int[size_];
		for (int i = 0; i < size_; i++)
		{
			tmp[i] = data_[i];
		}
		delete[]data_;
		capacity_ = size;
		data_ = new int[capacity_];
		if (size_ > capacity_)
			size_ = capacity_;
		for (int i = 0; i < size_; i++)
		{
			data_[i] = tmp[i];
		}
	}

}

void MyVector::swap(int el1, int el2)
{
	int tmp = data_[el1];
	data_[el1] = data_[el2];
	data_[el2] = tmp;
}



