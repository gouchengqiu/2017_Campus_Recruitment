 #include <boost/archive/text_oarchive.hpp> 
 #include <boost/archive/text_iarchive.hpp> 
 #include <iostream> 
 #include <fstream> 
 
//当 boost::archive::text_oarchive 被用来把数据序列化为文本流， boost::archive::text_iarchive 就用来从文本流恢复数据。
 void save() 
 { 
 	std::ofstream file("archiv.txt"); //流可以是一个文件流，或其他流，如 stringstream 流也是可以的
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