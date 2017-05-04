#include <stdio.h>
#include <stdlib.h>
void swap(int *dataArray,int m,int n)
{
    int temp = dataArray[m];
    dataArray[m] = dataArray[n];
    dataArray[n] = temp;
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
    int zeroPlaceIndex=-1,nonZeroPlaceIndex=0,start_pointer=0;
while(start_pointer<=(size-1))
{
    // find zero -> only remember first zero..... -1 says zero not found before
  if(dataArray[start_pointer]==0 && zeroPlaceIndex ==-1)
        zeroPlaceIndex = start_pointer;
    else if(dataArray[start_pointer]!=0 && zeroPlaceIndex!=-1) // find non-zero when zero is already present
    {
        nonZeroPlaceIndex = start_pointer;
        swap(dataArray,zeroPlaceIndex,nonZeroPlaceIndex);
        start_pointer = zeroPlaceIndex;
        zeroPlaceIndex = -1; 
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
     int size=10,dataArray[10] = {0,0,0,0,0,0,0,0,0,2};
        sortZerosToRight(dataArray,size);
        printArray(dataArray,size);
   
}

