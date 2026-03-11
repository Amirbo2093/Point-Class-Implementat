
#ifndef POINT_HPP
#define POINT_HPP
#include <iosfwd>
#include <cmath>

class Point 
{
public:
    // Constructor
    Point(double x = 0, double y = 0, int size = 3);
    // Rule of Three
    Point(const Point& other); // Copy Constructor
    Point& operator=(const Point& other); // Copy assignment operator
    ~Point(); // Destructor
    // Overloaded Operators
    // Member function
    Point operator*(const Point& rhs) const;
    // Non-member friend function
    // Must be declared as a friend inside the class to gain access
    // to private variables of the class; "friend" keyword acts as a
    // "guest pass" inside the class header, telling the compiler,
    // "This function is not a member, but has the same privileges as one"
    // Subtraction Operator overload
    friend Point operator-(const Point& lhs, const Point& rhs);
    // Mixed-type addition overloads
    friend Point operator+(const Point& lhs, const Point& rhs);// for point + point
    friend Point operator+(const Point& lhs, double val);// for point + double
    friend Point operator+(double val, const Point& rhs); //for commutativity
    friend bool operator==(const Point& lhs, const Point& rhs); // for midpoint and equality checks
    friend bool operator!=(const Point& lhs, const Point& rhs); // for midpoint and equality checks
    // Stream operator overload
    // References to the streams (ostream&, istream&)
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
    // Getter and Setter Functions
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    static Point midpoint(const Point& p1, const Point& p2);
    static double distance(const Point& p1, const Point& p2);
    static double slope(const Point& p1, const Point& p2);
    static bool samepoints(const Point& p1, const Point& p2);
    static Point reflection(const Point& p1, const Point& p2);
    static Point reflectX(const Point& p);
    static Point reflectY(const Point& p);
    void display() const;
private:
    double x_;
    double y_;
    int* history; // Pointer to dynamic array of integers
    int historySize;
};
#endif
