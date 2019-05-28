#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(double width, double height)
{
	this->width = width;
	this->height = height;
}

Rectangle::Rectangle(std::string input)
{
	auto width = input.substr(0, input.find(' '));
	auto height = input.substr(input.find(' ') + 1, input.size());

	this->width = std::stod(width);
	this->height = std::stod(height);
}

double Rectangle::getArea() const
{
	return this->width * this->height;
}

bool Rectangle::operator>(const Rectangle& T) const
{
	return getArea() > T.getArea() ? true : false;
}
bool Rectangle::operator>=(const Rectangle& T) const
{
	return getArea() >= T.getArea() ? true : false;
}
bool Rectangle::operator<(const Rectangle& T) const
{
	return this->getArea() < T.getArea() ? true : false;
}
bool Rectangle::operator<=(const Rectangle& T) const
{
	return this->getArea() <= T.getArea() ? true : false;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rec)
{
	os << "A:" << rec.getArea() << ", W:" << rec.width << ", H:" << rec.height;
	return os;
}