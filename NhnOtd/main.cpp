#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include "CircleSection.h"
#include "SectionTree.h"

using namespace std;

int main() {
	int sectionCount = 0;
	cin >> sectionCount;

	vector<CircleSection> circles;

	for (int i = 0; i < sectionCount; i++) {
		int n, x, y, r;
		cin >> n >> x >> y >> r;
		CircleSection newSection = CircleSection(n, x, y, r);
		circles.push_back(newSection);
	}

	sort(circles.begin(), circles.end(), greater<CircleSection>());

	cout << endl << endl;
	cout << "����" << endl;
	for (auto circle : circles) {
		circle.print();
		cout << endl;
	}

	cout << endl << endl;
	cout << "���� �׽�Ʈ" << endl;
	circles[0].isIncluding(&circles[1]);

	cout << endl << endl;
	cout << "Ʈ��" << endl;

	SectionTree sectionTree;

	for (auto iter = circles.begin(); iter != circles.end(); iter++) {
		sectionTree.AddSection(&(*iter));
	}

	sectionTree.print();

	return 0;
}