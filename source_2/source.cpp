#include <iostream>
#include <vector>
#include <cstddef>

template<typename T>
class table {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    table(size_t rows, size_t cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<T>(cols));
    }

    std::vector<T>& operator[](size_t row) {
        return data[row];
    }

    const std::vector<T>& operator[](size_t row) const {
        return data[row];
    }

    struct Size {
        size_t rows;
        size_t cols;
    };

    Size size() const {
        return { rows, cols };
    }

    size_t get_rows() const {
        return rows;
    }

    size_t get_cols() const {
        return cols;
    }
};

int main() {
    auto test = table<int>(2, 3);

    test[0][0] = 4;

    std::cout << "test[0][0] = " << test[0][0] << std::endl;

    auto sz = test.size();
    std::cout << "Rows: " << sz.rows << ", Cols: " << sz.cols << std::endl;

    std::cout << "Заполняем таблицу:" << std::endl;
    for (size_t i = 0; i < test.get_rows(); ++i) {
        for (size_t j = 0; j < test.get_cols(); ++j) {
            test[i][j] = static_cast<int>(i * 10 + j);
        }
    }

    std::cout << "Содержимое таблицы:" << std::endl;
    for (size_t i = 0; i < test.get_rows(); ++i) {
        for (size_t j = 0; j < test.get_cols(); ++j) {
            std::cout << test[i][j] << " ";
        }
        std::cout << std::endl;
    }

    const table<int>& const_test = test;
    std::cout << "Чтение через константную ссылку:" << std::endl;
    std::cout << "const_test[1][2] = " << const_test[1][2] << std::endl;

    table<double> double_table(2, 2);
    double_table[0][0] = 3.14;
    double_table[0][1] = 2.718;
    double_table[1][0] = 1.414;
    double_table[1][1] = 1.732;

    std::cout << "Таблица с double:" << std::endl;
    for (size_t i = 0; i < double_table.get_rows(); ++i) {
        for (size_t j = 0; j < double_table.get_cols(); ++j) {
            std::cout << double_table[i][j] << " ";
        }
        std::cout << std::endl;
    }

    table<std::string> string_table(2, 2);
    string_table[0][0] = "Hello";
    string_table[0][1] = "World";
    string_table[1][0] = "Table";
    string_table[1][1] = "Class";

    std::cout << "Таблица со строками:" << std::endl;
    for (size_t i = 0; i < string_table.get_rows(); ++i) {
        for (size_t j = 0; j < string_table.get_cols(); ++j) {
            std::cout << string_table[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
