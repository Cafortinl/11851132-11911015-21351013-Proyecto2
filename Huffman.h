#pragma once


#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "TreeNode.hpp"
#include "Object.hpp"
#ifndef Huffman_HPP
#define OBJECT_HPP
using namespace std;

//Delia Rivera

class Huffman  {
public:
	TreeNode* getNode(char cha, int frequ, TreeNode* left, TreeNode* right) {
		TreeNode* node = new TreeNode();
		cha = node->getChar();
		frequ = node->getFreq();
		node->left = left;
		node->right = right;
		return node;
	}

	void encode(TreeNode* root, string str, unordered_map<char, string> &huffmanCode);
		


	void decode(TreeNode* root, int &top_index, string str);
	
	void buildHuffmanTree(string text);
	

	
};

struct comp {
	bool operator()(TreeNode* l, TreeNode* r) {
		return l->getFreq() > r->getFreq();
	}
};


void Huffman::encode(TreeNode* root, string str, unordered_map<char, string> &huffmanCode) {
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		huffmanCode[root->getChar()] = str;
	}
	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}


 void Huffman::decode(TreeNode* root, int &top_index, string str) {

	if (root == nullptr) {
		return;
	}

	if (!root->left && !root->right) {
		cout << root->getChar();
		return;
	}
	top_index++;
	if (str[top_index] == '0')
		decode(root->left, top_index, str);
	else
		decode(root->right, top_index, str);

}


 void Huffman::buildHuffmanTree(string text) {
	 priority_queue<TreeNode*, vector<TreeNode*>, comp> pq;
	 unordered_map<char, int> freq;
	 
	 for (char ch : text) {
		 freq[ch]++;
	 }


	 for (auto pair : freq) {
		 pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	 }
	 
	 while (pq.size() != 1) {
		 TreeNode* left = pq.top();pq.pop();
		 TreeNode* right = pq.top();pq.pop();

		 int sum = left->getFreq() + right->getFreq();
		 pq.push(getNode('\0', sum, left, right));
	 }

	 TreeNode* root = pq.top();
	 unordered_map<char, string> huffmanCode;
	 encode(root, "", huffmanCode);

	 cout << "Código de Huffman es: \n" << '\n';

	 string str = " ";
	 for (char ch : text) {
		 str += huffmanCode[ch];
	 }
	 cout << "\nEl texto codificado es:\n" << str << '\n';
	 int top_index = -1;
	 cout << "\nEl texto decodificado es:\n";
	 while (top_index < (int)str.size() - 2) {
		 decode(root, top_index, str);
	 }
 }
#endif
