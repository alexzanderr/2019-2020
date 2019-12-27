#pragma once

typedef unsigned int UI;
typedef unsigned const int UCI;

#define en endl;
#define sp ' ';

#if defined(_WIN32) || defined(_WIN64)
#define CLS system("cls")
#else
#define CLS system("clear")
#endif


#define TITLE system("title [System Application v1.0 - Executable Commands Only]")

#define COLORPURPLE system("COLOR 5A")

#define PAUSE system("pause")

#define COMMAND system(nullptr)

#define DIRECTORY system("DIR")