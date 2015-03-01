#include <iostream>
#include <vector>
#include <algorithm>

int find_element(std::vector<int> A, std::vector<int> B, int k);
int find_element(std::vector<int> A, int lA, std::vector<int> B, int lB, int k);

int main() {
    int k;  // Element we are searching for
    int N, M;  // Sizes of the two arrays

/*    std::cin >> N;
    std::cin >> M;
    std::cin >> k;

    std::vector<int> A;
    std::vector<int> B;

    int tmp;
    for (int i = 0; i < N; ++i) {
        std::cin >> tmp;
        A.push_back(tmp);
    }

    for (int i = 0; i < M; ++i) {
        std::cin >> tmp;
        B.push_back(tmp);
    }*/

    std::vector<int> A {1, 3, 7, 8, 12, 15};
    std::vector<int> B {2, 4, 9, 11, 13, 14};

    std::cout << find_element(A, 0, B, 0, 7) << std::endl;

    return 0;
}

int find_element(std::vector<int> A, std::vector<int> B, int k) {
    std::vector<int> tmp(A.size() + B.size());
    std::merge(A.begin(), A.end(), B.begin(), B.end(), tmp.begin());
    return tmp[k-1];
}
