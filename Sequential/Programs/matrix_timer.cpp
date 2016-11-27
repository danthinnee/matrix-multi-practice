#include<fstream>
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>
using namespace std;
const int default_dim = 10000;
int numthreads = 1;
int rows1 = 10000;
int cols1 = 10000;
int rows2 = 10000;
int cols2 = 1;
int matrix1[default_dim][default_dim];
int matrix2[default_dim][1];
int product[default_dim][default_dim];
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
			matrix2[r][c] = rand() % 100;                                                                                }
}
int multiply_time (int iterations){
	int x = 0;
// pre time
// will need to be factored out of final time
	    time_t t = time(0); 
	
// execute multiplication given number of times
	//double iterations = 50000;
	while(x < iterations){	
	// multiply matrices together
		for(int i=0; i < rows1; i++){
		        for(int j=0; j < cols2; j++){
		                for(int k=0; k < cols1; k++){
		                        product[i][j] = product[i][j] + (matrix1[i][k] * matrix2[k][j]);
		                }
		        }
		}
		x++;
	}
	
// post time
// will need to be factored out of final time
	time_t t2 = time(0); 
	cout << t2-t << endl;	
	return t2-t;
}
string NumberToString ( int Number )
{
	stringstream ss;
	ss << Number;
	return ss.str();
}

int main () {
	int iteration_limit = 10000;
	int rows=1024, cols=1024;
	string filetitle = "SequentialTimes_" + NumberToString(rows) + "x";
	populate_matrices(rows, cols, rows1, rows2, cols1, cols2);
	ofstream outputFile;
	outputFile.open(filetitle.c_str(), ios_base::app);
	for(int i=0; i < iteration_limit; i=i+500){
		int iterations = i;
		int time = multiply_time(iterations);
		outputFile << iterations << "," << time << endl;
	}
	outputFile.close();
}
