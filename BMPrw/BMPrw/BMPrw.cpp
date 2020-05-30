#include <iostream>
#include<string>
#include <cstring>
#include <time.h>
#include "BMP.cpp"

int main() {
    time_t start, end;
    start = clock();
    for (int i = 1; i < 49; i++) {

        std::string pathin = "C:\\Users\\danse\\Desktop\\Prog\\3 year\\Paralel\\Labs\\img\\img" + std::to_string(i) + ".bmp";
        std::cout << pathin << "\n";
        std::string pathout = "C:\\Users\\danse\\Desktop\\Prog\\3 year\\Paralel\\Labs\\bw\\img" + std::to_string(i) + ".bmp";

        const char* cpathin = pathin.c_str();
        const char* cpathout = pathout.c_str();
        
        BMP bmp1(cpathin); 
        bmp1.grayscale();
        bmp1.write(cpathout);
    }
    
    printf("%.6f, seconds (rgb to grescale )", double(clock() - start) / 1000);

}