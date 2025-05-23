#include <iostream>
#include <vector>
#include <iterator>

std :: vector<int> :: const_iterator FindMaxIndex(const std :: vector<int>& vector) {
    int max = vector.at(0);
    std :: vector<int> :: const_iterator max_it = vector.begin();

    for(std :: vector<int> :: const_iterator it = vector.begin() + 1; it != vector.end(); ++it) {
        if(*it > max) {
            max = *it;
            max_it = it;
        }
    }

    return max_it;
}

std :: vector<int> :: const_iterator FindMinIndex(const std :: vector<int>& vector) {
    int min = vector.at(0);
    std :: vector<int> :: const_iterator min_it = vector.begin();

    for(std :: vector<int> :: const_iterator it = vector.begin() + 1; it != vector.end(); ++it) {
        if(*it < min) {
            min = *it;
            min_it = it;
        }
    }

    return min_it;
}

int main() {
    std :: vector<int> vect;
    for(size_t i = 0; i < 20; ++i) {
        vect.push_back(i + 1);
    }

    std :: vector<int> result;
    std :: vector<int> :: const_iterator begin = min(FindMaxIndex(vect),FindMinIndex(vect));
    std :: vector<int> :: const_iterator end = max(FindMaxIndex(vect),FindMinIndex(vect));

    if(begin != end) {
        for( std :: vector<int> :: const_iterator it = begin + 1; it != end; ++it) {
            result.push_back(*it);
        }
    }

    for(std :: vector<int> :: iterator it = result.begin(); it != result.end(); ++it) {
        std :: cout << *it << " ";
    }
    std :: cout << "|size " <<result.size();

    return 0;
}