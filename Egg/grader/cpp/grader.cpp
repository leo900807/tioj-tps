#include "Egg.h"

#include <cassert>
#include <stdio.h>
#include <stdlib.h>
// BEGIN SECRET
#include <string>
// END SECRET

namespace {
    long long M, h;
    int count;
    void wa(const char* msg) {
        printf("Wrong Answer: %s\n", msg);
        exit(0);
    }
}

int is_broken(long long k) {
    ++count;
    if (count > 60)
        wa("too many queries");
    if (k <= 0 || k > M)
        wa("invalid broken query");
    return k > h;
}

int main() {
    // BEGIN SECRET
    const std::string input_secret = "658b77d5cd1df1ccb948a11e1985a39294c6d63b";
    const std::string output_secret = "229d567448d159b617823b53cab93f3872704960";
    const long long xorM = 7280054266103598729;
    const long long xorh = 7051254730075703428;

    char secret[1000];
    assert(1 == scanf("%s", secret));
    if (std::string(secret) != input_secret)
        wa("cheating!");
    // END SECRET
    assert(2 == scanf("%lld %lld", &M, &h));
    // BEGIN SECRET
    M ^= xorM;
    h ^= xorh;
    h ^= M;
    // END SECRET
    long long rt = height_limit(M);
    // BEGIN SECRET
    printf("%s\n", output_secret.c_str());
    // END SECRET
    if (rt == h)
        printf("Accepted: %d\n", count);
    else
        wa("incorrect height");
}
