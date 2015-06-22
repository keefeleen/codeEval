#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[]){
    FILE *file = fopen(argv[1], "r");
    char buff[1024];
    char row_buff[225][5];
    int  matrix[15][15];
    const char *delim = " |";

    while(fgets(buff,1024,file)){
        int _ctr = 0;
        int _dim;
        char *_ptr;
        int i,j;

        // Processing the first row
        _ptr = strtok(buff,delim);
        strcpy(row_buff[_ctr],_ptr);
        _ctr += 1;

        while((_ptr = strtok(NULL,delim))){
            strcpy(row_buff[_ctr],_ptr);
            _ctr += 1;   
        } 

        _dim = sqrt(_ctr);
        
        for(i=0;i<_ctr;++i){
            matrix[i/_dim][i%_dim] = atoi(row_buff[i]);
        }

        for(i=0;i<_dim;++i){
            for(j=0;j<_dim;++j){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    fclose(file);
    return 0;
} 
