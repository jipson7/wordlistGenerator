#include "wordGen.h"
#include <iostream>

using namespace std;

int main(){
	
	wordGen newList;

	newList.inputMenu();
	newList.generateCharSet();
	newList.generateWordlist();



	return 0;
}