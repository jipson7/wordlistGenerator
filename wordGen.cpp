#include "wordGen.h"

using namespace std;

wordGen::wordGen(){
	list.open("wordlist.txt");
}

wordGen::~wordGen(){
	list.close();
}

void wordGen::inputMenu(){
	cout << "Welcome to Calebs wordlist creator\n" << "\nEnter the number of characters in the password: ";
  
  	cin >> length;

  	cout << "\n\nSelect a character set, or select custom to create your own.\n";

  	cout << "\n1) UPPER, lower, and numeric (e.g. ABCabc213)\n";

	cout << "\n2) lower and numberic (e.g. abc123)\n";

	cout << "\n3) Numeric (e.g. 123)\n";

	cout << "\n4) Custom Set\n\n Selection: ";

	cin >> selection;

	while ((selection < 1) || (selection > 4)){
		cerr << "\nError, please select 1, 2, 3, or 4: ";
		cin >> selection;
	}

}

void wordGen::generateCharSet(){
	
	char a;

	switch (selection)
	{
		case 1 : 
			for (int i = 65; i <= 90; i++){
				a = i;
				characterSet.push_back(a);
			}
			for (int i = 97; i <= 122; i++){
				a = i;
				characterSet.push_back(a);
			}
			for (int i = 48; i <= 57; i++){
				a = i;
				characterSet.push_back(a);
			}
			break;
		case 2 :
			for (int i = 97; i <= 122; i++){
				a = i;
				characterSet.push_back(a);
			}
			for (int i = 48; i <= 57; i++){
				a = i;
				characterSet.push_back(a);
			}
			break;
		case 3 :
			for (int i = 48; i <= 57; i++){
				a = i;
				characterSet.push_back(a);
			}
			break;
		case 4 : 
			cout << "Enter a list of characters to use in the wordlist (Enter when finished)->";

			string str;

			getline(cin, str);

			vector<char> customCharacters(str.begin(), str.end());
		
			checkForDuplicates(customCharacters);

			break;
	}
}

void wordGen::generateWordlist(){
	int numberCharacters = characterSet.size(); //How many different characters in each position
  
  	vector<int> toWrite;
  
  	for (int i = 0; i < length; i++){
   		toWrite.push_back(0); 
  	}
  
 	while (toWrite[0] != numberCharacters){ // While the most siginificant (left) position of the password is not equal to the final character. (Like a weird number system)
	    for (int i = 0; i < length; i++){ // Write out each password at the start of every iteration of the loop
	      	list << characterSet[toWrite[i]];
	    }
	    list << "\n";
	    
	    toWrite[length - 1]++; // Increment the weird character number system
	    
	    for (int i = length - 1; i >= 0; i--){ // check each place starting with the "ones" place of the fucked up number system. If its gone over the biggect characte, increment the next place (tens or something)
	    	if ((toWrite[i] >= numberCharacters)&&(i != 0)){ // The and "i not equal 0" is to account for being at the last password/weird number. Otherwise next line doesnt make sense
		  		toWrite[i] = 0;
		  		toWrite[i - 1] += 1;
	        }
	    }
	    
	    
	}
}

void wordGen::checkForDuplicates(std::vector<char> userInput){
	vector<char>::iterator i;

	for (i = userInput.begin(); i != userInput.end(); ++i){
		if ((find(characterSet.begin(), characterSet.end(), *i)) == characterSet.end()){
			characterSet.push_back(*i);
		}
	}
}