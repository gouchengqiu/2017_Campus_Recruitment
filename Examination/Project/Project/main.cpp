#include <iostream>
#include <string>

int computeMinNum(std::string& vStr)
{
	bool IsBreak = true;

	for (int i=0; i<vStr.length()-1; ++i)
	{
		if (vStr[i] == 'L')
		{
		  continue;
		}
		else if (vStr[i] == 'R')
		{
		   if (vStr[i+1] == 'L')
		   {  
		      int LIndex = i+1;
			  int RIndex = i;
			  int Prev = i - 1;
			  int Back = i + 2;
              if (Prev >= 0 && vStr[Prev] == 'R')
			  {
				  vStr.erase(RIndex, 1);
				  i -= 2;
				  continue;
			  }

			  if (Back < vStr.length() && vStr[Back] == 'L')
			  {
				  vStr.erase(LIndex, 1);
				  i--;
				  continue;
			  }

			  vStr.erase(LIndex, 1);
		   }
		   else {continue;}
		}
	}

	return vStr.length();
}

int main()
{
	//std::string Str = "LRRLRL";
	std::string Str;
	std::cin >> Str;

	int Test = computeMinNum(Str);
	std::cout << Test;

	return 0;
}