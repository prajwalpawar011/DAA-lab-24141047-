#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip> // for std::setprecision

using namespace std;

struct File {
    string name;
    int importance;
    int size;
    double ratio;

    File(string n, int imp, int sz) {
        name = n;
        importance = imp;
        size = sz;
        ratio = static_cast<double>(imp) / sz;
    }
};

bool compare(File a, File b) {
    return a.ratio > b.ratio;
}

double optimizeStorage(int totalSpace, vector<File>& files) {
    sort(files.begin(), files.end(), compare);

    double totalImportance = 0.0;
    int usedSpace = 0;

    cout << "\n📦 Storage Allocation:\n";
    for (auto& file : files) {
        if (usedSpace + file.size <= totalSpace) {
            // Store full file
            usedSpace += file.size;
            totalImportance += file.importance;
            cout << "✔ Stored full file: " << file.name << " (" << file.size << "MB)\n";
        } else {
            int remainingSpace = totalSpace - usedSpace;
            double fraction = static_cast<double>(remainingSpace) / file.size;
            totalImportance += file.importance * fraction;
            usedSpace += remainingSpace;
            cout << "⚠ Stored " << fixed << setprecision(2) << (fraction * 100)
                 << "% of file: " << file.name << " (" << remainingSpace << "MB)\n";
            break;
        }
    }

    cout << "\n📊 Total Importance Stored: " << fixed << setprecision(2) << totalImportance << endl;
    return totalImportance;
}

int main() {
    int totalSpace, n;
    cout << "Enter total storage space available (in MB): ";
    cin >> totalSpace;

    cout << "Enter number of files: ";
    cin >> n;

    vector<File> files;
    for (int i = 0; i < n; ++i) {
        string name;
        int importance, size;
        cout << "\nEnter name of file " << i + 1 << ": ";
        cin >> ws; // consume any leading whitespace
        getline(cin, name);
        cout << "Enter importance of " << name << ": ";
        cin >> importance;
        cout << "Enter size of " << name << " (in MB): ";
        cin >> size;
        files.emplace_back(name, importance, size);
    }

    optimizeStorage(totalSpace, files);

    return 0;
}
