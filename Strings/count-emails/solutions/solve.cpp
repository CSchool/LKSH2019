#include <cstdio>
#include <cctype>
#include <cassert>

using namespace std;

const int MAXC = 1024;
int cnt;

int main(){
	int ans = 0;
	int st = 0;
	char ch;
	while (scanf("%c", &ch) > 0){
		assert(isalpha(ch) || ch=='@' || ch=='.' || ch==' ' || ch=='\n' || ch=='\r');
		if (ch != '\n' && ch != '\r')
		    cnt++;
		if (ch == ' ' || ch == '\n' || ch == '\r'){
			ans += (st == 3);
			st = 0;
			continue;
		}
		switch (st){
			case -1: // trash
				break;
			case 0: // need letter
				if (isalpha(ch)) st = 1;
				else st = -1;
				break;
			case 1: // has letter
				if (isalpha(ch)) st = 1;
				else if (ch == '.') st = 0;
				else if (ch == '@') st = 2;
				else st = -1;
				break;
			case 2: // has @, need letter
				if (isalpha(ch)) st = 3;
				else st = -1;
				break;
			case 3: // has @, has letter
				if (isalpha(ch)) st = 3;
				else if (ch == '.') st = 2;
				else st = -1;
				break;
		}
	}
	assert(cnt <= MAXC);
	ans += (st == 3);
	printf("%d\n", ans);
	return 0;
}
