#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// check if two segments intersect
bool intersect(pair<int, int> p1, pair<int, int> p2, pair<int, int> q1, pair<int, int> q2) {
    auto orient = [](pair<int, int> a, pair<int, int> b, pair<int, int> c) {
        int area = (b.second - a.second) * (c.first - b.first) - (b.first - a.first) * (c.second - b.second);
        return (area == 0) ? 0 : (area > 0) ? 1 : 2; // 0: collinear, 1: clockwise, 2: counterclockwise
    };

    int o1 = orient(p1, p2, q1);
    int o2 = orient(p1, p2, q2);
    int o3 = orient(q1, q2, p1);
    int o4 = orient(q1, q2, p2);

    return (o1 != o2 && o3 != o4);
}

// mark a path on the grid
void mark(const vector<pair<int, int>>& path, char id, char g[10][10]) {
    for (const auto& pt : path) {
        g[pt.second][pt.first] = id; // Update grid with the path identifier
    }
}

// display the grid
void show(const char g[10][10]) {
    cout << "Grid:\n";
    for (int r = 9; r >= 0; --r) {
        for (int c = 0; c < 10; ++c) {
            cout << g[r][c] << ' ';
        }
        cout << endl;
    }
}

int main() {
    int numPaths;
    cout << "Enter the number of flight paths: ";
    cin >> numPaths;

    vector<vector<pair<int, int>>> paths(numPaths);
    vector<char> ids(numPaths);

    // Input flight paths from user
    for (int i = 0; i < numPaths; ++i) {
        cout << "Enter identifier for Path " << (char)('A' + i) << ": ";
        cin >> ids[i];

        int numPoints;
        cout << "Enter number of points for Path " << (char)('A' + i) << ": ";
        cin >> numPoints;

        cout << "Enter the points (x y format):\n";
        for (int j = 0; j < numPoints; ++j) {
            int x, y;
            cin >> x >> y;
            // Check if coordinates are within bounds
            if (x < 0 || x >= 10 || y < 0 || y >= 10) {
                cout << "Coordinates out of bounds! Please enter values between 0 and 9." << endl;
                --j; // Decrement j to retry this point
            } else {
                paths[i].emplace_back(x, y);
            }
        }
    }
    

    // Initialize an empty grid
    char grid[10][10];
    for (int i = 0; i < 10; ++i) {
        fill(grid[i], grid[i] + 10, '.'); // Fill grid with dots
    }

    // Mark paths on the grid
    for (int i = 0; i < numPaths; ++i) {
        mark(paths[i], ids[i], grid);
    }

    // Display the grid
    show(grid);

    return 0;
}
