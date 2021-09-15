#include "testlib.h"
#include <set>
#include <string>

void exit_WA() {
    quitf(_wa, "");
}

void exit_AC() {
    quitf(_ok, "");
}

void exit_PAR(double score) { // score should between 0 and 1
    quitp(score, "");
}

void check(bool res) {
    if (!res)
        exit_WA();
}

const int MAXC = 1000000000;
std::set<int> vis;
int N, M;

int readAns(InStream &stream) {
    int cnt = 0;
    while (!stream.seekEof()) {
        ++cnt;
        int A = stream.readInt(0, MAXC, "A_" + std::to_string(cnt));
        int B = stream.readInt(0, MAXC, "A_" + std::to_string(cnt));
        check(A + B == N);
        check(vis.find(A) == vis.end());
        vis.insert(A);
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    N = inf.readInt();
    M = inf.readInt();
    int cnt = readAns(ouf);
    if (cnt > M || cnt == 0)
        exit_WA();
    else if (cnt == M)
        exit_AC();
    else if (M == 100)
        exit_PAR((double)cnt / 100);
    else
        exit_WA();
}
