#include <iostream>
#include <locale>
#include"Queue.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	int len;
	std::cout << "Введите длину очереди";
	std::cout << std::endl;
	std::cin >> len;
	try
	{
		Queue<int> queue(len);
		for (int i = 0; i < len; i++)
		{
			queue.Push(i);
		}
		std::cout << std::endl;
		std::cout << "В очереди лежит:" << std::endl;
		queue.Print();
		std::cout << std::endl;
		std::cout << "Выведем вершину очереди" << std::endl;
		std::cout << queue.Top() << std::endl;
		std::cout << std::endl;
		std::cout << "Будем забирать элементы из очереди до тех пор, пока там что-то есть и выводить их на экран" << std::endl;
		while (!queue.IsEmpty())
		{
			std::cout << "В очереди лежит " << queue.Get() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Попробуем забрать еще элемент и получим исключение" << std::endl;
		queue.Get();
	}
	catch (Exception exp)
	{
		exp.Print();
	}
	return 0;
}
