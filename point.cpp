
#include <iostream>
#include "point.hpp"
// Constructor
Point::Point(double x, double y, int size) {
x_ = x;
y_ = y;
historySize = size;
history = new int[historySize]{0}; // Dynamically allocate and initialize to 0
}
/* Better form is to initialize member variables in a Member Initialization List
between the : and the opening curly brace {. It does the same thing, but it's
more efficient this way:
Point::Point(double x, double y, int size) : x_(x), y_(y), historySize(size) {
history = new int[historySize]{0};
}
*/
// Rule of Three
// Destructor
Point::~Point() {
delete[] history;
}
// Copy Constructor
Point::Point(const Point& other) : x_(other.x_), y_(other.y_),
historySize(other.historySize) {
/* Not needed with Member Initialization List
x_ = other.x_;
y_ = other.y_;
historySize = other.historySize;
*/
history = new int[other.historySize];
for (int i = 0; i < historySize; i++) {
history[i] = other.history[i];
}
}
Point& Point::operator=(const Point& other) {
if (this == &other) return *this; // Check for self-assignment
delete[] history; // Deallocate dynamic memory
this->x_ = other.x_; // Copy data
this->y_ = other.y_;
this->historySize = other.historySize;
this->history = new int[historySize];
for (int i = 0; i < historySize; i++) {
history[i] = other.history[i];
}
return *this;
}
//Point:: operator*/anything below is a member function, so it has access to the private members of the class
Point Point::operator*(const Point& rhs) const {
// this->x_ tells the compiler to use the current/calling object's variable;
// the purpose is to disambiguate in case the parameters happen to be
// named the same
return Point(this->x_ * rhs.x_, this->y_ * rhs.y_, this->historySize);
}
void Point::setX(double x) {
x_ = x;
}
void Point::setY(double y) {
y_ = y;
}
double Point::getX() {
return x_;
}
double Point::getY() {
return y_;
}
Point Point::midpoint(const Point& p1, const Point& p2) {
return Point((p1.x_ + p2.x_) / 2.0, (p1.y_ + p2.y_) / 2.0, p1.historySize);
}
double Point::distance(const Point& p1, const Point& p2) {
    return (abs(p1.x_ - p2.x_) + abs(p1.y_ - p2.y_));
}
double Point::slope(const Point& p1, const Point& p2) {
return (p2.y_ - p1.y_) / (p2.x_ - p1.x_);
}

bool Point::samepoints(const Point& p1, const Point& p2) {
return (p1.x_ == p2.x_ && p1.y_ == p2.y_);
}
Point Point::reflection(const Point& p1, const Point& p2) {
return Point(2 * p2.x_ - p1.x_, 2 * p2.y_ - p1.y_, p1.historySize);
}
Point Point::reflectX(const Point& p) {
return Point(p.x_, -p.y_, p.historySize); // Reflection across x-axis negates the y-coordinate
}
Point Point::reflectY(const Point& p) {
return Point(-p.x_, p.y_, p.historySize); // Reflection across y-axis negates the x-coordinate
}
void Point::display() const {
std::cout << "(" << x_ << ", " << y_ << ") " << std::endl;
}
// Non-Member Functions (Friends)
// No class+scope resolution (i.e., Point::) because it's not a member
// of the class; it's a global function
// "friend" keyword only belongs in the header file to give permission;
// you can't mandate friendship from outside the class definition in the
// header file
// Subtraction operator overload
Point operator-(const Point& lhs, const Point& rhs) {
return Point(lhs.x_ - rhs.x_, lhs.y_ - rhs.y_);
}
// Mixed-type addition overloads
Point operator+(const Point& lhs, const Point& rhs) {
return Point(lhs.x_ + rhs.x_, lhs.y_ + rhs.y_);
}
Point operator+(const Point& lhs, double val) {
return Point(lhs.x_ + val, lhs.y_ + val, lhs.historySize);
}
Point operator+(double val, const Point& rhs) {
// This calls the Point operator+(const Point& lhs, double val) overload above
return rhs + val;
}
bool operator==(const Point& lhs, const Point& rhs) {
return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}
bool operator!=(const Point& lhs, const Point& rhs) {
return !(lhs == rhs);
}
// Stream operator overloads
std::ostream& operator<<(std::ostream& os, const Point& p) {
os << "(" << p.x_ << ", " << p.y_ << ")";
return os;
}
std::istream& operator>>(std::istream& is, Point& p) {
is >> p.x_ >> p.y_;
return is;
}
