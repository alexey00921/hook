#include <iostream>
#include <utility>
#include <cmath>

#define v0 1
#define epsilon 0.000001 

#define n 2 

using namespace std;

double f(pair<double, double> x) {
    return -pow(x.first, 2) + 2 * pow(x.second, 2) - 3 * x.first * x.second - 3 * x.second;
}

int main(int argc, const char* argv[]) {
    pair<double, double> x0 = make_pair(-1, 4); 
    double f2 = f(x0);
    double f0 = f2;
    double f1;
    double v = 0.0;
    pair<double, double> x = x0;
    pair<double, double> x1;
    bool roboczy = false; 
    bool temp = true;
    int k = 1; 
    int counter = 0;
    v = v0; 


    return 0;
}