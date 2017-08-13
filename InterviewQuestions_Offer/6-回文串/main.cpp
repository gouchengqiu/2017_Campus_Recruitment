#include <iostream>
#include <string>

int findPos(const std::string& vInputStr, char vLetter, bool IsFirstAppear)
{
	int Position = -1;
	if (!IsFirstAppear)
	{
		for (int i=vInputStr.length()-1; i>=0; i--)
		{
			if (vLetter == vInputStr[i])
			{
				Position = i;
				break;
			}

		}
	}

	return Position;
}

int deleteToMakePalindrome(std::string vInputStr)
{
	int NumDelete = 0;
	int IndexI = 0, IndexJ = vInputStr.length()-1;

	while (IndexI < IndexJ)
	{
		if (vInputStr[IndexI] != vInputStr[IndexJ])
		{
			vInputStr.erase(IndexJ, 1);
			IndexJ -= 1;
			NumDelete += 1;

			if (IndexI+1 <= IndexJ)
			{
				std::string Others = vInputStr.substr(IndexI + 1, IndexJ - IndexI);
			    int Pos = findPos(Others, vInputStr[IndexI], false);
				
				if (Pos < 0) //Ã»ÕÒµ½
				{
					vInputStr.erase(IndexI, 1);
					IndexI--;
					NumDelete++;
				}
			
				if (Pos >= 0)
				{
					vInputStr.erase(IndexI+1+Pos+1, Others.length() - Pos - 1);
					NumDelete += (Others.length()- Pos - 1);
					IndexJ -= (Others.length()- Pos + 1);
				}
			}
		}
		IndexJ--;
		IndexI++;
	}

	return NumDelete;
}

#define MAXLENGTH 1000

int main()
{
	int NumStrings;
	std::cin >> NumStrings;
	char** ppString = new char*[NumStrings];

	int* pResult = new int[NumStrings];
	for (unsigned int i=0; i<NumStrings; i++)
	{
		ppString[i] = new char[MAXLENGTH];
		std::cin >> ppString[i];
		pResult[i] = deleteToMakePalindrome(ppString[i]);
	}

	for (unsigned int i=0; i<NumStrings; i++)
	{
		std::cout << pResult[i] << std::endl;
		delete[] ppString[i];
	}

	delete[] ppString;
	delete[] pResult;
}