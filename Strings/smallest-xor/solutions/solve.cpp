#include <iostream>
#include <algorithm>

struct node {
    node *next[2];

    node() { next[0] = next[1] = nullptr; }
};

node *root;

void add(int x) {
    node *cur = root;
    for (int i = 31; i >= 0; --i) {
        int b = (x >> i) & 1;
        if (!cur->next[b]) {
            cur->next[b] = new node;
        }
        cur = cur->next[b];
    }
}

int find(int x) {
    node *cur = root;
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
        int b = (x >> i) & 1;
        if (!cur->next[b]) {
            ans += (1 << i);
            b ^= 1;
        }
        cur = cur->next[b];
    }
    return ans;
}

int main() {
    root = new node;
    int n;
    std::cin >> n;
    int ans = 1 << 30;
    for (int i = 0; i < n; ++i) {
        int t;
        std::cin >> t;
        if (i > 0) {
            ans = std::min(ans, find(t));
        }
        add(t);
    }
    std::cout << ans << std::endl;
    return 0;
}
