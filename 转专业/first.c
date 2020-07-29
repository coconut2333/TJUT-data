#include<stdio.h>
int main()
{
	int i,j;
	int arr[10];
	for(i=0;i<10;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<9;i++){
		for(j=0;j<9-i;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<10;i++){
		printf("%3d",arr[i]);
	}
	return 0;
} 
