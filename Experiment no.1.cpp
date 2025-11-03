#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int binary_search_books(const std::vector<std::string>& books, int low, int high, const std::string& target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (books[mid] == target) return mid;
    else if (target < books[mid]) return binary_search_books(books, low, mid - 1, target);
    else return binary_search_books(books, mid + 1, high, target);
}

int main() {
    std::vector<std::string> books = {
        "Algorithms", "Artificial Intelligence", "Computer Networks",
        "Data Structures", "Database Systems", "Machine Learning",
        "Operating Systems", "Python Programming", "Software Engineering"
    };

    std::sort(books.begin(), books.end());

    std::cout << "📚 Library Book Search System (Type 'exit' to quit)\n\n";

    std::string target;
    while (true) {
        std::cout << "Enter the book title to search: ";
        std::getline(std::cin, target);

        if (target == "exit" || target == "EXIT") {
            std::cout << "Exiting the system. Goodbye!\n";
            break;
        }

        int index = binary_search_books(books, 0, books.size() - 1, target);

        if (index != -1) {
            std::cout << "✅ Book '" << target << "' found at position " << index << " in the catalog.\n\n";
        } else {
            std::cout << "❌ Book '" << target << "' not found in the catalog.\n\n";
        }
    }

    return 0;
}