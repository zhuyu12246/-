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
        printf("�������%dλѧ������Ϣ ����Ϊ ѧ�� ���� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ�(�ÿո����)\n",i+1);
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

    printf("��ȡ��Ϣ��ϣ������������");
    getch();  //¼�����
    int num;
    while(1){
        printf("1.�鿴ȫ��ѧ����Ϣ\n");
        printf("2.�鿴�ҿ�ѧ����Ϣ\n");
        printf("3.��ѧ������\n");
        printf("4.��ƽ��������\n");
        printf("5.�������ƽ����\n");
        printf("6.���浱ǰ����\n");
        printf("0.�˳�\n");
        printf("\n");
        printf("�������ֽ���ѡ��");
        printf("\n");
        scanf("%d",&num);
        if(num == 1){
            students(head);
            printf("�����������");
            getch();
        }
        else if(num == 2){
            fail(head);
            printf("�����������");
            getch();
        }
        else if(num == 3){
            sort(head);
            numbersort(head);
            printf("�����������");
            getch();
        }
        else if(num == 4){
            scoresort(head);
            numbersort(head);
            printf("�����������");
            getch();
        }
        else if(num == 5){
            average(head);
            printf("�����������");
            getch();
        }
        else if(num == 6){
            printf("������ϣ������������\n");
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
    printf("%10s%10s%10s%10s%10s%10s\n","ѧ��","����","����","��ѧ","Ӣ��","ƽ����");
    for(int i = 0; i < 5; i++){
        printf("%10d%10s%10d%10d%10d%10.2f\n",head->number,head->name,head->chinese,head->match,head->english,head->score);
        head = head->next;
    }
}
void fail(struct node *head){
    printf("%10s%10s%10s%10s%10s%10s\n","ѧ��","����","����","��ѧ","Ӣ��","ƽ����");
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

    printf("%10s%10s%10s%10s%10s%10s\n","ѧ��","����","����","��ѧ","Ӣ��","ƽ����");
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
    printf("%10s%10s%10s\n","����","��ѧ","Ӣ��");
    printf("%10.2f%10.2f%10.2f\n",c,m,e);
}
