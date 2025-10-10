#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std; 

int main( ){
    int ns; cin >> ns; 
    vector<int> search;
    while(ns--){
        int n; cin >> n; 
        search.push_back(n);
    }
    
    int c, r; cin >> r >> c;
    vector<vector<int> matrix(r,vector<int>(c));
    unordered_map<int, vector<pair<int,int>>> indexMap;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            int n; cin >> n; 
            matrix[i][j] = n; 
            indexMap[n].push_back({i,j}); 
        }

    } 

    for(int &l : search){
        if (indexMap.count(l)) {
            for (auto &pos : indexMap[l]) {
            cout << pos.first << " " << pos.second << endl;
            }
        } else {
            cout << -1 << endl;
        }   
    }

    return 0 ;
}