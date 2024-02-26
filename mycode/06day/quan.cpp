#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    // 结果集
    std::vector<std::string> RESULT;

    // 参与全排列的数字
    std::vector<int> NUMS = {1, 2, 3};

    // 遍历当前阶段的解
    void permutation(std::vector<int>& selectedNums, 
                     const std::vector<int>& selectableNums) {
        // 满足条件，加入结果集
        if (selectedNums.size() == NUMS.size()) {
            RESULT.push_back(arrayToString(selectedNums));
            return;
        }

        // 遍历每个阶段的可选解集合
        for (int i = 0; i < selectableNums.size(); ++i) {
            int num = selectableNums[i];

            // 去除不符合条件的解，减枝
            if (std::find(selectedNums.begin(), 
                selectedNums.end(), num) != selectedNums.end()) {
                continue;
            }

            // 选择当前阶段其中一个解
            selectedNums.push_back(num);

            // 选完之后再进入下个阶段遍历
            permutation(selectedNums, selectableNums);

            // 回溯，换一个解继续遍历
            selectedNums.pop_back();
        }
    }

    // 将 vector<int> 转换为字符串
    std::string arrayToString(const std::vector<int>& arr) {
        std::string result = "[";
        for (int i = 0; i < arr.size(); ++i) {
            result += std::to_string(arr[i]);
            if (i < arr.size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> selectedNums;
    solution.permutation(selectedNums, solution.NUMS);

    for (const auto& str : solution.RESULT) {
        std::cout << str << std::endl;
    }

    return 0;
}
