#include "defines.h"
#include "DateTime.h"
#include <iostream>

using namespace std;

int main()
{
	TITLE;
	DateTime time;
	time.CurrentTime();
	cout << "--------------------\n";
	time.MainLoop(1000);

	cout << endl;
    return 0;
}
