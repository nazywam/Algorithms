#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

#define N 20

int tab[N];
int sec[N];

int getDigit(int num, int index){ //returns indexth digit (counting from right, 0==last)
	int d = num/pow(10, index);
	return d%10;
}

void radix(int index){ //performs one radix sort 
	int tmp[10];

	for(int x=0; x<10; x++){
		tmp[x] = 0;
	}

	for(int x=0; x<N; x++){
		int n = getDigit(tab[x], index);
		tmp[n]++;
	}
	for(int x=1; x<N; x++){
		tmp[x] += tmp[x-1];
	}

	for(int x=N-1; x>=0; x--){
		int n = getDigit(tab[x], index);

		tmp[n]--;
		int index = tmp[n];
		sec[index]=tab[x];
	}
}

int main(){
	srand(time(NULL));
	cout << "starting: " << endl;
	for(int x=0; x<N; x++){
		tab[x] = rand()%1000;
		cout << tab[x] << " ";
	}
	cout << endl << endl;

	for(int q=0; q<3; q++){
		cout << q+1  <<"th iteration " << endl;
		radix(q);

		for(int x=0; x<N; x++){
			cout << sec[x] << " ";
			tab[x] = sec[x];
		}
		cout << endl << endl;
	}
}