#include "openssl_sha256.h"
#include "MerkleTree.h"
#include <iostream>
#include "openssl/evp.h"
using namespace std;

int main() {
	MerkleTree<string> test;
	cout << endl << "PreOrder��" << endl;
	test.PreOrder(test.getRoot());
	cout << endl << "InOrder��" << endl;
	test.InOrder(test.getRoot());
	cout << endl << "PostOrder��" << endl;
	test.PostOrder(test.getRoot());
}