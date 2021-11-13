#include "function.h"

template<typename T>
void fillChainsaw(std::vector<T> &chainsaw, int n) {
    for (int i = 0; i < n; ++i) {
        T input;
        std::cin >> input;
        chainsaw.emplace_back(input); // == push_back
    }
}

void print(const std::vector<int> &vec) {
    for (auto i: vec) {
        for (int j = 0; j < i; j++)
            std::cout << ">";
        std::cout << std::endl;
    }
}

int main() {
/*    std::map<std::string, int> mapa;
//    for (int i = 0; i < 50; ++i) {
//        mapa["abc" + std::to_string(i)] = log(2 + 100 * i);
//    }
//    std::vector<int> vector = {1, 2, 3, 4, 5, 6, 6, 7, 7, 8, 8, 6};
//    for (const auto i: vector) // for (int i = vector.begin(); i != vector.end(); ++i)
//        std::cout << i << std::endl;
//    for (const auto i: mapa)
//        std::cout << i.first << " " << i.second << std::endl;
*/
    int n;
    std::cin >> n;
    std::vector<int> chainsaw;
    fillChainsaw(chainsaw, n);
    FileWrite("FileWrite.txt", chainsaw, " | ", std::ios_base::out);
    std::vector<int> vector = FileRead("FileWrite.txt");
    FileWrite("out.txt", vector, " ъ ", std::ios_base::out);
    print(vector);
    return 0;
}