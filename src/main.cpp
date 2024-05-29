#include "MyString.h"
#include <iostream>

int main() {
    std::string a1 = "HEllO";
    std::string b1 = "hello";
    MyString a(a1);
    MyString b(b1);
    MyString d("String");
    std::cout << "MyString d is " << d.get() << '\n';
    std::cout << "d length is " << d.length() << '\n';
    std::cout << a.get() << " - H equals: " << (a - "H").get() << '\n';
    std::cout << a.get() << " + " << b.get() << " = " << (a + b).get() << '\n';
    std::cout << a.get() << " * 3 = " << (a * 3).get();
    MyString a2 = a;
    MyString a3 = std::move(a);
    MyString c = b;
    MyString d1("test");
    MyString d2("new_test");
    std::cout << '\n' << "is d1 < d2 " << (d1 < d2) << '\n';
    std::cout << "is d1 >= d2 " << (d1 >= d2) << '\n';
    std::cout << "is d1 <= d2 " << (d1 <= d2);
    std::cout << '\n' << "is d1 = d1 " << (d1 == d1);
    std::cout << '\n' << "is not d1 = d1 " << (d1 != d2);
    std::cout << '\n' << "is d1 > d2 " << (d1 > d2);
    std::cout << '\n' << "d1 is: " << d1.get();
    std::cout << '\n' << "!d1 is: " << ((!d1).get());
    std::cout << '\n' << "d1[1] is: " << d1[1];
    std::cout << '\n' << "E found at index: " << d1('E');
    std::cout << '\n' << "d1 = " << (!d1).get() << " is found at index: " << d2(d1) << " in string d2 = " << d2.get();
    MyString g1;
    MyString g2;
    std::cout << '\n' << "enter 2 strings";
    std::cin >> g1 >> g2;
    std::cout << "The first is: "<< g1 <<'\n';
    std::cout << "The second is: "<< g2 <<'\n';
    return 0;
}