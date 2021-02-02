#include"MultiStack.h"
#include<math.h>
#include"Steck.h"

using namespace std;

template<class T>
inline void TMultiStack<T>::StackRelocation(int index)
{
	int freeSize = 0;
	for (int i = 0; i < stackCount; i++)
	{
		freeSize += stacks[i].GetSize() - stacks[i].GetCount();
	}

	if (freeSize == 0)
	{
		throw logic_error("Error");
	}

	int count = int(floor(double(freeSize) / stackCount));
	int* sizes = new int[this->stackCount];

	for (int i = 0; i < (stackCount - 1); i++)
	{
		sizes[i] = stacks[i].GetCount() + count;
	}
	int c = stacks[stackCount - 1].GetCount();
	sizes[this->stackCount - 1] = c + (freeSize - (count * (this->stackCount - 1)));

	T** newData = new T * [stackCount];
	int k = 0;

	for (int i = 0; i < stackCount; i++)
	{
		newData[i] = &(data[k]);
		k = k + sizes[i];
	}


	for (int i = 0; i < stackCount; i++)
	{
		if (newData[i] == oldData[i])
		{
			stacks[i].SetData(newData[i], sizes[i], stacks[i].GetCount());
		}
		else if (newData[i] < oldData[i])
		{
			for (int j = 0; j < stacks[i].GetCount(); j++)
			{
				newData[i][j] = oldData[i][j];
			}
			stacks[i].SetData(newData[i], sizes[i], stacks[i].GetCount());
		}
		else if (newData[i] > oldData[i])
		{
			int k = i;
			for (; k < stackCount; k++)
			{
				if (newData[k] > oldData[k])
				{
					continue;
				}
				else
				{
					break;
				}
			}
			k--;

			for (int s = k; s <= i; s--)
			{
				for (int j = stacks[s].GetCount() - 1; j >= 0; j--)
				{
					newData[s][j] = oldData[s][j];
				}
				stacks[s].SetData(newData[s], sizes[s], stacks[s].GetCount());
			}

		}
	}

	T** buf = oldData;
	oldData = newData;
	delete[] buf;
	delete[] sizes;
}

template<class T>
inline TMultiStack<T>::TMultiStack(int size, int _stackCount)
{
	if ((size > 0) && (_stackCount > 0))
	{
		this->length = size;
		this->stackCount = _stackCount;

		data = new T[length];
		for (int i = 0; i < length; i++)
		{
			data[i] = 0;
		}

		int count = int(floor(double(size) / stackCount));
		int* sizes = new int[this->stackCount];

		for (int i = 0; i < (stackCount - 1); i++)
		{
			sizes[i] = count;
		}

		sizes[stackCount - 1] = size - (count * (stackCount - 1));
		oldData = new T * [stackCount];
		this->stacks = new TStack<T>[stackCount];
		int k = 0;

		for (int i = 0; i < stackCount; i++)
		{
			this->stacks[i].SetData(&(data[k]), sizes[i], 0);
			this->oldData[i] = &(data[k]);
			k = k + sizes[i];
		}
	}
	else
	{
		throw logic_error("Error");
	}
}

template <class T>
TMultiStack<T>::TMultiStack(TMultiStack<T>& _v)
{
	length = _v.length;
	stackCount = _v.stackCount;

	data = new T[length];
	for (int i = 0; i < length; i++)
	{
		data[i] = _v.data[i];
	}

	stacks = new TStack<T>[stackCount];
	for (int i = 0; i < stackCount; i++)
	{
		stacks[i] = _v.stacks[i];
	}
	oldData = _v.oldData;
}

template <class T>
TMultiStack<T>::~TMultiStack()
{
	length = 0;
	stackCount = 0;

	if (data == NULL)
	{
		delete[] data;
		data = NULL;
	}

	if (stacks == NULL)
	{
		delete[] stacks;
		stacks = NULL;
	}
}

template <class T>
TMultiStack<T>& TMultiStack<T>::operator =(TMultiStack<T>& _v)
{
	if (this == &_v)
	{
		return *this;
	}

	this->length = _v.length;
	if (data != NULL)
	{
		delete[] data;
	}
	if (stacks != NULL)
	{
		delete[] stacks;
	}

	data = new T[length];
	for (int i = 0; i < length; i++)
	{
		data[i] = _v.data[i];
	}

	stacks = new TStack<T>[stackCount];
	for (int i = 0; i < stackCount; i++)
	{
		stacks[i] = _v.stacks[i];
	}

	return *this;
}

template<class T>
inline void TMultiStack<T>::Push(T d, int i)
{
	if (i < 0 || i >= stackCount)
	{
		throw logic_error("Error");
	}

	if (stacks[i].IsFull())
	{
		StackRelocation(i);
	}

	stacks[i].Push(d);
}

template<class T>
inline T TMultiStack<T>::Get(int i)
{
	if (i < 0 || i > stackCount)
	{
		throw logic_error("Error");
	}

	if (stacks[i].IsEmpty())
	{
		throw logic_error("Error_mem");
	}

	T d = stacks[i].Get();
	return d;
}



template<class T>
inline bool TMultiStack<T>::IsEmpty(int i) const
{
	if (i < 0 || i > stackCount)
	{
		throw logic_error("Error");
	}


	return stacks[i].IsEmpty();
}

template<class T>
inline bool TMultiStack<T>::IsFull(int i) const
{
	if (i < 0 || i > stackCount)
	{
		throw logic_error("Error");
	}

	return stacks[i].IsFull();
}

template <class T>
int TMultiStack<T>::GetSize()
{
	return length;
}

template<class T>
inline void TMultiStack<T>::Resize(int size, int stackCount)
{
	stacks[stackCount].Resize(size);
}