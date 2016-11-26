#include <iostream>
#include <pthread.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

// default matrix dimensions
const int default_dim = 8000;
int numthreads = 1;
int rows1=8000;
int cols1=8000;
int rows2=8000;
int cols2=1;
int matrix1[default_dim][default_dim];
int matrix2[default_dim][1];
int product[default_dim][default_dim];

// function declarations
void *add(void *);
void *multiply(void *);
int multiplication_timer(int, int, int&);
void populate_matrices(int, int, int&, int&, int&, int&);
string NumberToString ( int Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}
// main function
int main(){
	// change these variables alone to control number of iterations, threads, row and column dimensions
	int iteration_limit = 10000;
	int threads = 8;
	int rows = 8192, cols = 8192;
	string filetitle = "ParallelTimes_" + NumberToString(threads) + "pt" + NumberToString(rows) + "x";
	populate_matrices(rows,cols, rows1, rows2, cols1, cols2);
	ofstream outputFile;
	outputFile.open(filetitle.c_str(), ios_base::app);
	// writes time for i number of iterations into text file paralleldata_long.txt
	for(int i=0; i<iteration_limit; i=i+500){
		int time_process = multiplication_timer(i,threads, numthreads);
		outputFile << i << ","<< time_process << endl;
	} 
	outputFile.close();
}

// populates matrix1 and matrix2 to desired dimensions, up to 8000
void populate_matrices(int rows, int cols, int& rows1, int& rows2, int& cols1, int& cols2){
	rows1 = rows;
	rows2 = rows;
	cols1 = cols;
	cols2 = 1;

	// populate with random values
	for(int r=0; r< rows; r++){
        	for(int c=0; c<cols; c++)
                       matrix1[r][c] = rand() % 100;
                }
        for(int r=0; r< rows; r++){
                for(int c=0; c<1; c++)
                       matrix2[r][c] = rand() % 100;
                }
}

// times iterations x's multiplications of previously populated matrices 
int multiplication_timer(int iterations,int threads, int& nthreads)
{
	nthreads = threads;
	int cycle=0;	
	time_t t = time(0);
	while(cycle < iterations){
		pthread_t multiply_entry[rows1];
	
        	for(int x=0; x<numthreads; x++){ 
                	pthread_create(&multiply_entry[x], NULL, multiply, (void *) x);
		}
	        for(int x=0; x<numthreads; x++)
        	        pthread_join(multiply_entry[x],NULL);
		cycle++;
	}
	time_t t2 = time(0);
	cout << t2-t << endl;
	return t2-t;
}

// pthreads function multiplies for given chunks
void *multiply (void *row){
        long current_row;
        current_row = (long) row;
	long lower_limit = rows1/numthreads * (current_row);
	long upper_limit = lower_limit + rows1/numthreads;
	int entry=0;
	for(long y=lower_limit; y<upper_limit; y++){
	        for(long x=0; x<rows1; x++)
        	{
                	entry+=matrix1[y][x] * matrix2[x][0];
        	}
		product[current_row][0] = entry;
	}
}


