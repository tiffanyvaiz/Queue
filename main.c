#include "Queue.h"

int main()
{
    int size,option;
    printf("Enter size:");
    scanf("%d",&size);
    queue_t* newQueue= CreateQueue(size);

    printf("請輸入選項(-1結束)：\n(1)Add node\n(2)Remove node\n(3)clear\n$c>");
    
    while(scanf("%d",&option))
    {
        switch(option)
        {
            case -1:
                return 0;
                
            case 1:
            {
                int enterValue;
                printf("Enter value :");
                scanf("%d",&enterValue);
                enQueue(newQueue,enterValue);//function直接傳入自訂size 
                OutputQueue(newQueue);
                break;
            }
            
            case 2:
            {
                deQueue(newQueue);
                OutputQueue(newQueue);
                break;
            }
            
            case 3:
            {
                Clear(newQueue);
                OutputQueue(newQueue);
                break;
            }
        }
        printf("請輸入選項(-1結束)：\n(1)Add node\n(2)Remove node\n(3)clear\n$c>");
    }    
}
