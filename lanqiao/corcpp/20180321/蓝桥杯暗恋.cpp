#include<iostream>

using namespace std;

const int MAXN = 205;
int map[MAXN][MAXN];

bool isspace(int x, int y, int a) {
    int index = map[x][y];
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < a; j++) {
            if(map[x+i][y+j] != index) return false;
        }
    }
    return true;
}

int main () {
    int n, m, ans = 0;
    cin >> n >> m;
    int max1 = max(n, m);//��󲻻ᳬ��max1
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> map[i][j];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int a = ans + 1; a < max1; a++)//��������þ������2x2���������ж�3x3�������������break
                if(i+a<=n && j+a<=m) {
                    if(isspace(i, j, a)) ans = a;
                }
                else break;
        }
    }
    cout << ans * ans << endl;
    return 0;
}
