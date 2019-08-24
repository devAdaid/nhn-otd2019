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

	SectionTree sectionTree;

	for (auto iter = circles.begin(); iter != circles.end(); iter++) {
		sectionTree.addSection(&(*iter));
	}

	int from, to;
	cin >> from >> to;

	sectionTree.printPath(from, to);

	return 0;
}