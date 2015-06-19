#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char row[1024];
    char *sample;
    int len;
    const char *delim = ",";

    while (fgets(row, 1024, file)) {
        int min_len;
        int CAV = 0;
        len = strlen(row);
        row[len-1] = '\0';

        char *start,*end;
        sample = strtok(row,delim);

        start = strchr(sample,'.');
        if( start != NULL ){
            end = strchr(sample,'Y');
            if (start<end){ min_len = end-start; }
            else { printf("0\n"); CAV = 1; }
            while((sample=strtok(NULL,delim))&&(!CAV)) {
                start = strchr(sample,'.'); if( start == NULL ){ min_len = 0; break; }
                end   = strchr(sample,'Y'); 
                if(start>end){ printf("0\n"); CAV = 1; }
                else{
                    if(min_len>(end-start)){ min_len = end-start; continue;}
                    else{ continue; }
                }
            }
            if(!CAV){ printf("%d\n",min_len); }
        }
        else{printf("0\n");}
    }
    fclose(file);
    return 0;
}
