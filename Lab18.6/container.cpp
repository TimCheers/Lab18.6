#include "container.h"
#include <iostream>
using namespace std;
container :: container(int size)
{
	this->size = size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
	beg.lin = &data[0];
	end.lin = &data[size];
}
container::container(const container& obj)
{
	this->size = obj.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = obj.data[i];
	}
	beg = obj.beg;
	end = obj.end;
}
container::~container()
{
	delete[] data;
	data = nullptr;
}
container& container::operator = (const container& obj)
{
	if (this==&obj)
	{
		return *this;
	}
	this->size = obj.size;
	if (data!=0)
	{
		delete[]data;
	}
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = obj.data[i];
	}
	beg = obj.beg;
	end = obj.end;
	return *this;
}
int& container:: operator [] (const int index)
{
	if (index < size)
	{
		return data[index];
	}
	else
	{
		cout << "Îøèáêà!";
	}
}
bool container::operator != (const container& obj)
{
	if (this->size == obj.size)
	{
		bool tmp = false;
		for (int i = 0; i < size; i++)
		{
			if (data[i] != obj.data[i])
			{
				tmp = true;
			}
		}
		return tmp;
	}
	else
	{
		return true;
	}
}
bool container::operator < (const int value)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
		{
			return true;
		}
	}
	return false;
}
ostream& operator<<(ostream& out, const container& other)
{
	for (int i = 0; i < other.size; i++)
	{
		out << other.data[i] << "  ";
	}
	return out;
}
istream& operator>>(istream& in, const container& other)
{
	for (int i = 0; i < other.size; i++)
	{
		in >> other.data[i];
	}
	return in;
}