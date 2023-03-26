#pragma once
#include <iostream>
#include <windows.h>
#include "tree.h"

using namespace std;

class forest {
	int num_trees;

public:

	forest(int n) {
		num_trees = n;
	}

	forest() {
		num_trees = 3;
	}

	void print_forest(tree treeA) {
		
		for (int i=0; i < num_trees; i++) {
			treeA.printTree();
		}
		cout << endl;
	}
};