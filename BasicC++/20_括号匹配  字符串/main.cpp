#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef pair<char, int> CHARPOSITION;  

std::string RemoveBracketsAndContents(std::string Input)  
{  
	stack<CHARPOSITION> staCheak;  
	for (size_t i = 0; i < Input.length(); i++)  
	{  
		char ch = Input[i];  
		switch(ch)  
		{  
		case  '(':  
		case  '[':  
		case  '{':  
		case  '<':  
			{  
				staCheak.push(make_pair(Input[i],i));  
				break;  
			}  
		case ')':  
		case ']':  
		case '}':  
		case '>':  
			{  
				if (!staCheak.empty())  
				{  
					CHARPOSITION charPos = staCheak.top();  
					if ( (Input[i] == ')' && charPos.first == '(' ) || (Input[i] == ']' && charPos.first == '[' )   
						|| (Input[i] == '>' && charPos.first == '<' ) || (Input[i] == '}' && charPos.first == '{' ) )  
					{  
						staCheak.pop();  
						size_t Left = charPos.second;  
						Input.replace(Left,i - Left + 1, i - Left + 1, ' ');  
					}  
				}  
				break;  
			}  
		}  
	}  
	return Input;   
}  

int main()
{
	std::string Res = RemoveBracketsAndContents("{abc}{d}");

	return 0;
}