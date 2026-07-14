#include <iostream>
#include <vector>
#include <string>
#include <sstream>

template<typename T>
T square(T value) {
    return value * value;
}

template<typename T>
std::vector<T> square(const std::vector<T>& vec) {
    std::vector<T> result;
    result.reserve(vec.size());
    for (const auto& item : vec) {
        result.push_back(item * item);
    }
    return result;
}

template<typename T>
void printVector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << vec[i];
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "[IN]: 4" << std::endl;
    std::cout << "[OUT]: " << square(4) << std::endl;
    
    std::vector<int> vec = {-1, 4, 8};
    std::cout << "[IN]: ";
    printVector(vec);
    
    auto result = square(vec);
    std::cout << "[OUT]: ";
    printVector(result);
    
    return 0;
}
