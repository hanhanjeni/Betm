#include <stdio.h>
#include <stdlib.h>
//#define N 40
unsigned short int temp[20];
unsigned short int tem;
int i,password;
long length;
void decryption(int password)
{
    FILE *in,*out;
    while((out=fopen("be_encryption.md","rb"))==NULL)
    {
        printf("fail open");
        exit(0);
    }
    while((in=fopen("be_decryption.md","wb"))==NULL)
    {
        printf("fail open");
        exit(0);
    }
    fseek(out,0,2);
    length=ftell(out);
    rewind(out);
    for(i=0;i<10;i++)
    {
        fread(&temp[i],sizeof(unsigned short int),1,out);
        temp[i]^=password;
        fwrite(&temp[i],sizeof(unsigned short int),1,in);
    }
#if 0
    for(i=0;i<10;i++)
        fwrite(&temp[i],sizeof(unsigned short int),1,in);
#endif
    fseek(out,20,0);
    i=0;
#if 1
    while(i<length/2)
    {
        fread(&tem,sizeof(unsigned short int),1,out);
        fwrite(&tem,sizeof(unsigned short int),1,in);
        i++;
    }
#endif
    printf("Have a good day,bye!");
    fclose(in);
    fclose(out);
}

int main()
{
    puts("Please enter your password");
    scanf("%d",&password);
    decryption(password);
    return 0;
}
