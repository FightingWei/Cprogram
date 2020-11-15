/*************************************************************************
	> File Name: 600.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 04 Nov 2020 08:50:00 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m, t, num[3005][3005];

int main() {
    scanf("%d%d%d", &n, &m, &t);//为了防止超时
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        } 
    }
    int x = n, y = 1;
    while (1) {
        if (num[x][y] == t) {
            //cout << x << " " << y << endl;
            printf("%d %d\n", x, y);//与scanf搭配
            return 0;
        } else if (num[x][y] > t) {
            x--;
        } else {
            y++;
        }
    }
    cout << -1 << endl;
    return 0;
}
