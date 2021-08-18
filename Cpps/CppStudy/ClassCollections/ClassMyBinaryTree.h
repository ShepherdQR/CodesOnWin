/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-01-10 10:59:00
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2021-08-18 23:01:58
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/
#pragma once

#include<iostream>
using namespace std;

template<class T>
class BinaryTreeNode {
public:
	BinaryTreeNode();
	BinaryTreeNode(T iData, 
		BinaryTreeNode<T> *iChildL=NULL,
		BinaryTreeNode<T> *iChildR = NULL);

	BinaryTreeNode<T>*& childLeft() { return _pChildL; }
	BinaryTreeNode<T>*& childRight(){return _pChildR;}

	T& data(){return _data;}

private:
	T _data;
	BinaryTreeNode<T> *_pChildL;
	BinaryTreeNode<T> *_pChildR;
};

template<class T>
class MyBinaryTree {

public:
	MyBinaryTree() :_pRoot(NULL),_top(0),_pStack(NULL) {
		_pStack = new T[50];
	}
	~MyBinaryTree() {
		DestroySubTree(_pRoot);
		if(_pStack){
			delete[] _pStack;
			_pStack = NULL;
		}
	}

	BinaryTreeNode<T>* ChildLeft(BinaryTreeNode<T>* &iNoodCurrent){
		return (iNoodCurrent!=NULL) ? (iNoodCurrent->childLeft()) : NULL;
	}

	BinaryTreeNode<T>* ChildRight(BinaryTreeNode<T>* &iNoodCurrent){
		return (iNoodCurrent!=NULL) ? (iNoodCurrent->childRight()) : NULL;
	}

	void PreOrder(){PreOrder(_pRoot);}
	void MidOrder(){MidOrder(_pRoot);}
	void PostOrder(){PostOrder(_pRoot);}

	//
	void DestroySubTree(BinaryTreeNode<T>* &ipNood);
	void PreOrder(BinaryTreeNode<T>* &ipNood);
	void MidOrder(BinaryTreeNode<T>* &ipNood);
	void PostOrder(BinaryTreeNode<T>* &ipNood);

	int Height(BinaryTreeNode<T>* &ipNood);
	int SizeNood(BinaryTreeNode<T>* &ipNood);
	int NumberLeaf(BinaryTreeNode<T>* &ipNood);
	int NumberNoodDegreeOne(BinaryTreeNode<T>* &ipNood);
	void ShowPath(BinaryTreeNode<T>* &ipNood, bool isTopBottom = 1);

	void ExchangeLR(BinaryTreeNode<T>* &ipNood);

	BinaryTreeNode<T>* createTreeFromTable(T** ippStr);

private:

	BinaryTreeNode<T> *_pRoot;

	int _top;
	T* _pStack;

	BinaryTreeNode<T>* createNode();
};
