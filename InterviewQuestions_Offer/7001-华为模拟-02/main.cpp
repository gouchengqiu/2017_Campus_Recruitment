#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

std::map<long int, long int> DataMap;
std::map<long int, bool> OutputDataMap;

vector<string> split(const string &s, const string &seperator){
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while(i != s.size()){
		//找到字符串中首个不等于分隔符的字母；
		int flag = 0;
		while(i != s.size() && flag == 0){
			flag = 1;
			for(string_size x = 0; x < seperator.size(); ++x)
				if(s[i] == seperator[x]){
					++i;
					flag = 0;
					break;
				}
		}

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while(j != s.size() && flag == 0){
			for(string_size x = 0; x < seperator.size(); ++x)
				if(s[j] == seperator[x]){
					flag = 1;
					break;
				}
				if(flag == 0) 
					++j;
		}
		if(i != j){
			result.push_back(s.substr(i, j-i));
			i = j;
		}
	}
	return result;
}


void AddDependency(unsigned int ModuleId, unsigned int DependModuleId)
{
	DataMap[ModuleId] = DependModuleId;
}

bool isIter(unsigned int ModuleIdSrc, unsigned int ModuleIdDst)
{
	auto Element = DataMap.find(DataMap[ModuleIdSrc]);
	if (Element == DataMap.end())
	{
		return false;
	}

	if (Element->second == ModuleIdDst)
	{
		return true;
	}
	else
	{
		isIter(Element->second, ModuleIdDst);
	}
}

bool MouldeIsCycularDependency(unsigned int ModuleId)
{
	auto Element = DataMap.find(DataMap[ModuleId]);
	if (Element == DataMap.end())
	{
		return false;
	}

	return isIter(Element->second, ModuleId);
}

bool isOutput(const std::vector<std::string>& vSet, const std::string& vTargetStr)
{
	for (auto& Str : vSet)
	{
		if (!strcmp(vTargetStr.c_str(), Str.c_str()))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	
	std::string Str;
	while (std::getline(std::cin, Str))
 	{
		if (!Str.empty())
		{
			std::vector<std::string> DataSet;
			DataSet = split(Str, " {},");

			std::string DataA = DataSet[0];
			std::string DataB = DataSet[1];
			
			AddDependency(atoi(DataSet[0].c_str()), atoi(DataSet[1].c_str()));
		}
	}

	std::vector<std::string> OutputStr;
	for (unsigned int i=0; i<DataMap.size(); ++i)
	{
		auto Element = DataMap.find(DataMap[i]);
		if (!isOutput(OutputStr, Str))
		{
			std::cout << "{" << Element->first << ", " << MouldeIsCycularDependency(Element->first) << "}";
			if (i != DataMap.size() - 1)
			{
				std::cout << "," << std::endl;
			}

			stringstream ss;
			std::string Temp;
			ss << Element->first;
			ss >> Temp;
			OutputStr.push_back(Temp);
		}
	}
}