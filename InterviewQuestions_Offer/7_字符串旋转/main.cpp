//https://www.nowcoder.com/practice/85062aa6016640d188a6a0daf9f5da0e?tpId=49&&tqId=29375&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//对于一个字符串，和字符串中的某一位置，请设计一个算法，将包括i位置在内的左侧部分移动到右边，将右侧部分移动到左边。
//给定字符串A和它的长度n以及特定位置p，请返回旋转后的结果。

#include <string>
#include <iostream>

 std::string rotateString(std::string Str, int Length, int Pos)
 {
	//_ASSERT();
	 std::string Result;
	 Result += Str.substr(Pos+1, Length-Pos-1);
	 Result += Str.substr(0, Pos+1);

	 return Result;
 }