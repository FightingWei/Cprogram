/*************************************************************************
	> File Name: 599.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Nov 2020 08:35:25 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, t, num[1000005];

int main() {
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int l = 0, r = n - 1;//双指针
    while (l < r) {
        if (num[l] + num[r] == t) {
            cout << l << " " << r << endl;
            return 0;
        }
        if (num[l] + num[r] < t) {
            l++;
        } else {
            r--;
        }
    }
    cout << - 1 << endl;
    return 0;
}
