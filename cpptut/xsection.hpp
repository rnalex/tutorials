/*
 * Template templates on classes and function.
 * Allows to have comparable items like int,float,char which can be housed in vectors,deque etc.
 */
#include <iostream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <memory>

using namespace std;

//Find the common elements in n lists.
template <typename D=int,template <typename E, typename Allocator = allocator<E>> class C = vector>
C<D> & find_xsection(C<C<D>*> & lists)
{
	//typedef typename C<D>::iterator CItr;
	//C<CItr> positions;
	C<typename C<D>::iterator> positions;
	C<D> *xlist=new C<D>;

	if (lists.size() == 0) return *xlist;

	for (auto itr = lists.begin(); itr != lists.end(); ++itr)
	{
		positions.push_back((*itr)->begin());
	}

	bool has_more_elements=true;
	bool has_same_elements=false;
	D smallest = 0;

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

template <typename D=int,template <typename E, typename Allocator = allocator<E>> class C = vector>
void
test_combo()
{

	C<D> l1 {1,2,3,4,5,6,7,8,9,10};
	C<D> l2 {1,2,3,4,5,6,7,8,9,10};
	C<D> l3 {2,3,4,5,7,8,9,10};
	C<D> l4 {4,5,7,8,9,10};
	C<D> l5 {11,12,13,14,15};
	C<C<D>*> l {&l1,&l2,&l3,&l4,/*&l5*/};
	auto xl = find_xsection<D,C>(l);	
	cout << endl << "Testing with type = " << typeid(l).name();
	//for(int i=0; i < xl.size();++i) cout << " "<< xl[i];
}
#if 0
int
main(int argc, char **argv)
{
	test_combo<int,vector>();
	test_combo<float,vector>();
	test_combo<float,deque>();
	test_combo<char,deque>();
	test_combo<long long,deque>();

}
#endif


