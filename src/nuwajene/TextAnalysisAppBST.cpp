/**
 * Author: Nadine Uwajeneza
 * AndrewID: nuwajene
 * Date of submission: March 03, 2024
 * 
 * Program overview
 * This program is designed to anlyse text data by using the binary search tree(simply Binary search tree is 
 * is a rooted binary tree data structure with key of each internal node being greater than all the keys in the respective
 * node's left subtree and less than the ones in its right subtree) for storing words and their frequencies and level.
 * it then calculates and outputs the maximum number of probes, the average of probes
 * and the word frequency and levels  to an output file. 
 * 
 * FUNCTIONALITY
 * This program iconsists of three main functions:
 * 
 * 1.INSERT(root, myword, levelTree)
 * inserts a word into the binary search tree
 * if the words alredy exists, increments its frequency count
 * Maintains the level of each node in the tree for proble calculations
 * parameters: 
 * root= this is a Pointer to the root node of the binary search tree
 * myword= this is a word to be inserted
 * levelTree= the level of the current node in the tree
 *  
 * 
 * 2.TRAVERSENODEANDWRITEOUT(root, outPutfile)
 * Traverses the binary search tree in-order and writes word frequesncy data to the output file
 * utilises recursion to traverse left subtree, write data, and traverse right subtree.
 * parameters:
 * root= this is pointer to the root node of the binary search tree
 * outputfile= This is the output stream to write data
 * 
 * 3.CALCULATEPROBES(root, maximumprobes, totalcalaculationprobes, totalnodes, levelTree)
 * recursively calculate the maximum and average number of probes
 * computes total probes by accumaling probe levels and counting nodes
 * upadating the maximum probes encountered during traversal
 * paramteres:
 * root= This is a pointer to the root node of the binary search tree
 * maximumprobes=This is the reference to store the maximuma number of probes
 * totalcalaculationprobes= this is the Reference to accumulate the total probes
 * totalnodes= This is the reference to count total nodes
 * levelTree = This is the level of the current node in the tree.
 * 
 * Formart of Iput and output:
 * Input:
 *  This program read 10 filenames from input file(Those file are called textfile1,textfile2,textfile3,textfile4,textfile5
 * textfile6,textfile7,textfile8,textfile9, textfile10). And each files contain a word
 * to be anlysed
 * 
 * Output:
 * The program writes the output of all those file to an output file, with my andrew id
 * and each section contain the path of file, The maximum number of probes,the average probes
 * The frequency of the word correponding with the levels, and at the end of each section files 
 * ends with separator 20 dashes.
 * 
 * Solution Strategy
 * I would like to implement the pseudocode to implement my solution strategy
 * 
 * 
 * 1.Read filenames from input file
 * 2. Open output File for writing
 * 
 * 3. For each filename in input file:
 * i.Initialize variables:
 * -root=NULL
 * -totalNodes=0
 * -maximumProbes=0
 * -toatalCalculationProbes=0
 * 
 * ii. Open the the text file corresponding to the current filename
 * iii.while not end of text file:
 * a) read a word from the text file
 * b)Clean the word (Remove non-alpganumeric charactes, convert to lowercase)
 * c)Inserst the cleaned word into the BST
 * 
 * iv)close The text file
 * 
 * 
 * v) Compute total probes:
 * Call computeTotalPRobes(root, maximumprobes, totalclaculationprobes, totalnode)
 * calculate average probes: avgprobes = totalclaculationprobes / totalnode
 * 
 * vi)write results to output file:
 * -Wirite andrew id to output file
 * -Wite the path of the file to output file
 * -write maximum number of probes to output file
 * -Write average number of probes to output file
 * -traverse the binary search tree in-order and write word frequency data to output file
 * -write the dashes at the end of each section
 * Clean memory: delet toot
 * 
 * 4. close input and output files
 * 
 * 
 * SUMMARY OF HOW FILE ARE TESTED
 * My first test case: this file contains the word which has not any frequency of word
 * My second test case: This file contain the word with the two frequency of word 
 * My Third test case: This file contain the word with more than two frequency of word
 * My Fourth test case: this file contains the word with 's, the program is going to ignore the apostrophe and the s
 * My Firth test case: This file contain the word with other character not apostrophe only
 * My sixth test case: This file contain the word with mixed with others character and (')apostrophe followed with s.
 * My seventh test case : this file contain the the word with apostrophe and and the other word which does not have apostrophe, all words are similar, it will be doubled
 * My eighth test case: This test case is will have word with repeating many times and my word with apostrophe
 * My nineth test case : this case will have one word repeat many times
 * Tenth test case: this case have will have the word repeated many times with apostrophe and non apostrophe but simiar
 * 
 * 
 * COMPLEXITY ANALYSIS
 * insertion:
 * average case: O(log n) -balanced BST
 * worst case: O(n) - unbalanced BST
 * 
 * 
 *probe calaculation:
 * O(n) - visits each node once to claculate probes.
*/


#include "TextAnalysisInterfaceBST.h"
#include <cmath> // for rounding
using namespace std; //defining namespace for string and file operations

int main(){
     ifstream myInputFile("../data/input.txt");
     ofstream myOutPutFile("../data/output.txt");


     //My Andrew id
     myOutPutFile << "nuwajene" <<endl;

     string myFileName;
    
     while(getline(myInputFile, myFileName)){
        myTreeNode* root = nullptr;
        ifstream insideFile(myFileName);
        string myWord;


        //read from my input file
        while(insideFile >> myWord){

            //remove the characters which is non alphanumeric characters and convert to lower case
            string wordCleaned;
            bool ignoreAprostopS = false; //false to ignore
            for(char c : myWord){
                if(isalnum(c) || c == '-'){
                    wordCleaned+=tolower(c); //convert to lower case
                
                }else if(c == '\''){
                    break; //stop processing the word if an apostrophe is encountered
                }
                }
                    //check if the previous character was an apostrophe
                    if(!wordCleaned.empty())
                         insert(root, wordCleaned, 0);
        }

                insideFile.close();



        //the maximum and average probes
         int totalNodes = 0;
        int maximumProbes = 0; 
        int totalCalculationProbes = 0;
        calculateProbes(root, maximumProbes, totalCalculationProbes, totalNodes, 1);
        double avgProbes = static_cast<double>(totalCalculationProbes)/totalNodes;

        //output results in my output file
        myOutPutFile<<myFileName<<endl;
        myOutPutFile<<"The maximum number of probes: "<<maximumProbes<<endl;
        myOutPutFile << "The average number of probes: "<< round(avgProbes*10)/10 <<endl;

        traverseNodeAndWriteOut(root, myOutPutFile);
        myOutPutFile << "--------------------"<<endl;

        //clean memort
        delete root;

     }
     myInputFile.close();
     myOutPutFile.close();


    return 0;
}