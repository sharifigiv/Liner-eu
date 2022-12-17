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


class Line2 {
    public:
        int get_y(float x);
        float a, b, c;
    
};

int Line2::get_y(float x){
    return(a * x * x + b * x + c);
};