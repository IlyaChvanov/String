#include <string>
#include <iostream>
#include <cstring>

class MyString {
public:
    MyString() = default;

    explicit MyString(const char *);

    explicit MyString(char *);

    explicit MyString(std::string);

    MyString(const MyString &);
    MyString(MyString &&) noexcept;
    ~MyString();

    size_t length() const;

    char* get() const;

    MyString &operator=(const MyString &);

    MyString &operator=(MyString &&) noexcept ;

    bool operator==(const MyString &);

    bool operator==(const char *) const;

    bool operator!=(const MyString &) const;

    bool operator!=(const char *) const;

    bool operator>(const MyString &);

    bool operator>(const char *) const;

    bool operator<(const MyString &) const;

    bool operator<(const char *) const;

    bool operator>=(const MyString &) const;

    bool operator>=(const char *) const;

    bool operator<=(const MyString &) const;

    bool operator<=(const char *) const;

    MyString &operator!();

    char operator[](unsigned int);

    int operator()(const char *);

    int operator()(char);

    int operator()(const MyString &);

private:
    unsigned int str_len = 0;
    char *ptrstr = nullptr;
};

std::istream& operator>>(std::istream &, MyString &str);

std::ostream& operator<<(std::ostream&, const MyString &);

MyString operator+(const MyString&, const MyString&);

MyString operator-(const MyString&, const MyString&);

MyString operator*(const MyString&, unsigned int);

