#pragma once
#include <iostream>
using namespace std;
class iter
{
	friend class container;
public:
	iter() { lin = 0; }
	iter(const iter& it) { lin = it.lin; }
	bool operator ==(const iter& it) { return lin == it.lin; }
	bool operator !=(const iter& it) { return !(lin == it.lin); }
	void operator ++() { ++lin; }
	void operator --() { --lin; }
	int& operator *() const { return *lin; }
	iter& operator + (const int n)
	{
		lin += n;
		return *this;
	}
private:
	int* lin;
};
class container
{
public:
	container() { size = 0; data = nullptr; }
	container(int size);
	container(const container& obj);
	~container();
	container& operator = (const container& obj);
	int& operator [] (const int index);
	friend ostream& operator <<(ostream& out, const container& other);
	friend istream& operator >>(istream& out, const container& other);
	bool operator != (const container& obj);
	bool operator < (const int value);
	iter first() { return beg; }
	iter last() { return end; }
private:
	int size;
	int* data;
	iter beg;
	iter end;
};
