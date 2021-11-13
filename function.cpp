#include "function.h"

void FileWrite(std::string file_path, const std::vector<int> &list,
               std::string delimiter, std::ios_base::openmode mode) {
    std::ofstream fin(file_path, mode);
    for (auto i: list) {
        fin << i << delimiter;
    }
    std::cout << std::endl;
    fin.close();
}

bool IsTooth(const std::vector<int> &list, int i) {
    return (list[i] > list[i - 1] && list[i] > list[i + 1]) || (list[i] < list[i - 1] && list[i] < list[i + 1]);
}

int SumTeeth(const std::vector<int> &list) {
    int sum = 0;
    for (int i = 1; i < list.size() - 1; ++i) {
        if (IsTooth(list, i))
            sum += list.at(i); // == list[i]
    }
    return sum;
}

int Height(const std::vector<int> &list) {
    int min;
    int max;
    bool isInit = false;
    for (int i = 1; i < list.size() - 1; ++i) {
        if (IsTooth(list, i)) {
            if (!isInit) {
                min = list[i];
                max = min;
                isInit = true;
            } else {
                if (list[i] < min)
                    min = list[i];
                else if (max < list[i])
                    max = list[i];
            }
        }
    }
    return isInit
           ? max - min
           : 0;
}

unsigned int IndexOfKThItemNotTooth(const std::vector<int> &list, int k) {
    for (int i = 0; i < list.size(); ++i) {
        if(!IsTooth(list, i)) {
            if (k == 0) return i;
            else --k;
        }
    }
    return list.size() - 1;
}

unsigned int IndexTheLastKThItemNotTooth(const std::vector<int> &list) {
    return list.size() - 1;
}

std::vector<int> FileRead(std::string file_path) {
    std::vector<int> vector;
    std::ifstream file(file_path);
    if (!file.is_open())
        throw "can't open infile!";
    std::string file_string, t;
    while (getline(file, t))
        for (auto i: t)
            file_string.push_back(i);
    file.close();
    std::string temp_str = "";
    for (int i = 0; i < file_string.length(); ++i){
        if (file_string[i] >= '0' && file_string[i] <= '9') {
            // если это цифра
            temp_str.push_back(file_string[i]);
        }
        else if (temp_str.length() != 0) {
            vector.emplace_back(std::stoi(temp_str));
            temp_str.clear();
        }
    }
    return vector;
}