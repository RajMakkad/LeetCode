/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    stack<NestedInteger*> Start, End; // stores pointer to start & end of nested lists
    NestedIterator(vector<NestedInteger> &nestedList) {
        Start.push(&nestedList.front());
        End.push(&nestedList.back());
    }
    // will only return the next integer and increment the pointer on top of stack
    int next() {
        return Start.top()++ -> getInteger();
    }
    // Returns true only if there's more integer(s) yet to be traversed
	// If there are next integers, this function also ensures the stack top points to it
	// when size of stack becomes 0, we have traversed all of nestedList
    bool hasNext() {  
        while(size(Start)){
            auto top = Start.top();            
            if(Start.top() > End.top()){ // when a list is completely traversed
                Start.pop(), End.pop();
                continue;
            }                            
            if(top -> isInteger()) break;            
            Start.top()++;
            if(!size(top -> getList())) continue;
            Start.push(&top -> getList().front());  
            End.push(&top -> getList().back());
        }
        return size(Start);
    }
};