#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <omp.h>
#include "BMP.cpp"

const int NUMBER_OF_THREADS = 4;
const int NUMBER_OF_FILES = 48;

using namespace std;


int main()
{
    double time_start, time_end;
	int i;
    time_start = omp_get_wtime(); 
	
 #pragma omp parallel for num_threads(4)
	for (i = 1; i < NUMBER_OF_FILES+1; i++)
	{
        std::string pathin = "C:\\Users\\danse\\Desktop\\Prog\\3 year\\Paralel\\Labs\\img\\img" + std::to_string(i) + ".bmp";
        std::cout << pathin << "\n";
        std::string pathout = "C:\\Users\\danse\\Desktop\\Prog\\3 year\\Paralel\\Labs\\bw\\img" + std::to_string(i) + ".bmp";

        const char* cpathin = pathin.c_str();
        const char* cpathout = pathout.c_str();

        BMP bmp1(cpathin);

        bmp1.grayscale();
        bmp1.write(cpathout);
	}

    time_end = omp_get_wtime(); 

    printf("OpenMP: total elapsed time: %.6f sec. Number of threads: %d.\n", time_end - time_start, NUMBER_OF_THREADS);
}
