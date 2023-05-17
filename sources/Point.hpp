#pragma once
#include <string>
namespace ariel{
    class Point
    {
    private:
        double _x;
        double _y;
    public:
        Point(double x , double y);
        double distance(const Point& other);
        std :: string print();
        static Point moveTowards(const Point& src , const Point& dst , double distance);
        
    };
}


