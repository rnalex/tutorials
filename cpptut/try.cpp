/*
 * Author RN Alex
 *
 */
#include <iostream>
#include <memory>
#include <typeinfo>
#include <deque>
#include <unordered_map>

using namespace std;

template <typename K , typename V ,size_t L = 2>
class CacheStore {
	typedef pair<K,weak_ptr<V>> UsedItem;
	typedef deque <UsedItem> UsedItems;
	typedef unordered_map <K,shared_ptr<V>> CachedItems;
#if 0
	typedef typename deque <UsedItem>::iterator UsedItemsIt;
	typedef typename unordered_map <K,shared_ptr<V>>::iterator CachedItemIt;
#endif
	public:
	CacheStore(){ cout << endl << "Creating Cache Store ...";};
	virtual ~CacheStore(){ cout <<endl << "Destroying Cache Store ..";};

	bool Cache(K &k , V &v){
		while (_recentlyUsedItems.size() >= L) {
			_recentlyUsedItems.pop_back();
		}
		_cachedItems[k]=make_shared<V>(v);
		_recentlyUsedItems.push_front(make_pair(k,weak_ptr<V>(_cachedItems[k])));
		return true;
	}
	shared_ptr<V> Find(K &k) {
		auto search = _cachedItems.find(k);
		if (search != _cachedItems.end()) {
			cout << endl << "Found --" << typeid(search).name() << " " << search->second.use_count();
			return search->second;
		}
		else return nullptr;
	}
	void Expire(const K &k) {
		auto search = _cachedItems.find(k);
		if (search != _cachedItems.end())_cachedItems.erase(search);
	}
	void Show() {
		cout << endl << "--- Recently Used Items ---";
		for(auto it = _recentlyUsedItems.begin(); it != _recentlyUsedItems.end();++it) {
			if (auto sp = it->second.lock()) {
			cout << endl << it->first << " " << *sp ;
			}
			else {
				cout << endl << it->first << " " << "Expired";
			}
		}              

		cout << endl << "--- Cached Items ---";
		for(auto it = _cachedItems.begin(); it != _cachedItems.end();++it) {
			cout << endl << it->first <<" "<< *it->second;
		}              
	}

	private:
	CachedItems _cachedItems;
	UsedItems _recentlyUsedItems;
};


int
main(int argc , char **argv)
{
	int k[]={1,2,3,4,5};
	int v[]={2,4,6,8,10};

	CacheStore <int,int,8> cs;
	for(int i=0; i < 5; ++i) {
		cs.Cache(k[i],v[i]);
		cs.Show();
		if (i&1)cs.Expire(k[i]);
		shared_ptr<int> sv = cs.Find(k[i]);
		cout << endl <<"Finding Key " << k[i] <<" Value " << ((sv == nullptr) ?  0 : *sv.get()) ;
	}
}
