/*
 * Footorial07.cpp
 *
 *  Created on: Feb 23, 2021
 *      Author: kkeiper1103
 */

#include "Footorial07.h"

Footorial07::Footorial07() {
	// TODO Auto-generated constructor stub

}

Footorial07::~Footorial07() {
	// TODO Auto-generated destructor stub
}

void Footorial07::init() {
	user.first_name = "Kyle";
	user.last_name = "Keiper";
	user.age = 28;
	user.phone = "(234) 542-9939";
	user.email = "kkeiper1103@gmail.com";

	theThread = SDL_CreateThread(printUserInfo, "print-user-thread", (void*)(&user));
}

void Footorial07::renderLogic() {
}

void Footorial07::close() {
	SDL_WaitThread(theThread, nullptr);
}

/**
 *
 */
int printUserInfo(void* data) {
	PersonInfo* user = (PersonInfo*)(data);

	std::cout << "Entering New Thread" << std::endl;

	if(user) {
		std::cout << "Name: " << user->first_name << " " << user->last_name << std::endl;
		std::cout << "Phone: " << user->phone << std::endl;
		std::cout << "Email: " << user->email << std::endl;
		std::cout << "Age: " << user->age << std::endl;
	}

	return 0;
}
