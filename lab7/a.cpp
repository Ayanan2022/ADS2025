#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].size() <= R[j].size()) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int t;
    cin >> t;
    cin.ignore(); // ignore newline after number

    while (t--) {
        vector<string> arr;
        string s;

        string line;
        getline(cin, line);

        string word = "";
        for (char c : line) {
            if (c == ' ') {
                if (!word.empty()) {
                    arr.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) arr.push_back(word);

        mergeSort(arr, 0, arr.size() - 1);

        for (string &x : arr) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
