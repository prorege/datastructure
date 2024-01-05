#include <stdio.h>
#include <stdlib.h>
#define SIZE 100


/*
size 100의 queue가 있다.
여기서 중요한 점은 stack은 top만 가지고 index위치를 표현한 반면 queue는 rear와 front 둘 다 필요하다는 점이다.
아래와 같은 queue가 있다고 하자. 각 번호는 각 queue의 value가 아니라 index이다. 현재는 다 비워져있는 상태
|0|1|2|3|4|5|6|7|8|9|||||||||||||||||||||||||98|99|

이때 rear와 front는 둘 다
여기를 가리키고 있다.
  ↓
|-1|0|1|2|3|4|5|6|7|8|9|||||||||||||||||||||||||98|99|

그러다가 맨 처음 queue가 발생하면
  front
    ↓
|-1|0|1|2|3|4|5|6|7|8|9|||||||||||||||||||||||||98|99|
    ↑
   rear
이렇게 바뀐다.

이후로 queue가 발생하면
  front
    ↓
|-1|0|1|2|3|4|5|6|7|8|9|||||||||||||||||||||||||98|99|
            ↑
            rear
이런식으로 rear+1되며 바뀐다.

만약 dequeue가 발생하면
        front
        ↓
|-1|0|1|2|3|4|5|6|7|8|9|||||||||||||||||||||||||98|99|
            ↑
            rear
이런식으로 front+1되며 바뀐다.

dequeue가 너무 많이 발생해서 만약 front>rear가 되면 underflow라고 표시
*/



void enqueue();
void dequeue();
void show();

int inp_arr[SIZE];
int Rear = - 1; //꼬리
int Front = - 1; //머리

int main(){
    int ch; //choice
    while (1)
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                enqueue();
                break;//이 break는 switch문만 빠져나올 뿐 while문은 빠져나오지 못한다.
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("Incorrect choice \n");
        }
    }
}

void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
        printf("Overflow \n");
    else
    {
        if (Front == - 1) Front = 0;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        inp_arr[Rear] = insert_item;
    }
} 
 
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[Front]);
        Front = Front + 1;
    }
} 
 
void show()
{
    
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}