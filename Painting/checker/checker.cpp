#include "testlib.h"
#include <string>
using namespace std;

string ans1[2]={"01", "10"};
string ans2[5]={"1111011110111101001", "1001010000100001001", "1111010000111101111", "1000010000000101001", "1000011110111101001"};
string opt[105];

void wa() {
    quitf(_wa, "translate:wrong");
}

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);
    int n, m, cnt = 0;
    n = inf.readInt();
    m = inf.readInt();
    for (int i = 0; i < n; ++i) {
        opt[i] = ouf.readString("[01]+", "translate:wrong");
        if (int(opt[i].size()) != m)
            wa();
        for (char c : opt[i])
            if (c == '1')
                ++cnt;
            else if (c != '0')
                wa();
    }       
    if (cnt == 0 || cnt == n * m)
        wa();
    if (n == 2 && m == 2) {
        int flag = 1;
        for (int i = 0; i < n; ++i)
            if (ans1[i] != opt[i])
                flag = 0;
        if (flag)
            wa();
    }
    if (n == 5 && m == 19) {
        int flag = 1;
        for (int i = 0; i < n; ++i)
            if (ans2[i] != opt[i])
                flag = 0;
        if (flag)
            wa();
    }
    quitf(_ok, "translate:success");
}
