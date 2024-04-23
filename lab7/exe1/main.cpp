#include <iostream>
#include <stdio.h>

float operator"" _Kelvin(long long float temp) {
    return temp - 273.15;
}

float operator"" _Fahrenheit(long long float temp) {
    return (temp - 32) * 5 / 9;
}

int main() {

    float a = 200_Kelvin;
    float b = 100_Fahrenheit;

    std::cout << "200 K in C: " << a << '\n';
    std::cout << "100 F in C: " << b << '\n';

    return 0;
}
