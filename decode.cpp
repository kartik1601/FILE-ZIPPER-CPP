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

    //argv[1] contains the input huffman filename
    //argv[2] containss the output text filename
    huffman f(argv[1], argv[2]);
    f.decompress();
    cout << "Decompressed successfully" << endl;

    return 0;
}