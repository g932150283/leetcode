#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:  

    vector<string> result;

    vector<int> nums = {1,  2, 3, 4};

    void permutation(vector<int>& selectNums){
        if(selectNums.size() == nums.size()){
            result.push_back(arrayToString(selectNums));
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];

            if(find(selectNums.begin(), selectNums.end(), num) != 
               selectNums.end()){
                continue;
            }

            selectNums.push_back(num);

            permutation(selectNums);

            selectNums.pop_back();
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
    solution.permutation(selectedNums);

    for (const auto& str : solution.result) {
        std::cout << str << std::endl;
    }

    return 0;
}
