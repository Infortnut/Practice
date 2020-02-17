#include "stdafx.h"
#include "iostream"

#include "Header.h"

int addElementsToFirstList(List *FirstList); 
int addElementsToSecondList(List *FirstList, List *SecondList);

int main()
{
	int nStopVar = 0;

	List *FirstList = NULL;
	List *SecondList = NULL;

	try
	{
		FirstList = new List;
	}
	catch (std::bad_alloc)
	{
		std::cout << "- memory allocation error - new()\n";
		std::cin >> nStopVar;
		abort();
	}

	try
	{
		SecondList = new List;
	}
	catch (std::bad_alloc)
	{
		std::cout << "memory allocation error - new()\n";
		std::cin >> nStopVar;
		abort();
	}

	

	addElementsToFirstList(FirstList); //Заполнить первый список и вывести значения
	std::cout << "\n"; 
	addElementsToSecondList(FirstList, SecondList); //Заполнить второй список на основе первого и вывести значения

	delete FirstList; 
	delete SecondList; 

	
	std::cout << "\n... ";
	std::cin >> nStopVar;

	return 0;
}

int addElementsToFirstList(List *FirstList) //Заполняет первый список
{
	//Семь элементов с заданными параметрами
	(*FirstList).addElementToEndOfList(-1.0);
	(*FirstList).addElementToEndOfList(2.0);
	(*FirstList).addElementToEndOfList(-3.0);
	(*FirstList).addElementToEndOfList(4.0);
	(*FirstList).addElementToEndOfList(-5.0);
	(*FirstList).addElementToEndOfList(6.0);
	(*FirstList).addElementToEndOfList(-7.0);

	if ((*FirstList).isEmpty()) { return 0; } //В случае изменения списка параметров останавливает выполнение функции, если нет значений

	std::cout << "First list:\n"; //Вывод

	Element *pCurrentElement = (*FirstList).getPointerOfFirstElementOfList(); //Получает указатель на первый элемент первого списка, делая его текущим

	while(!(*FirstList).isEndOfList(pCurrentElement)) //Пока текущий элемент не является последним...
	{
		std::cout << (*pCurrentElement).dMainValue << "\n"; //Выводит его значения
		pCurrentElement = (*pCurrentElement).pNextElement; //Переключается на следующий элемент
	}

	std::cout << (*pCurrentElement).dMainValue << "\n"; //Выводит последнее значение
	
	return 1; //success
};

int addElementsToSecondList(List *FirstList, List *SecondList) //Заполняет второй список на основе значений первого 
{
	//Присвоение значений

	Element *pCurrentElement = (*FirstList).getPointerOfFirstElementOfList(); // Получает указатель на первый элемент первого списка и делает его текущим

	while (!(*FirstList).isEndOfList(pCurrentElement)) //Пока текущий элемент не является последним...
	{   
		if ((*pCurrentElement).dMainValue < 0) //Если значение текущего элемента меньше 0
		{
			(*SecondList).addElementToEndOfList((*pCurrentElement).dMainValue); //Создать элемент второго списка с таким значением
		}
		pCurrentElement = (*pCurrentElement).pNextElement; //Переключится на следующий элемент
	}

	if ((*pCurrentElement).dMainValue < 0) //Если значение последнего элемента меньше 0
	{
		(*SecondList).addElementToEndOfList((*pCurrentElement).dMainValue); //Создать элемент второго списка с таким значением
	}

	if ((*SecondList).isEmpty()) {
		return 0;
	} //Останавливает выполнение функции, если нет элементов в втором списке
	
	//Вывод значений второго списка

	std::cout << "Second list:\n";

	Element *pCurrentElementSecond = (*SecondList).getPointerOfFirstElementOfList(); //Получает указатель на первый элемент второго списка и делает его текущим

	while (!(*SecondList).isEndOfList(pCurrentElementSecond)) //Пока текущий элемент не является последним...
	{
		std::cout << (*pCurrentElementSecond).dMainValue << "\n"; //Выводит его значение
		pCurrentElementSecond = (*pCurrentElementSecond).pNextElement; //Переключается на следующий элемент
	}

	std::cout << (*pCurrentElementSecond).dMainValue << "\n"; //Выводит значение последнего элемента второго списка

	return 1; //success
}
