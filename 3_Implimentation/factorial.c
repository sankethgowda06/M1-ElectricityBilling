#include<stdio.h>

int factorial(int number)
{
 int fact=1;
	if(number<0)	
    		return -1;
	else{
		for(int i=1;i<=number;i++)
			fact*=i;
		return fact;
}
}
int main() 
{
  int num = 0, N = 0;

  scanf("%d",&N);
  for(int i = 0; i< N; i++)
  {
    scanf("%d", &num);
    printf("%d\n",factorial(num));
  }
    
  return 0;
}
