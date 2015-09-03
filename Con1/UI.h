#pragma once
#include <regex>
#include <time.h>
#include <conio.h>
#include "Calendar.h"

class UI
{
private:
	time_t GetTimeFromStr(char* tempTime) const;/*метод формирует значения времени из данных введенных пользователем
	                                                                   Параметры: принимает название событияначало и конец события
																	   возвращает true если успешно и false если ввод не удался*/
	
	bool EnterEvent(char*& name, time_t& startTime, time_t& endTime);/*метод инициализирует переменные введеными пользователем параметрами
	                                                                   Параметры: принимает название событияначало и конец события
																	   возвращает true если успешно и false если ввод не удался*/
	void AddEvent();//добавляет событие
	void EditEvent();//редактирует событие
	void RemoveEvent();//удаляет событие

	Calendar calendar;

public:
	void RunUI();/*метод реализующий меню календаря событий
                  Параметры: принимает название событияначало и конец события
	             возвращает true если успешно и false если ввод не удался */

};

