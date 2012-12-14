#include "to_xml.hpp"
#include <stdio.h>

struct A
{
    struct D {
        int v;
        DEF_TO_XML_MEM1("D", XML_ATTR1(v) );
    };
    D a;
    struct B {
        int i;
        std::string name;
        std::vector<std::string> other;
        DEF_TO_XML_MEM3("B", XML_ATTR1(name), i, other)
    };

   std::vector<int> b;
   B c;
   std::string d;
};

DEF_TO_XML4(A, XML_ATTR1(d), a, b, c)

int main(int argc, const char *argv[])
{
    A a;
    a.a.v = 1;
    a.d = "abc";
    a.b.push_back(2);
    a.b.push_back(3);
    a.b.push_back(4);
    a.c.i=4;
    a.c.name="piboye&";
    a.c.other.push_back("piboye1<>");
    a.c.other.push_back("piboye2'\"");

    std::string out = to_xml(a);
    printf("%s\n", out.c_str());

    return 0;
}
