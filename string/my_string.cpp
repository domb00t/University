#include "my_string.h"

String :: String() : str_(nullptr), sz_(0), cap_(0) {}

String :: String(size_t sz) : str_(new char[sz + 1]), sz_(sz), cap_(sz + 1) {
    std :: memset(str_,'1',sz_);
    str_[sz_] = '\0';
}

String::String(const char *c_str) {

}

String :: String(const String& other) {

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
    is.getline(string.str_,string.sz_);
    return is;
}
