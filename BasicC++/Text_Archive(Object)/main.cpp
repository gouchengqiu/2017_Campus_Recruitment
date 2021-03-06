//#include <boost/archive/text_oarchive.hpp> 
//#include <boost/archive/text_iarchive.hpp> 
//#include <iostream> 
//#include <sstream> 
//
//std::stringstream ss; 
//
//class person 
//{ 
//public: 
//	person() 
//	{ 
//	} 
//
//	person(int age) 
//		: age_(age) 
//	{ 
//	} 
//
//	int age() const 
//	{ 
//		return age_; 
//	} 
//
//private: 
//	friend class boost::serialization::access; 
//
//	template <typename Archive> 
//	void serialize(Archive &ar, const unsigned int version) 
//	{ 
//		ar & age_; 
//	} 
//
//	int age_; 
//}; 
//
//void save() 
//{ 
//	boost::archive::text_oarchive oa(ss); 
//	person p(31); 
//	oa << p; 
//} 
//
//void load() 
//{ 
//	boost::archive::text_iarchive ia(ss); 
//	person p; 
//	ia >> p; 
//	std::cout << p.age() << std::endl; 
//} 
//
//int main() 
//{ 
//	save(); 
//	load(); 
//
//	system("pause");
//	return 0;
//} 

#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <iostream> 
#include <sstream> 

std::stringstream ss; 

class person 
{ 
public: 
	person() 
	{ 
	} 

	person(int age) 
		: age_(age) 
	{ 
	} 

	int age() const 
	{ 
		return age_; 
	} 

private: 
	friend class boost::serialization::access; 

	template <typename Archive> 
	friend void serialize(Archive &ar, person &p, const unsigned int version);  //serialization申明为friend使得该函数可以访问person的私有变量

	int age_; 
}; 

template <typename Archive> 
void serialize(Archive &ar, person &p, const unsigned int version) 
{ 
	ar & p.age_; 
} 

void save() 
{ 
	boost::archive::text_oarchive oa(ss); 
	person p(31); 
	oa << p; 
} 

void load() 
{ 
	boost::archive::text_iarchive ia(ss); 
	person p; 
	ia >> p; 
	std::cout << p.age() << std::endl; 
} 

int main() 
{ 
	save(); 
	load(); 
} 
