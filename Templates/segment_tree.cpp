// Segment Tree Template (for range sum queries)
#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    int n;
    int size;
    vector<long long> tree;

public:
    SegmentTree(vector<int> &data) {
        n = data.size();
        size = 1;
        while (size < n) {
            size <<= 1;
        }
        tree.assign(2 * size, 0);
        for (int i = 0; i < n; i++) {
            tree[size + i] = data[i];
        }
        for (int i = size - 1; i >= 1; i--) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void update(int pos, long long value) {
        pos += size;
        tree[pos] = value;
        pos >>= 1;
        while (pos >= 1) {
            long long new_val = tree[2 * pos] + tree[2 * pos + 1];
            if (tree[pos] == new_val) {
                break;
            }
            tree[pos] = new_val;
            pos >>= 1;
        }
    }

    long long query(int l, int r) {
        long long res = 0;
        l += size;
        r += size;
        while (l <= r) {
            if (l % 2 == 1) {
                res += tree[l];
                l += 1;
            }
            if (r % 2 == 0) {
                res += tree[r];
                r -= 1;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main() {
    vector<int> data = {1, 2, 3, 4, 5};
    SegmentTree st(data);

    cout << st.query(0, 4) << endl;
    st.update(2, 10);
    cout << st.query(0, 4) << endl;

    return 0;
}
