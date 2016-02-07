#include <iostream>
#include <utility>

using namespace std;

//Use fast doubling to calculate nth fibbonaci number in O(logN) time

//F(2k) = F(k) * (2*F(k+1) - F(k))
//F(2k+1) = F(k+1)^2 + F(k)^2

pair<int, int> _fastFib(int n){

	if(n == 0){
		return make_pair(0, 1);
	}
	if(n == 1){
		return make_pair(1, 1);
	}


	pair<int, int> prev = fastFib(n/2);
	int a = prev.first;
	int b = prev.second;

	int c = a*(2*b-a);
	int d = a*a+b*b;

	if(n%2==0){
		return make_pair(c, d);
	} else {
		return make_pair(d, c+d);
	}
}

int fib(int n){
	return fastFib(b).first;
}

int main(){
	cout << fib(12) << endl;
}