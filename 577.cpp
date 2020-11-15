/*************************************************************************
	> File Name: 577.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 18 Oct 2020 07:48:35 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

//string check[1005];
map<string, int> m;
//int total, 

void check(string &str) {//传输地址，直接改数值
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
    return ;
}

int main() {
    string str, ans;
    int ans_cnt = 0;
    while (cin >> str) {
        check(str);
        m[str]++;
        if (m[str] > ans_cnt) {
            ans_cnt = m[str];
            ans = str;
        } else if (m[str] == ans_cnt && str < ans) {
            ans_cnt = m[str];
            ans = str;
        }
    }
    cout << ans << " " << ans_cnt << endl; 
    return 0;
}
