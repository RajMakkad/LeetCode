/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    int idx = 0;
    vector<int> hash;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        hash.clear();
        for(int i:nums) hash.push_back(i);
	}
	
	int peek() {
        return hash[idx];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return hash[idx++];
	}
	
	bool hasNext() const {
	    return idx < hash.size();
	}
};