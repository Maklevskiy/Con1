#define _CRT_SECURE_NO_WARNINGS //strcpy
#include <time.h>
#include "Event.h"

Event::~Event() {
	delete [] this->name;
}

char * Event::GetName() {
	return name;
}

void Event::SetName(char* name) {
	this->name=new char[51];
	strcpy(this->name, name);
}

time_t Event::GetStartDate() {
	return startDate;
}

void Event::SetStartDate(time_t date) {
	this->startDate = date;
}

time_t Event::GetFinishDate() {
	return finishDate;
}

void Event::SetFinishDate(time_t date) {
	this->finishDate = date;
}
void Event::ShowEvent() {
	std::cout<<"Event: " << name << "\n";
	std::cout<<"from " << ctime(&startDate);
	std::cout<<"to " << ctime(&finishDate) << std::endl;
}
