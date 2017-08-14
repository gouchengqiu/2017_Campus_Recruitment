 #include <boost/archive/text_oarchive.hpp> 
 #include <boost/archive/text_iarchive.hpp> 
 #include <iostream> 
 #include <fstream> 
 
//�� boost::archive::text_oarchive ���������������л�Ϊ�ı����� boost::archive::text_iarchive ���������ı����ָ����ݡ�
 void save() 
 { 
 	std::ofstream file("archiv.txt"); //��������һ���ļ����������������� stringstream ��Ҳ�ǿ��Ե�
 	boost::archive::text_oarchive oa(file); 
 	int i = 10; 
 	oa << i; 
 } 
 
 void load() 
 { 
 	std::ifstream file("archiv.txt"); 
 	boost::archive::text_iarchive ia(file); 
 	int i = 0; 
 	ia >> i; 
 	std::cout << i << std::endl; 
 } 
 
 int main() 
 { 
 	save(); 
 	load(); 

	system("pause");
	return 0;
 } 