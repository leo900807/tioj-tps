#include "testlib.h"

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(100, 1000000000, "N");
    inf.readSpace();
    int M = inf.readInt(100, 100, "M");
    inf.readEoln();
    inf.readEof();
}
