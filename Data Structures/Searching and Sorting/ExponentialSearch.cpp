#include <cassert>
#include <cmath>
#include <iostream>
#ifdef _MSC_VER 
#else
#include <cstring> 
#endif

template <class Type>
inline Type* binary_s(Type* array, size_t size, Type key) {
    int32_t lower_index(0), upper_index(size - 1), middle_index;

    while (lower_index <= upper_index) {
        middle_index = std::floor((lower_index + upper_index) / 2);

        if (*(array + middle_index) < key)
            lower_index = (middle_index + 1);
        else if (*(array + middle_index) > key)
            upper_index = (middle_index - 1);
        else
            return (array + middle_index);
    }

    return nullptr;
}

template <class Type>
Type* struzik_search(Type* array, size_t size, Type key) {
    uint32_t block_front(0), block_size = size == 0 ? 0 : 1;
    while (block_front != block_size) {
        if (*(array + block_size - 1) < key) {
            block_front = block_size;
            (block_size * 2 - 1 < size) ? (block_size *= 2) : block_size = size;
            continue;
        }
        return binary_s<Type>(array + block_front, (block_size - block_front),
                              key);
    }
    return nullptr;
}

/* main function */
int main() {
    // TEST CASES
    int* sorted_array = new int[7]{3, 5, 11, 18, 89, 107, 333};
    assert(struzik_search<int>(sorted_array, 5, 0) == nullptr);
    assert(struzik_search<int>(sorted_array, 5, 1000) == nullptr);
    assert(struzik_search<int>(sorted_array, 5, 30) == nullptr);
    assert(struzik_search<int>(sorted_array, 5, 5) == sorted_array);
    // TEST CASES
    delete[] sorted_array;
    return 0;
}