#include <stdio.h>
#include <string.h>
//#include <regex.h>

#define MAX_LEN 100

int main(void)
{
    FILE *file;
    char row[MAX_LEN];
    char *sample;
    int len;
    const char *delim = ",";

    // Related to regular expression
    /*
    regx_t reg;
    int cflags = REG_NEWLINE;
    const char *pattern="X\.*?Y";
    regcomp(&reg,pattern);
    regmatch_t pmatch[1];
    const size_t nmatch = 1;
    */

    file = fopen("input.txt", "r");

    while(fgets(row,MAX_LEN,file)!=NULL) {
        int min_len;
        len = strlen(row);
        row[len-1] = '\0';
            
        //if (!regexec(&reg,strtok(row,delim),nmatch,pmatch,0)) {
        //}

        char *start,*end;
        sample = strtok(row,delim);
        //printf("%s\n",sample);

        start = strchr(sample,'.');
        if( start != NULL ){
            end = strchr(sample,'Y'); 
            //min_len = (end-start)/(sizeof(char));
            min_len = end-start;
            while((sample=strtok(NULL,delim))) {
                //printf("%s\n",sample);
                start = strchr(sample,'.'); if( start == NULL ){ min_len = 0; break; }
                end   = strchr(sample,'Y');   
                if(min_len>(end-start)){ min_len = end-start; continue;}
                else{ continue; }
            }           
            printf("%d\n",min_len);
        }
        else{printf("0\n");}
    }

    //regfree(&reg);
    fclose(file);
    return 0;
}
