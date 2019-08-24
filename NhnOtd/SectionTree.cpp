#include "SectionTree.h"
#include <iostream>
using namespace std;


SectionTree::SectionTree()
{
	root = new SectionNode();
	root->sectionPtr = new CircleSection(0, 0, 0, 20000);
	nodeMap.insert(make_pair(0, root));
}


SectionTree::~SectionTree()
{
	delete root;
}

void SectionTree::print() {
	root->print();
}

void SectionTree::addSection(CircleSection* section) {
	SectionNode* node = root;
	bool isIncluding = false;
	do {
		isIncluding = false;

		SectionNode* nextChild = node->getChildIncluding(section);
		if (nextChild != nullptr) {
			isIncluding = true;
			node = nextChild;
		}
	} while (isIncluding);

	SectionNode* newNodePtr = node->addChildWith(section);
	nodeMap.insert(make_pair(section->number, newNodePtr));
}

void SectionTree::printPath(int fromNumber, int toNumber) {
	auto fromNode = findNode(fromNumber);
	auto toNode = findNode(toNumber);

	if (fromNode == nullptr || toNode == nullptr) {
		cout << -1;
		return;
	}

	vector<int> fromPath;
	vector<int> toPath;

	// 노드 높이 맞춤
	while (fromNode->depth != toNode->depth) {
		if (fromNode->depth > toNode->depth) {
			fromPath.push_back(fromNode->sectionPtr->number);
			fromNode = fromNode->parentNodePtr;
		}
		else {
			toPath.push_back(toNode->sectionPtr->number);
			toNode = toNode->parentNodePtr;
		}
	}

	// 같은 부모를 찾을 때까지 올라감
	while (fromNode->sectionPtr->number != toNode->sectionPtr->number) {
		fromPath.push_back(fromNode->sectionPtr->number);
		toPath.push_back(toNode->sectionPtr->number);
		fromNode = fromNode->parentNodePtr;
		toNode = toNode->parentNodePtr;
	}
	
	// 경로 출력
	int count = fromPath.size();
	for (int i = 0; i < count; i++) {
		cout << fromPath[i] << " ";
	}

	int lowestCommonAncestor = fromNode->sectionPtr->number;
	cout << lowestCommonAncestor << " ";

	count = toPath.size();
	for (int i = count-1; i >=0; i--) {
		cout << toPath[i] << " ";
	}
}

SectionNode* SectionTree::findNode(int number) {
	auto findNode = nodeMap.find(number);
	if (findNode != nodeMap.end()) {
		return findNode->second;
	}
	return nullptr;
}