#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

// Function to calculate minimum merge cost
int optimalMergeCost(vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> minHeap(files.begin(), files.end());
    int totalCost = 0;

    while (minHeap.size() > 1) {
        int x = minHeap.top(); minHeap.pop();
        int y = minHeap.top(); minHeap.pop();

        int cost = x + y;
        totalCost += cost;
        minHeap.push(cost);

        cout << "Merged " << x << " + " << y << " → Cost = " << cost << endl;
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<int> files(n);
    cout << "Enter the sizes of the files:\n";
    for (int i = 0; i < n; ++i) {
        cout << "File " << i + 1 << ": ";
        cin >> files[i];
    }

    auto start = high_resolution_clock::now();
    int minCost = optimalMergeCost(files);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "\n📊 Total Merge Cost = " << minCost << endl;
    cout << "⏱️ Execution Time: " << duration.count() << " microseconds" << endl;
    size_t memoryUsed = files.size() * sizeof(int);
    cout << "💾 Estimated Memory Used: " << memoryUsed << " bytes" << endl;

    return 0;
}