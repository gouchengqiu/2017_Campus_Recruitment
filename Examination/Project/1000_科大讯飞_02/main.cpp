#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

std::vector<char> g_Name;
std::vector<int>  g_Score;
std::vector<int>  g_JuShu;

template<typename T>
int getIndex(const std::vector<T> vSet, T vName)
{
	for (int i=0; i<vSet.size(); ++i)
	{
		if (vName == vSet[i])
		{
		 return i;
		}
	}
	return -1;
}

void parseOneLineBiSai(std::string& vOneLine)
{
    std::stringstream SS;
	SS << vOneLine;

	std::string Name2Name;
	std::string Score2Score;
	SS >> Name2Name >> Score2Score;

	int Pos = Name2Name.find('-');
	Name2Name.replace(Pos, 1, 1, ' ');

	Pos = Score2Score.find(':');
	Score2Score.replace(Pos, 1, 1, ' ');

	 std::stringstream S1, S2;
	S1 << Name2Name;
	S2 << Score2Score;

	char NameA, NameB;
	int  ScoreA, ScoreB;
	S1 >> NameA >> NameB;
	S2 >> ScoreA >> ScoreB;

	int IndexA = getIndex(g_Name, NameA);
	int IndexB = getIndex(g_Name, NameB);

	if (ScoreA > ScoreB)
	{
	   g_Score[IndexA] += 3;
	   g_JuShu[IndexA] += 1;
	}
	else if (ScoreA < ScoreB)
	{
		 g_Score[IndexB] += 3;
		 g_JuShu[IndexB] += 1;
	}
	else {
		 g_Score[IndexA] += 1;
		 g_Score[IndexB] += 1;
	}
}

int main()
{
	int Number;
	std::cin >> Number;

	for (int i=0; i<Number; ++i)
	{
		//std::cin >> pName[i];
		char TempName;
		std::cin >> TempName;
		g_Name.push_back(TempName);
		g_Score.push_back(0);
		g_JuShu.push_back(0);
	}

	int NumBiSai = Number * (Number - 1) / 2;

	std::cin.ignore();
	for (int i=0; i<NumBiSai; ++i)
	{
// 		std::string OneLine;
// 		std::cin >> OneLine;
		char OneLine[50];
		std::cin.getline(OneLine, 50);
		std::string StrOneLine(OneLine);
		parseOneLineBiSai(StrOneLine);
	}

	std::vector<int> Temp = g_Score;
	sort(Temp.begin(), Temp.end());

	int OutNum = Number / 2;
	int Border = Temp[Temp.size() - OutNum];

	int ResultNum = 0;
	std::vector<int> EqualScoreNameIndex;
 	for (int i=Number-1; i>=0; --i)
 	{
		if (Temp[i] > Border)
		{
		  ResultNum++;
		  int ScoreIndex = getIndex(g_Score, Temp[i]);
		  std::cout << g_Name[ScoreIndex] << std::endl;
		  if (ResultNum >= OutNum)
		  {
		     break;
		  }
		}
		else if (Temp[i] == Border)
		{
			int ScoreIndex = getIndex(g_Score, Temp[i]);
			EqualScoreNameIndex.push_back(ScoreIndex);
		}
		else
		{
			break;
		}
 	}

	if (ResultNum < OutNum)
	{
	  std::map<int, int> JuShuMap;
	  for (int i=0; i<EqualScoreNameIndex.size(); ++i)
	  {
		  JuShuMap.insert(std::make_pair(g_JuShu[EqualScoreNameIndex[i]], EqualScoreNameIndex[i]));
	  }
	 // sort(JuShuMap.begin(), JuShuMap.end());

	  std::map<int, int>::reverse_iterator Iter = JuShuMap.rbegin();

	  for (int i=0; i<OutNum - ResultNum; ++i)
	  {
		  int NameIndex = Iter->second;
		  std::cout << g_Name[NameIndex] << std::endl;
		  Iter++;
	  }
	}

	system("pause");
	return 0;
}