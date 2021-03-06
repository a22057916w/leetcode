/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
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
#define SOLUTION 1

#if(SOLUTION == 0)

// the concept is to store the next value to var value. And using flag to
// determine wether peek() is occur before next()
class PeekingIterator : public Iterator {
private:
  bool flag;    // to determine it peek() is execute before next()
  int value;    // store the from of next()
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.

      flag = false;

	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
    if(!flag)
      value = Iterator::next();

    flag = true;
    return value;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	  if(!flag)
      return Iterator::next();
    else {
      flag = false;
      return value;
    }
	}

	bool hasNext() const {
	  return flag ? value : Iterator::hasNext();
	}
};


#else

// using copy consturctor trick ClassName (const ClassName &old_obj);
// e.g. Iterator(const Iterator& iter) -> Iterator(*this)
class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {}

	int peek() {
    return Iterator(*this).next();
	}

	int next() {
	  return Iterator::next();
	}

	bool hasNext() const {
	  return Iterator::hasNext();
	}
};

#endif // SOLUTION
