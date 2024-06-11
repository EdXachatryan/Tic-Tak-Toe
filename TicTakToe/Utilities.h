#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>

using pairInts = std::pair<int, int>;

inline pairInts getTwoNumber() {
	int f, s;
	std::cin >> f >> s;
	return pairInts(f, s);
}

#endif // !UTILITIES_H
