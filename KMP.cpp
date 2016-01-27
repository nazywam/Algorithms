#include <iostream>
using namespace std;

void kmp(string data, int* prefixTable){ //run prefix algorithm on data and put values in prefixTable
	prefixTable[0] = 0;
	int c = 0;
	for(int i=1; i<data.size(); i++){
		while(c > 0 && data[c] != data[i]){
			c = prefixTable[c];
		}
		if(data[c] == data[i]){
			c++;
		}
		prefixTable[i] = c;
	}
}

int main(){
	string pattern = "cat";
	string text = "tacocattacocat";
	string data = pattern+'#'+text;

	int* prefixTable = new int[data.size()];

	kmp(data, prefixTable);
	
	//find occurences of pattern in text
	for(int x=0; x<data.size(); x++){
		if(prefixTable[x] == pattern.size()){ 
			cout << "Found " << pattern << " at " << x << endl;
		}
	}
}