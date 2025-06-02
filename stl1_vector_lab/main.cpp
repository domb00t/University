#include <iostream>
#include <vector>
#include <iterator>

std :: vector<int> :: iterator FindMaxIndex(std :: vector<int>& vector) {
    int max = *vector.begin();
    std :: vector<int> :: iterator max_it = vector.begin();

    for(std :: vector<int> :: iterator it = ++vector.begin(); it != vector.end(); ++it) {
        if(*it > max) {
            max = *it;
            max_it = it;
        }
    }

    return max_it;
}

std :: vector<int> :: iterator FindMinIndex(std :: vector<int>& vector) {
    int min = *vector.begin();
    std :: vector<int> :: iterator min_it = vector.begin();

    for(std :: vector<int> :: iterator it = ++vector.begin(); it != vector.end(); ++it) {
        if(*it < min) {
            min = *it;
            min_it = it;
        }
    }

    return min_it;
}

int main() {
    size_t size = 0;
    std :: cout << "size: ";
    std :: cin >> size;
    std :: vector<int> vect(size);
    for(size_t i = 0; i < vect.size(); ++i) {
        std :: cin >> vect[i];
    }
    

    std :: vector<int> result;
    std :: vector<int> :: iterator begin = (std :: distance(vect.begin(),FindMinIndex(vect))  < std :: distance(vect.begin(),FindMaxIndex(vect))) ? FindMinIndex(vect) : FindMaxIndex(vect);
    std :: vector<int> :: iterator end  = (begin == FindMinIndex(vect)) ? FindMaxIndex(vect) : FindMinIndex(vect);

    if(begin != end) {
        for( std :: vector<int> :: iterator it = begin + 1; it != end; ++it) {
            result.push_back(*it);
        }
    }


    for(std :: vector<int> :: iterator it = result.begin(); it != result.end(); ++it) {
        std :: cout << *it << " ";
    }
    std :: cout << "|size " <<result.size();

    return 0;
}