#pragma once
#include <string>
#include <iostream>

class Rectangle
{
private:
	double width, height;
public:
	Rectangle();
	Rectangle(double width, double height);
	Rectangle(std::string input);

	double getArea() const;

	bool operator> (const Rectangle& T) const;
	bool operator>= (const Rectangle& T) const;
	bool operator< (const Rectangle& T) const;
	bool operator<= (const Rectangle& T) const;
	Rectangle& operator= (const Rectangle& T);

	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rec);
};

