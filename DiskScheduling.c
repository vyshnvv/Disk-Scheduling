#include <stdio.h>
#include <stdlib.h>
int ncylinders,nreq,initialhead,totalHeadMove;

void FCFS(int Requests[]){
    int prev=initialhead,current;
    totalHeadMove = 0;
    printf("Order:\n");
    printf("%d ",initialhead);
    for(int i=0; i<nreq; i++){
        current = Requests[i];
        printf("%d ",current);
        totalHeadMove += abs(prev - current);
        prev = current;
    }
    printf("\nTotal head movements:%d\n",totalHeadMove);

}
//Bubble Sorting the given requests in ascending order
void Sort(int Requests[]){
    int temp,i,j;
    for(i=0; i<nreq; i++){
        for(j=0; j<nreq-i-1; j++){
            if(Requests[j] > Requests[j+1]){
                temp = Requests[j];
                Requests[j] = Requests[j+1];
                Requests[j+1] = temp;
            }
        }
    }
}

void SCAN(int Requests[]){
    int i=0,j,x=initialhead,index=0;
    totalHeadMove = 0;
    printf("Order:\n");
    printf("%d ",initialhead);
    do{
        if(Requests[i] > initialhead){
            totalHeadMove += abs(x-Requests[i]);
            printf("%d ",Requests[i]);
            x = Requests[i];
            i++;
        }
        else {
            i++;
            index++;
        }
    }while(i<nreq);
    totalHeadMove += (ncylinders-1) - x;
    x = ncylinders-1;
    index--;
    while(index>=0){
        
        totalHeadMove += abs(x-Requests[index]);
        printf("%d ",Requests[index]);
        x = Requests[index];
        index--;
    }
    printf("\nTotal head movements:%d\n",totalHeadMove);

}

void CSCAN(int Requests[]){
    int i=0,j,x=initialhead,y=0;
    totalHeadMove = 0;
    printf("Order:\n");
    printf("%d ",initialhead);
    do{
        if(Requests[i] > initialhead){
            totalHeadMove += abs(x-Requests[i]);
            printf("%d ",Requests[i]);
            x = Requests[i];
            i++;
        }
        else i++;
    }while(i<nreq);
    totalHeadMove += (ncylinders-1) - x;
    x = 0;
    totalHeadMove += ncylinders-1;
    
    while(Requests[y]<initialhead){
        totalHeadMove += abs(x-Requests[y]);
        printf("%d ",Requests[y]);
        x = Requests[y];
        y++;
    }
    printf("\nTotal head movements:%d\n",totalHeadMove);
}






void main(){
    int i,j,ch=0;
    printf("Enter number of cylinders:\n");
    scanf("%d",&ncylinders);
    printf("Enter number of requests:\n");
    scanf("%d",&nreq);
    int Requests[nreq];
    printf("Enter the requests:\n");
    for(i=0; i<nreq; i++){
        scanf("%d",&Requests[i]);
    }
    printf("Enter initial head position:\n");
    scanf("%d",&initialhead);
    do{
        printf("Enter choice:\n1.FCFS\n2.SCAN\n3.C-SCAN\n4.Exit\n");
        scanf("%d",&ch);
        if(ch!=4 && ch!=1)
            Sort(Requests);
        switch(ch){
            case 1:
                FCFS(Requests);
                break;
            case 2:
                SCAN(Requests);
                break;
            case 3:
                CSCAN(Requests);
                break;
            case 4:
                break;
        }
    }while(ch!=4);
}