#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class tree {
	int height;
	char symbol;
	int color;
	

public:

	void printTree() {
		
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);


		for (int i = 1; i <= height; i++) {
		
			for (int j = 1; j <= height - i; j++) {
				cout << " ";
			}
		
			for (int k = 1; k <=2*i-1; k++) {
				cout << symbol;
			}
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, 15);
		cout << endl;
	
	}

	tree() {
		height = 5;
		symbol = '*';
		color = 10;
	}

	tree(int h, char s, int c) {
		height=h;
		symbol = s;
		color = c;
	}
};
