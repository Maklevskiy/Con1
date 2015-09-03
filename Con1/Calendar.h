#pragma once
#include <vector>
#include "Event.h"

class Calendar
{
	std::vector<Event*> calendar;
public:
	void AddEvent(Event* ev);	/* добавляет событие в календарь
								   Параметры:
								   принимает событие*/
	void EditEvent(int position, char* name, time_t stDate, time_t finDate);	/* редактирует событие
																				Параметры:
																				принимает номер позиции события
																				название события
																				начало даты,конец даты*/

	bool RemoveEvent(char* name);	/* удаляет событие по имени
									Параметры:принимает название события
									возвращает true если удаление успешно*/
	void ShowAllEvent();	// вывод всех событий на экран

	Event* FindEvent(char* name);/*находит событие
								 Параметры:принимает название события
								 возвращает  событие*/

	std::vector<Event*> TimeIntervalEvent(time_t stDate, time_t finDate);/*проверяет все события по датам 
																		 Параметры:принимает начальную дату события,конечную дату события
																		 возвращает массив с событиями имеющими пересечение с заданным временем*/

};
