#include <iostream>
#include <fstream>
#include <cctype> // case sensitive
#include "TextAnalysisInterfaceBST.h"
using namespace std;

//definitionn of function of insering a word int o a birary search tree
void insert(myTreeNode*& root, const string& myWord, int levelTree){
    if(!root){
        root = new myTreeNode(myWord);
        root->levelTree = levelTree;
        return;
    }

    if(myWord < root->myWord){
        insert(root->left, myWord, levelTree + 1);
    }else if(myWord > root->myWord){
         insert(root->right, myWord, levelTree + 1);

    }else{
        root->myFrequency++; //increment the word which is already exists 
    }
     
}

//definition of the tunction to traverse the binary search tree and write out in th the output file
void traverseNodeAndWriteOut(myTreeNode* root, ofstream& outPutFile){
    if(!root) return;
    traverseNodeAndWriteOut(root->left, outPutFile);
    outPutFile << root->myWord <<" "<<root->myFrequency <<" "<<"(" <<root->levelTree<<")" <<endl;
    traverseNodeAndWriteOut(root->right, outPutFile);
}


//definition of the calculating the maximum and average of probes
void calculateProbes(myTreeNode* root, int& maximumProbes, int& totalCalculationProbes, int& totalNodes, int levelTree){
    if(!root) return; 

     //increment totalCalculationProbes for every node visited
    totalNodes++;

    //accumulate probes ath the current node
    totalCalculationProbes+=levelTree; 

     //upadtaing the maximum probes
    maximumProbes = max(maximumProbes, levelTree);
    
    

    calculateProbes(root->left, maximumProbes, totalCalculationProbes,totalNodes, levelTree + 1);
    // maximumProbes = max(maximumProbes, levelTree); //upadtaing the maximum probes
    calculateProbes(root->right, maximumProbes, totalCalculationProbes, totalNodes, levelTree + 1);

}
void computesTotalProbes(myTreeNode* root, int& maximumProbes, int& totalCalculationProbes, int& totalNodes){
    totalCalculationProbes = 0;
    calculateProbes(root, maximumProbes, totalCalculationProbes,totalNodes, 1);

}






