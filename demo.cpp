#include <iostream>
#include "point.hpp"

using namespace std;
int main() {
    Point p1, p2;
    cout << "Give point cordinates (x y): of p1: ";
    cin >> p1;
    cout << "Give point cordinates (x y): of p2: ";
    cin >> p2;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "Same points? " << ((p1 == p2) ? "Yes" : "No") << endl;
    cout << "Different points? " << ((p1 != p2) ? "Yes" : "No") << endl;
    cout << "Slope: " << Point::slope(p1, p2) << endl;
    cout << "Distance: " << Point::distance(p1, p2) << endl;
    Point mid = Point::midpoint(p1, p2);
    cout << "Midpoint: " << mid << endl;
    Point reflected = Point::reflection(p1, p2);
    cout << "Reflection of p1 across p2: " << reflected << endl;
    Point reflectedX = Point::reflectX(p1);
    Point reflectedY = Point::reflectY(p1);
    cout << "Reflection of p1 across x-axis: " << reflectedX << endl;
    cout << "Reflection of p1 across y-axis: " << reflectedY << endl;
    
    return 0;
}