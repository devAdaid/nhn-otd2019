#include "SectionNode.h"
#include <iostream>

using namespace std;


SectionNode::SectionNode()
{
	cout << "노드생성" << endl;
	depth = 0;
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
	cout << "ㄴ";
	sectionPtr->print();

	for (auto section : childs) {
		section.print();
	}
}

SectionNode* SectionNode::getChildIncluding(CircleSection* s) {
	for (auto iter = childs.begin(); iter != childs.end(); iter++) {
		iter->sectionPtr->print();
		cout << "이 ";
		s->print();
		cout << "를 포함하는가?" << endl;
		bool isIncluding = iter->sectionPtr->isIncluding(s);
		if (isIncluding) {
			cout << "진짜포함" << endl;
			return &(*iter);
		}
	}
	return nullptr;
}

void SectionNode::addChildWith(CircleSection* s) {
	cout << "넣기 호출: "<< depth << endl;

	SectionNode newNode = SectionNode(s);
	newNode.depth = depth + 1;
	childs.push_back(newNode);

	sectionPtr->print();
	cout << "에 넣은거: ";
	newNode.sectionPtr->print();
}