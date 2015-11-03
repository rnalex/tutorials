/*
 * Author RN Alex
 *
 */
#include <iostream>
#include <memory>
#include <typeinfo>
#include <deque>
#include <unordered_map>
#if !defined(CPP_CACHE_STORE_H_)
#define CPP_CACHE_STORE_H_
using namespace std;

#ifdef LOGIT
#define LOG(...) do { cout << endl << __VA_ARGS__ ;}while(0);
#else
#define LOG(...)
#endif

template <typename K , typename V ,size_t L = 2>
class CacheStore {
	typedef pair<K,weak_ptr<V>> UsedItem;
	typedef deque <UsedItem> UsedItems;
	typedef unordered_map <K,shared_ptr<V>> CachedItems;
	typedef typename deque <UsedItem>::iterator UsedItemsIt;
	typedef typename unordered_map <K,shared_ptr<V>>::iterator CachedItemIt;

	public:
	CacheStore(){ LOG("Creating Cache Store");};
	virtual ~CacheStore(){ LOG("Destroying Cache Store ..");};

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
			LOG("Found --" << typeid(search).name() << " " << search->second.use_count());
			return search->second;
		}
		else return nullptr;
	}
	void Expire(const K &k) {
		auto search = _cachedItems.find(k);
		if (search != _cachedItems.end())_cachedItems.erase(search);
	}
	void Show() {
		LOG("--- Recently Used Items ---");
		for(auto it = _recentlyUsedItems.begin(); it != _recentlyUsedItems.end();++it) {
			if (auto sp = it->second.lock()) {
			LOG(it->first << " " << *sp );
			}
			else {
				LOG(it->first << " " << "Expired");
			}
		}              

		LOG("--- Cached Items ---");
		for(auto it = _cachedItems.begin(); it != _cachedItems.end();++it) {
			LOG(it->first <<" "<< *it->second);
		}              
	}

	private:
	CachedItems _cachedItems;
	UsedItems _recentlyUsedItems;
};

#endif

