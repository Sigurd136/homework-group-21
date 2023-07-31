#pragma once
#include "sm3.h"
#include<iostream>
using namespace std;

template<class T>
class MerkleTreeNode {
	template<class T>
	friend class MerkleTree;
private:
	T data;
	MerkleTreeNode<T>* leftchild;
	MerkleTreeNode<T>* rightchild;
public:
	MerkleTreeNode() {
		leftchild = NULL;
		rightchild = NULL;
	}
	MerkleTreeNode(const T& dataValue) {
		data = iteration(padding(dataValue));
		leftchild = NULL;
		rightchild = NULL;
	}
	MerkleTreeNode(const T& dataValue, MerkleTreeNode<T>* leftchildValue, MerkleTreeNode<T>* rightchildValue) {
		data = dataValue;
		leftchild = leftchildValue;
		rightchild = rightchildValue;
	}
	~MerkleTreeNode() {
		leftchild = NULL;
		rightchild = NULL;
	}
	void UpdateNode(const T& dataValue) {
		data = dataValue;
	}
	void VisitNode() {
		cout << data << endl;
	}
	MerkleTreeNode<T>* getLeft() {
		return leftchild;
	}
	MerkleTreeNode<T>* getRight() {
		return rightchild;
	}
};

template<class T>
class MerkleTree {
private:
	MerkleTreeNode<T>* root;
public:
	MerkleTree() {
		root = NULL;
		cout << "Now start to construct the MerkleTree" << endl;
		CreateNode(root);
	}
	~MerkleTree() {
		root = NULL;
	}
	void CreateNode(MerkleTreeNode<T>*& treeNode) {
		cout << "Please enter value or '#' to stop:";
		T value;
		cin >> value;
		treeNode = new MerkleTreeNode<T>(value);
		if (value == "#") {
			delete treeNode;
			treeNode = NULL;
		}
		else {
			CreateNode(treeNode->leftchild);
			CreateNode(treeNode->rightchild);
			if (treeNode->leftchild != NULL && treeNode->rightchild != NULL) {
				treeNode->data = iteration(padding(treeNode->leftchild->data + treeNode->rightchild->data));
			}
		}
	}
	MerkleTreeNode<T>* getRoot() {
		return root;
	}
	void PreOrder(MerkleTreeNode<T>* treeNode) {
		if (treeNode != NULL) {
			treeNode->VisitNode();
			PreOrder(treeNode->getLeft());
			PreOrder(treeNode->getRight());
		}
	}
	void InOrder(MerkleTreeNode<T>* treeNode) {
		if (treeNode != NULL) {
			InOrder(treeNode->getLeft());
			treeNode->VisitNode();
			InOrder(treeNode->getRight());
		}
	}
	void PostOrder(MerkleTreeNode<T>* treeNode) {
		if (treeNode != NULL) {
			PostOrder(treeNode->getLeft());
			PostOrder(treeNode->getRight());
			treeNode->VisitNode();
		}
	}
};