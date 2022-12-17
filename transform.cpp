#include <iostream>
using namespace std;

class Line {
    public:
        int get_y(float x);
        float m, b;

};

int Line::get_y(float x){
    return(m * x + b);
};

