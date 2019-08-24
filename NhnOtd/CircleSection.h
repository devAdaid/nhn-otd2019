#pragma once
class CircleSection
{
public:
	int number = 0;
	int xPos = 0;
	int yPos = 0;
	int radius = 1;

	CircleSection(int n, int x, int y, int r);
	~CircleSection();
	bool operator<(CircleSection circle) const;
	bool operator>(CircleSection circle) const;

	void print();
	bool isIncluding(CircleSection* circle);

};

