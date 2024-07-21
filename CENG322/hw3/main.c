#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

unsigned countNumOfElements(char* filename){
    FILE *file;
    file = fopen(filename, "r");
    unsigned count = 0;
    char c;
    do{
        c = fgetc(file);
        if (c == '\n') count++;
    }while(c != EOF);
    count--;
    return count;
}

unsigned* readNumbers(char* filename, unsigned num_element){
    FILE *file;
    file = fopen(filename, "r");
    int count = 0;
    char line[200];
    char *sp;
    char *sp2;
    char *ptr;
    unsigned* num_ary = (unsigned*)malloc(num_element * sizeof(unsigned));
    
    while(fgets(line, sizeof(line), file)){
        sp = strtok(line,",");
        if(strcmp("number_id",sp) != 0){
            sp2 = strtok(NULL, ",");
            unsigned number_id = strtoul(sp, &ptr, 10);
            unsigned number = strtoul(sp2, &ptr, 10);
            num_ary[number_id] = number;
        }
    }
    return num_ary;
}

int main() {
    unsigned count = countNumOfElements("numbers.csv");
    unsigned *num_ary = readNumbers("numbers.csv", count);
    for(int i = 0; i<count; i++){
        printf("%u\n", num_ary[i]);
        // sleep(1);
    }
    
    


}