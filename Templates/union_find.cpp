// Union Find (Disjoint Set Union) Template
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank_;

public:
    UnionFind(int size) {
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
        rank_.assign(size, 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        if (x_root == y_root) {
            return;
        }
        if (rank_[x_root] < rank_[y_root]) {
            parent[x_root] = y_root;
        } else {
            parent[y_root] = x_root;
            if (rank_[x_root] == rank_[y_root]) {
                rank_[x_root] += 1;
            }
        }
    }
};

int main() {
    UnionFind uf(5);
    uf.unite(0, 1);
    uf.unite(1, 2);

    cout << (uf.find(0) == uf.find(2)) << endl;
    cout << (uf.find(0) == uf.find(3)) << endl;

    return 0;
}
