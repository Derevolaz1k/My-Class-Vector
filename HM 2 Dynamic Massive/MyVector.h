#pragma once
class MyVector
{
public:
	MyVector() :size_{ 0 }, capacity_{ 0 }, data_{ nullptr } {}//Конструктор по умолчанию
	MyVector(int size, int* data);//Конструктор создания массива
	MyVector(const MyVector& other) :MyVector(other.size_, other.data_) {}//Конструктор копирования
	~MyVector();
	void printArr();//Вывод массива на экран
	const MyVector& operator=(const MyVector& other);
	int& at(int index)
	{
		return (data_[index]);
	}
	int const& operator [](int n)
	{
		return data_[n];
	}
	bool const& operator ==(const MyVector& other);
	int& front()
	{
		return data_[0];
	}
	int& back()
	{
		return data_[size_-1];
	}
	int* data()
	{
		return &data_[0];
	}
	int const capacity()
	{
		return capacity_ - size_;
	}
	bool empty();
	int size()
	{
		return size_;
	}
	void reserve(int count);
	void shrink_to_fit();
	void clear();
	void insert(int pos, int value, int count = 1);
	void erase(int begin, int end);
	void push_back(int value);
	void emplace_back(int index)
	{
		push_back(data_[index]);
	}
	void pop_back()
	{
		erase(data_[size_-1], data_[size_ - 1]);
	}
	void resize(int size);
	void swap(int el1, int el2);
private:
	int capacity_;
	int size_;
	int* data_;
};

