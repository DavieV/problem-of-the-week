#include <iostream>
#include <vector>

int find_value(std::vector<int> nums);

int main() {
    int N;
    std::vector<int> nums;
    int tmp;

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> tmp;
        nums.push_back(tmp);
    }

    std::cout << find_value(nums) << std::endl;

    return 0;
}

int find_value(std::vector<int> nums) {
    int val = 0;
    for (int i : nums)
        val ^= i;
    return val;
}

