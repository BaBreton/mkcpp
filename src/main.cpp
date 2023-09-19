/*
	* Project name : mkCPP
	* Contibutors : BaBreton, cparras
	* Creation date : 19/09/2023
*/

#include "../include/mkcpp.hpp"

int	main(int argc, char **argv, char **env) {
	Config 	test;
	
	if (argc == 2 && strcmp(argv[1], "--version") == 0) {
		cout << "mkCPP version 1.0.0" << endl;
		return (0);
	}
	test.start();
	return (0);
}