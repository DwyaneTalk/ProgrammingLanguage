/*   DwyaneTalk@gmail.com
 *   by lutao
 *   hihocoder : 基站选址
 *             : http://hihocoder.com/contest/msbop2015qual/problem/3
*/

#include <stdio.h>
#include <limits.h>

int ABS(int x, int y){
	return x > y? x - y:y-x;
}

int T, M, N, A, B;
int posA[1000][2]; //用户位置
int posB[100][2];  //通讯公司位置
int xMin,xMax,yMin,yMax;

long userCost(int x1, int y1, int x2, int y2) {
    long dx = x1 - x2;
    long dy = y1 - y2;
    return (dx * dx + dy * dy);
}

int companyCost(int x, int y) {
    int i, min_cost = INT_MAX, cost;
    for (i = 0; i < B; ++i) {
        cost = ABS(posB[i][0], x) + ABS(posB[i][1], y);
        if(cost < min_cost)
            min_cost = cost;
    }
    return min_cost;
}

long solution() {
    int i, j, k;
    long min_cost = INT_MAX;
    long cost;
    for (i = xMin; i <= xMax; ++i) {
        for (j = yMin; j <= yMax; ++j) {
            cost = companyCost(i, j);
            if(cost >= min_cost)
                continue;
            for (k = 0; k < A; ++k) {
                cost += userCost(i,j,posA[k][0],posA[k][1]);
                if(cost >= min_cost)
                    break;
            }
            if(k == A){
            	if(cost < min_cost)
            		min_cost = cost;
            }
        }
    }
    return min_cost;
}

int main() {
    long cost;
    int i, j = 0;
    i = INT_MAX;
    j = (2e31) - 1;
    scanf("%d", &T);
    while(j++ < T) {
        scanf("%d %d %d %d", &N, &M, &A, &B);
        xMin = N;   xMax = 1;
        yMin = M;   yMax = 1;
        for (i = 0;i < A; i++) {
            scanf("%d %d", &posA[i][0], &posA[i][1]);
            if (posA[i][0] < xMin)  xMin = posA[i][0];
            if (posA[i][0] > xMax)  xMax = posA[i][0];
            if (posA[i][1] < yMin)  yMin = posA[i][1];
            if (posA[i][1] > yMax)  yMax = posA[i][1];
        }
        for (i=0;i < B; i++){
            scanf("%d%d", &posB[i][0], &posB[i][1]);
            if (posB[i][0] < xMin)  xMin = posB[i][0];
            if (posB[i][0] > xMax)  xMax = posB[i][0];
            if (posB[i][1] < yMin)  yMin = posB[i][1];
            if (posB[i][1] > yMax)  yMax = posB[i][1];
         }
        cost = solution();
        printf("Case #%d: %ld\n", j, cost);
    }
    return 0;
}
