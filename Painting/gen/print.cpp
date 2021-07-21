#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wtype-limits"
#include "testlib.h"
#pragma GCC diagnostic pop
#include <bits/stdc++.h>
using namespace std;

const int C_MAX = 1000000;

int main(int argc, char* argv[]) {
    assert(argc > 2);
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    printf("%d %d\n", N, M);
}

