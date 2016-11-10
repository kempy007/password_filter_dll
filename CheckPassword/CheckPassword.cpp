// CheckPassword.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <atlbase.h>
#include <regex>
#include <vector>
#include <stdio.h>
#include <string>

#include <iostream> // for cout not required in dll
 
#include <cmath> // for entropy algo
#include <set>

#define SIZE 258

#define MAX_REGEX_LENGTH 4096



using namespace std;

double entropy(string& st) {
	vector<char> stvec(st.begin(), st.end());
	set<char> alphabet(stvec.begin(), stvec.end());
	vector<double> freqs;
	for (set<char>::iterator c = alphabet.begin(); c != alphabet.end(); ++c) {
		int ctr = 0;
		for (vector<char>::iterator s = stvec.begin(); s != stvec.end(); ++s) {
			if (*s == *c) {
				++ctr;
			}
		}
		freqs.push_back((double)ctr / (double)stvec.size());
	}
	double ent = 0;
	double ln2 = log(2);
	for (vector<double>::iterator f = freqs.begin(); f != freqs.end(); ++f) {
		ent += *f * log(*f) / ln2;
	}
	ent = -ent;
	return ent;
}



int main()
{
	char password[SIZE];
	int i;
	bool running = true;

	wstring wordarray[] = { L"badbadbadpw", L"password" };

	while (running)
	{
		printf("please enter password or type exit to end\n\n");
		fgets(password, SIZE, stdin);

		string sX(password);
		double d_entropy = entropy(sX);
		cout << "\nEntropy = " << d_entropy << "\n" << endl;

		/* remove newline, if present */
		i = strlen(password) - 1;
		if (password[i] == '\n')
			password[i] = '\0';

		// convert string to lowercase
		int ix = 0;
		char c;
		int pwsize = strlen(password);
		//int pwsizT = 4; 
		char *lcPassword = new char[pwsize]; // has garbage need to null the end
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
				if (pwsize / 2 >= word.size())
				{
					wcout << "---Allowed--- dictionary word >> " << word << " << Because it forms less than half of the password \n" << endl;
				}
				else
				{
					wcout << "***WARNING*** Found dictionary word >> " << word << " << \n" << endl;
				}
			}
		}
		if (d_entropy <= 3)
		{
			cout << "***WARNING*** Entropy is too low" << endl;
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

