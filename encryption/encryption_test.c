#include <stdio.h>
#include <stdlib.h>
//#define N 40
void encryption(char name[],int password);
unsigned short int temp[20];
unsigned short int tem;
int password;
int main()
{
    char filename[20];
    puts("Hello!\nPlease enter the file name and "
         "password that you want to encrypt:");
    scanf("%s%d",filename,&password);
    encryption(filename,password);
    return 0;
}

void encryption(char name[20],int password)
{
    FILE *in,*out;
    long length=0;
    int i;
    while((in=fopen(name,"rb"))==NULL)
    {
        printf("open fail!");
        exit(0);
    }
    #if 1
    while((out=fopen("be_encryption.md","wb+"))==NULL)
    {
        printf("open fail!");
        exit(0);
    }
    #endif
    //printf("here is fine\n");
    for(i=0;i<10;i++)
    {
        fread(&temp[i],sizeof(unsigned short int),1,in);
        temp[i]^=password;
        fwrite(&temp[i],sizeof(unsigned short int),1,out);
    }
    //printf("here is fine\n");
    fseek(in,0,2);
    length=ftell(in);
#if 0
    fclose(in);
    out=fopen("be_encryption.md","wb");
    in=fopen(name,"rb");
//#endif
    for(i=0;i<10;i++)
        fwrite(&temp[i],sizeof(unsigned short int),1,out);
    //printf("here is fine\n");
#endif
    fseek(in,20,0);
    while(i<length/2)
    {
        fread(&tem,sizeof(unsigned short int),1,in);
        fwrite(&tem,sizeof(unsigned short int),1,out);
        i++;
    }
    printf("Please remember your password,bye!");
    fclose(in);
    fclose(out);
}
