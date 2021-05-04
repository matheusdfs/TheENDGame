#pragma once
#include <iostream>

//Classe baseada nos slides do Prof Simão

template <class TYPE>
class List
{
public:

	template <class TYPE>
	class Element {
	private:

		Element<TYPE>* pNext;
		Element<TYPE>* pBefore;
		TYPE* pInfo;

	public:

		Element() { pNext = NULL; pBefore = NULL; pInfo = NULL; }
		~Element() { pNext = NULL; pBefore = NULL; pInfo = NULL; }

		void setNext(Element<TYPE>* elem)
		{
			pNext = elem;
		}
		void setBefore(Element<TYPE>* elem)
		{
			pBefore = elem;
		}
		Element<TYPE>* getNext()
		{
			return pNext;
		}
		Element<TYPE>* getBefore()
		{
			return pBefore;
		}
		void setInfo(TYPE* inf)
		{
			pInfo = inf;
		}
		TYPE* getInfo()
		{
			return pInfo;
		}
	};
private:
	int quant;
	Element<TYPE>* pFirst;
	Element<TYPE>* pCurrent;
	Element<TYPE>* pLast;

public:

	List() { pFirst = NULL; pCurrent = NULL; pLast = NULL; quant = 0; }
	~List() { Clean(); }

	void Add(TYPE* pInfo)
	{
		if (NULL != pInfo)
		{
			Element<TYPE>* pNewElem = new Element<TYPE>;
			pNewElem->setInfo(pInfo);
			if (NULL != pFirst)
			{
				Element<TYPE>* pElemAux2 = pFirst;
				while (pElemAux2->getNext() != NULL)
				{
					pElemAux2 = pElemAux2->getNext();
				}
				pElemAux2->setNext(pNewElem);
				pNewElem->setBefore(pElemAux2);
				pLast = pNewElem;
				quant++;
			}
			else
			{
				pFirst = pNewElem;
				quant++;
			}
		}
	}
	Element<TYPE>* getLast()
	{
		return pLast;
	}
	void setLast(Element<TYPE>* at)
	{
		pLast = at;
	}
	Element<TYPE>* getPrim()
	{
		return pFirst;
	}
	Element<TYPE>* getAtual()
	{
		return pCurrent;
	}
	void setAtual(Element<TYPE>* at)
	{
		pCurrent = at;
	}
	void Reset()
	{
		pCurrent = pFirst;
	}
	void Clean()
	{
		Element<TYPE>* pElemAux = NULL;
		Element<TYPE>* pElemAux2 = NULL;
		pElemAux = pFirst;

		while (pElemAux->getNext() != NULL)
		{
			pElemAux2 = pElemAux;
			pElemAux = pElemAux2->getNext();
			delete(pElemAux2->getInfo());
			delete(pElemAux2);
		}
		delete(pElemAux->getInfo());
		delete(pElemAux);

		pCurrent = NULL;
		pFirst = NULL;
	}
};