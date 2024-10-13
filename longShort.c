#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    //checkin that user supplys 3 arguments
    if(argc < 4){
        printf("Please supply 3 arguments.");
        exit(1);
    }
    //open first file 
    FILE *file1 = fopen(argv[1],"r");

    //checking if file1 was open to read
    if (file1 == NULL){
        printf("couldn't open %s for reading\n", argv[1]);
        exit(1);
    } 

    //open file2
    FILE *file2 = fopen(argv[2],"w");

    //checking if file2 was open to write
    if (file2 == NULL){
        printf("couldn't open %s for reading\n", argv[2]);
        exit(1);
    } 

    //open file3
    FILE *file3 = fopen(argv[3],"w");

    //checking if file3 was open to write
    if (file3 == NULL){
        printf("couldn't open %s for reading\n", argv[3]);
        exit(1);
    }

    int i = 0;
    char line[1000];
    int countforLong = 0;
    int countforShort = 0;
    
    while ( !feof(file1) ){
        
        fgets(line,1000,file1);

        if (strlen(&line[i]) > 20){
            for (int i = 0; line[i] != '\n' /*&& line[i] != '\0'*/; i++){
                line[i] = toupper(line[i]);
            }
            fprintf(file2, "%s",line);
            countforLong++;

        }
        else{
            fprintf(file3, "%s",line);
            countforShort++;
        }
    }
    printf("%d lines written to long.txt.\n",countforLong);
    printf("%d lines written to short.txt.\n",countforShort);
    fclose(file1);
    fclose(file2);
}