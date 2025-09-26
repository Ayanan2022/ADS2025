#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    int a;
    cin >> a;

    vector<int> primes;
    for(int i=2;primes.size()<10000;i++){
        if(isPrime(i)){
            primes.push_back(i);
        }
    }
    int pn=primes[a-1];
    int result=primes[pn-1];
    cout << result << endl;

    return 0;
}