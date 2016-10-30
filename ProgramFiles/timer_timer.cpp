#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int timer_time(int iterations){
	int x = 0;
        time_t t = time(0);
        	
	while(x < iterations){
		time_t fuck = time(0); 
		//cout << "t1 is " << t << endl;
		x++;
	}
        time_t t2 = time(0);
        cout << "diff is " << t2-t << endl;

}

int main(){
	for(int i=10; i<50000; i=i+2000){
		timer_time(i);
	}
}
