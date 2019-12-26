#pragma once

#define TITLE system("title DateTimeApp")

#if defined(_WIN32) || defined(_WIN64)
#define CLS system("cls")
#else
#define CLS system("clear")
#endif