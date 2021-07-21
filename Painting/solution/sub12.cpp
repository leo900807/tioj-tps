#include <bits/stdc++.h>
using namespace std;


string to2(int num){
    int n = num;
    string re = "";
    while(n != 0){
        int t = 0;
        t = n%2;
        n = n/2;
        re += to_string(t);
    }
    return re;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int now = 0;
    for (int i = 0;  i<n ; i++){
        now++;
        string pr = to2(now);
        string f;
        for (int w = 0;  w < m - pr.size() ; w++){
            f += "0";
        }
        cout << pr + f << '\n';
    }
}