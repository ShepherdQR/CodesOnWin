/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-01-10 10:59:00
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-18 23:02:58
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#include <iostream>
#include "ClassMyBinaryTree.h"

#include <cstring>
#include <stdio.h>

using namespace std;
int testFuncClassMyBinaryTree() {

	/*
	 *					A
	 *			B				G
	 *		C		F		H		I
	 *		  D

	*/

	// 1. Build a binaryTree.
	char* pStrIn = new char[20];
	strcpy(pStrIn, "A(B(C(,D),F),G(H,I))");
	MyBinaryTree<char> myTree;
	BinaryTreeNode<char>* pRoot = NULL;

	cout << endl << "createTreeFromTable:";	
	pRoot = myTree.createTreeFromTable(&pStrIn);

	// 2. Display the binaryTree in 3 ways.
	cout << endl << "PreOrder: ";	
	myTree.PreOrder(pRoot);
	cout << endl << "MidOrder: ";
	myTree.MidOrder(pRoot);
	cout << endl << "PostOrder: ";
	myTree.PostOrder(pRoot);

	// 3. The depth, the nood number, the leaf nood number
	cout << endl << "Depth: " <<
	myTree.Height(pRoot);
	cout << endl << "Number of noods: " <<
	myTree.SizeNood(pRoot);
	cout << endl << "Number of leaf noods: " <<
	myTree.NumberLeaf(pRoot);

	// 4. Number of noods whose degree is 1
	cout << endl << "Number of noods whose degree is 1: " <<
	myTree.NumberNoodDegreeOne(pRoot);


	// 5. Dsiplay each path From Top downwards.
	cout << endl << "Dsiplay each path From Top downwards: " << endl;
	myTree.ShowPath(pRoot);

	cout << endl << "Dsiplay each path From Bottom upwards: " << endl;
	myTree.ShowPath(pRoot, 0);


	// 6. switch left with right.
	myTree.ExchangeLR(pRoot);
	cout << endl << "PreOrder: ";	
	myTree.PreOrder(pRoot);



	if(pStrIn){
		delete[] pStrIn;
		pStrIn = NULL;
	}

    cout << "\nProgram ends." << endl;

	return 0;
}
