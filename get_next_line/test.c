

// C Program to illustrate the static variable lifetime
#include <stdio.h>
 
// function with static variable
int fun()
{
    static int count = 0;
	if (count < 5)
    	count++;
	// count = 5;
    return count;
}
 
int main()
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d \n", fun());
	}
    printf("%d ", fun());
    printf("%d ", fun());
    return 0;
}
