#include "Calendar.h"

void Calendar::AddEvent(Event* ev)
{
	calendar.push_back(ev);
}

void Calendar::EditEvent(int position, char * name, time_t stDate, time_t finDate)
{
	calendar[position]->SetName(name);
	calendar[position]->SetStartDate(stDate);
	calendar[position]->SetFinishDate(finDate);
}

bool Calendar::RemoveEvent(char* name) {
	unsigned int count = 0;
	for each (Event* ev in calendar) {
		if (!strcmp(ev->GetName(), name)) {
			delete ev;
			this->calendar.erase(calendar.begin() + count);
			return true;
		}
		count++;
	}
	return false;
}

void Calendar::ShowAllEvent()
{
	for each (Event* ev in calendar) {
		ev-> ShowEvent();
		std::cout<<"\n\a";
	}
	
}

Event * Calendar::FindEvent(char * name) {
	for each (Event* ev in calendar) {
		if (!strcmp(ev->GetName(), name)) {
			return ev;
		}
	}
	return nullptr;
}

std::vector<Event*> Calendar::TimeIntervalEvent(time_t startTime, time_t endTime) {
	std::vector<Event*> tempVector;

	for each (Event* ev in calendar) {
// даты которые не вошли в заданный промежуток
		if (ev->GetStartDate() < startTime && ev->GetFinishDate() > endTime) {
			tempVector.push_back(ev);
			continue;
		}
// даты которые  вошли в заданный промежуток целиком
		if (ev->GetStartDate()>startTime && ev->GetFinishDate()<endTime) {
			tempVector.push_back(ev);
			continue;
		}
// даты которые  вошли в заданный промежуток частично
		if (ev->GetStartDate() > startTime && ev->GetFinishDate()>endTime && ev->GetStartDate()<endTime) {
			tempVector.push_back(ev);
			continue;
		}
// даты которые  вошли в заданный промежуток частично
		if (ev->GetStartDate()<startTime && ev->GetFinishDate()<endTime && ev->GetFinishDate()>startTime) {
			tempVector.push_back(ev);
			continue;
		}
	}

	return tempVector;
}
