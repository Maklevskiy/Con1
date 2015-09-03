#pragma once
#include <iostream>

class Event
{
	char* name;//название события
	time_t startDate;//начало времяни события
	time_t finishDate;//конец времяни события
public:
	char* GetName();// метод, позволяющий получить данные о название события
	void SetName(char* name);// присваивает значение названию события
	time_t GetStartDate();// метод, позволяющий получить данные о начале события
	void SetStartDate(time_t date);/*присваивает значение началу времени события
								   Параметры:	принимает начало времени события*/

	time_t GetFinishDate();// метод, позволяющий получить данные о конце события
	void SetFinishDate(time_t date);/*присваивает значение концу времени события
								   Параметры:	принимает конец времени события*/
	void ShowEvent();	// выводит событие на экран

	~Event();//деструктор
};

