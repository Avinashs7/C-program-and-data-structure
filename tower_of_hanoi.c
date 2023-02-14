#include<stdio.h>
void tower_of_hanoi(int n,char S,char T,char D)
{
	if(n==0)
	return;
	tower_of_hanoi(n-1,S,D,T);
	printf("Move disc %d from %c to %c\n",n,S,D);
	tower_of_hanoi(n-1,T,S,D);
}
int main()
{
	int n;
	printf("Enter number of discs\n");
	scanf("%d",&n);
	printf("Assume your source rod is 'A'\n temporary rod is 'B'\ndestination rod is 'C'\n");
	tower_of_hanoi(n,'A','B','C');
}
