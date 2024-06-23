#include <iostream>

int main(int argc, char **argv) {
    using namespace std;

    if (argc != 2) {
        cerr << "usage: ./solve [input-file]" << endl;
        exit(1);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        cerr << "Unable to open file: " << filename << endl;
        exit(1);
    }

    fclose(file);
    return 0;
}