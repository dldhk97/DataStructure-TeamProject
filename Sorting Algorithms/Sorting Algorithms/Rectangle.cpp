#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(double width, double height)
{
	this->width = width;
	this->height = height;
}

bool Rectangle::operator>(const Rectangle& T) const
{
	return this->width * this->height > T.width * T.height ? true : false;
}
bool Rectangle::operator<(const Rectangle& T) const
{
	return this->width* this->height < T.width* T.height ? true : false;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rec)
{
	os << "A:" << rec.width * rec.height << ", W:" << rec.width << ", H:" << rec.height;
	return os;
}