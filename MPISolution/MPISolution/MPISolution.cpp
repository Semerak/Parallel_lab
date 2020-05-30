#include <mpi.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include "BMP.cpp"


int ALL_FILES = 48;

int main(int argc, char** argv)
{

    time_t start;
    int size, rank, i;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double t_from;
    if (rank == 0) {
        start = clock();
        printf("Total processes count = %d\n", size);
    }
      
    int startfile = (ALL_FILES * (rank-1)) / (size-1) +1 ;
    int finishfile = (ALL_FILES * rank) / (size-1) +1 ;
    if (startfile >= finishfile) {
        printf("Proces %d is doing nothing\n");
    }
    else {
        if (rank != 0) {
            int cur_file = startfile;
            while (cur_file < finishfile) {
                printf("Proces %d is working on %d\n", rank, cur_file);

                std::string pathin = "C:\\Users\\danse\\Desktop\\Prog\\3 year\\Paralel\\Labs\\img\\img" + std::to_string(cur_file) + ".bmp";
                std::string pathout = "C:\\Users\\danse\\Desktop\\Prog\\3 year\\Paralel\\Labs\\bw\\img" + std::to_string(cur_file) + ".bmp";

                const char* cpathin = pathin.c_str();
                const char* cpathout = pathout.c_str();

                BMP bmp1(cpathin);

                bmp1.grayscale();
                bmp1.write(cpathout);

                cur_file++;
            }
        }
    }
    
    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        printf("%.6f seconds (rgb to grescale )\n", double(clock() - start) / 1000 );
    }
    
    MPI_Finalize();

    return 0;
}