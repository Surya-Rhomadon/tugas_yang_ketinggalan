#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan Jumlah Kota: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));
    
    cout << "Nilai Cost Matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Cost Element Baris Ke-- " << i+1 << " : ";
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    cout << "\nCost List :\n";
    for (int i = 0; i < n; i++) {
        cout << "Cost Element Baris Ke-- " << i+1 << " : ";
        for (int j = 0; j < n; j++) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> path;
    for (int i = 0; i < n; i++) path.push_back(i);

    int minCost = INT32_MAX;
    vector<int> minPath;

    do {
        int total = 0;
        for (int i = 0; i < n - 1; i++) {
            total += cost[path[i]][path[i+1]];
        }

        if (total < minCost) {
            minCost = total;
            minPath = path;
        }

    } while (next_permutation(path.begin(), path.end()));

    cout << "\nJalur Terpendek : ";
    for (int i = 0; i < minPath.size(); i++) {
        cout << minPath[i]+1;
        if (i != minPath.size() - 1) cout << " ---> ";
    }

    cout << "\nMinimum Cost : " << minCost << endl;

    return 0;
}
