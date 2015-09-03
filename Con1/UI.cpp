#define _CRT_SECURE_NO_WARNINGS //localtime, strcpy, strtok


#include "UI.h"

time_t UI::GetTimeFromStr(char* tempStDate) const {
	char* tempTime = new char[11];

	strcpy(tempTime, tempStDate);

	time_t tekTime = time(NULL);//
	struct tm * timeinfo;//
	timeinfo = localtime(&tekTime);

	char* validDay = strtok(tempTime, "- /.");
	char* validMon = strtok(NULL, "- /.");
	char* validYear = strtok(NULL, "- /.");

	timeinfo->tm_year = atoi(validYear) - 1900;
	timeinfo->tm_mon = atoi(validMon) - 1;
	timeinfo->tm_mday = atoi(validDay);
	
	delete[] tempTime;

	return mktime(timeinfo);
}

void UI::RunUI()
{
	char choice;

	do
	{
		std::cout << "Choose an action:"
					 "\n1 - add event"
					 "\n2 - edit event"
					 "\n3 - remove event"
					 "\n4 - show all events"
					 "\nq - quit" << std::endl;
		choice =static_cast<char>(_getch());
		switch (choice)
		{
		case '1': AddEvent();break;
		case '2': EditEvent();break;
		case '3': RemoveEvent();break;
		case '4': this->calendar.ShowAllEvent();break;
		case 'q': std::cout << "\nHave a nice day!!!" << std::endl;break;
		default : std::cout << "\nWrong choice, try again" << std::endl;break;
		}
	} while (choice != 'q');
}

void UI::AddEvent()
{
	char* name= new char[51];
	time_t startTime;
	time_t endTime;

	if (EnterEvent(name, startTime, endTime)==true) {

		Event* ev=new Event;
		ev->SetName(name);
		ev->SetStartDate(startTime);
		ev->SetFinishDate(endTime);

		this->calendar.AddEvent(ev);
	}
	delete [] name;
}

void UI::EditEvent() {
	char* tempName = new char[51];
	std::cout << "\nEnter event name: ";
	std::cin >> tempName;

	Event* tempEvent=this->calendar.FindEvent(tempName);

	if (tempEvent!=nullptr) {
		char* name = new char[51];
		time_t startTime;
		time_t endTime;
		if (EnterEvent(name, startTime, endTime) == true) {
			tempEvent->SetName(name);
			tempEvent->SetStartDate(startTime);
			tempEvent->SetFinishDate(endTime);
		}
		delete[] name;
	}
	else {
		std::cout << "\nEvent is not found!" << std::endl;
	}

	delete[] tempName;
}

void UI::RemoveEvent() {
	char* tempName = new char[51];
	std::cout << "\nEnter event name: ";
	std::cin >> tempName;

	if (this->calendar.RemoveEvent(tempName)){
		std::cout << "\nYou deletes event "<<tempName << std::endl;
	}
	else {
		std::cout << "\nEvent is not found!" << std::endl;
	}

	delete [] tempName;
}

bool UI::EnterEvent(char *& name, time_t & startTime, time_t & endTime) {

//ÂÂÎÄ ÈÌÅÍÈ
	std::regex patternName("[A-Za-z]{1,50}");
	while (true)
	{
		std::cout << "\nEnter event name (name < 50 symbol ): ";
		std::cin >> name;

		if (std::regex_match(name, patternName))
			break;
		else
			std::cout << "\nIncorrect data!" << std::endl;
	}
//ÂÂÎÄ ÍÀ×ÀËÜÍÎÉ ÄÀÒÛ
	char* tempStDate = new char[11];
	std::regex patternDate("(0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20)[0-9]{2}");
	time_t validTime;

	while (true)
	{
		std::cout << "\nEnter event start date (DD/MM/YYYY) : ";
		std::cin >> tempStDate;

		if (!std::regex_match(tempStDate, patternDate)) {
			std::cout << "\nIncorrect data!" << std::endl;
			continue;
		}
/* validTime - ââåäåííîå âðåìÿ â ñåêóíäàõ ñ 1970 ãîäà
 currentTime - òåêóùåå âðåìÿ â ñåêóíäàõ ñ òîãî æå ãîäà
86400 cåêóíä = ñóòêè */

		time_t currentTime = time(NULL);
		validTime = GetTimeFromStr(tempStDate);

		if (validTime < currentTime + 86400) {
			std::cout << "\nYou can plan only tomorrow" << std::endl;
			continue;
		}
		break;
	}

//ÂÂÎÄ ÊÎÍÅ×ÍÎÉ ÄÀÒÛ
	char* tempFinDate = new char[11];
	time_t finTime;
	while (true)
	{
		std::cout << "\nEnter event finish date (DD/MM/YYYY) : ";
		std::cin >> tempFinDate;

		if (!std::regex_match(tempFinDate, patternDate)) {
			std::cout << "\nIncorrect data!" << std::endl;
			continue;
		}
		finTime = GetTimeFromStr(tempFinDate);

		if (finTime < validTime + 86400) {
			std::cout << "\nYou can plan only next day after start date" << std::endl;
			continue;
		}
		break;
	}

	startTime = validTime;
	endTime=finTime;

	delete[] tempStDate;
	delete[] tempFinDate;
//ÅÑËÈ ÑÎÁÛÒÈß ÑÎÂÏÀÄÀÞÒ ÏÎ ÂÐÅÌÅÍÈ
	std::vector<Event*> tempVector = this->calendar.TimeIntervalEvent(validTime, finTime);

	if (tempVector.size() > 0)
	{
		std::cout << "\nYour event is imposed on:\n";
		for each (Event* ev in tempVector)
		{
			ev->ShowEvent();
		}

		std::cout << "\nDo you want add this event? y/n\n";
		if (_getch() == 'y')
		{
			EditEvent();
			return true;
		}
	}
	else {
		return true;
	}
	return false;
}
