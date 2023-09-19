/*
	* Project name : mkCPP
	* Contibutors : BaBreton, cparras
	* Creation date : 19/09/2023
*/

#include "../include/mkcpp.hpp"
# include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int	main() {
	ifstream	input("./include/maybeHeader");

	if (input) {
		string line;
		while (getline(input, line)) {
			cout << line << endl;
		}
		input.close();
	}
	else {
		cout << "Error opening file." << endl;
		perror("open");
	}
}