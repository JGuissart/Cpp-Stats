#ifndef STRUCTCELLULE_H_INCLUDED
#define STRUCTCELLULE_H_INCLUDED

template <class T> struct Cellule
{
	T* val;
	Cellule<T>* pNext;
};

#endif // STRUCTCELLULE_H_INCLUDED
