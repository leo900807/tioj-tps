#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wtype-limits"
#include "testlib.h"
#pragma GCC diagnostic pop
#include <bits/stdc++.h>
using namespace std;

const int N_MAX = 2;
const int M_MAX = 2;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(2, N_MAX, "N");
    inf.readSpace();
    int M = inf.readInt(2, M_MAX, "M");
    inf.readEoln();
    ensuref(N * M >= 2, "N * M < 2");
    inf.readEof();
}

