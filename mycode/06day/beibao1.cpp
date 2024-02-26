#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
private:
    static int RESULT;
    static const int KNAPSACK_MAX_WEIGHT = 10;
    static std::vector<int> WEIGHTS;

public:

    static const std::vector<int>& getWeights() {
        return WEIGHTS;
    }

    static int getResult() {
        return RESULT;
    }

    static void knapsack(std::vector<int>& selectedWeights, 
                         const std::vector<int>& selectableWeight) {
        
        // 计算selectedWeights向量中元素的总和                    
        int sumOfWeights = std::accumulate(
                selectedWeights.begin(), selectedWeights.end(), 0);

        if (sumOfWeights == KNAPSACK_MAX_WEIGHT) {
            RESULT = std::max(RESULT, sumOfWeights);
            return;
        } else if (sumOfWeights > KNAPSACK_MAX_WEIGHT) {
            selectedWeights.pop_back();
            sumOfWeights = std::accumulate(
                selectedWeights.begin(), selectedWeights.end(), 0);
            RESULT = std::max(RESULT, sumOfWeights);
            return;
        } else {
            RESULT = std::max(RESULT, sumOfWeights);
        }

        for (int i = 0; i < selectableWeight.size(); i++) {
            int num = selectableWeight[i];

            if (std::find(selectedWeights.begin(), selectedWeights.end(), num) 
                != selectedWeights.end()) {
                continue;
            }

            selectedWeights.push_back(num);
            knapsack(selectedWeights, selectableWeight);
            selectedWeights.pop_back();
        }
    }
};

int Solution::RESULT = 0;
std::vector<int> Solution::WEIGHTS = {3, 4, 6, 8};

int main() {
    std::vector<int> selectedNums;
    Solution::knapsack(selectedNums, Solution::getWeights());
    std::cout << "result = " << Solution::getResult() << std::endl;
    return 0;
}
