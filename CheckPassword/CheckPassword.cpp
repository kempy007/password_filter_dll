// CheckPassword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>
#include <regex>
#include <vector>
#include <stdio.h>
 

#define SIZE 258

#define MAX_REGEX_LENGTH 4096

using namespace std;

int main()
{
	char password[SIZE];
	int i;
	bool running = true;

	while (running)
	{
		printf("please enter password or type exit to end\n");
		fgets(password, SIZE, stdin);

		/* remove newline, if present */
		i = strlen(password) - 1;
		if (password[i] == '\n')
			password[i] = '\0';

		char tmpPw[4]; tmpPw = password;
		printf("Do something with the password << %s >>\n", password);
		if (password == "exit")
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

