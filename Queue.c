#include "Queue.h"

queue_t* CreateQueue(int enterSize) 
{
    queue_t* newQueue = (queue_t*)malloc(sizeof(queue_t));
    newQueue->size=enterSize; //�qQueue�j�p 
    //��l�� 
	newQueue->headNode.next=NULL;
    newQueue->front= NULL;
    newQueue->rear= NULL;
    return newQueue;
}


bool isEmpty(queue_t* sourceQueue)
{
    if(sourceQueue->headNode.next==NULL)
    //��headNode���VNULL�ɪ��Queue����  
    {
        return true;
    }
    else
        return false;
}
bool isFull (queue_t* sourceQueue)
{
    if(elementAmount(sourceQueue)==sourceQueue->size)
    // elementAmount(queue_t*)���P�_�ثenode�ƶq 
    {
        return true;
    }
    else
        return false;

}

queue_t* deQueue(queue_t* sourceQueue)
{
    if(isEmpty(sourceQueue)==true)
    //���Ůɪ����^�� 
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
        }//���X�j���tempNode���V�˼ƲĤG��Node 
        
        sourceQueue->rear=&tempNode;
        tempNode->next= NULL;//�̫�@��=NULL 

        return sourceQueue;
    }
}

queue_t* enQueue(queue_t* sourceQueue,int nodeValue)
//�����ǤJ�s��Node��J�A�æb��function�ؤ@�ӷs��Node 
{
    node_t* newNode=(node_t*)malloc(sizeof(node_t));

    if(isFull(sourceQueue)==true)
    //���ɤ��[�J 
    {
        return sourceQueue;
    }
    else
    {
        newNode->value=nodeValue;
        newNode->next=sourceQueue->headNode.next;//�sNode->Next���V�쥻�Ĥ@�� 
        sourceQueue->headNode.next=newNode;//headNode.next���V�sNode 
        sourceQueue->front=&sourceQueue->headNode.next;//front���V�sNode 
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
    }//�Q��deQueue�@�@�R��Node 
    
    //��Queue�u�ѤUsize�A��L��l�� 
    sourceQueue->headNode.next=NULL;
    sourceQueue->front= NULL;
    sourceQueue->rear= NULL;
    return sourceQueue;
}


void OutputQueue(queue_t* sourceQueue)
// ��X�{�� 
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
    
    else//�p�G�O�Ū� 
    {
        printf("!!IS EMPTY!!");
    }
    
    printf("\n");
}

int elementAmount(queue_t* sourceQueue)
//�p��node�ƶq 
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



