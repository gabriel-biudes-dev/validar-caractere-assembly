#include <stdio.h>
#include <stdlib.h>

char x = 'r';
int isUpperC;

int main() {
  asm(".intel_syntax noprefix       \n\
        movzx eax, BYTE PTR x       \n\
        cmp al, 'a'                 \n\
        setne cl                    \n\
        cmp al, 'e'                 \n\
        setne ch                    \n\
        and cl, ch                  \n\
        cmp al, 'i'                 \n\
        setne ch                    \n\
        and cl, ch                  \n\
        cmp al, 'o'                 \n\
        setne ch                    \n\
        and cl, ch                  \n\
        cmp al, 'u'                 \n\
        setne ch                    \n\
        and cl, ch                  \n\
        cmp al, 97                  \n\
        setge ch                    \n\
        and cl, ch                  \n\
        cmp al, 122                 \n\
        setle ch                    \n\
        and cl, ch                  \n\
        movzx ecx, cl               \n\
        mov isUpperC, ecx           \n\
        .att_syntax prefix          \n");
  printf("%d\n", isUpperC);
  return 0;
}
