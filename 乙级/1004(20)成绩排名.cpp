#include <stdio.h>
#define N 102
//分数各不相同，且分数范围为0-100，说明最多101个学生，建立102的数组足够用了

struct stu{
    char name[11]; //注意，姓名学号长度不超过10位，那么字符数组要分配11位，结束符'\0'也要占一位
    char no[11];
    int mark;
};

int main(){
    struct stu students[N];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%s%d", students[i].name, students[i].no, &students[i].mark);
    }
    int maxid, minid, maxm = 0, minn = 100;
    for(int i = 0; i < n; i++){
        if (students[i].mark > maxm){
            maxm = students[i].mark;
            maxid = i;
        }
        if (students[i].mark < minn){
            minn = students[i].mark;
            minid = i;
        }
    }
    printf("%s %s\n", students[maxid].name, students[maxid].no);
    printf("%s %s\n", students[minid].name, students[minid].no);
    return 0;
}
