


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void alloc(const vector<int>& w) {
    vector<int> r, s, h;
    int total = 0;

    // Payment individuals
    int rp = 50, sp = 30, hp = 20;

    //  total weight
    for (int weight : w) {
        total += weight;
    }

    // each target weights
    int rt = (total * rp) / 100;
    int st = (total * sp) / 100;
    int ht = (total * hp) / 100;

    // Sort weights in descending order
    vector<int> sw = w;
    sort(sw.rbegin(), sw.rend());

    // Allocate apples
    for (int weight : sw) {
        if (rt >= weight) {
            r.push_back(weight);
            rt -= weight;
        } else if (st >= weight) {
            s.push_back(weight);
            st -= weight;
        } else if (ht >= weight) {
            h.push_back(weight);
            ht -= weight;
        }
    }

    // Display allocation results
    cout << "Result:\nRam: ";
    for (int w : r) {
        cout << w << " ";
    }
    cout << "\nSham: ";
    for (int w : s) {
        cout << w << " ";
    }
    cout << "\nRahim: ";
    for (int w : h) {
        cout << w << " ";
    }
    cout << endl;
}

int main() {
    vector<int> w;
    int i;

    cout << "Enter weights (enter -1 to stop): ";
    while (true) {
        cin >> i;
        if (i == -1) {
            break;
        }
        w.push_back(i);
    }


    alloc(w);

    return 0;
}

