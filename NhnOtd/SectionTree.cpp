#include "SectionTree.h"
#include <iostream>
using namespace std;


SectionTree::SectionTree()
{
	cout << "Ʈ������" << endl;
	root = new SectionNode();
	root->sectionPtr = new CircleSection(0, 0, 0, 20000);
}


SectionTree::~SectionTree()
{
	//
}

void SectionTree::print() {
	root->print();
}

void SectionTree::AddSection(CircleSection* section) {
	cout << "�ֱ�" << endl;
	SectionNode* node = root;
	bool isIncluding = false;
	do {
		isIncluding = false;

		SectionNode* nextChild = node->getChildIncluding(section);
		if (nextChild != nullptr) {
			cout << "����" << endl;
			isIncluding = true;
			node = nextChild;
		}
	} while (isIncluding);

	cout << "��?" << endl;
	node->addChildWith(section);
}