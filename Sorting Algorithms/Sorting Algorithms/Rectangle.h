#pragma once

#include <iostream>

class Rectangle
{
private:
	double width, height;
public:
	Rectangle();
	Rectangle(double width, double height);

	double getArea() const;

	bool operator> (const Rectangle& T) const;
	bool operator< (const Rectangle& T) const;
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rec);
};

