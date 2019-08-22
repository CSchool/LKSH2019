#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string s;

    getline(cin, s);
    int cnt = 0;
    bool isTag = false;
    bool isClosing = false;
    for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '<') {
			isTag = true;
		} else if (s[i] == '>') {
			cnt += isClosing ? -1 : 1;
			isTag = false;
			isClosing = false;
		} else if (s[i] == '/') {
			isClosing = true;
		} else {
			if (!isTag && cnt == 0) {
				cout << s[i];
			}
		}
    }

    return 0;
}
