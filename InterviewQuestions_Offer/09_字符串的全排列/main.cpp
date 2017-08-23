//http://www.cnblogs.com/weiyi-mgh/p/6667742.html
//字符串的全排列和组合
//本例为求字符串的全排列

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool hasSame(const std::string& vStr, int vStart, int i)
{
	for (int j=vStart; j<i; j++)
	{
		if (vStr[j] == vStr[i])
		{
			return true;
		}
	}

	return false;
}

void permutationResive(std::string& vStr, int vStart, int vEnd, std::vector<std::string>& voResultSet)
{
	if (vStart == vEnd)
	{
		voResultSet.push_back(vStr);
	}
	else
	{
		for (unsigned int i=vStart; i<vEnd; ++i)
		{
			if (!hasSame(vStr, vStart, i))
			{
				char Temp = vStr[i];
				vStr[i] = vStr[vStart];
				vStr[vStart] = Temp;

				permutationResive(vStr, vStart+1, vEnd, voResultSet);

				Temp = vStr[i];
				vStr[i] = vStr[vStart];
				vStr[vStart] = Temp;
			}
		}
	}
}

std::vector<std::string> permutation(std::string& vStr)
{
	std::vector<std::string> ResultSet;

	if (vStr.size() == 0)
	{
		return ResultSet;
	}

	permutationResive(vStr, 0, vStr.size(), ResultSet);

	sort(ResultSet.begin(), ResultSet.end());
	return ResultSet;
}

int main()
{
	std::string Str = "abc";
	std::vector<std::string> ResultSet = permutation(Str);

	return 0;
}