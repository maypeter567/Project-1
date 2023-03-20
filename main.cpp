#include <iostream>
#include "Convert.h"
using namespace std;

//used to check if the file names exist


int main(int argc, char *argv[]) {
//    check if the command line was used correctly
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " [File Name 1]" << " [File Name 2]" << endl;
        cerr << " Required File Name 1 to read from, optional File Name 2 to print to.";
        return 1;
    } else if (argc > 3) {
        cerr << "usage: " << argv[0] << " [File Name 1]" << " [File Name 2]" << endl;
        cerr << "Too many inputs" << endl;
        return 1;
    }

    if (argc == 3) {
        Convert conv(argv[1], argv[2]);
        conv.run();
    } else {
        Convert conv(argv[1]);
        conv.run();
    }

    return 0;
}