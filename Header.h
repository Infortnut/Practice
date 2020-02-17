#pragma once

#include "iostream"

struct Element
{
	double dMainValue; //Значение элемента спиcка
	Element *pNextElement; //Указатель на следующий элемент

	Element() //Конструктор элемента списка
	{
		dMainValue = 0.0; //Инициализация значения нового списка
		pNextElement = NULL; //Инициализация указателя на следующий элемент
	}

	~Element() //Деструктор элемента списка
	{
		std::cout << "element has been deleted\n"; //Отладка
	}
};

struct List
{
private:

	int		nCountOfElements; //Кол-во элементов
	Element *pFirstElement; //Первый элемент
	Element *pLastElement; //Последний элемент

public:

	List() //Конструктор списка
	{
		nCountOfElements = 0; //Инициализация кол-ва элементов
		pFirstElement = NULL; //Инициализация указателя на последний элемент
		pLastElement = NULL; //Инициализация указателя на первый элемент
	}
	~List() //Деструктор списка
	{
		if (pFirstElement != NULL)
		{
			Element *pCurrentElementForDel = pFirstElement; //Запись указателя на первый элемент
			Element *pNextElementForDel; //Создание указателя на следующий элемент

			while (!isEndOfList(pCurrentElementForDel)) //Пока элемент НЕ конец списка
			{
				pNextElementForDel = (*pCurrentElementForDel).pNextElement; //Записать указатель на следующий элемент
				delete pCurrentElementForDel; //Удалить текущий элемент
				pCurrentElementForDel = pNextElementForDel; //Записать указатель на следующий элемент как текущий и повторить цикл
			}
			delete pCurrentElementForDel; //Удалить текущий (Последний) элемент
		}

		nCountOfElements = 0;

		std::cout << "list has been deleted\n"; //Отладка
	}

	Element * addElementToEndOfList(double newValue = 0.0) //Добавление элемента в конец списка
	{		
		//Создание нового элемента и указателя на него

		Element *pNewElement = NULL; 

		try 
		{
			pNewElement = new Element;
		}
		catch (std::bad_alloc)
		{
			int nStopVar = 0;
			std::cout << "-New\n";
			std::cin >> nStopVar;
			abort();
		}

		if (pFirstElement == NULL) //Если указатель на первый элемент равен NULL
		{
			pFirstElement = pNewElement; //То присвоить ему указатель на новый элемент
		}
		else //Иначе
		{			
			(*pLastElement).pNextElement = pNewElement; //Присвоить указатель на новый элемент последнему элементу списка
		}		
		
		(*pNewElement).dMainValue = newValue;

		++nCountOfElements; //Увелить счетчик элементов на один
		pLastElement = pNewElement; //Присвоить указатель на последний элемент параметру "Последний элемент списка"

		return pNewElement;
	};

	inline int isEndOfList(Element *currentElement)
	{
		if ((*currentElement).pNextElement == NULL) //Проверка на конец списка
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	inline int isEmpty() 
	{
		if (nCountOfElements == 0) //Проверка на пустоту списка
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	Element * getPointerOfFirstElementOfList()
	{
		return pFirstElement; //Возврат указателя на первый элемент
	}
};
