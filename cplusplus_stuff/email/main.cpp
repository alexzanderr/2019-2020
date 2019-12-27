#include <iostream>

#include "len&email.h"

using namespace std;

int main() {
	const char name[] = "Petter Griffin";
	const char domain[] = "trying_to_understand_the_reality.com";
	const string email = CreateEmail(name, domain);
	cout << email << endl;

	return 0;
}

