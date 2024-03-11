#include <iostream>
#include <sstream>
#include <vector>

int Distance(std::vector<int>& vec1, std::vector<int>& vec2, int size)
{
    int res = 0;

    for (int i = 0; i < size; i++) {
        res += vec1[i] * vec2[i];
    }

    return res;
}

void word2vec(int words, int size)
{
    std::string buffer, name, vec_name;
    std::vector<std::pair<std::string, int>> data;
    std::vector<int> nums, vec_nums;
    int tmp, max_val = 0, dist = 0;

    // first vector
    getline(std::cin, buffer);
    std::stringstream ss(buffer);
    ss >> vec_name;

    for (int i = 0; i < size; i++) {
        ss >> tmp;
        vec_nums.push_back(tmp);
    }

    // other vectors
    for (int i = 0; i < words - 1; i++) {
        nums.clear();

        getline(std::cin, buffer);
        std::stringstream ss(buffer);
        ss >> name;

        for (int j = 0; j < size; j++) {
            ss >> tmp;
            nums.push_back(tmp);
        }

        dist = Distance(vec_nums, nums, size);
        if (max_val < dist || i == 0) {
            max_val = dist;
        }

        std::pair<std::string, int> p = std::make_pair(name, dist);
        data.push_back(p);
    }

    for (unsigned int i = 0; i < data.size(); ++i) {
        if (data[i].second == max_val) {
            std::cout << data[i].first << '\n';
        }
    }
}

int main()
{
    int words, size;

    std::cin >> words >> size;
    std::cin.ignore();

    word2vec(words, size);

    return 0;
}