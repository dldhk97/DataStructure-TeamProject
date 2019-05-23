#include "Rectangle.h"

Rectangle::Rectangle()
{
}

Rectangle::Rectangle(double width, double height)
{
	this->width = width;
	this->height = height;
}

void Rectangle::calculateArea()
{
	area = width * height;
}
double Rectangle::getArea()
{
	return area;
}