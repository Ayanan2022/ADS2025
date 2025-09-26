#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> boris;
    queue<int> nurik;
    int num;

    for(int i=0;i<5;i++){
        cin >> num;
        boris.push(num);
    }

    for(int i=0;i<5;++i){
        cin >> num;
        nurik.push(num);
    }

    int moves=0;
    const int MAX_MOVES = 1000000;

    while(!(boris.empty()) && !(nurik.empty()) && moves<MAX_MOVES){
        int b=boris.front(); boris.pop();
        int n=nurik.front(); nurik.pop();

        if (b == 0 && n == 9) {
            // Boris wins
        boris.push(b);
        boris.push(n);
        } else if (b == 9 && n == 0) {
         // Nursik wins
            nurik.push(b);
            nurik.push(n);
        } else if (b > n) {
            // Boris wins
            boris.push(b);
            boris.push(n);
        } else {
        // Nursik wins
            nurik.push(b);
            nurik.push(n);
        }
        moves++;
    }

    if (moves>=MAX_MOVES){
        cout << "Draw" << endl;
    }
    else if (boris.empty()){
        cout << "Nursik " << moves ;
    }
    else if(nurik.empty()){
        cout << "Boris " << moves;
    }



    return 0;
}