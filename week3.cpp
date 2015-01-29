#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <cstring>
#include <utility>

struct compare {
    bool operator()(std::pair<int, int> x, std::pair<int, int> y) {
        return x.first < y.first;
    }
};

int main() {
    int M;  // number of integers
    int N;  // sum requirement
    int tmp;
    std::vector<int> v;  // vector of inputs
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> tmp;
        v.push_back(tmp);
    }
    std::cin >> N;
    std::unordered_map<int, int> map;
    std::set<std::pair<int, int>, compare> set;
    for (int i = 0; i < M; ++i) {
        map[N-v[i]] = v[i];  // key value is the val that makes the pair
        set.insert(std::make_pair(N-v[i], v[i]));  // use a set to keep pairs sorted
    }
    for (auto i : set) {
        // check if both values are present
        if (map.find(i.first) != map.end() && map.find(i.second) != map.end())
            std::cout << i.first << " + " << i.second << std::endl;
    }
    return 0;
}
