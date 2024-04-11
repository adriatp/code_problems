#include <bits/stdc++.h>

using namespace std;

int solve() {
    int value, cycle = 0, signal = 1, res = 0;
    set<int> cycles_vip = {20, 60, 100, 140, 180};
    string s;
    while (!cin.eof()) {
        getline(cin,s);
        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
            res = res + cycle * signal;
        if (s[0] == 'a') {
            sscanf (s.data(), "addx %d", &value);
            cycle++;
            if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
                res = res + cycle * signal;
            cycle++;
            signal = signal + value;
        }
        else
            cycle++;
    }
    return res;
}

int main() {
    cout << solve() << endl;
    // cout << solve_str() << endl;
    // cout << solve_int() << endl;
    // cout << solve_vec_int() << endl;
    // cout << solve_group_ints_separated_by_line() << endl;
    return 0;
}