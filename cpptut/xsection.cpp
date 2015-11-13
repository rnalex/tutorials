#include <iostream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <memory>

using namespace std;

//Find the common elements in n lists.

vector<int> &
find_xsection_indexed(vector<vector<int>*> & lists)
{
	vector<vector<int>::iterator> positions;
	vector<int> *xlist=new vector<int>;

	if (lists.size() == 0) return *xlist;

	for (vector<vector<int>*>::iterator itr = lists.begin(); itr != lists.end(); ++itr)
	{
		positions.push_back((*itr)->begin());
	}

	bool has_more_elements=true;
	bool has_same_elements=false;
	int smallest = 0;

	while ( has_more_elements) {
		has_same_elements=true;

		for( auto i = 0; i < positions.size(); ++ i)
		{

			//All elements less than the smallest should be discarded
			while ((positions[i]!=lists[i]->end()) && 
					((*positions[i]) < smallest)) ++positions[i];

			//If one of the list processed there cannot be overlapping elements
			if (positions[i]==lists[i]->end()) {
				has_more_elements = false;
				return *xlist;
			}

			//All elements have to match the smallest element if they are overlapping
			if ((positions[i]!=lists[i]->end()) && ((*positions[i]) > smallest)) {
				has_same_elements = false;
			}

		}		

		if (has_same_elements) {
			xlist->push_back(*positions[0]);
			smallest = *positions[0];
			for (auto i=0; i < positions.size();++i) {
				++positions[i];
			}
		}
		else {
			for (auto i=0; i < positions.size();++i) {
				if ((positions[i] != lists[i]->end()) &&
						((*positions[i]) > smallest)) {
					smallest = *positions[i];
				}
			}
		}
	}

	return *xlist;
}


int
main(int argc, char **argv)
{
	vector<int> l1 {1,2,3,4,5,6,7,8,9,10};
	vector<int> l2 {1,2,3,4,5,6,7,8,9,10};
	vector<int> l3 {2,3,4,5,7,8,9,10};
	vector<int> l4 {4,5,7,8,9,10};
	vector<int> l5 {11,12,13,14,15};
	vector<vector<int>*> l {&l1,&l2,&l3,&l4,/*&l5*/};
	vector<int> xl = find_xsection_indexed(l);	
	for(int i=0; i < xl.size();++i) cout << " "<< xl[i];
}

