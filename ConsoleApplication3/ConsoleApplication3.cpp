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


    do {
        counter++;
        if (temp) {
            k = 1;
        } temp = true;
        cout << counter << endl << "k = " << k << endl << x.first << " " << x.second << endl << "f(x) = " << f(x) << endl << endl;

        if (k == 1) x1 = make_pair(x.first + v, x.second); //3
        if (k == 2) x1 = make_pair(x.first, x.second + v);

        f1 = f(x1);

        if (f1 < f2) {
            x = x1;
            f2 = f1;
        }

        else {
            if (k == 1) x1 = make_pair(x.first - v, x.second); //6
            if (k == 2) x1 = make_pair(x.first, x.second - v);

            f1 = f(x1);

            if (f1 < f2) {
                x = x1;
                f2 = f1;
            }
        }

        if (k < n) {
            k++;
            temp = false;
            continue;
        }

        if (f2 < f1) {
            x1 = x0;
            x0 = x;
            f0 = f2;

            roboczy = true;

            x = make_pair(x0.first + 1.5 * (x.first - x1.first), x0.second + 1.5 * (x.second - x1.second));
            f2 = f(x);
            v *= 1.25; cout << "wies";

        }
        else {
            if (roboczy) {
                x = x0;
                f2 = f0;

            }
            else {
                if (v > epsilon) v *= 0.8;
            }
            roboczy = false;
        }

    } while (v > epsilon);

    cout << "f(" << x.first << " " << x.second << ") = " << f(x) << endl;

    return 0;
}