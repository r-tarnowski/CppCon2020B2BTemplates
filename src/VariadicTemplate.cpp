#include <iostream>



using std::cout;
using std::endl;

void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "                  CppCon 2020                   " << endl;
   cout << "           Back to Basics: Templates            " << endl;
   cout << "           Lecture by Andreas Fertig            " << endl;
   cout << "           Variadic Template Example            " << endl;
   cout << "================================================" << endl;
   cout << endl;
}

template<typename T,
         typename... Ts>
constexpr auto min( const T& a, const T& b, const Ts&... ts ) {
   const auto m = a < b ? a : b;
   std::cout << "min( const T& a, const T& b, const Ts&... ts ) : sizeof...(ts) = "
             << sizeof...(ts) << std::endl;
   if constexpr (sizeof...(ts) > 0) {
      return min( m, ts...);
   }
   return m;
}

int main(int argc, char *argv[]) {
   printHeader();

   std::cout << "Calling min( 3, 2, 3, 4, 5 ):" << std::endl;
   auto min1 = min( 3, 2, 3, 4, 5 );
   std::cout << "min( 3, 2, 3, 4, 5 ) = " << min1 << std::endl;

   std::cout << std::endl;

   std::cout << "Calling min( 3, 2 ):" << std::endl;
   auto min2 = min( 3, 2 );
   std::cout << "min( 3, 2 ) = " << min2 << std::endl;

   return 0;
}
