#pragma once
#include <vector>
using namespace std;
template<class T>
class cycleQueue {
	vector<T> q;
public:
	void push(const T & obj) {
		q.push_back(obj);
	}
	void push(T && obj) {
		q.push_back(obj);
	}
	void pop(bool remove=1) {
		if (!remove) {
			/*T tmp = q[0];
			q.erase(begin(q));
			q.push_back(q[0]);*/
			q.push_back(move(q[0]));
		}
		q.erase(begin(q));
	}
	T& front() {
		return q[0];//return *begin(q);
	}
	T& back() {
		return q[q.size() - 1];
	}
	const T& front() const {
		return q[0];//return *begin(q);
	}
	const T& back() const {
		return q[q.size() - 1];
	}
	int size() const {
		return q.size();
	}
	bool empty() const {
		return q.empty();
	}
};