#include "testlib.h"
#include <string>
using namespace std;

const long long MAXC = 1e18;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    const string input_secret = "658b77d5cd1df1ccb948a11e1985a39294c6d63b";
    const string output_secret = "229d567448d159b617823b53cab93f3872704960";
    const long long xorM = 7280054266103598729;
    const long long xorh = 7051254730075703428;
    
    string str = inf.readWord(input_secret, "input_secret");
    inf.readEoln();

    long long M = inf.readLong(0LL, 9223372036854775807LL, "M");
    inf.readSpace();
    long long h = inf.readLong(0LL, 9223372036854775807LL, "h");
    inf.readEoln();
    
    M ^= xorM;
    h ^= xorh;
    h ^= M;
    
    ensuref(1 <= M && M <= MAXC, "M = %lld violate the range", M);
    ensuref(1 <= h && h <= M, "h = %lld violate the range", h);
    
    inf.readEof();
}
