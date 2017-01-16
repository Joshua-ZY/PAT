#include <stdio.h>

typedef struct peopleInfo PINFO;
struct peopleInfo{
	char name[6];
	int year;
	int month;
	int day;
};

int AisOlder(PINFO A, PINFO B) {//如果B比A年龄小，返回1，比A大或相同，返回0
	if (B.year > A.year)
		return 1;
	else if (B.year == A.year && B.month > A.month)
		return 1;
	else if (B.year == A.year && B.month == A.month && B.day > A.day)
		return 1;
	else
		return 0;
}

int main() {
	int num;
	PINFO people[100000];
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%s%d/%d/%d", people[i].name, &people[i].year, &people[i].month, &people[i].day);
	}
	int oldestID = -1, youngestID = -1, count = 0;
	PINFO today = { "today", 2014, 9, 6 }, year200 = { "y200", 2014 - 200, 9, 6 };//等于200岁不算不合理年龄
	for (int i = 0; i < num; i++) {
		if (AisOlder(today, people[i]))//今天比实际出生年龄还老，说明实际出生年龄在今天之后，不合理
			continue;
		else if (AisOlder(people[i], year200)) //比200年前出生的人还老，说明年龄大于200，不合理
			continue;
		else {
			count++;
			if (oldestID == -1)
				oldestID = i;
			if (youngestID == -1)
				youngestID = i;
			if (AisOlder(people[i], people[oldestID]))
				oldestID = i;
			if (AisOlder(people[youngestID], people[i]))
				youngestID = i;
		}
	}
	
	if(oldestID == -1 && youngestID == -1) //如果所有年龄都是不合理的
		printf("%d\n", count);
	else
		printf("%d %s %s\n", count, people[oldestID].name, people[youngestID].name);
	return 0;
}