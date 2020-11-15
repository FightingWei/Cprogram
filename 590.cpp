/*************************************************************************
	> File Name: 590.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 30 Oct 2020 08:27:19 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], mmax[1005][2];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
        scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {//自上而下
        for (int j = 1; j <= i; j++) {
            utd[i][j] = max(utd[i - 1][j - 1], utd[i - 1][j]) + num[i][j];
        }
    }
    for (int i = n; i > 0; i--) {//自下而上
        for (int j = 1; j <= i; j++) {
            dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1] + num[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];//获取权值，因为+了两次数值，需要减掉一个
        }
    }
    for (int i = 1; i <= n; i++) {
        int m2 = 0, m1 = 0, cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (ans[i][j] > m1) {
                m2 = m1;
                m1 = ans[i][j];
                cnt = j;
            } else if (m2 < ans[i][j]) {
                m2 = ans[i][j];
            }
        }
        mmax[0] = cnt;
        mmax[1] = m2;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 1 && b == 1) {
            printf("-1");
        } else if (mmax[a][0] == b){//判断是否删除最大值点
            printf("%d\n", mmax[a][1]);
        } else {
            printf("%d\n", dtu[1][1]);//否则直接输出最大值
        }
    }
    return 0;
}
