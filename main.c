#include <stdio.h>
#include <stdlib.h>
#define SINE 40
int main()
{
    char words[SINE];
    FILE *in=fopen("in.txt","r");
    FILE *out=fopen("out","w");
    while(fscanf(in,"%s",words)==1)
    {
        printf("%s",words);
        fprintf(out,"%s",words);
    }
    fclose(in);
    fclose(out);
    return 0;
}
