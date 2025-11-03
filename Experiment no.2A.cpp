#include <iostream>
#include <vector>
#include <string>

// Quick Sort function
std::vector<std::pair<std::string, int>> quick_sort(const std::vector<std::pair<std::string, int>>& students) {
    if (students.size() <= 1)
        return students;

    auto pivot = students.back();
    std::vector<std::pair<std::string, int>> left, right;

    for (size_t i = 0; i < students.size() - 1; ++i) {
        if (students[i].second > pivot.second)
            left.push_back(students[i]);
        else
            right.push_back(students[i]);
    }

    auto sorted_left = quick_sort(left);
    auto sorted_right = quick_sort(right);

    sorted_left.push_back(pivot);
    sorted_left.insert(sorted_left.end(), sorted_right.begin(), sorted_right.end());

    return sorted_left;
}

int main() {
    int n;
    std::cout << "Enter number of students: ";
    std::cin >> n;
    std::cin.ignore(); // Clear newline from input buffer

    std::vector<std::pair<std::string, int>> students;

    for (int i = 0; i < n; ++i) {
        std::string name;
        int score;
        std::cout << "Enter name of student " << i + 1 << ": ";
        std::getline(std::cin, name);
        std::cout << "Enter score of " << name << ": ";
        std::cin >> score;
        std::cin.ignore(); // Clear newline again
        students.push_back({name, score});
    }

    auto sorted_students = quick_sort(students);

    std::cout << "\nRank List:\n";
    for (size_t i = 0; i < sorted_students.size(); ++i) {
        std::cout << i + 1 << ". " << sorted_students[i].first << " - " << sorted_students[i].second << "\n";
    }

    return 0;
}