#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>

// It's required to use Jacobsthal search ?
template <typename T>
void	binaryInsert(T &container, int value) {
	int low = 0;
	int high = container.size() - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (container[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	container.insert(container.begin() + low, value);
}

template <typename T>
T	&mergeInsertSort(T &container, unsigned int size) {
	if (size <= 1)
		return container;

	T    Small;

	if (size % 2) { size--;
		Small.push_back(container[size]);
		container.erase(container.begin() + size);
	}
	for (unsigned int i = 0; i < size; i++) {
		int	index = i;
		if (container[i] > container[i + 1]) ++index;
		Small.push_back(container[index]);
		container.erase(container.begin() + index); --size;
	}

	mergeInsertSort(container, container.size());

	size = Small.size();
	for (unsigned int i = 0; i < size; i++) {
		binaryInsert(container, Small[i]);
	}

	return container;
}


#endif