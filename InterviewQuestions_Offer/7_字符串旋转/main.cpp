//https://www.nowcoder.com/practice/85062aa6016640d188a6a0daf9f5da0e?tpId=49&&tqId=29375&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//����һ���ַ��������ַ����е�ĳһλ�ã������һ���㷨��������iλ�����ڵ���ಿ���ƶ����ұߣ����Ҳಿ���ƶ�����ߡ�
//�����ַ���A�����ĳ���n�Լ��ض�λ��p���뷵����ת��Ľ����

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