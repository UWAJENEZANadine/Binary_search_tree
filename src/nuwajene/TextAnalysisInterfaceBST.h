#ifndef TEXT_ANALYSIS_INTERFACE_BST_H
#define TEXT_ANALYSIS_INTERFACE_BST_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std; //define namespace for string and file operations


//Define structure for my tree node
struct myTreeNode{
    string myWord;
    int totalNodes;
    int myFrequency;
    myTreeNode* left;
    myTreeNode* right;
    int levelTree; //level in the tree

    myTreeNode(const string& wo): myWord(wo), myFrequency(1), left(nullptr), right(nullptr), levelTree(0){}

};

//My functions 
void insert(myTreeNode*& root, const string& myWord, int levelTree);
void traverseNodeAndWriteOut(myTreeNode* root, ofstream& outPutFile);
void calculateProbes(myTreeNode* root, int& maximumProbes, int& totalCalculationProbes, int& totalNodes, int levelTree);

#endif  //TEXT_ANALYSIS_INTERFACE_BST_H


