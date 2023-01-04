#include <bits/stdc++.h>
using namespace std;

// Reference video: https://www.youtube.com/watch?v=RV0QeTyHZxo 
// The goal is to count the number of distinct substrings in a string including an empty substring

class Node {
public:
    Node* tree[26];
    bool containsKey(char c) {
        return tree[c - 'a'];
    }
    void insert(char c, Node* node) {
        tree[c - 'a'] = node;
    }
    Node* get(char c) {
        return tree[c - 'a'];
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int cnt = 1;
        Node *root = new Node();
        for (int i = 0; i < s.size(); ++i) {
            Node* node = root;
            for (int j = i; j < s.size(); ++j) {
                if (!node -> containsKey(s[j])) {
                    ++cnt;
                    node -> insert(s[j], new Node());
                }
                node = node -> get(s[j]);
            }
        }
        printf("%d\n", cnt);
    }
}
