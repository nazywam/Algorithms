#include <iostream>
using namespace std;

void kmp(string pattern, string text, int* prefixTable){ //run prefix algorithm on data and put values in prefixTable
	prefixTable[0] = 0;
	string data = pattern+'#'+text;
	int c = 0;
	for(int i=0; i<data.size(); i++){
		while(c > 0 && (data[c] != data[i]) || c == pattern.size()){
			c = prefixTable[c-1];
		}
		if(data[c] == data[i]){
			c++;
		}
		prefixTable[i+1] = c;
	}
}

int main(){
	string pattern = "a";
	string text = "aaaaaa";
	string data = pattern+'#'+text;

	int* prefixTable = new int[data.size()+1];

	kmp(pattern, text, prefixTable);
	
	//find occurences of pattern in text
	for(int x=pattern.size()+2; x<data.size(); x++){
		if(prefixTable[x] == pattern.size()){ 
			cout << "Found " << pattern << " at " << x-pattern.size()-2 << endl;
		}
	}
}