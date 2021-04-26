
#include"ClassMyBinaryTree.h"


template class MyBinaryTree<char>;
template class BinaryTreeNode<char>;

// BinaryTreeNode
template<class T>
BinaryTreeNode<T>::BinaryTreeNode():_pChildL(NULL), _pChildR(NULL){
}
//template BinaryTreeNode<char>::BinaryTreeNode();



// BinaryTreeNode
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T iData,
	BinaryTreeNode<T> *iChildL,
	BinaryTreeNode<T> *iChildR): _data(iData),_pChildL(iChildL), _pChildR(iChildR) {
}





template<class T>
void MyBinaryTree<T>::DestroySubTree(BinaryTreeNode<T>* &ipNood){
	if (ipNood) {
		DestroySubTree(ipNood->childLeft());
		DestroySubTree(ipNood->childRight());
		delete ipNood;
		ipNood = NULL;
	}
}


// PreOrder
template<class T>
void MyBinaryTree<T>::PreOrder(BinaryTreeNode<T>* &ipNood){
	if(ipNood){
		cout << ipNood->data() << " ";
		PreOrder(ipNood->childLeft());
		PreOrder(ipNood->childRight());
	}
}

// MidOrder
template<class T>
void MyBinaryTree<T>::MidOrder(BinaryTreeNode<T>* &ipNood){
	if(ipNood){
		MidOrder(ipNood->childLeft());
		cout << ipNood->data() << " ";
		MidOrder(ipNood->childRight());
	}
}

// PostOrder
template<class T>
void MyBinaryTree<T>::PostOrder(BinaryTreeNode<T>* &ipNood){
	if(ipNood){
		PostOrder(ipNood->childLeft());
		PostOrder(ipNood->childRight());
		cout << ipNood->data() << " ";
	}
}


// createNode
template<class T>
BinaryTreeNode<T>* MyBinaryTree<T>::createNode(){
	BinaryTreeNode<T>* pNood = new BinaryTreeNode<T>();
	pNood->childLeft() = NULL;
	pNood->childRight() = NULL;
	return pNood;
}

// createTreeFromTable
template<class T>
BinaryTreeNode<T>* MyBinaryTree<T>::createTreeFromTable(T** ippStr){
	
	BinaryTreeNode<T>* pNood = NULL;

	if(isalpha(**ippStr)){
		cout << **ippStr << " ";
		pNood = createNode();
		pNood->data() = **ippStr;
		++(*ippStr);
	}

	if (**ippStr == '('){
		cout << **ippStr << " ";
		++(*ippStr);
		if (pNood)
			pNood->childLeft() = createTreeFromTable(ippStr);
		else 
			cout << "ERROR 1." << endl;	
	}else
		return pNood;


	if (**ippStr == ','){
		cout << **ippStr << " ";
		++(*ippStr);
		if (pNood)
			pNood->childRight() = createTreeFromTable(ippStr);
		else 
			cout << "ERROR 2." << endl;	
	}else
		return pNood;


	if (**ippStr == ')'){
		cout << **ippStr << " ";
		++(*ippStr);
		return pNood;
	}else
		cout << "ERROR 3." << endl;

	return pNood;
}


// Height
template<class T>
int MyBinaryTree<T>::Height(BinaryTreeNode<T>* &ipNood){
	if(!ipNood)
	return 0;
	int i = Height(ipNood->childLeft());
	int j = Height(ipNood->childRight());
	return i<j ? j+1 : i+1;
}


// SizeNood
template<class T>
int MyBinaryTree<T>::SizeNood(BinaryTreeNode<T>* &ipNood){
	if(!ipNood)
		return 0;
	return 1 + SizeNood(ipNood->childLeft()) + SizeNood(ipNood->childRight());
}


// NumberLeaf
template<class T>
int MyBinaryTree<T>::NumberLeaf(BinaryTreeNode<T>* &ipNood){
	if(!ipNood)
		return 0;
	if(ipNood->childLeft()==NULL && ipNood->childRight()==NULL)
		return 1;
	return NumberLeaf(ipNood->childLeft()) + NumberLeaf(ipNood->childRight());
}

// NumberNoodDegreeOne
template<class T>
int MyBinaryTree<T>::NumberNoodDegreeOne(BinaryTreeNode<T>* &ipNood){
	if(!ipNood)
		return 0;
	if( (ipNood->childLeft()==NULL + ipNood->childRight()==NULL ) == 1)
		return 1;
	return NumberNoodDegreeOne(ipNood->childLeft()) + NumberNoodDegreeOne(ipNood->childRight());
}


// ShowPath
template<class T>
void MyBinaryTree<T>::ShowPath(BinaryTreeNode<T>* &ipNood, bool isTopBottom){
	
	if(!ipNood)
		return ;

	_pStack[_top] = ipNood->data();
	++_top;

	if(ipNood->childLeft()==NULL && ipNood->childRight()==NULL){

		if(isTopBottom){
			for(int i=0;i<_top;++i)
				cout << _pStack[i] << " ";
			cout << endl;
		}else{
			for(int i=_top-1;i>=0;--i)
				cout << _pStack[i] << " ";
			cout << endl;
		}
	}
	ShowPath(ipNood->childLeft(), isTopBottom);
	ShowPath(ipNood->childRight(), isTopBottom);
	--_top;
}


// ExchangeLR
template<class T>
void MyBinaryTree<T>::ExchangeLR(BinaryTreeNode<T>* &ipNood){
	BinaryTreeNode<T>* pNoodCur = new BinaryTreeNode<T>();
	if(!ipNood)
		return ;
	pNoodCur = ipNood->childLeft();
	ipNood->childLeft() = ipNood->childRight();
	ipNood->childRight() = pNoodCur;

	ExchangeLR(ipNood->childLeft());
	ExchangeLR(ipNood->childRight());
}

