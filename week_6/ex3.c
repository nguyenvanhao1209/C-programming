#include<stdio.h>
#include<stdlib.h>
void search( int key,int r[], int n ) {
	int i,j;
	int tempr;
	for ( i=0; i<n; i++ )
		if ( key == r[i] ) {
			tempr = r[i];
			 for (j=i-1; j>=0; j--)
				r[j+1]=r[j];
			 r[0]=tempr;
		}
	for(i=0;i<n;i++){
		printf("%d ",r[i]);
	}	 
}
int main(){
	int a[10];
	int i;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	int b;
	scanf("%d",&b);
	search(b,a,10);	
	return 0;
}
