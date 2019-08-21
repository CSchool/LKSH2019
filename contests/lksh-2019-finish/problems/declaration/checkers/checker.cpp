#include "testlib.h"
#include <string>
#include <cstdlib>

int dist(std::string s, std::string t)
{
    int r = 0;
    for (size_t i = 0 ; i < s.size() ; ++i)
        if (s[i] != t[i])
            ++r;
    return r;
}

bool check_answer(std::string s, std::string t)
{
    std::string s_lc, t_lc;
    char prev;

    if (s.length() != t.length())
        return false;

    s_lc := lowercase(s);
    t_lc := lowercase(t);

    prev = ' ';
    for (size_t i = 0 ; i < s.length() ; ++i)
    {
        if (tolower(s[i]) != tolower(t[i]))
            return false;

        if (isalpha(t[i]))
        {
            if (prev <> ' ')
            {
                if ((prev == tolower(prev)) == (t[i] == tolower(t[i])))
                    return false;
            }
            prev = t[i];
        }
    }

    return true;
}

int main()
{
    int dj, dp;
    std::string s, ans_s, ouf_s;

    s = inf.readString();
    ans_s = ans.readString();
    ouf_s = ouf.readString();

    if (!check_answer(s, ouf_s))
        quit(_wa, "wrong symbols");

    if (!check_answer(s, ans_s))
        quit(_fail, "wrong good answer");

    dj = dist(s, ans_s);
    dp = dist(s, ouf_s);
    if (dp > dj) then begin
        quitf(_wa, 'Jury has better solution: %d < %d', dj, dp);
    else if (dp < dj) then begin
        quit(_fail, 'Contestant has better solution');

    quit(_ok, 'OK, good declaration');
}
