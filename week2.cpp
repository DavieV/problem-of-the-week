/*
Copyright DavieV
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

double linearMedian(vector<int>, vector<int>);
double logMedian(vector<int>, vector<int>);

int main() {
    int m, n;
    cin >> m >> n;

    vector<int>a;
    vector<int>b;

    for (int i = 0; i < m; i++)
        a.push_back(rand() % 100);

    for (int j = 0; j < n; j++)
        b.push_back(rand() % 100);

    cout << linearMedian(a, b) << endl;

    return 0;
}

double linearMedian(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int>merged;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(merged));

    int size = merged.size();
    if (size & 1 == 1)
        return merged[size/2];
    else
        return (merged[size/2] + merged[size/2 - 1]) / 2.0;
}

double logMedian(vector<int> a, vector<int> b) {
    int loA = 0, hiA = a.size(), loB = 0, hiB = b.size();
    int midA = (loA + hiB) / 2;
    int midB = (loA + hiB) / 2;
    while ((hiA - loA) > 2 && (hiB - loB) > 2) {
        if (a[midA] < b[midB]) {
            loA = midA;
            midA = (loA + hiA) / 2;
            hiB = midB;
            midB = (loB + hiB) / 2;
        } else if (a[midA] > b[midB]) {
            hiA = midA;
            midA = (loA + hiA) / 2;
            loB = midB;
            midB = (loB + midB) / 2;































            
        }
    }
}
