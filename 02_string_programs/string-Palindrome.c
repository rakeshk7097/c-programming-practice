#include <stdio.h>
#include <string.h>


int main()
{
	char str[100] = "Madam";
	int i=0;
	int j=0;

	for(i=0,j=strlen(str)-1; i<=j; i++,j--) {
		if(str[i]!= str[j])
			break;
	}

	if(i>j)
		printf("** String is palindrome\n");
	else
		printf("** String is not palindrome\n");
}
