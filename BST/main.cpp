#include "BSTree.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	cout << "Hello World" << endl;
	BSTree<int>* myBST = new BSTree<int>();
	myBST->insertNode(1);
	myBST->insertNode(5);
	myBST->insertNode(8);
	myBST->insertNode(4);
	myBST->insertNode(76567);
	myBST->insertNode(-32333);
	myBST->insertNode(0);
	myBST->insertNode(88);
	myBST->inOrder();
	cout << endl;
//	cout << myBST->minimum() << endl;
//	cout << myBST->successor(myBST->iterativeSearch(0))->key << endl;
	myBST->remove(1);
	myBST->inOrder();
	cout << endl;
	delete myBST;
	//cout << myBST;
	system("pause");
	return 0;
}