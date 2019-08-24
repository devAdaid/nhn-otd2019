#include "CircleSection.h"
#include <iostream>

using namespace std;

CircleSection::CircleSection(int n, int x, int y, int r)
{
	number = n;
	xPos = x;
	yPos = y;
	radius = r;
}


CircleSection::~CircleSection()
{
}


bool CircleSection::operator<(CircleSection circle) const {
	return radius < circle.radius;
}

bool CircleSection::operator>(CircleSection circle) const {
	return radius > circle.radius;
}

void CircleSection::print() {
	cout <<"("<< number << "," << radius<<")";
}

bool CircleSection::isIncluding(CircleSection* circle) {
	int xDiff = (xPos - circle->xPos);
	int yDiff = (yPos - circle->yPos);
	int dSquare = xDiff * xDiff + yDiff * yDiff;
	int rDiffSquare = (radius - circle->radius) * (radius - circle->radius);

	return (dSquare < rDiffSquare);
}