#include "SectionNode.h"
#include <iostream>

using namespace std;


SectionNode::SectionNode()
{
	depth = 0;
	parentNodePtr = nullptr;
}

SectionNode::SectionNode(CircleSection* sptr) {
	sectionPtr = sptr;
}

SectionNode::~SectionNode()
{
}

void SectionNode::print() {
	cout << endl;
	for (int i = 0; i < depth; i++) {
		cout << " ";
	}
	cout << "¤¤";
	sectionPtr->print();

	for (auto section : childs) {
		section->print();
	}
}

SectionNode* SectionNode::getChildIncluding(CircleSection* s) {
	int count = childs.size();
	for (int i = 0; i < count; i++) {
		bool isIncluding = childs[i]->sectionPtr->isIncluding(s);
		if (isIncluding) {
			return (childs[i]);
		}
	}
	return nullptr;
}

SectionNode* SectionNode::addChildWith(CircleSection* s) {
	SectionNode* newNode = new SectionNode(s);
	newNode->depth = depth + 1;
	newNode->parentNodePtr = this;
	childs.push_back(newNode);

	return childs.back();
}