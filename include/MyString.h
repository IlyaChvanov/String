#include <string>

class MyString {
public:
    MyString(const char *);

    MyString(std::string);

    MyString(const MyString &);
    MyString(MyString &&);
    ~MyString();

    unsigned int length() const;

    char *get() const;

    MyString &operator=(const MyString &);

    MyString &operator=(const MyString &&);

    bool operator==(const MyString &);

    bool operator==(const char *);

    bool operator!=(const MyString &);

    bool operator!=(const char *);

    bool operator>(const MyString &);

    bool operator>(const char *);

    bool operator<(const MyString &);

    bool operator<(const char *);

    bool operator>=(const MyString &);

    bool operator>=(const char *);

    bool operator<=(const MyString &);

    bool operator<=(const char *);

    MyString &operator!();

    char operator[](unsigned int);

    int operator()(const char *);

    int operator()(const char);

    int operator()(const MyString &);

    void operator>>(MyString &);

    void operator<<(MyString &);

private:
    unsigned int str_len = 0;
    char *ptrstr = nullptr;
};

MyString operator+(const MyString, const MyString);

MyString operator-(const MyString, const MyString);

MyString operator*(const MyString, unsigned int);

