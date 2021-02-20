#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Ispalindrome(char *s)
{
    int i=0, j = strlen(s) - 1 ;
    while(i<j&&s[i]==s[j])
    {
      i++;
      j--;
    }
    if(i<j)
    {
      printf("Not palindrome");
      printf("\n");
      return 0;
    }
    else
    {
      printf("palindrome");
      printf("\n");
      return 1;
    }
}
int main()
{
  int t,i;
  scanf("%d\n", &t);
  for(i=0;i<t;i++)
  {
    char s[10000];
    gets(s);

    printf("%d\n", Ispalindrome(s));
  }
  return 0;
}