/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  14/09/2014 23:45:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#include "Application.hpp"
#include "SDLManager.hpp"

int main(int argc, char *argv[]) {
	SDLManager::init();
	
	Application app;
	
	app.run();
	
	SDLManager::free();
	
	return 0;
}
