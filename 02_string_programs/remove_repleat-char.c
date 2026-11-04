#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    int visited[256] = {0};
    int i, j = 0;

    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin) == NULL)
        return 1;

    /* Remove trailing newline */
    str[strcspn(str, "\n")] = '\0';

    /* Traverse the string */
    for (i = 0; str[i] != '\0'; i++)
    {
        unsigned char ch = (unsigned char)str[i];

        if (visited[ch] == 0)
        {
            visited[ch] = 1;
            str[j] = str[i];
            j++;
        }
    }

    /* Terminate the resultant string */
    str[j] = '\0';

    printf("String after removing duplicates: %s\n", str);

    return 0;
}
