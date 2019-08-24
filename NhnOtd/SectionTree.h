#pragma once
#include <map>
#include "SectionNode.h"
#include "CircleSection.h"

class SectionTree
{
public:
	SectionNode* root;
	map<int, SectionNode*> nodeMap;

	SectionTree();
	~SectionTree();

	void print();
	void addSection(CircleSection* section);
	void printPath(int fromNumber, int toNumber);
	SectionNode* findNode(int number);
};

