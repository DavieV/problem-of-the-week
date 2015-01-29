#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <functional>
#include <cassert>

int max_profit(std::vector<int> stocks);
int max_profit(bool h, int p, int cost, int i, std::vector<int> stocks);

int main() {
    std::uniform_int_distribution<int> dist(1, 10);
    std::knuth_b gen;
    gen.seed(time(NULL));

    auto roll = std::bind(dist, gen);

    int c = 1;
    while (true) {
        int stock_len = 15;
        std::vector<int> stocks(stock_len);

        for (int i = 0; i < stocks.size(); ++i) {
            stocks[i] = roll();
        }
        assert(max_profit(stocks) == max_profit(false, 0, 0, 0, stocks));
        std::cout << "Case: " << c << std::endl;
        ++c;
    }

    return 0;
}

/*
----Linear time solution----
Greedy approach, simply buy/sell stocks while their price increases
*/
int max_profit(std::vector<int> stocks) {
    int profit = 0;
    for (int i = 0; i < stocks.size() - 1; ++i) {
        if (stocks[i] < stocks[i+1])
            profit += stocks[i+1] - stocks[i];
    }
    return profit;
}

/* 
----Brute force 2^n solution used to verify answers----
Checks all possible outcomes and returns the maximum profit
*/
int max_profit(bool h, int p, int c, int i, std::vector<int> stocks) {
    if (i >= stocks.size())
        return p;
    if (h)
        return std::max(max_profit(h, p, c, i+1, stocks),
            max_profit(!h, p + (stocks[i]-c), 0, i+1, stocks));
    else
        return std::max(max_profit(!h, p, stocks[i], i+1, stocks),
            max_profit(h, p, c, i+1, stocks));
}
