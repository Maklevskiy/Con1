#pragma once
#include <vector>
#include "Event.h"

class Calendar
{
	std::vector<Event*> calendar;
public:
	void AddEvent(Event* ev);	/* ��������� ������� � ���������
								   ���������:
								   ��������� �������*/
	void EditEvent(int position, char* name, time_t stDate, time_t finDate);	/* ����������� �������
																				���������:
																				��������� ����� ������� �������
																				�������� �������
																				������ ����,����� ����*/

	bool RemoveEvent(char* name);	/* ������� ������� �� �����
									���������:��������� �������� �������
									���������� true ���� �������� �������*/
	void ShowAllEvent();	// ����� ���� ������� �� �����

	Event* FindEvent(char* name);/*������� �������
								 ���������:��������� �������� �������
								 ����������  �������*/

	std::vector<Event*> TimeIntervalEvent(time_t stDate, time_t finDate);/*��������� ��� ������� �� ����� 
																		 ���������:��������� ��������� ���� �������,�������� ���� �������
																		 ���������� ������ � ��������� �������� ����������� � �������� ��������*/

};
