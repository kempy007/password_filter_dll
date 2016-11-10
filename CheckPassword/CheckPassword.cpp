// CheckPassword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>
#include <regex>
#include <vector>
#include <stdio.h>
#include <string>

#include <iostream>
 

#define SIZE 258

#define MAX_REGEX_LENGTH 4096



using namespace std;


int main()
{
	char password[SIZE];
	int i;
	bool running = true;

	wstring wordarray[] = { L"badbadbadpw", L"password" };

	while (running)
	{
		printf("please enter password or type exit to end\n");
		fgets(password, SIZE, stdin);

		/* remove newline, if present */
		i = strlen(password) - 1;
		if (password[i] == '\n')
			password[i] = '\0';

		// convert string to lowercase
		int ix = 0;
		char c;
		int pwsize = strlen(password);
		//int pwsizT = 4; 
		char *lcPassword = new char[pwsize]; // has garbage need to null the end http://google.com 
		wchar_t *lcpw = new wchar_t[pwsize];
		while (password[ix])
		{
			c = password[ix];
			// reverse leet speak and other common subs here
			switch (c)
			{
			case '0': c = 'o'; break;
			case '1': c = 'l'; break;
			case '2': c = 'z'; break;
			case '3': c = 'e'; break;
			case '4': c = 'a'; break;
			case '5': c = 's'; break;
			case '6': c = 'd'; break;
			case '7': c = 't'; break;
			case '8': c = 'b'; break;
			case '9': c = 'g'; break;
			case '$': c = 's'; break;
			case '!': c = 'i'; break;
			case '(': c = 'c'; break;
			case '#': c = 'f'; break;
			case '<': c = 'k'; break;
			case '+': c = 't'; break;
			case '>': c = 'v'; break;
			case '%': c = 'x'; break;
			case '?': c = 'y'; break;
			case '@': c = 'a'; break;
			default:
				break;
			}
			lcPassword[ix] = tolower(c); // putchar(tolower(c));
			lcpw[ix] = tolower(c);  // putchar(tolower(c));
			ix++;
		}
		lcPassword[ix] = '\0'; // add null
		lcpw[ix] = '\0'; // add null
		// return 0;
		
		printf("Do something with the deobfuscated password << %s >>\n\n", lcPassword);

		
		wstring LCPW = lcpw;
		for each (wstring word in wordarray)
		{
			if (LCPW.find(word) != std::string::npos)
			{
				//printf("Found dictionary word >> %ls << \n", word); // getting garbage 
				wcout << "***WARNING*** Found dictionary word >> " << word << " << \n" << endl;
			}
		}

		// exit check routine - not really necessary but it's here now
		if (strcmp(lcPassword, "exit") == 0)
		{
			printf("Exiting");
			running = false;
		}
	}

	/*PUNICODE_STRING AccountName,
		PUNICODE_STRING FullName,
		PUNICODE_STRING Password,
		BOOLEAN SetOperation*/
    return 0;
}

