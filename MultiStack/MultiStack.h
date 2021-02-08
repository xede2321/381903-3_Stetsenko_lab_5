#ifndef _MULTISTACK_
#define _MULTISTACK_

#include <iostream>
#include <fstream>
#include <math.h>
#include"Steck.h"
using namespace std;

template <class T>
class TMultiStack
{
protected:
	int length;
	int stackCount;
	TStack<T>* stacks;
	T** oldData;
	T* data;

	void StackRelocation(int i);

public:
	TMultiStack(int size = 1, int stackCount = 1);
	TMultiStack(TMultiStack<T>& _v);
	~TMultiStack();

	TMultiStack<T>& operator =(TMultiStack<T>& _v);
	T Get(int i);

	void Push(T d, int i);
	bool IsEmpty(int i) const;
	bool IsFull(int i) const;
	int GetSize();
	void Resize(int size = 1, int stackCount = 1);


	template <class T1>
	friend ostream& operator<< (ostream& ostr, const TMultiStack<T1>& A);
	template <class T1>
	friend istream& operator >> (istream& istr, TMultiStack<T1>& A);
};

template<class T1>
inline istream& operator>>(istream& istr, TMultiStack<T1>& A)
{
	int stCount = 0;
	istr >> stCount;
	int size = 0;
	istr >> size;
	A.Resize(size, stCount);

	for (int i = 0; i < A.stCount; i++)
	{
		istr >> A.stacks[i];
	}
	return istr;
}

template<class T1>
inline ostream& operator<<(ostream& ostr, const TMultiStack<T1>& A)
{
	for (int i = 0; i < A.stackCount; i++)
	{
		ostr << (A.stacks[i]) << endl;
	}
	return ostr;
}
#endif 