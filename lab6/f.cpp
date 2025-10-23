#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    string last, first;
    double gpa;
};

vector<Student> a;

double getGPA(string mark) {
    if (mark == "A+") return 4.0;
    if (mark == "A")  return 3.75;
    if (mark == "B+") return 3.5;
    if (mark == "B")  return 3.0;
    if (mark == "C+") return 2.5;
    if (mark == "C")  return 2.0;
    if (mark == "D+") return 1.5;
    if (mark == "D")  return 1.0;
    return 0.0;
}

void quick_sort(int l, int r) {
    int i = l, j = r;
    double pivot = a[(l + r) / 2].gpa;
    string pivot_last = a[(l + r) / 2].last;
    string pivot_first = a[(l + r) / 2].first;

    while (i <= j) {
        while (
            (a[i].gpa < pivot) ||
            (a[i].gpa == pivot && a[i].last < pivot_last) ||
            (a[i].gpa == pivot && a[i].last == pivot_last && a[i].first < pivot_first)
        ) i++;

        while (
            (a[j].gpa > pivot) ||
            (a[j].gpa == pivot && a[j].last > pivot_last) ||
            (a[j].gpa == pivot && a[j].last == pivot_last && a[j].first > pivot_first)
        ) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quick_sort(l, j);
    if (i < r) quick_sort(i, r);
}

int main() {
    int n;
    cin >> n;

    for (int k = 0; k < n; k++) {
        string last, first;
        int m;
        cin >> last >> first >> m;

        double sum = 0;
        int totalCredits = 0;

        for (int i = 0; i < m; i++) {
            string grade;
            int credit;
            cin >> grade >> credit;
            sum += getGPA(grade) * credit;
            totalCredits += credit;
        }

        Student s;
        s.last = last;
        s.first = first;
        s.gpa = sum / totalCredits;
        a.push_back(s);
    }

    quick_sort(0, a.size() - 1);

    cout << fixed << setprecision(3);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i].last << " " << a[i].first << " " << a[i].gpa << endl;
    }

    return 0;
}
