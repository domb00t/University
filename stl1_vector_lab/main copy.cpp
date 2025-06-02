#include <iostream>
#include <list>
#include <iterator>

std :: list<int> :: iterator FindMaxIndex(std :: list<int>& vector) {
    int max = *vector.begin();
    std :: list<int> :: iterator max_it = vector.begin();

    for(std :: list<int> :: iterator it = ++vector.begin(); it != vector.end(); ++it) {
        if(*it > max) {
            max = *it;
            max_it = it;
        }
    }

    return max_it;
}

std :: list<int> :: iterator FindMinIndex(std :: list<int>& vector) {
    int min = *vector.begin();
    std :: list<int> :: iterator min_it = vector.begin();

    for(std :: list<int> :: iterator it = ++vector.begin(); it != vector.end(); ++it) {
        if(*it < min) {
            min = *it;
            min_it = it;
        }
    }

    return min_it;
}

int main() {
    std :: list<int> vect;
    for(size_t i = 0; i < 10; ++i) {
        vect.push_back(i + 1);
    }

    std :: list<int> result;
    std :: list<int> :: iterator begin = (std :: distance(vect.begin(),FindMinIndex(vect))  < std :: distance(vect.begin(),FindMaxIndex(vect))) ? FindMinIndex(vect) : FindMaxIndex(vect);
    std :: list<int> :: iterator end  = (begin == FindMinIndex(vect)) ? FindMaxIndex(vect) : FindMinIndex(vect);

    if(begin != end) {
        for( std :: list<int> :: iterator it = ++begin; it != end; ++it) {
            result.push_back(*it);
        }
    }


    for(std :: list<int> :: iterator it = result.begin(); it != result.end(); ++it) {
        std :: cout << *it << " ";
    }
    std :: cout << "|size " <<result.size();

    return 0;
}