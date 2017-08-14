#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
//#include <cmath>

const long SIZE1 = 39L;
const long SIZE2 = 100 * SIZE1;
const long SIZE3 = 100 * SIZE2;

bool f3(int x) {return x%3 == 0;}
bool f13(int x) {return x%13 == 0;}

int main()
{
   std::vector<int> Numbers(10);

   // ÓÃËæ»úÊıÌî³ävector
   std::srand(/*std::time(0)*/1);
   //std::generate_n(Numbers.begin(), 10, std::rand);
   std::generate(Numbers.begin(), Numbers.end(), std::rand);

   //using function pointers
   int Count3 = std::count_if(Numbers.begin(), Numbers.end(), f3);
   int Count13 = std::count_if(Numbers.begin(), Numbers.end(), f13);

   //using a functor
   class f_mod
   {
   public:
	   f_mod(int dv = 1) : m_dv(dv) {}
	   bool operator() (int x) {return x%m_dv == 0;}

   private:
	   int m_dv;
   };

   int Count3F = std::count_if(Numbers.begin(), Numbers.end(), f_mod(3));
   int Count13F = std::count_if(Numbers.begin(), Numbers.end(), f_mod(13));

   //using lambda
   int Count3L = std::count_if(Numbers.begin(), Numbers.end(), [](int x) {return x%3 == 0;});
   int Count13L = std::count_if(Numbers.begin(), Numbers.end(), [](int x) {return x%13 == 0;});

   return 0;
}