#pragma once
#include<vector>
#include "CircleSection.h"

using namespace std;

class SectionNode
{
public:
	int depth = 0;
	SectionNode* parentNodePtr;
	CircleSection* sectionPtr;
	vector<SectionNode*> childs;

	SectionNode();
	SectionNode(CircleSection* sptr);
	~SectionNode();

	void print();
	SectionNode* getChildIncluding(CircleSection* s);
	SectionNode* addChildWith(CircleSection* s);
};

