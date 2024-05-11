#include <string>

class MyString {
public:
    MyString(const char *);

    MyString(std::string);

    MyString(const MyString &);
    MyString(MyString &&) noexcept;
    ~MyString();

    unsigned int length() const;

    char* get() const;

    MyString &operator=(const MyString &);

    MyString &operator=(MyString &&);

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

    void operator>>(MyString &);

    void operator<<(MyString &);

private:
    unsigned int str_len = 0;
    char *ptrstr = nullptr;
};

MyString operator+(const MyString&, const MyString&);

MyString operator-(const MyString&, const MyString&);

MyString operator*(const MyString&, unsigned int);

