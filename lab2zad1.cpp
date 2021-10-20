#include <tuple>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <random>

using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<double> booth_domain(-10.0, 10.0);
uniform_real_distribution<double> himmelblau_domain(-5.0, 5.0);
uniform_real_distribution<double> shift;


auto booth_function = [](double x, double y){
  return pow((x + 2 * y - 7), 2) + pow((2 * x + y - 5), 2);
};

auto himmelblau_function = [](double x, double y){
    return pow((pow(x, 2) + y - 11), 2) + pow((x + pow(y, 2) - 7), 2);
};


auto hillclimb = [](auto tested_function, double x, double y, int iterations) {
    
    double max_y = tested_function(x, y);
    for (int i = 0; i < iterations - 1; i++) {
        double x2 = x + shift(gen);
        double y2 = y + shift(gen);

        double highest_y = tested_function(x2, y2);
        if (highest_y < max_y) {

            max_y = highest_y;
            x = x2;
            y = y2;
        }
    }
    return make_pair(x, y);
};


int main(int argc, char **argv) {
    double start,stop;
    
    cout << "Podaj przedzial przesuniecia: "<<endl;;
    cin >> start >> stop;
    
    
    shift = uniform_real_distribution<double> (start, stop);
    int iterations;
    cout << "Podaj ilosc iteracji: " << endl;
    cin >> iterations;
    
        auto [booth_x, booth_y] = make_pair(booth_domain(gen), booth_domain(gen));
        auto [result_x, result_y] = hillclimb(booth_function, booth_x, booth_y, iterations);
        auto [himmelblau_x, himmelblau_y] = make_pair(himmelblau_domain(gen), himmelblau_domain(gen));
        auto [result_x2, result_y2] = hillclimb(himmelblau_function, himmelblau_x, himmelblau_y, iterations);

        cout << "Wspolrzedne dla funkcji Bootha: " << endl;
        cout << result_x << " : " << result_y << endl;
        cout << "Wspolrzedne dla funkcji Himmelblau: " << endl;
        cout << result_x2 << " : " << result_y2 << endl;
    
        return 0;
    }

