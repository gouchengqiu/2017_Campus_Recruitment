//#include <iostream>  
//#include <algorithm>  
//#include <functional>  
//#include <string>  
//#include <vector>  
//
//using namespace std;  
//
//// Return true if string str starts with letter 'S'  
//int MatchFirstChar(const string& str)  
//{  
//	string s("S") ;  
//	return s == str.substr(0, 1) ;  
//}  
//
//int main()  
//{  
//	const int VECTOR_SIZE = 8 ;  
//
//	// Define a template class vector of strings  
//	typedef vector<string > StringVector ;  
//
//	//Define an iterator for template class vector of strings  
//	typedef StringVector::iterator StringVectorIt ;  
//
//	StringVector NamesVect(VECTOR_SIZE) ;   //vector containing names  
//
//	StringVectorIt start, end, it ;  
//
//	int result = 0 ;   // stores count of elements that match value.  
//
//	// Initialize vector NamesVect  
//	NamesVect[0] = "She" ;  
//	NamesVect[1] = "Sells" ;  
//	NamesVect[2] = "Sea" ;  
//	NamesVect[3] = "Shells" ;  
//	NamesVect[4] = "by" ;  
//	NamesVect[5] = "the" ;  
//	NamesVect[6] = "Sea" ;  
//	NamesVect[7] = "Shore" ;  
//
//	// print content of NamesVect  
//	cout << "NamesVect { " ;  
//	for(it = start; it != end; it++)  
//		cout << *it << " " ;  
//	cout << " }\n" << endl ;  
//
//	start = NamesVect.begin() ;   // location of first  
//	// element of NamesVect  
//
//	end = NamesVect.end() ;       // one past the location  
//	// last element of NamesVect 
//
//	// Count the number of elements in the range [first, last +1)  
//	// that start with letter 'S'  
//	result = count_if(start, end, MatchFirstChar) ;  
//
//	// print the count of elements that start with letter 'S'  
//	cout << "Number of elements that start with letter \"S\" = "  
//		<< result << endl  ;  
//}

#include <iostream>  
#include <algorithm>  
#include <functional>  
#include <string>  
#include <vector>  

using namespace std;  


int main()  
{  
	const int VECTOR_SIZE = 8 ;  

	// Define a template class vector of strings  
	typedef vector<string > StringVector ;  

	//Define an iterator for template class vector of strings  
	typedef StringVector::iterator StringVectorIt ;  

	StringVector NamesVect(VECTOR_SIZE) ;   //vector containing names  

	string value("Sea") ;  // stores the value used  
	// to count matching elements  

	StringVectorIt start, end, it ;  

	ptrdiff_t result = 0 ;   // stores count of elements  
	// that match value.  

	// Initialize vector NamesVect  
	NamesVect[0] = "She" ;  
	NamesVect[1] = "Sells" ;  
	NamesVect[2] = "Sea" ;  
	NamesVect[3] = "Shells" ;  
	NamesVect[4] = "by" ;  
	NamesVect[5] = "the" ;  
	NamesVect[6] = "Sea" ;  
	NamesVect[7] = "Shore" ;  

	start = NamesVect.begin() ;   // location of first  
	// element of NamesVect  

	end = NamesVect.end() ;       // one past the location  
	// last element of NamesVect  

	// print content of NamesVect  
	cout << "NamesVect { " ;  
	for(it = start; it != end; it++)  
		cout << *it << " " ;  
	cout << " }\n" << endl ;  

	// Count the number of elements in the range [first, last +1)  
	// that match value.  
	result = count(start, end, value) ;  

	// print the count of elements that match value  
	cout << "Number of elements that match \"Sea\" = "  
		<< result << endl  ;  
}  