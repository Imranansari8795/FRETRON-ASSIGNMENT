#include <iostream>
#include <vector>
#include <set>

using namespace std;


typedef pair<int, int> Coord;
typedef vector<Coord> Path;

// check if the castle can move to the target coordinate
bool canMove(const Coord& curr, const Coord& tgt, const set<Coord>& slds) {
    if (curr.first != tgt.first) return false;
    if (curr.second > tgt.second) return false;

    for (int x = curr.second + 1; x < tgt.second; ++x) {
        if (slds.count({curr.first, x})) {
            return false;
        }
    }
    return true;
}

// Recursive function to find paths

void dfs(const Coord& start, Coord curr, vector<Coord>& path, set<Coord>& slds, vector<vector<Coord>>& paths) {
    if (curr == start && !path.empty()) {
        paths.push_back(path);
        return;
    }

    for (auto& s : slds) {
        if (canMove(curr, s, slds)) {
            path.push_back(s);
            set<Coord> newSlds = slds;
            newSlds.erase(s);

            // Move to the next cell (turn left)
            Coord next = {curr.first - 1, curr.second};

            dfs(start, next, path, newSlds, paths);

            path.pop_back();
        }
    }
}

int main() {
    int n;
    cout << "find_my_home_castle soldiers ";
    cin >> n;

    set<Coord> slds;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cout << "Enter coordinates for soldier " << (i + 1) << ": ";
        cin >> x >> y;
        slds.insert({x, y});
    }

    Coord start;
    cout << "Enter the coordinates for your 'special' castle: ";
    cin >> start.first >> start.second;

    vector<vector<Coord>> paths;
    vector<Coord> currPath;
    dfs(start, start, currPath, slds, paths);

    cout << "Thanks. There are " << paths.size() << " unique paths for your 'special_castle'\n";

    int pIdx = 1;
    for (const auto& p : paths) {
        cout << "Path " << pIdx++ << "\n";
        cout << "=======\n";
        cout << "Start (" << start.first << "," << start.second << ")\n";
        for (const auto& c : p) {
            cout << "Kill (" << c.first << "," << c.second << "). Turn Left\n";
        }
        cout << "Arrive (" << start.first << "," << start.second << ")\n";
    }

    return 0;
}





