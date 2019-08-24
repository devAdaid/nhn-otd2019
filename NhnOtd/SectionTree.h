#pragma once
#include "SectionNode.h"
#include "CircleSection.h"

class SectionTree
{
public:
	SectionNode* root;

	SectionTree();
	~SectionTree();

	void print();
	void AddSection(CircleSection* section);
};

