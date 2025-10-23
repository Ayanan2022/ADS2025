#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
    string original;
};

vector<Date> dates;


bool isEarlier(Date d1, Date d2) {
    if (d1.year != d2.year) return d1.year < d2.year;
    if (d1.month != d2.month) return d1.month < d2.month;
    return d1.day < d2.day;
}


void quick_sort(int left, int right) {
    Date pivot = dates[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (isEarlier(dates[i], pivot)) i++;
        while (isEarlier(pivot, dates[j])) j--;

        if (i <= j) {
            swap(dates[i], dates[j]);
            i++;
            j--;
        }
    }

    if (left < j) quick_sort(left, j);
    if (i < right) quick_sort(i, right);
}

int main() {
    int n;
    cin >> n;
    dates.resize(n);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dates[i].original = s;

        dates[i].day   = (s[0] - '0') * 10 + (s[1] - '0');
        dates[i].month = (s[3] - '0') * 10 + (s[4] - '0');
        dates[i].year  = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
    }

    quick_sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << dates[i].original << "\n";
    }

    return 0;
}
