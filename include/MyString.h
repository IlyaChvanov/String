#include <string>
#include <iostream>
#include <cstring>

class MyString {
public:
    MyString() = default;

    MyString(const char *);

    MyString(char *);

    MyString(std::string);

    MyString(const MyString &);
    MyString(MyString &&) noexcept;
    ~MyString();

    size_t length() const;

    char* get() const;

    void deletePtr();

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

    char operator[](size_t);

    int operator()(const char *);

    int operator()(char);

    int operator()(const MyString &);

private:
    size_t str_len = 0;
    char *ptrstr = nullptr;
};

std::istream& operator>>(std::istream &, MyString &str);

std::ostream& operator<<(std::ostream&, const MyString &);

MyString operator+(const MyString&, const MyString&);

MyString operator-(const MyString&, const MyString&);

MyString operator*(const MyString&, size_t);

