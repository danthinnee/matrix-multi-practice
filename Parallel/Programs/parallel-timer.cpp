#include <iostream>
#include <pthread.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int sum = 0;
pthread_mutex_t mut;
int x=0;
const int rows1=1000;
const int cols1=1000;
const int rows2=1000;
const int cols2=1;
int matrix1[rows1][cols1];
int matrix2[rows2][cols2];
int product[rows1][cols2];

void *add(void *);
void *multiply(void *);
int timer(int);
int main(){
for(int i=1; i<10000; i=i+2000){
int time = timer(i);
ofstream outputFile;
outputFile.open("paralleldata_long.txt",ios_base::app);
outputFile << i << ","<<time << endl;
outputFile.close();
}
}

int timer(int iterations){
int hi=0;	
time_t t = time(0);
while(hi < iterations){
	for(int r=0; r< rows1; r++){
        	for(int c=0; c<cols1; c++)
                	matrix1[r][c] = rand() % 100;
	}

	for(int r=0; r< rows2; r++){
        	for(int c=0; c<cols2; c++)
                	matrix2[r][c] = rand() % 100;
	}

	pthread_t trying[rows1];
		
        for(int x=0; x < rows1; x++)
                pthread_create(&trying[x], NULL, multiply, (void *) x);
        for(int x=0; x<rows1; x++)
                pthread_join(trying[x],NULL);
	hi++;
}
	time_t t2 = time(0);
	cout << t2-t << endl;
	return t2-t;
}

void *multiply (void *row){
        long current_row;
        current_row = (long) row;
	int total=0;
        for(long x=0; x<rows1; x++)
        {
		
                total+=matrix1[current_row][x] * matrix2[x][0];
        }
	
	product[current_row][0] = total;
        pthread_mutex_unlock(&mut);
}

