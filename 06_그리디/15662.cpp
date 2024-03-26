#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_TIME = 1001;
const int LED_COUNT = 8;

int d[MAX_TIME][LED_COUNT];
int chk[MAX_TIME];

// LED의 상태를 변경하는 함수
void changeLEDState(int x, int y) {
    chk[x] = y;
    for (int j = x; j < MAX_TIME; j++) {
        if (d[j][2] != d[j + 1][6]) {
            chk[j + 1] = -chk[j];
        } else
            break;
    }
    for (int j = x; j > 1; j--) {
        if (d[j][6] != d[j - 1][2]) {
            chk[j - 1] = -chk[j];
        } else
            break;
    }
    for (int j = 1; j <= MAX_TIME; j++) {
        if (chk[j] == 0)
            continue;
        else if (chk[j] == 1) {
            int tmp = d[j][LED_COUNT - 1];
            for (int k = LED_COUNT - 1; k > 0; k--) {
                d[j][k] = d[j][k - 1];
            }
            d[j][0] = tmp;
        } else if (chk[j] == -1) {
            int tmp = d[j][0];
            for (int k = 0; k < LED_COUNT - 1; k++) {
                d[j][k] = d[j][k + 1];
            }
            d[j][LED_COUNT - 1] = tmp;
        }
    }
}

// LED가 켜져 있는지 확인하여 개수를 반환하는 함수
int countLitLEDs(int t) {
    int ans = 0;
    for (int i = 1; i <= t; i++) {
        if (d[i][0] == 1)
            ans += 1;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < LED_COUNT; j++) {
            scanf("%1d", &d[i][j]);
        }
    }

    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        memset(chk, 0, sizeof(chk));
        int x, y;
        scanf("%d %d", &x, &y);
        changeLEDState(x, y);
    }

    int result = countLitLEDs(t);
    printf("%d\n", result);

    return 0;
}
