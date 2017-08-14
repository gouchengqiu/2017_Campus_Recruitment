#include <iostream>
#include <string>
#include <sstream>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

class CTest
{
public:
	CTest(bool b, char ch, int i, double d, const std::string& str) : m_bool(b), m_char(ch), m_int(i), m_double(d), m_str(str)
	{

	}

private:
	bool        m_bool;
	char        m_char;
	int         m_int;
	double      m_double;
	std::string m_str;

	friend class boost::serialization::access;

	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar& m_bool;
		ar& m_char;
		ar& m_int;
		ar& m_double;
		ar& m_str;
	}
};

int main()
{
	CTest test(true, 'm', 50, 17.89, "fuzhijie");

	std::stringstream binary_sstream;
	std::stringstream text_sstream;

	long long begin, end;
	int size;

	//使用二进制的方式序列化
	boost::archive::text_oarchive text_oa(text_sstream);
	boost::archive::binary_oarchive binary_oa(binary_sstream);

	begin = time(NULL);
	std::string Test;
	for(int i = 0; i < 1000000; ++i)
	{
		text_oa << test;
		Test = text_sstream.str();
		int ik = 0;
	}
	std::cout << binary_sstream << std::endl;
	end = time(NULL);

	size = text_sstream.tellp() / (1024 * 1024);

	std::cout << "text serialization seconds: " << end - begin << ", space: " << size << std::endl;

	begin = time(NULL);
	for(int i = 0; i < 1000000; ++i)
	{
		binary_oa << test;
	}
	end = time(NULL);

	//以MB为单位
	size = binary_sstream.tellp() / (1024 * 1024);

	std::cout << "binary serialization seconds: " << end - begin << ", space: " << size << std::endl;

	return 0;
};