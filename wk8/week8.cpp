#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>

int find_index(std::vector<int> marbles);

template <class Iter>
Iter find_marble(Iter first, Iter last);

template <class Iter>
Iter partition(Iter first, Iter last, int len);

template <class Iter>
int heavier(Iter a_first, Iter a_last, Iter b_first, Iter b_last);

int main() {
    std::vector<int> marbles;
    int tmp;

    while (std::cin >> tmp)
        marbles.push_back(tmp);

    std::cout << find_index(marbles) << std::endl;

    return 0;
}

/*
    Translates the iterator which points to the heavy marble into an index.
    *NOTE*: This method of iterator subtraction will only work on sequence
            containers which are stored contiguously in memory.
            (ie: vector, array)
*/
int find_index(std::vector<int> marbles) {
    auto iter = find_marble(std::begin(marbles), std::end(marbles));
    return iter - std::begin(marbles);
}

/*
    Returns an iterator to the heavy marble in a sequence of marble weights
*/
template <class Iter>
Iter find_marble(Iter first, Iter last) {
    auto len = std::distance(first, last);
    if (len <= 3) {
        if (len == 2) {
            int n = heavier(first, std::next(first), std::next(first), last);
            if (n == 1)
                return first;
            return std::next(first);
        } else {
            Iter m = partition(first, last, len);
            int n = heavier(first, m, m, std::next(m));
            if (n == 1)
                return first;
            else if (n == 2)
                return m;
            return std::next(m);
        }
    }
    /*
        Split the list into 3 (relatively) equal portions.
        portion 1: [first, end_1)
        portion 2: [end_1, end_2)
        portion 3: [end_2, last)
    */

    Iter end_1 = partition(first, last, len);
    Iter end_2 = partition(end_1, last, len);

    int n = heavier(first, end_1, end_1, end_2);

    if (n == 2)
        return find_marble(end_1, end_2);   // Marble is in middle portion
    else if (n == 1)
        return find_marble(first, end_1);   // Marble is in first portion
    return find_marble(end_2, last);        // Marble is in last portion
}

// Function used to split the list into 3 portions
template <class Iter>
Iter partition(Iter first, Iter last, int len) {
    for (int i = 0; i < len/3 && std::next(first) != last; ++i)
        ++first;
    return first;
}

/*
    Takes in iterators for two lists and returns if one is heavier
    than the other or if they weigh the same
*/
template <class Iter>
int heavier(Iter a_first, Iter a_last, Iter b_first, Iter b_last) {
    int a_weight = 0;
    int b_weight = 0;
    for (Iter i = a_first; i != a_last; ++i)
        a_weight += *i;

    for (Iter i = b_first; i != b_last; ++i)
        b_weight += *i;

    if (a_weight == b_weight)
        return 0;
    else if (a_weight > b_weight)
        return 1;
    else
        return 2;
}

