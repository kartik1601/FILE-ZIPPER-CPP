#include <iostream>
#include "huffman.hpp"
using namespace std;

/*
argc - argument count - represents the number of command-line arg passed to the program
argv - argument vector - contains all the arguments as array of strings
*/

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Failed to detect Files";
		exit(1);
	}
    
    //argv[1] contains the input text filename
    //argv[2] containss the output huffman filename
    huffman f(argv[1], argv[2]);
    f.compress();
    cout << "Compressed successfully" << endl;
    
    return 0;
}