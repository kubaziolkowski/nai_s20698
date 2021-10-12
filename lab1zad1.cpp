#include <unistd.h>
#include <iostream>
#include <tuple>
#include <cstdlib>


   auto obliczenia = [](auto f1, auto f2, int n) {
        using namespace std;

    int max_x = f2(0);
    int max_y = f1(max_y);
    for (int i = 0; i < n + 1; i++) {
        int x = f2(i);
        int y = f1(x);
        if (y > max_y) {
             max_x = x;
             max_y = y;
        }
    }
    return make_pair(max_x, max_y);
};

auto f1 = [](int x){
    return 20 - abs(x);
    };
   
   auto f2 = [](int x2){
    return (2 * (x2 % 2) - 1) * (x2 / 2);
}; 

int main(int argc, char **argv) {
    using namespace std;
    auto [a,b] = obliczenia(f1, f2, 3);
    cout << a << endl;
    cout << b << endl;
}
