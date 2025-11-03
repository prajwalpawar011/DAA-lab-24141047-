#include <iostream>
#include <vector>

// Merge function
std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> result;
    size_t i = 0, j = 0;

    // Merge two sorted lists
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            ++i;
        } else {
            result.push_back(right[j]);
            ++j;
        }
    }

    // Append remaining elements
    while (i < left.size()) {
        result.push_back(left[i++]);
    }
    while (j < right.size()) {
        result.push_back(right[j++]);
    }

    return result;
}

// Merge Sort function
std::vector<int> merge_sort(const std::vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    size_t mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    return merge(merge_sort(left), merge_sort(right));
}

int main() {
    int n;
    std::cout << "Enter number of days in the week: ";
    std::cin >> n;

    std::vector<int> sales(n);
    std::cout << "Enter units sold per day:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Day " << i + 1 << ": ";
        std::cin >> sales[i];
    }

    std::cout << "\nOriginal Sales Data: ";
    for (int s : sales) {
        std::cout << s << " ";
    }

    std::vector<int> sorted_sales = merge_sort(sales);

    std::cout << "\nSorted Sales Data:   ";
    for (int s : sorted_sales) {
        std::cout << s << " ";
    }
    std::cout << "\n";

    return 0;
}