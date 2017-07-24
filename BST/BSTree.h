#pragma once
template<class T>
class BSTNode {
	T key;
	BSTNode<T>* parent;
	BSTNode<T>* leftChild;
	BSTNode<T>* rightChild;
	BSTNode(T, BSTNode<T>*, BSTNode<T>*, BSTNode<T>*);
};
template<class T>
BSTNode<T>::BSTNode(T key, BSTNode<T>* parent, BSTNode<T>* leftChild, BSTNode<T>* rightChild)
{
	this->key = key;
	this->parent = parent;
	this->leftChild = leftChild;
	this->rightChild = rightChild;
}
template<class T>
class BSTree {
private:
	BSTNode<T>* mRoot;
public:
	BSTree();
	~BSTree();
	void insertNode(T key);
	void preOrder();
	void inOrder();
	void postOrder();
	
private:
	void insertNode(T key, BSTNode<T>* mRoot);
	void preOrder(BSTNode<T>* tree);
	void inOrder(BSTNode<T>* tree);
	void postOrder(BSTNode<T>* tree);
};
