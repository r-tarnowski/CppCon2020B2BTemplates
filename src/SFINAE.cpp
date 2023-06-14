#include <iostream>



using std::cout;
using std::endl;

void printHeader() {
    cout << endl;
    cout << "================================================" << endl;
    cout << "                  CppCon 2020                   " << endl;
    cout << "           Back to Basics: Templates            " << endl;
    cout << "           Lecture by Andreas Fertig            " << endl;
    cout << "                SFINAE Example                  " << endl;
    cout << "================================================" << endl;
    cout << endl;
}

template<typename T>
std::enable_if_t<not std::is_floating_point_v<T>, bool>
equal( const T & a, const T & b ) {
    std::cout << "equal() method for non-floating types called" << std::endl;
    return a == b;
}

template<typename T>
std::enable_if_t<std::is_floating_point_v<T>, bool>
equal( const T & a, const T & b ) {
    std::cout << "equal() method for floating types called" << std::endl;
    return std::abs( a - b ) < 0.00001;
}

int main(int argc, char *argv[]) {
    printHeader();

    int iA = 2;
    int iB = 1;
    std::cout << "equal( iA, iB ) -> ";
    std::cout << equal( iA, iB ) << std::endl;
    std::cout << "equal( iA, iA ) -> ";
    std::cout << equal( iA, iA ) << std::endl;

    double dA = 2.0;
    double dB = 1.0;
    std::cout << "equal( dA, dB ) -> ";
    std::cout << equal( dA, dB ) << std::endl;
    std::cout << "equal( dA, dA ) -> ";
    std::cout << equal( dA, dA ) << std::endl;

    float fA = 2.0;
    float fB = 1.0;
    std::cout << "equal( fA, fB ) -> ";
    std::cout << equal( fA, fB ) << std::endl;
    std::cout << "equal( fA, fA ) -> ";
    std::cout << equal( fA, fA ) << std::endl;

    //std::cout << "equal( fA, dB ) -> ";
    //std::cout << equal( fA, dB ) << std::endl; //ERROR - conflicting types float and double

    return 0;
}