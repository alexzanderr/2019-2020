#pragma once

#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned int UI;

// returns len of a string using pointers arithmetic
UI Strlen(const char *text) {
	UI len = 0;
	for (; *text != '\0'; text++)
		len++;
	return len;
}

// returns a email format, as a pointer
char *CreateEmail(const char *username, const char *domain) {
	char *email = new char[Strlen(username) + Strlen(domain) + 2];
	strcpy(email, username);
	strcat(email, "@");
	strcat(email, domain);
	return email;
}