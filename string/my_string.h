#ifndef __MY__STRING__
#define __MY__STRING__

#include <iostream>
#include <cstring>

class String {
public:
    String();
    String(size_t sz);
    String(const char* c_str);
    String(const String& other);
    String& operator=(const String&);
    ~String();

    friend std :: ostream& operator<<(std :: ostream& os, const String& string);
    friend std :: istream& operator>>(std :: istream& is, String& string);
private:

    void swap(String&);
    char* str_;
    size_t sz_;
    size_t cap_;
};

#endif
