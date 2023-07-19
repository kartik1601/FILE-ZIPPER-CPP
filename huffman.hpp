//Header Guards to prevent header files from being included multiple times
#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//Defining Huffman Tree Node
//created during compression or decompression
struct Node {
    char data;
    unsigned freq;
    string code;
    //left and right nodes denotes the nodes whose 
    //sum is the current node {during huffman algo}
    Node *left, *right;
    Node():left(NULL),right(NULL) {}
};

class huffman {
    private:
        vector<Node*> arr;

        fstream inFile, outFile;

        string inFileName, outFileName;
        
        Node *root;
        
        class Compare {
            public:
                //operator overloading to compare two nodes with a custom condition
                /*the two nodes added in the priority queue are 
                sorted in descending order using their frequency variable */
                bool operator() (Node* l, Node* r){
                    return l->freq > r->freq;
                }
        };

        priority_queue <Node*, vector<Node*>, Compare> minHeap;
        
        //Initializing a vector of tree nodes representing character's ascii value and initializing its frequency with 0
        void createArr();
        
        //Traversing the constructed tree to generate huffman codes of each present character
        void traverse(Node*, string);
        
        //Function to convert binary string to its equivalent decimal value
        int binToDec(string);
        
        //Function to convert a decimal number to its equivalent binary string
        string decToBin(int);
        
        //Reconstructing the Huffman tree while Decoding the file
        void buildTree(char, string&);

        //Creating Min Heap of Nodes by frequency of characters in the input file
        void createMinHeap();
        
        //Constructing the Huffman tree
        void createTree();
        
        //Generating Huffman codes
        void createCodes();
        
        //Saving Huffman Encoded File
        void saveEncodedFile();
        
        //Saving Decoded File to obtain the original File
        void saveDecodedFile();
        
        //Reading the file to reconstruct the Huffman tree
        void getTree();

    public:
        //Constructor Intialisation
        huffman(string inputFileName, string outputFileName){
            this->inFileName = inputFileName;
            this->outFileName = outputFileName;
            createArr();
        }
        //Compressing input file
        void compress();
        //Decrompressing input file
        void decompress();
};
#endif