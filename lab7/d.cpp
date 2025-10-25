#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string last, first;
    double gpa;
};

double getValue(string grade) {
    if (grade == "A+") return 4.00;
    if (grade == "A") return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B") return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C") return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D") return 1.00;
    return 0.0; // F
}

bool better(const Student &a, const Student &b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.last != b.last) return a.last < b.last;
    return a.first < b.first;
}

void mergeStudents(vector<Student> &arr, int L, int M, int R) {
    int n1 = M - L + 1;
    int n2 = R - M;

    vector<Student> left(n1), right(n2);
    int i;

    for (i = 0; i < n1; i++) left[i] = arr[L + i];
    for (i = 0; i < n2; i++) right[i] = arr[M + 1 + i];

    i = 0;
    int j = 0, k = L;

    while (i < n1 && j < n2) {
        if (better(left[i], right[j])) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

void mergeSort(vector<Student> &arr, int L, int R) {
    if (L < R) {
        int M = L + (R - L) / 2;
        mergeSort(arr, L, M);
        mergeSort(arr, M + 1, R);
        mergeStudents(arr, L, M, R);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        string last, first;
        cin >> last >> first;

        int t;
        cin >> t;

        double sum_gpa = 0.0;
        int sum_credits = 0;

        for (int j = 0; j < t; j++) {
            string grade;
            int credit;
            cin >> grade >> credit;

            sum_gpa += getValue(grade) * credit;
            sum_credits += credit;
        }

        students[i].last = last;
        students[i].first = first;
        students[i].gpa = sum_gpa / sum_credits;
    }

    mergeSort(students, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << students[i].last << " " << students[i].first << " ";
        cout << fixed << setprecision(3) << students[i].gpa << "\n";
    }

    return 0;
}
