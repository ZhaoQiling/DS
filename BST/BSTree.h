#pragma once
#include <iomanip>
using namespace std;
template<class T>
class BSTNode {
public:
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
	void preOrder() const;
	void inOrder() const;
	void postOrder() const;
	void destory();
	BSTNode<T>* iterativeSearch(T key) const;
	T minimum() const;
	T maximum() const;
	BSTNode<T>* successor(BSTNode<T>* tree) const;
	BSTNode<T>* predecessor(BSTNode<T>* tree) const;
	void remove(T key);
private:
	void insertNode(BSTNode<T>* newNode, BSTNode<T>* mRoot);
	void preOrder(BSTNode<T>* tree) const;
	void inOrder(BSTNode<T>* tree) const;
	void postOrder(BSTNode<T>* tree) const;
	void destory(BSTNode<T>*& mRoot);
	BSTNode<T>* iterativeSearch(T key, BSTNode<T>* mRoot) const;
	BSTNode<T>* minimum(BSTNode<T>* mRoot) const;
	BSTNode<T>* maximum(BSTNode<T>* mRoot) const;
	BSTNode<T>* remove(BSTNode<T> * p);
};
template<class T>
BSTree<T>::BSTree():mRoot(NULL)
{
}
template<class T>
BSTree<T>::~BSTree()
{
	destory(mRoot);
}

template<class T>
void BSTree<T>::destory()
{
	destory(mRoot);
}

template<class T>
void BSTree<T>::destory(BSTNode<T>*& tree)
{
	if (NULL == tree)
		return;
	if (NULL != tree->leftChild)
		destory(tree->leftChild);
	if (NULL != tree->rightChild)
		destory(tree->rightChild);
	delete tree;
	tree = NULL;
}

template<class T>
void BSTree<T>::insertNode(T key)
{
	BSTNode<T>* newNode = new BSTNode<T>(key, NULL, NULL, NULL);
	insertNode(newNode, mRoot);
}
template<class T>
void BSTree<T>::insertNode(BSTNode<T>* newNode, BSTNode<T>* tree)
{
	if (NULL == tree)
	{
		mRoot = newNode;
		return;
	}
	BSTNode<T>* save;
	while (tree != NULL)
	{
		save = tree;
		if (newNode->key < tree->key)
			tree = tree->leftChild;
		else if (newNode->key > tree->key)
			tree = tree->rightChild;
	}

	newNode->parent = save;
//	cout << newNode->key << " at " << save->key;
	if (newNode->key < save->key)
	{
		save->leftChild = newNode;
//		cout << " left" << endl;
	}
	else if (newNode->key > save->key)
	{
		save->rightChild = newNode;
//		cout << " right" << endl;
	}

}

template<class T>
void BSTree<T>::preOrder() const
{
	preOrder(mRoot);
}
template<class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const
{
	if (tree == NULL)
		return;
	std::cout << tree->key << " ";
	preOrder(tree->leftChild);
	preOrder(tree->rightChild);
}

template<class T>
void BSTree<T>::inOrder() const
{
//	std::cout << "using inOrder" << endl;
	inOrder(mRoot);
}
template<class T>
void BSTree<T>::inOrder(BSTNode<T>* tree) const
{
	if (tree == NULL)
		return;
	inOrder(tree->leftChild);
	std::cout << tree->key << " ";
	inOrder(tree->rightChild);
}

template<class T>
void BSTree<T>::postOrder() const
{
	postOrder(mRoot);
}
template<class T>
void BSTree<T>::postOrder(BSTNode<T>* tree) const
{
	if (tree == NULL)
		return;
	postOrder(tree->leftChild);
	postOrder(tree->rightChild);
	std::cout << tree->key << " ";
}
template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key) const
{
	return iterativeSearch(key, mRoot);
}
template<class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key, BSTNode<T>* tree) const
{
	if (tree == NULL)
		return NULL;
	while (tree != NULL)
	{
		if (key == tree->key)
			break;
		else if (key < tree->key)
			tree = tree->leftChild;
		else if (key > tree->key)
			tree = tree->rightChild;
	}
	return tree;
}
// a bug: minimum and maximum can't get max or min value is an empty tree.
template<class T>
T BSTree<T>::minimum() const
{
	return  minimum(mRoot)->key;
}
template<class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree) const
{
	if (tree == NULL)
		return NULL;
	while (tree->leftChild != NULL)
	{
		tree = tree->leftChild;
	}
	return tree;
}

template<class T>
T BSTree<T>::maximum() const
{
	return maximum(mRoot);
}
template<class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree) const
{
	if (tree == NULL)
		return NULL;
	while (tree->rightChild != NULL)
		tree = tree->rightChild;
	return tree;
}
template<class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T>* tree) const
{
	//has rightChild
	if (tree->rightChild != NULL)
		return minimum(tree->rightChild );
	//not have rightChild
	BSTNode<T>* p = tree;
	while ((p->parent->leftChild != p) && p != NULL)
	{
		p = p->parent;
	}
	return (p != NULL) ? p->parent : p;
}
template<class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T>* tree) const
{
	if (tree->leftChild != NULL)
		return maximum(tree->leftChild);

	BSTNode<T>* p = tree;
	while ((p->parent->rightChild != p) && p != NULL)
	{
		p = p->parent;
	}
	return (p != NULL) ? p->parent : p;
}
template<class T>
void BSTree<T>::remove(T key)
{
	BSTNode<T>* removed;
	if ((removed = iterativeSearch(key))!= NULL)
	{
		delete remove(removed);
	}
}
template<class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* removed)
{
	BSTNode<T>* surrenal = NULL;
	if ((NULL == removed->leftChild) || (NULL == removed->rightChild))
	{
		surrenal = (removed->leftChild != NULL) ? (removed->leftChild) : (removed->rightChild);

		if (mRoot == removed)
		{
			BSTNode<T>* p = mRoot;
			mRoot = surrenal;
			if(surrenal != NULL)
				surrenal->parent = NULL;
			return p;
		}

		if (removed->parent->leftChild == removed)
			removed->parent->leftChild = surrenal;
		else if (removed->parent->rightChild == removed)
			removed->parent->rightChild = surrenal;
		
		if (surrenal != NULL)
			surrenal->parent = removed->parent;
		return removed;
	}
	else if ((NULL != removed->leftChild) && (NULL != removed->rightChild))
	{
		//surrenal后继结点
		surrenal = successor(removed);
		//是左孩子
		if (surrenal->parent->leftChild == surrenal)
		{
			surrenal->parent->leftChild = surrenal->rightChild;
			if (surrenal->rightChild != NULL)
				surrenal->rightChild = surrenal->parent;
		}
		else if (surrenal->parent->rightChild == surrenal)
		{
			surrenal->parent->rightChild = surrenal->rightChild;
			if (surrenal->rightChild != NULL)
				surrenal->rightChild = surrenal->parent;
		}
		removed->key = surrenal->key;
		return surrenal;
	}

}