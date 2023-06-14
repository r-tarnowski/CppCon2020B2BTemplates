#include <iostream>



using std::cout;
using std::endl;

void printHeader() {
    cout << endl;
    cout << "================================================" << endl;
    cout << "                  CppCon 2020                   " << endl;
    cout << "           Back to Basics: Templates            " << endl;
    cout << "           Lecture by Andreas Fertig            " << endl;
    cout << "                    Requires                    " << endl;
    cout << "            (modified a little bit)             " << endl;
    cout << "================================================" << endl;
    cout << endl;
}

template<typename T, typename U>
concept IsFloatingPoint = std::is_floating_point_v<T> || std::is_floating_point_v<U>;

template<typename T, typename U >
requires IsFloatingPoint< T, U >
bool equal( const T & a, const U & b ) {
    std::cout << "equal() method for floating types called" << std::endl;
    return std::abs( a - b ) < 0.00001;
}

template<typename T, typename U >
bool equal( const T & a, const U & b ) {
    std::cout << "equal() method for non-floating types called" << std::endl;
    return a == b;
}


int main(int argc, char *argv[]) {
    printHeader();

    int iA = 2;
    int iB = 1;
    std::cout << "equal( iA, iB ) -> ";
    std::cout << equal( iA, iB ) << std::endl;
    std::cout << "equal( iA, iA ) -> ";
    std::cout << equal( iA, iA ) << std::endl;

    short int siA = 2;
    short int siB = 1;
    std::cout << "equal( siA, siB ) -> ";
    std::cout << equal( siA, siB ) << std::endl;
    std::cout << "equal( siA, siA ) -> ";
    std::cout << equal( siA, siA ) << std::endl;

    std::cout << "equal( iA, siB ) -> ";
    std::cout << equal( iA, siB ) << std::endl;
    std::cout << "equal( iA, siA ) -> ";
    std::cout << equal( iA, siA ) << std::endl;

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

    std::cout << "equal( fA, dB ) -> ";
    std::cout << equal( fA, dB ) << std::endl;

    std::cout << "equal( fA, dA ) -> ";
    std::cout << equal( fA, dA ) << std::endl;

    std::cout << "equal( iA, dB ) -> ";
    std::cout << equal( iA, dB ) << std::endl;

    std::cout << "equal( iA, dA ) -> ";
    std::cout << equal( iA, dA ) << std::endl;

    return 0;
}
