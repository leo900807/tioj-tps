#include "testlib.h"
#include <set>
#include <string>

void exit_WA() {
    quitf(_wa, "Wrong Answer");
}

void exit_AC() {
    quitf(_ok, "Accept");
}

void exit_PAR(double score) { // score should between 0 and 1
    quitp(score, "Partially Correct");
}

void check(bool res) {
    if (!res)
        exit_WA();
}

const std::string output_secret = "229d567448d159b617823b53cab93f3872704960";

int readAns(InStream &stream) {
    stream.readWord(output_secret, "output_secret");
    stream.readWord("Accepted:", "accepted msg");
    stream.readInt(0, 60, "time");
    return 1;
}

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);
    int rt = readAns(ouf);
    if (rt == 1)
        exit_AC();
    else
        exit_WA();
}
