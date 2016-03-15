#ifndef SACK_H
#define SACK_H

#include <vector>
#include <random>

//template <typename T>
//template <typename T, template<typename> class container>			// MUST be a class!
template <typename T,
	template<typename...> class container=std::vector>
class Sack {
	using SackType = std::vector<T>;
	using size_type = typename SackType::size_type;

	SackType theSack{};

public:
	Sack<T, container> makeOtherSack(std::initializer_list<T> list);
	bool empty() const { return theSack.empty(); }
	size_type size() const { return theSack.size(); }
	void putInto(T const& item) { theSack.push_back(item); }
	T getOut();
};

template <template<typename...> class container, typename T>
Sack<T, container> makeOtherSack(std::initializer_list<T> list) {
	return Sack<T, container>{ list };
}

template <typename T>
inline T Sack<T>::getOut() {
	if (!size()) throw std::logic_error("empty Sack");
	auto index = static_cast<size_type>(rand() % size());
	T retval{ theSack.at(index) };
	theSack.erase(theSack.begin() + index);
	return retval;
}

//template <typename T

#endif // SACK_H
