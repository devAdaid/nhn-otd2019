#include "SectionNode.h"
#include <iostream>

using namespace std;


SectionNode::SectionNode()
{
	cout << "������" << endl;
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
	cout << "��";
	sectionPtr->print();

	for (auto section : childs) {
		section.print();
	}
}

SectionNode* SectionNode::getChildIncluding(CircleSection* s) {
	for (auto iter = childs.begin(); iter != childs.end(); iter++) {
		iter->sectionPtr->print();
		cout << "�� ";
		s->print();
		cout << "�� �����ϴ°�?" << endl;
		bool isIncluding = iter->sectionPtr->isIncluding(s);
		if (isIncluding) {
			cout << "��¥����" << endl;
			return &(*iter);
		}
	}
	return nullptr;
}

void SectionNode::addChildWith(CircleSection* s) {
	cout << "�ֱ� ȣ��: "<< depth << endl;

	SectionNode newNode = SectionNode(s);
	newNode.depth = depth + 1;
	childs.push_back(newNode);

	sectionPtr->print();
	cout << "�� ������: ";
	newNode.sectionPtr->print();
}