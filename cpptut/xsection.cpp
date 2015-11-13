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
	//int i=0;

	if (lists.size() == 0) return *xlist;

	for (vector<vector<int>*>::iterator itr = lists.begin(); itr != lists.end(); ++itr)
	{
		positions.push_back((*itr)->begin());
		//cout << endl << "Starting positions " << *((*itr)->begin());
	}
	//cout << endl << "Size of positions " << positions.size() << endl;
	bool has_more_elements=true;
	bool has_same_elements=false;

	while ( has_more_elements) {
		has_same_elements=true;
		int smallest = *positions[0]; //TODO this may be invalid

		for( auto i = 0; i < positions.size(); ++ i)
		{

			//If one of the list processed there cannot be overlapping elements
			if (positions[i]==lists[i]->end()) {
				has_more_elements = false;
				return *xlist;
			}
			
			//All elements less than the smallest should be discarded
			while ((positions[i]!=lists[i]->end()) && 
					((*positions[i]) < smallest)) ++positions[i];

			//All elements have to match the smallest element if they are overlapping
			if ((positions[i]!=lists[i]->end()) && ((*positions[i]) > smallest)) {
				//smallest = *positions[i];
				has_same_elements = false;
			}

		}		

		if (has_same_elements) {
			xlist->push_back(smallest);
			for (auto i=0; i < positions.size();++i) {
				++positions[i];
			}
		}
		else {
			for (auto i=0; i < positions.size();++i) {
				if ((positions[i] != lists[i]->end()) &&
					((*positions[i]) == smallest)) {
					++positions[i];
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
	vector<int> l5 {};
	vector<vector<int>*> l={&l1,&l2,&l3,&l4,};
	vector<int> xl = find_xsection_indexed(l);	
	for(int i=0; i < xl.size();++i) cout << " "<< xl[i];
}

