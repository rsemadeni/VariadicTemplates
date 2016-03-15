#ifndef HEADER_H
#define HEADER_H

#include <iostream>

void println(std::ostream &out) {
	out << '\n';
}

template<typename Head, typename... Tail>
void println(std::ostream &out, Head const& head, Tail const& ...tail) {
	out << head;
	if (sizeof...(tail)) {
		out << ", ";
		println(out, tail...);
	} else {
		out << '\n';
	}
}

template <typename...ARGS>
void variadic(ARGS...args) {
	println(std::cout, args...);
}

#endif // !HEADER_H
