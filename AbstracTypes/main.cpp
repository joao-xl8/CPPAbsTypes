#include <iostream>
#include "Vector.hpp"

void use(Container<int>& c)
{
    const int sz = c.size();
    
    for (int i=0; i!=sz; ++i)
        std::cout << c[i] << '\n';
}

void h() {
//    List_container lc = { 1, 2, 3, 4, 5 };
//    use(lc);
}

void j() {
    Vector_container<int> vc(2);
    use(vc);
}

int main(int argc, const char * argv[]) {
    h();
    j();
    std::cout << "Hello, World!\n";
    return 0;
}


