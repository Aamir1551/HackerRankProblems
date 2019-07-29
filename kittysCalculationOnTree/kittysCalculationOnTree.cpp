#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	vector<int> value;
	int numOfChildren = 0;

	Node(vector<int> v) {
		this->value = v;
	}

	void static prvect(vector<int> v) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ",";
		}
		cout << endl;
	}
};

void addChild(int childIndex, int childRoot, std::map<int, Node*> &tree) {
	Node *root = tree.at(childRoot);
	vector<int> q = root->value;
	int numChildren = root->numOfChildren;
	vector<int> h(q);
	h.push_back(numChildren);
	root->numOfChildren++;
	tree.insert_or_assign(childIndex, new Node(h));
}

int getDistance(int a, int b, const std::map<int, Node*> &tree) {
	//we are going from a to b
	if (a == b) {
		return 0;
	}	
	vector<int> dira(tree.at(a)->value);
	vector<int> dirb(tree.at(b)->value);
	if (dira.size() > dirb.size()) {
		return getDistance(b, a, tree);
	}
	dira.push_back(-1);
	dirb.push_back(-2);

	int i = 0;
	
	for (i = 0; i < dirb.size(); i++) {
		if (dira[i] != dirb[i]) {
			break;
		}
	}
	return dira.size() - i + dirb.size() - i - 2;

}

int main()
{
    std::cout << "Hello World!\n";
	std::map<int, Node*> t = { {3, new Node(vector<int>({}))} };
	addChild(8, 3, t);
	addChild(10, 3, t);
	addChild(15, 10, t);
	addChild(12, 10, t);
	addChild(13, 12, t);
	addChild(21, 8, t);
	addChild(22, 8, t);
	cout << "printing distances" << endl;
	cout << getDistance(8, 10, t) << endl;
	cout << getDistance(8, 15, t) << endl;
	cout << getDistance(10, 15, t) << endl;
	cout << getDistance(10, 12, t) << endl;
	cout << getDistance(8, 12, t) << endl;
	cout << getDistance(13, 22, t) << endl; 
	cout << getDistance(22, 13, t) << endl; 
}
