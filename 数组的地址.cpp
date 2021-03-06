#include <stdio.h>
int main()
{
int a[5];
printf("%d\n", a);
printf("%d\n", &a);
printf("%d\n", &a[0]);
printf("%d\n", a + 1);
printf("%d\n", &a + 1);
printf("%d\n", &a[0] + 1);
printf("---------------\n");
printf("%d\n",sizeof(a));
printf("%d\n",sizeof(&a));
return 0;
}
