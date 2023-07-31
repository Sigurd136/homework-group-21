#include "openssl_sha256.h"
#include "MerkleTree.h"
#include <iostream>
#include "openssl/evp.h"
using namespace std;

int main() {
	MerkleTree<string> test;
	cout << endl << "PreOrder£º" << endl;
	test.PreOrder(test.getRoot());
	cout << endl << "InOrder£º" << endl;
	test.InOrder(test.getRoot());
	cout << endl << "PostOrder£º" << endl;
	test.PostOrder(test.getRoot());
}