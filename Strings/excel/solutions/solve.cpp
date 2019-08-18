// Written by Nikita Tsarev

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

const int INF = 1000000;
const int ADD = INF + 1;
const int SUB = INF + 2;
const int MUL = INF + 3;
const int DIV = INF + 4;
const int OP = INF + 5;
const int CL = INF + 6;

struct node {
    int x = INF;
    node *l = nullptr;
    node *r = nullptr;
};

node *eq[500];
int used[500];
int value[500];

int cell_to_int(const char *s) {
    return INF + 100 + (s[0] - 'A') * 10 + (s[1] - '0');
}

int get_prio(int x) {
    int p = 0;
    if (x == ADD || x == SUB) p = 1;
    if (x == MUL || x == DIV) p = 2;
    return p;
}

int eval(node *t);

int eval_cell(int x) {
    if (used[x] == 1) {
        std::cout << INF << std::endl;
        exit(0);
    }
    if (used[x] == 2) return value[x];
    used[x] = 1;

    node *t = eq[x];
    value[x] = eval(t);
    used[x] = 2;
    return value[x];
}

int eval(node *t) {
    if (!t) return 0;
    if (t->x < INF) return t->x;
    if (t->x == ADD) return eval(t->l) + eval(t->r);
    if (t->x == SUB) return eval(t->l) - eval(t->r);
    if (t->x == MUL) return eval(t->l) * eval(t->r);
    if (t->x == DIV) {
        int r = eval(t->r);
        if (r == 0) return 0;
        return eval(t->l) / r;
    }
    return eval_cell(t->x - INF);
}

node *make_tree(const std::vector<int> &v) {
    std::vector<int> s;
    std::vector<node*> st;
    int prio = 0;
    for (int x : v) {
        if (x < INF || x > (INF + 99)) {
            node *t = new node;
            t->x = x;
            st.push_back(t);
            s.push_back(x);
            continue;
        }
        int p = get_prio(x);
        if (p < prio || p == 0) {
            while (s.size() >= 3 && get_prio(s[s.size() - 2]) > p) {
                node *t = new node;
                t->x = s[s.size() - 2];
                t->r = st[st.size() - 1];
                t->l = st[st.size() - 2];
                st.pop_back();
                st.pop_back();
                st.push_back(t);
                s.pop_back();
                s.pop_back();
                s.pop_back();
                s.push_back(-1);
            }
        }
        if (x == CL) {
            s.pop_back();
            s.pop_back();
            s.push_back(-1);
        } else {
            s.push_back(x);
        }
        prio = p;
    }
    return st[0];
}

void add_equation(const std::string &s) {
    std::string lhs;
    std::string t;
    bool f = false;
    std::vector<int> tokens;
    tokens.push_back(OP);
    for (char c : s) {
        if (c <= 32) continue;
        if (c == '=') {
            f = true;
            continue;
        }
        if (f) {
            if ('A' <= c && c <= 'Z') {
                t = c;
            } else if ('0' <= c && c <= '9') {
                if (!t.empty() && t[0] >= 'A' && t[0] <= 'Z') {
                    t += c;
                    tokens.push_back(cell_to_int(t.c_str()));
                    t = "";
                } else {
                    t += c;
                }
            } else {
                if (!t.empty()) {
                    tokens.push_back(atoi(t.c_str()));
                    t = "";
                }
                if (c == '(') tokens.push_back(OP);
                if (c == ')') tokens.push_back(CL);
                if (c == '+') tokens.push_back(ADD);
                if (c == '-') tokens.push_back(SUB);
                if (c == '*') tokens.push_back(MUL);
                if (c == '/') tokens.push_back(DIV);
            }
        } else {
            lhs += c;
        }
    }
    if (!t.empty()) {
        tokens.push_back(atoi(t.c_str()));
    }
    tokens.push_back(CL);
    eq[cell_to_int(lhs.c_str()) - INF] = make_tree(tokens);
}

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::getline(std::cin, s);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, s);
        add_equation(s);
    }
    std::cout << eval_cell(101) << std::endl;
    return 0;
}
