#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

struct node{
    int number;
    char name[20];
    int chinese;
    int match;
    int english;
    float score;
    struct node *next;
};
void students(struct node *head);
void fail(struct node *head);
void sort(struct node *head);
void numbersort(struct node *head);
void scoresort(struct node *head);
void average(struct node *head);
int main() {
        int i;
        struct node student[5];
    for(i = 0; i < 5;i++){
        printf("请输入第%d位学生的信息 依次为 学号 姓名 语文成绩 数学成绩 英语成绩(用空格隔开)\n",i+1);
        scanf("%d %s %d %d %d",&student[i].number,student[i].name,&student[i].chinese,&student[i].match,&student[i].english);
        student[i].score = (float)(student[i].english + student[i].match + student[i].chinese)/3;
    }
    struct node *head = NULL,*p;
    for(i = 0; i < 5;i++){
        p = (struct node*)malloc(sizeof (struct node));
        p->next = NULL;
        p->number = student[i].number;
        strcpy(p->name,student[i].name);
        p->match = student[i].match;
        p->chinese = student[i].chinese;
        p->english = student[i].english;
        p->score = student[i].score;
        p->next = head;
        head = p;
    }

    printf("读取信息完毕，按任意键继续");
    getch();  //录入操作
    int num;
    while(1){
        printf("1.查看全部学生信息\n");
        printf("2.查看挂科学生信息\n");
        printf("3.按学号排序\n");
        printf("4.按平均分排序\n");
        printf("5.计算各科平均分\n");
        printf("6.保存当前数据\n");
        printf("0.退出\n");
        printf("\n");
        printf("输入数字进行选择：");
        printf("\n");
        scanf("%d",&num);
        if(num == 1){
            students(head);
            printf("按任意键继续");
            getch();
        }
        else if(num == 2){
            fail(head);
            printf("按任意键继续");
            getch();
        }
        else if(num == 3){
            sort(head);
            numbersort(head);
            printf("按任意键继续");
            getch();
        }
        else if(num == 4){
            scoresort(head);
            numbersort(head);
            printf("按任意键继续");
            getch();
        }
        else if(num == 5){
            average(head);
            printf("按任意键继续");
            getch();
        }
        else if(num == 6){
            printf("保存完毕，按任意键继续\n");
            getch();
        }
        else if(num == 0){
            while(head){
                p = head;
                head = head ->next;
                free(p);
            }
            break;
        }
    }
}

void students(struct node *head){
    printf("%10s%10s%10s%10s%10s%10s\n","学号","姓名","语文","数学","英语","平均分");
    for(int i = 0; i < 5; i++){
        printf("%10d%10s%10d%10d%10d%10.2f\n",head->number,head->name,head->chinese,head->match,head->english,head->score);
        head = head->next;
    }
}
void fail(struct node *head){
    printf("%10s%10s%10s%10s%10s%10s\n","学号","姓名","语文","数学","英语","平均分");
    for(int i = 0; i < 5; i++){
        if(head->chinese < 60 || head->match < 60 || head->english < 60) {
            printf("%10d%10s%10d%10d%10d%10.2f\n", head->number, head->name, head->chinese, head->match, head->english,
                   head->score);
            head = head->next;
        }
        else{
            head = head->next;
            continue;
        }
    }
}
void sort(struct node *head){
    struct node *firstnode = head;//head->next
    struct node *secondnode = head;
    while (firstnode != NULL)
    {
        while (firstnode->next != NULL)
        {
            if (secondnode->number > firstnode->next->number)//first--secon
            {
                int temp = secondnode->number;
                secondnode->number = firstnode->next->number;
                firstnode->next->number = temp;
                char str[20];
                strcpy(str,secondnode->name);
                strcpy(secondnode->name,firstnode->next->name);
                strcpy(firstnode->next->name,str);
                int cn = secondnode->chinese;
                secondnode->chinese = firstnode->next->chinese;
                firstnode->next->chinese = cn;
                int ma = secondnode->match;
                secondnode->match = firstnode->next->match;
                firstnode->next->match = ma;
                int en = secondnode->english;
                secondnode->english = firstnode->next->english;
                firstnode->next->english = en;
                float sc = secondnode->score;
                secondnode->score = firstnode->next->score;
                firstnode->next->score = sc;

            }
            firstnode = firstnode->next;
        }
        firstnode = secondnode->next;
        secondnode = firstnode;
    }

}
void numbersort(struct node *head){
    struct node *p = head;

    printf("%10s%10s%10s%10s%10s%10s\n","学号","姓名","语文","数学","英语","平均分");
    while (p){
        printf("%10d%10s%10d%10d%10d%10.2f\n",p->number,p->name,p->chinese,p->match,p->english,p->score);
        p = p->next;
    }
}
void scoresort(struct node *head){
    struct node *firstnode = head;
    struct node *secondnode = head;
    while (firstnode != NULL)
    {
        while (firstnode->next != NULL)
        {
            if (secondnode->score > firstnode->next->score)
            {
                int temp = secondnode->number;
                secondnode->number = firstnode->next->number;
                firstnode->next->number = temp;
                char str[20];
                strcpy(str,secondnode->name);
                strcpy(secondnode->name,firstnode->next->name);
                strcpy(firstnode->next->name,str);
                int cn = secondnode->chinese;
                secondnode->chinese = firstnode->next->chinese;
                firstnode->next->chinese = cn;
                int ma = secondnode->match;
                secondnode->match = firstnode->next->match;
                firstnode->next->match = ma;
                int en = secondnode->english;
                secondnode->english = firstnode->next->english;
                firstnode->next->english = en;
                float sc = secondnode->score;
                secondnode->score = firstnode->next->score;
                firstnode->next->score = sc;
            }
            firstnode = firstnode->next;
        }
        firstnode = secondnode->next;
        secondnode = firstnode;
    }

}
void average(struct node *head){
    struct node *p = head;
    float c,m,e;
    for(int i = 0; i < 5; i++){
        c += p->chinese;
        m += p->match;
        e += p->english;
        p = p->next;
    }
    c = c/5;
    m = m/5;
    e = e/5;
    printf("%10s%10s%10s\n","语文","数学","英语");
    printf("%10.2f%10.2f%10.2f\n",c,m,e);
}
