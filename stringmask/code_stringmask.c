#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char buff[1024];
    int len;
    const char *delim = " ";

    while (fgets(buff, 1024, file)) {
        len = strlen(buff)/2-1;

        int i;
        for(i=0;i<len;++i){
            buff[i] -= 32*(buff[i+len+1]-48);
        }
        
        printf("%s\n",strtok(buff,delim));
    }

    fclose(file);
    return 0;
}
