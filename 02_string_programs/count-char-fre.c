#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[100];
    int freq[26] = {0};
    int i;
    int max_count = 0;
    char max_char = '\0';

    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin) == NULL)
        return 1;

    /* Remove trailing newline */
    str[strcspn(str, "\n")] = '\0';

    /* Check for empty string */
    if (str[0] == '\0')
    {
        printf("Empty string entered.\n");
        return 0;
    }

    /* Count frequency of each character */
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 'a' || str[i] > 'z')
        {
            printf("Please enter lowercase alphabets only.\n");
            return 1;
        }

        freq[str[i] - 'a']++;
    }

    /* Find the maximum occurring character */
    for (i = 0; i < 26; i++)
    {
        if (freq[i] > max_count)
        {
            max_count = freq[i];
            max_char = 'a' + i;
        }
    }

    printf("Maximum occurring character: %c\n", max_char);
    printf("Frequency: %d\n", max_count);

    return 0;
}
