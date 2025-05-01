#include "my_string.h"
#include <cstring>
#include <ctime>
#include <functional>

String :: String() : str_(nullptr), sz_(0), cap_(0) {}

String :: String(size_t sz) : str_(new char[sz + 1]), sz_(sz), cap_(sz + 1) {
    std :: memset(str_,'1',sz_);
    str_[sz_] = '\0';
}

String::String(const char *c_str) : str_(new char[strlen(c_str) + 1]), sz_(strlen(c_str)), cap_(strlen(c_str) + 1) {
    std :: memcpy(str_,c_str,cap_);
    str_[sz_] = '\0';
}

String :: String(const String& other) : str_(new char[other.cap_]), sz_(other.sz_), cap_(other.cap_) {
    std :: memcpy(str_,other.str_,cap_);
}

void String :: swap(String& other) {
    char* tstr = other.str_;
    str_ = other.str_;
    other.str_ = tstr;

    size_t tmp;

    tmp = other.sz_;
    sz_ = other.sz_;
    other.sz_ = tmp;

    tmp = other.cap_;
    cap_ = other.cap_;
    other.cap_ = tmp;
}

String& String :: operator=(const String& other) {
    if(this == &other) return *this;
    String copy(other);
    swap(copy);
    return *this;
}

String::~String() {
    if(str_) {
        delete[] str_;
    }
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    os << string.str_;
    return os;
}

std::istream &operator>>(std::istream &is, String &string) {
    char buffer[512];
    is.getline(buffer,512);
    String tmp(buffer);
    string = tmp;
    is.clear();
    return is;
}
