/*
	* Project name : mkCPP
	* Contibutors : BaBreton, cparras
	* Creation date : 19/09/2023
*/

#include "../include/mkcpp.hpp"

int	main(int argc, char **argv, char **env) {
	
	Config 	test(env);
	
	(void)argc;
	(void)argv;

	test.start();
	return (0);
}