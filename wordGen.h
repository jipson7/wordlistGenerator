#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


class wordGen{
public:
	wordGen();
	~wordGen();
	void inputMenu();
	void generateCharSet();
	void generateWordlist();
	void checkForDuplicates(std::vector<char> userInput);
private:
	std::vector<char> characterSet;
	int length;
	std::ofstream list;
	int selection;
};