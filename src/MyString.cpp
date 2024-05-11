#include <iostream>
#include <cstring>
#include <string>
#include "../include/MyString.h"

MyString::MyString(const char *st) : str_len(strlen(st)) {
    ptrstr = new char[str_len];
    strcpy(ptrstr, st);
}

MyString::MyString(std::string st) : str_len(st.length()) {
    ptrstr = new char[str_len];
    strcpy(ptrstr, &st[0]);
}

MyString::MyString(const MyString &other) : str_len(other.str_len) {
    ptrstr = new char[str_len];
    strcpy(ptrstr, other.ptrstr);
}

MyString::MyString(MyString &&other) noexcept : str_len(other.str_len) {
    ptrstr = other.ptrstr;
    other.~MyString();
}

MyString::~MyString() {
    delete[] ptrstr;
    ptrstr = nullptr;
    str_len = 0;
}

unsigned int MyString::length() const { return str_len; };

char *MyString::get() const { return ptrstr; }

MyString operator+(const MyString& first_string, const MyString& second_string) {
    unsigned int new_str_len = first_string.length() + second_string.length() ;
    char *new_str = new char[new_str_len];
    auto counter = 0;
    for (int i = 0; counter < first_string.length(); i++) {
        new_str[counter] = first_string.get()[counter];
        counter++;
    }
    for (int i = 0; i < second_string.length(); i++) {
        new_str[counter] = second_string.get()[i];
        counter++;
    }

    return {new_str};
}

MyString operator-(const MyString& first_string, const MyString& second_string) {
    std::string new_str = first_string.get();
    std::string new_second_string = second_string.get();
    constexpr int err = -1;
    for (char i: new_second_string) {
        while (new_str.find(i) != err)
            new_str.erase(new_str.find(i), 1);

    }
    return {new_str};
}

MyString operator*(const MyString& str, unsigned int scale) {
    unsigned int new_str_len = str.length() * scale;
    char *new_str = new char[new_str_len];
    unsigned int counter = 0;
    for (int i = 0; i < scale; i++) {
        for (int j = 0; j < str.length(); j++) {
            new_str[counter] = str.get()[j];
            counter++;
        }
    }
    return MyString(new_str);
}

MyString &MyString::operator=(const MyString &other) {
    if (other.ptrstr == nullptr)
        return *this;

    MyString::~MyString();
    this->str_len = other.length();
    ptrstr = new char[str_len];
    for (int i = 0; i < str_len; i++)
        ptrstr[i] = other.get()[i];
    return *this;
}

MyString &MyString::operator=(MyString &&other) {
    MyString::~MyString();
    this->str_len = other.length();
    ptrstr = new char[str_len];
    for (int i = 0; i < str_len; i++)
        ptrstr[i] = other.get()[i];

    other.~MyString();
    return *this;
}

bool MyString::operator==(const MyString &other) {
    if (ptrstr && other.get()) {
        if (strcmp(ptrstr, other.get()) == 0)
            return true;
    }
    return false;
}

bool MyString::operator==(const char *other) const {
    if (strcmp(this->get(), other) == 0)
        return true;
    return false;
}

bool MyString::operator!=(const MyString &other) const {
    if (strcmp(this->get(), other.get()) == 0)
        return false;
    return true;
}

bool MyString::operator!=(const char *other) const {
    if (strcmp(this->get(), other) == 0)
        return false;
    return true;
}

bool MyString::operator>(const MyString &other) {
    std::string first_string = ptrstr;
    std::string second_string = other.get();
    if (first_string > second_string)
        return true;
    return false;
}

bool MyString::operator>(const char *other) const {
    if (std::string(this->get()) > std::string(other))
        return true;
    return false;
}

bool MyString::operator<(const MyString &other) const {
    if (std::string(this->get()) > std::string(other.get()))
        return false;
    return true;
}

bool MyString::operator<(const char *other) const {
    if (std::string(this->get()) > std::string(other))
        return false;
    return true;
}

bool MyString::operator>=(const MyString &other) const {
    if (std::string(this->get()) >= std::string(other.get()))
        return true;
    return false;
}

bool MyString::operator>=(const char *other) const {
    if (std::string(this->get()) >= std::string(other))
        return true;
    return false;
}

bool MyString::operator<=(const MyString &other) const {
    if (std::string(this->get()) > std::string(other.get()))
        return false;
    return true;
}

bool MyString::operator<=(const char *other) const {
    if (std::string(this->get()) > std::string(other))
        return false;
    return true;
}

MyString &MyString::operator!() {
    for (int i = 0; i < str_len; i++) {
        if ((int) ptrstr[i] >= 65 && (int) ptrstr[i] <= 90)
            ptrstr[i] = (char) ((int) ptrstr[i] + 32);

        else if ((int) ptrstr[i] >= 97 && (int) ptrstr[i] <= 122)
            ptrstr[i] = (char) ((int) ptrstr[i] - 32);
    }
    return *this;
}

char MyString::operator[](unsigned int index) {
    return ptrstr[index];
}

int MyString::operator()(const char *sub_string) {
    std::string str = ptrstr;
    unsigned int pos = str.find(sub_string);

    if (pos != std::string::npos)
        return pos;
    return -1;
}

int MyString::operator()(char sub_string) {
    std::string str = ptrstr;
    unsigned int pos = str.find(sub_string);

    if (pos != std::string::npos)
        return pos;
    return -1;
}

int MyString::operator()(const MyString &other) {
    std::string str = ptrstr;
    unsigned int pos = str.find(other.get());

    if (pos != std::string::npos)
        return pos;
    return -1;
}

void MyString::operator<<(MyString &other) {
    for (int i = 0; i < other.length(); i++)
        std::cout << other.ptrstr[i];
}

void MyString::operator>>(MyString &other) {
    for (int i = 0; i < other.length(); i++)
        std::cin >> other.ptrstr[i];
}

