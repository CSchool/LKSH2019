/**
 * Validates that the input file contains valid xml file, containing one-letter tags, small letters and whitespaces.
 * Also validates right tags nesting.
 * Also validates that file ends with EOLN and EOF.
 */

#include "testlib.h"
#include <string>
#include <stack>
#include <iostream>

using namespace std;

const int maxLength = 1000000;
const int maxTagLength = 1;

int main()
{
    registerValidation();

    string s = inf.readLine();
    if (s.size() > maxLength) {
    	__testlib_fail("input size exceeds " + vtos(maxLength));
    }


    stack<string> tags;
    string tag = "";
    bool isTag = false;
    bool isClosing = false;
    for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '<') {
			isTag = true;
		} else if (s[i] == '>') {
			if (tag.size() > maxTagLength) {
					__testlib_fail("Tag's size exceeds " + vtos(maxTagLength) + " symbols");
			}
			if (isClosing) {
				if (tags.empty() || tags.top() != tag) {
					__testlib_fail("wrong tags nesting");
				}
				tags.pop();
			} else {
				tags.push(tag);
			}
			isTag = false;
			isClosing = false;
			tag = "";
		} else if (s[i] == '/') {
			isClosing = true;
		} else {
			if (!(s[i] == ' ' || (s[i] >= 'a' && s[i] <= 'z'))) {
				__testlib_fail("wrong symbols at " + vtos(i + 1) + "-th position: " + s[i]);
			}
			if (isTag) {
				tag += s[i];
			}
		}
    }
    if (!tags.empty()) {
    	__testlib_fail("not all tags are closed");
    }
    inf.readEof();

    return 0;
}
