#include <iostream>
#include <stack>
#include "BinaryTree.h"
using namespace std;

int mainbinarytree(){
	BinaryTree b;
	b.InitTree();
	b.PreOrder();
	cout << endl;
	b.InOrder();
	cout << endl;
	b.PostOrder();

	system("pause");
	return 0;
}