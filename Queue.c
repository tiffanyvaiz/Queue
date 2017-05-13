#include "Queue.h"

queue_t* CreateQueue(int enterSize) 
{
    queue_t* newQueue = (queue_t*)malloc(sizeof(queue_t));
    newQueue->size=enterSize; //訂Queue大小 
    //初始化 
	newQueue->headNode.next=NULL;
    newQueue->front= NULL;
    newQueue->rear= NULL;
    return newQueue;
}


bool isEmpty(queue_t* sourceQueue)
{
    if(sourceQueue->headNode.next==NULL)
    //當headNode指向NULL時表示Queue為空  
    {
        return true;
    }
    else
        return false;
}
bool isFull (queue_t* sourceQueue)
{
    if(elementAmount(sourceQueue)==sourceQueue->size)
    // elementAmount(queue_t*)為判斷目前node數量 
    {
        return true;
    }
    else
        return false;

}

queue_t* deQueue(queue_t* sourceQueue)
{
    if(isEmpty(sourceQueue)==true)
    //為空時直接回傳 
    {
        return sourceQueue;
    }
    else
    {
        int i=1;
        int amount=elementAmount(sourceQueue);
        node_t* tempNode=(node_t*)malloc(sizeof(node_t));
        tempNode=&sourceQueue->headNode;
        
        while(i<amount)
        {
            tempNode=tempNode->next;
            i++;
        }//跳出迴圈時tempNode指向倒數第二個Node 
        
        sourceQueue->rear=&tempNode;
        tempNode->next= NULL;//最後一個=NULL 

        return sourceQueue;
    }
}

queue_t* enQueue(queue_t* sourceQueue,int nodeValue)
//直接傳入新的Node輸入，並在此function建一個新的Node 
{
    node_t* newNode=(node_t*)malloc(sizeof(node_t));

    if(isFull(sourceQueue)==true)
    //滿時不加入 
    {
        return sourceQueue;
    }
    else
    {
        newNode->value=nodeValue;
        newNode->next=sourceQueue->headNode.next;//新Node->Next指向原本第一個 
        sourceQueue->headNode.next=newNode;//headNode.next指向新Node 
        sourceQueue->front=&sourceQueue->headNode.next;//front指向新Node 
        return sourceQueue;
    }
}


queue_t* Clear(queue_t* sourceQueue)
{
    int i;
    int amount=elementAmount(sourceQueue);
    
    for(i=0;i<amount;i++)
    {
        deQueue(sourceQueue);
    }//利用deQueue一一刪除Node 
    
    //讓Queue只剩下size，其他初始化 
    sourceQueue->headNode.next=NULL;
    sourceQueue->front= NULL;
    sourceQueue->rear= NULL;
    return sourceQueue;
}


void OutputQueue(queue_t* sourceQueue)
// 輸出現有 
{
    if(isEmpty(sourceQueue)==false)
    {
        node_t* tempNode=(node_t*)malloc(sizeof(node_t));
        tempNode=sourceQueue->headNode.next;
        do{
            printf("%d ",tempNode->value);
            tempNode=tempNode->next;
        }while(tempNode);
    }
    
    else//如果是空的 
    {
        printf("!!IS EMPTY!!");
    }
    
    printf("\n");
}

int elementAmount(queue_t* sourceQueue)
//計算node數量 
{
    int amount;
    node_t* tempNode=(node_t*)malloc(sizeof(node_t));
    tempNode=sourceQueue->headNode.next;
    
    while(tempNode)
    {
        amount++;
        tempNode=tempNode->next;
    }
    
    return amount;
}



