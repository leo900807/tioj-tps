#include <iostream>
using namespace std;

int main () {
ios_base::sync_with_stdio(0);cin.tie(0);
int N, M, x=0, y=0;
while(cin >> M >> N){
while(y<M){
if(x<N){
    if(M<=0 or N<=0){
        break;
    }
    if(x%2==0){
        cout << "1";
    }
    else{
        cout << "0";
    }
    x++;
        }
else{
    cout << endl;
    y++;
    x=0;
    }
    break;
}
}
}