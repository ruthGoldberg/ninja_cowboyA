#include <cmath>
#include <iostream>
#include "Point.hpp"
using namespace ariel;
using namespace std;

Point::Point(double x , double y):_x(x),_y(y){}

double Point:: distance(const Point& other){
    double dx = _x - other._x;
    double dy = _y - other._y;
    return sqrt(dx * dx + dy * dy);
}
string Point:: print(){
   return "("+to_string(_x)+","+to_string(_y)+")";
}
Point Point:: moveTowards(const Point& src , const Point& dst , double distance){
     if (distance < 0) {
        throw std::invalid_argument("distance can't be below zero");
    }
    double dx = dst._x - src._x;
    double dy = dst._y - src._y;

    double curDis = std::sqrt(dx * dx + dy * dy);

    if (curDis <= distance) {
        return dst;
    } else {
        double ratio = distance / curDis;
        return {src._x + ratio * dx, src._y + ratio * dy};
    }
}