#include <iostream>
#include <vector>
#include <algorithm>

class DivisibleByThreeCounter {
private:
    int sum;
    int count;

public:
    DivisibleByThreeCounter() : sum(0), count(0) {}

    void operator()(int num) {
        if (num % 3 == 0) {
            sum += num;
            count++;
        }
    }

    int get_sum() const {
        return sum;
    }

    int get_count() const {
        return count;
    }
};

int main() {
    std::vector<int> numbers;
    int n, num;

    std::cout << "Введите количество чисел: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout <<std::endl << "Введите число: " ;
        std::cin >> num;
        numbers.push_back(num);
    }

    DivisibleByThreeCounter counter;
    counter = std::for_each(numbers.begin(), numbers.end(), counter);

    std::cout << "get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "get_count() = " << counter.get_count() << std::endl;

    return 0;
}
