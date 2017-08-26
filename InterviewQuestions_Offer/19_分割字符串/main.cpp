#include <string>
#include <vector>
#include <iostream>

void splitString(const std::string& vInputStr, const std::string& vOperator, std::vector<std::string>& voResultSet)
{
	if (vOperator.empty())
	{
		voResultSet.push_back(vInputStr);
	}

	int FirstIndex = 0, SecondIndex = -1;
	bool bFlag = false;

	while (FirstIndex != vInputStr.length() - 1)
	{
		for (unsigned int i=FirstIndex; i<vInputStr.length(); ++i)
		{
			bFlag = false;
			for (unsigned int k=0; k<vOperator.size(); ++k)
			{
				if (vInputStr[i] == vOperator[k])
				{
					bFlag = true;
					FirstIndex = i;
					break;
				}
			}

			if (bFlag)
			{
				break;
			}
		}

		for (unsigned int i=FirstIndex+1; i<vInputStr.length(); ++i)
		{
			bFlag = false;

 			for (unsigned int k=0; k<vOperator.size(); ++k)
			{
				if (vInputStr[i] == vOperator[k])
				{
					bFlag = true;
					SecondIndex = i;
					break;
				}
			}

			if (bFlag)
			{
				break;
			}
		}

		if (SecondIndex <= FirstIndex)
		{
			break;
		}
		else
		{
			voResultSet.push_back(vInputStr.substr(FirstIndex + 1, SecondIndex - (FirstIndex + 1)));
			FirstIndex = SecondIndex;
		}
	}
}


#include <sstream>

int main()
{
	std::string TestStr = "{1234,0000}";
	std::string Splitor = "{},";

	std::vector<std::string> ResultSet;
	splitString(TestStr, Splitor, ResultSet);

	return 0;
}