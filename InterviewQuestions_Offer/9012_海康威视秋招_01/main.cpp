#include <iostream>
#include <string>
#include <sstream>

bool isTimeStrRight(const std::string& vInputStr, std::string& DayStr, std::string& TimeStr)
{
	//std::string DayStr;
	//std::string TimeStr;

	std::stringstream SS;
	SS << vInputStr;

	SS >> DayStr;
	SS >> TimeStr;

	int Pos = DayStr.find('-');
	int TotalNum = 0;

	while (Pos != std::string::npos)
	{
		TotalNum++;
		DayStr.replace(Pos, 1, 1, ' ');
		Pos = DayStr.find('-');
	}
	
	TotalNum++;
	if (TotalNum != 3)
	{
		return false;
	}

	Pos = TimeStr.find(':');
	TotalNum = 0;
	while (Pos != std::string::npos)
	{
		TotalNum++;
		TimeStr.replace(Pos, 1, 1, ' ');
		Pos = TimeStr.find(':');
	}

		TotalNum++;
	if (TotalNum != 3)
	{
		return false;
	}

	return true;
}

int main()
 {
// 	std::string InputString;
// 	std::cin >> InputString;

	std::string InputString = "3,2017-07-25 06:00:00,2017-07-25 06:06:00";
	int Pos = InputString.find(',');
	int TotalNum = 0;

	while (Pos != std::string::npos)
	{
		InputString.replace(Pos, 1, 1, ' ');
		Pos = InputString.find(',');
		TotalNum++;
	}

	std::stringstream SS;
	SS << InputString;

	int NumStation;
	SS >> NumStation;

	if (NumStation < 3)
	{
		std::cout << "incorrect data" << std::endl;
		return 0;
	}

	std::string TempStr;

	std::string FirstTimeStr;
	SS >> FirstTimeStr;
	SS >> TempStr;
	FirstTimeStr += " ";
	FirstTimeStr += TempStr;

	std::string FirstDayStr1;
	std::string FirstTimeStr1;

	if (!isTimeStrRight(FirstTimeStr, FirstDayStr1, FirstTimeStr1))
	{
		std::cout << "incorrect data" << std::endl;
		return 0;
	}

	std::string CurrentTimeStr;
	SS >> CurrentTimeStr;
	SS >> TempStr;
	CurrentTimeStr += " ";
	CurrentTimeStr += TempStr;

	std::string CurrentDayStr1;
	std::string CurrentTimeStr1;
	if (!isTimeStrRight(CurrentTimeStr, CurrentDayStr1, CurrentTimeStr1))
	{
		std::cout << "incorrect data" << std::endl;
		return 0;
	}

	int NumHour, NumMinutes, NumSeconds;

	int FirstHour, FirstMinutes, FirstSeconds, CurrentHour, CurrentMinutes, CurrentSeconds;
	SS.clear(); //¹Ø¼ü°¡
	//SS.str(FirstTimeStr1);
	SS << FirstTimeStr1;

	SS >> FirstHour;
	SS >> FirstMinutes;
	SS >> FirstSeconds;

	SS.clear();
	SS << CurrentTimeStr1;

	SS >> CurrentHour;
	SS >> CurrentMinutes;
	SS >> CurrentSeconds;

	NumHour = CurrentHour - FirstHour;
	NumMinutes = CurrentMinutes - FirstMinutes;

	int DiffMinutes = NumHour * 60 + NumMinutes;

	int OneCircleSpendTime = NumStation * 5 + (NumStation - 1) * 10;
	int QuanShu = DiffMinutes / OneCircleSpendTime + 1;

	int ResultA;
	int YuShu = DiffMinutes % 15;

	DiffMinutes = DiffMinutes % OneCircleSpendTime;
	ResultA = DiffMinutes / 15;
	if (YuShu >= 0 && YuShu <= 5)
	{
		std::cout << QuanShu << ";" << ResultA + 1 << std::endl;
	}
	else
	{
		std::cout << QuanShu << ";" << ResultA + 1 << "-" << ResultA + 2 << std::endl;
	}

	return 0;
}