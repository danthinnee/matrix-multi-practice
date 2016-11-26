#include<fstream>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int multiply_time (int iterations){
	int x = 0;
	int rows1 = 8192;
	int cols1 = 8192;
	int rows2 = 8192;
	int cols2 = 1;
	int matrix1[rows1][cols1];
	int matrix2[rows2][cols2];
        int product[rows1][cols2];

// populate matrices using random number generator
	for(int r=0; r < rows1; r++){
		for(int c=0; c< cols1; c++){
			matrix1[r][c] = rand() % 100; 
		}
	}        
	for(int r=0; r < rows2; r++){
                for(int c=0; c< cols2; c++){
                        matrix2[r][c] = rand() % 100;
                }
        }
        for(int r=0; r < rows1; r++){
                for(int c=0; c< cols2; c++){
                        product[r][c] = 0;
                }
        }

// pre time
// will need to be factored out of final time
	    time_t t = time(0); 
//	    cout << "t1 is " << t << endl;
	
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

int main () {

for(int i=0; i < 10000; i=i+500){
	int iterations = i;
	int time = multiply_time(iterations);
	ofstream outputFile;
	outputFile.open("matrixdata.txt",ios_base::app);
	outputFile << iterations << "\t" << time << endl;
	outputFile.close();
}
}
