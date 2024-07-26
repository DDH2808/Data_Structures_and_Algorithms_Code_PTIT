#include <iostream>
#include <deque>
#include <vector>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::deque<int> dq;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        // Loại bỏ các phần tử ngoài cửa sổ trượt
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Loại bỏ các phần tử nhỏ hơn phần tử hiện tại
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Thêm phần tử hiện tại vào deque
        dq.push_back(i);

        // Thêm phần tử lớn nhất vào kết quả
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        std::vector<int> nums;
        int temp;
        while (std::cin >> temp) {
            nums.push_back(temp);
            if (std::cin.peek() == '\n') break;
        }

        std::vector<int> result = maxSlidingWindow(nums, k);

        for (int i = 0; i < result.size(); i++) {
            std::cout << result[i] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}