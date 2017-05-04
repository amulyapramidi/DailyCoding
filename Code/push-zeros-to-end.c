#include <stdio.h>
#include <stdlib.h>
void swap(int *dataArray,int m,int n)
{
    int temp = dataArray[m];
    dataArray[m] = dataArray[n];
    dataArray[n] = temp;
}
int findNextNonZero(int *dataArray,int startingFrom,int size)
{
    int nonZeroPlaceIndex = -1;
    while(startingFrom<size)
    {
        if(dataArray[startingFrom]!=0)
        {
        nonZeroPlaceIndex= startingFrom;
        break;
        }
        startingFrom++;
    }
    return nonZeroPlaceIndex;
}
void printArray(int *dataArray,int size)
{
    int index=0;
    printf("\n");
    while(index<size)
    {
        printf("%d",dataArray[index]);
        index++;
    }
    
}
void sortZerosToRight(int *dataArray,int size)
{
    int start_pointer=0,next_pointer=0,nonZeroPlaceIndex=0;
while(start_pointer<=(size-1))
{
    // find zero -> search for adjacent non-zero-> swap
  if(dataArray[start_pointer]==0)
    {
        
        if(nonZeroPlaceIndex == 0) // for first time
        nonZeroPlaceIndex = findNextNonZero(dataArray,start_pointer+1,size);
        else // search from non-Zero place from next time
        nonZeroPlaceIndex = findNextNonZero(dataArray,nonZeroPlaceIndex,size);
        if(nonZeroPlaceIndex == -1) // no more non-zeros ?
          break;
        swap(dataArray,start_pointer,nonZeroPlaceIndex);
        nonZeroPlaceIndex++;
        
    }
    start_pointer ++;
}
}
void  saveData(int *dataArray,int size)
{
    int index;
       for(index=0;index<size;index++)
    {
        scanf("%d",&dataArray[index]);
    }
}
int main(void) {
    int size,*dataArray;
    while(1)
    {
    printf("\nEnter size of array or -1 to quit");
    scanf("%d",&size);
    if(size>0)
    {
        dataArray = (int * )malloc(size * sizeof(int));
        saveData(dataArray,size);
        sortZerosToRight(dataArray,size);
        printArray(dataArray,size);
    }
    else if(size==-1)
    break;
    else
    printf("\nEnter valid size");
    }

}

