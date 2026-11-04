# Goal is to remove characters from the first string that are present in the second string

#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[100];
    char s2[100];
    int present[26] = {0};
    int i, j = 0;

    printf("Enter first string: ");

    if (fgets(s1, sizeof(s1), stdin) == NULL)
        return 1;

    printf("Enter second string: ");

    if (fgets(s2, sizeof(s2), stdin) == NULL)
        return 1;

    /* Remove trailing newlines */
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    /* Mark characters present in s2 */
    for (i = 0; s2[i] != '\0'; i++)
    {
        if (s2[i] < 'a' || s2[i] > 'z')
        {
            printf("Only lowercase alphabets are allowed.\n");
            return 1;
        }

        present[s2[i] - 'a'] = 1;
    }

    /* Remove characters from s1 that exist in s2 */
    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] < 'a' || s1[i] > 'z')
        {
            printf("Only lowercase alphabets are allowed.\n");
            return 1;
        }

        if (present[s1[i] - 'a'] == 0)
        {
            s1[j] = s1[i];
            j++;
        }
    }

    /* Terminate the resultant string */
    s1[j] = '\0';

    printf("Resultant string: %s\n", s1);

    return 0;
}
