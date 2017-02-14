#include <stdio.h>
#include <algorithm>
using namespace std;
//!!!注意题意！，是有E天骑车超过E英里，是超过！不可以相等！
/*网上看的思路：
(1)i from 1 to n，将所有数据进行从大到小排序；
(2)a[i]<=i时，break;
(3)i-1即为所求
*/


#define MAXDAY 100010
int dist[MAXDAY] = { 0 };

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int day;
	scanf("%d", &day);
	for (int i = 0; i < day; i++)
		scanf("%d", &dist[i]);
	
	sort(dist, dist + day, cmp);
	int find_flag = 0;
	for (int i = 0; i < day; i++) {
		if (i + 1 >= dist[i]) { //如果发现某天的天数比当天距离大，就说明前一天是答案（天数比序号大1, i + 1就是天数）
			printf("%d\n", i);
			find_flag = 1;
			break;
		}
	}
	if (!find_flag) {
		printf("%d\n", day);
	}
	return 0;
}