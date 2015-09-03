#pragma once
#include <regex>
#include <time.h>
#include <conio.h>
#include "Calendar.h"

class UI
{
private:
	time_t GetTimeFromStr(char* tempTime) const;/*����� ��������� �������� ������� �� ������ ��������� �������������
	                                                                   ���������: ��������� �������� ������������� � ����� �������
																	   ���������� true ���� ������� � false ���� ���� �� ������*/
	
	bool EnterEvent(char*& name, time_t& startTime, time_t& endTime);/*����� �������������� ���������� ��������� ������������� �����������
	                                                                   ���������: ��������� �������� ������������� � ����� �������
																	   ���������� true ���� ������� � false ���� ���� �� ������*/
	void AddEvent();//��������� �������
	void EditEvent();//����������� �������
	void RemoveEvent();//������� �������

	Calendar calendar;

public:
	void RunUI();/*����� ����������� ���� ��������� �������
                  ���������: ��������� �������� ������������� � ����� �������
	             ���������� true ���� ������� � false ���� ���� �� ������ */

};

