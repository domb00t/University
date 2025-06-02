#include <iostream>
#include <string>


char toLower(char c) {
    if (c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}


bool hasUniqueLetters(const std::string& word) {
    std::string used;

    for (size_t i = 0; i < word.length(); ++i) {
        char c = toLower(word[i]);
        if (used.find(c) != std::string::npos) {
            return false;
        }
        used += c;
    }

    return true;
}


std::string filterWords(const std::string& input) {
    std::string result;
    std::string word;

    for (size_t i = 0; i <= input.length(); ++i) {
        if (i < input.length() && input[i] != ' ') {
            word += input[i];
        } else {
            if (!word.empty() && hasUniqueLetters(word)) {
                result += word + ' ';
            }
            word.clear();
        }
    }

    return result;
}

int main() {
    std::string input;
    std :: getline(std :: cin, input);
    std::string output = filterWords(input);
    std::cout << "relust: " << output << std::endl;
    return 0;
}