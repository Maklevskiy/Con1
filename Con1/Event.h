#pragma once
#include <iostream>

class Event
{
	char* name;//�������� �������
	time_t startDate;//������ ������� �������
	time_t finishDate;//����� ������� �������
public:
	char* GetName();// �����, ����������� �������� ������ � �������� �������
	void SetName(char* name);// ����������� �������� �������� �������
	time_t GetStartDate();// �����, ����������� �������� ������ � ������ �������
	void SetStartDate(time_t date);/*����������� �������� ������ ������� �������
								   ���������:	��������� ������ ������� �������*/

	time_t GetFinishDate();// �����, ����������� �������� ������ � ����� �������
	void SetFinishDate(time_t date);/*����������� �������� ����� ������� �������
								   ���������:	��������� ����� ������� �������*/
	void ShowEvent();	// ������� ������� �� �����

	~Event();//����������
};

