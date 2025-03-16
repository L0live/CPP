#include "iter.hpp"

int main() {
    std::cout << "Int array:" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, print);
    std::cout << std::endl;
    iter(arr, 5, add);
    iter(arr, 5, print);
    std::cout << std::endl;

    std::cout << "Char array:" << std::endl;
    char arr2[] = {'a', 'b', 'c', 'd', 'e'};
    iter(arr2, 5, print);
    std::cout << std::endl;
    iter(arr2, 5, add);
    iter(arr2, 5, print);
    std::cout << std::endl;

    return 0;
}