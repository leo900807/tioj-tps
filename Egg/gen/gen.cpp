#include "testlib.h"
#include <cassert>

int main(int argc, char* argv[]) {
    assert(argc > 2);
    registerGen(argc, argv, 1);
    const std::string input_secret = "658b77d5cd1df1ccb948a11e1985a39294c6d63b";
    const long long xorM = 7280054266103598729;
    const long long xorh = 7051254730075703428;

    long long M = atol(argv[1]);
    long long h = atol(argv[2]);

    if (h == -1)
        h = rnd.next(1LL, M);

    h ^= M;
    h ^= xorh;
    M ^= xorM;

    printf("%s\n", input_secret.c_str());
    printf("%lld %lld\n", M, h);
}
