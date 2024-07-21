// Onur Altug Akca 260201060
// Fatih Kircicek 260201016

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct NormalMenu {
    char date[30];
    char soup[30];
    char main_dish[30];
    char side_dish[30];
    char extra[30];
    int count_ary[3];
}NormalMenu;

typedef struct VeganMenu {
    char date[30];
    char soup[30];
    char main_dish[30];
    char side_dish[30];
    char extra[30];
    int count_ary[3];
}VeganMenu;

typedef struct VegetarianMenu {
    char date[30];
    char soup[30];
    char main_dish[30];
    char side_dish[30];
    char extra[30];
    int count_ary[3];
}VegetarianMenu;

typedef struct Cafeteria {
    char month[30];
    NormalMenu *normal_menu_array;
    VeganMenu *vegan_menu_array;
    VegetarianMenu *vegetarian_menu_array;
}Cafeteria;

int line_count;

void line_counter(char *csv_file_name){
    FILE *file;
    file = fopen("cafeteria_march_menu.csv","r");
    if(file==NULL){
        printf("Error");
    }
    char line[500];
    int x = 0;
    while(fgets(line,100,file) != NULL){
        x++;
    }
    line_count = x;

}

void print_menus(Cafeteria *cafeteria){
    printf("---Normal Menu for the last and first days of the month---\n");
    printf("Date: %s\nSoup: %s\nMain Dish: %s\nSide Dish: %s\nExtra: %s\n", cafeteria->normal_menu_array[0].date, cafeteria->normal_menu_array[0].soup, cafeteria->normal_menu_array[0].main_dish, cafeteria->normal_menu_array[0].side_dish, cafeteria->normal_menu_array[0].extra);
    printf("Date: %s\nSoup: %s\nMain Dish: %s\nSide Dish: %s\nExtra: %s\n", cafeteria->normal_menu_array[(line_count/3)-1].date, cafeteria->normal_menu_array[(line_count/3)-1].soup, cafeteria->normal_menu_array[(line_count/3)-1].main_dish, cafeteria->normal_menu_array[(line_count/3)-1].side_dish, cafeteria->normal_menu_array[(line_count/3)-1].extra);
    
    printf("---Vegan Menu for the last and first days of the month---\n");
    printf("Date: %s\nSoup: %s\nMain Dish: %s\nSide Dish: %s\nExtra: %s\n", cafeteria->vegan_menu_array[0].date, cafeteria->vegan_menu_array[0].soup, cafeteria->vegan_menu_array[0].main_dish, cafeteria->vegan_menu_array[0].side_dish, cafeteria->vegan_menu_array[0].extra);
    printf("Date: %s\nSoup: %s\nMain Dish: %s\nSide Dish: %s\nExtra: %s\n", cafeteria->vegan_menu_array[(line_count/3)-1].date, cafeteria->vegan_menu_array[(line_count/3)-1].soup, cafeteria->vegan_menu_array[(line_count/3)-1].main_dish, cafeteria->vegan_menu_array[(line_count/3)-1].side_dish, cafeteria->vegan_menu_array[(line_count/3)-1].extra);
    
    printf("---Vegetarian Menu for the last and first days of the month---\n");
    printf("Date: %s\nSoup: %s\nMain Dish: %s\nSide Dish: %s\nExtra: %s\n", cafeteria->vegetarian_menu_array[0].date, cafeteria->vegetarian_menu_array[0].soup, cafeteria->vegetarian_menu_array[0].main_dish, cafeteria->vegetarian_menu_array[0].side_dish, cafeteria->vegetarian_menu_array[0].extra);
    printf("Date: %s\nSoup: %s\nMain Dish: %s\nSide Dish: %s\nExtra: %s\n", cafeteria->vegetarian_menu_array[(line_count/3)-1].date, cafeteria->vegetarian_menu_array[(line_count/3)-1].soup, cafeteria->vegetarian_menu_array[(line_count/3)-1].main_dish, cafeteria->vegetarian_menu_array[(line_count/3)-1].side_dish, cafeteria->vegetarian_menu_array[(line_count/3)-1].extra);
    
    printf("Example output for normal menu ==> %s|%s|%s|%s|%s", cafeteria->normal_menu_array[5].date, cafeteria->normal_menu_array[5].soup, cafeteria->normal_menu_array[5].main_dish, cafeteria->normal_menu_array[5].side_dish, cafeteria->normal_menu_array[5].extra);
    printf("Example output for vegan menu ==> %s|%s|%s|%s|%s", cafeteria->vegan_menu_array[10].date, cafeteria->vegan_menu_array[10].soup, cafeteria->vegan_menu_array[10].main_dish, cafeteria->vegan_menu_array[10].side_dish, cafeteria->vegan_menu_array[10].extra);
    printf("Example output for vegetraian menu ==> %s|%s|%s|%s|%s\n", cafeteria->vegetarian_menu_array[15].date, cafeteria->vegetarian_menu_array[15].soup, cafeteria->vegetarian_menu_array[15].main_dish, cafeteria->vegetarian_menu_array[15].side_dish, cafeteria->vegetarian_menu_array[15].extra);
    
    printf("Counts for the example of normal menu output of %s ==> Student: %d, Academic: %d, Administrative: %d\n", cafeteria->normal_menu_array[5].date, cafeteria->normal_menu_array[5].count_ary[0], cafeteria->normal_menu_array[5].count_ary[1], cafeteria->normal_menu_array[5].count_ary[2]);
    printf("Counts for the example of vegan menu output of %s ==> Student: %d, Academic: %d, Administrative: %d\n", cafeteria->vegan_menu_array[10].date, cafeteria->vegan_menu_array[10].count_ary[0], cafeteria->vegan_menu_array[10].count_ary[1], cafeteria->vegan_menu_array[5].count_ary[2]);
    printf("Counts for the example of vegetarian menu output of %s ==> Student: %d, Academic: %d, Administrative: %d\n", cafeteria->vegetarian_menu_array[15].date, cafeteria->vegetarian_menu_array[15].count_ary[0], cafeteria->vegetarian_menu_array[15].count_ary[1], cafeteria->vegetarian_menu_array[15].count_ary[2]);

}

char* remove_quotes(char* s1) {
    size_t len = strlen(s1);
    if (s1[0] == '"' && s1[len - 1] == '"') {
        s1[len - 1] = '\0';
        memmove(s1, s1 + 1, len - 1);
    }
    return s1;
}
void calc_and_show_income(Cafeteria *cafeteria){
    int student = 6;
    int academic = 16;
    int administration = 12;
    int normal_menu_sales = 0;
    int vegan_menu_sales = 0;
    int vegetarian_menu_sales = 0;
    int student_sales = 0;
    int academic_sales = 0;
    int administration_sales = 0;

    for(int i = 0; i < line_count/3; i++){
        normal_menu_sales = (cafeteria->normal_menu_array[i].count_ary[0]*student) + normal_menu_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        normal_menu_sales = (cafeteria->normal_menu_array[i].count_ary[1]*academic) + normal_menu_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        normal_menu_sales = (cafeteria->normal_menu_array[i].count_ary[2]*administration) + normal_menu_sales;
    }

    for(int i = 0; i < line_count/3; i++){
        vegan_menu_sales = (cafeteria->vegan_menu_array[i].count_ary[0]*student) + vegan_menu_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        vegan_menu_sales = (cafeteria->vegan_menu_array[i].count_ary[1]*academic) + vegan_menu_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        vegan_menu_sales = (cafeteria->vegan_menu_array[i].count_ary[2]*administration) + vegan_menu_sales;
    }

    for(int i = 0; i < line_count/3; i++){
        vegetarian_menu_sales = (cafeteria->vegetarian_menu_array[i].count_ary[0]*student) + vegetarian_menu_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        vegetarian_menu_sales = (cafeteria->vegetarian_menu_array[i].count_ary[1]*academic) + vegetarian_menu_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        vegetarian_menu_sales = (cafeteria->vegetarian_menu_array[i].count_ary[2]*administration) + vegetarian_menu_sales;
    }

    for(int i = 0; i < line_count/3; i++){
        student_sales = (cafeteria->normal_menu_array[i].count_ary[0]*student) + student_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        student_sales = (cafeteria->vegan_menu_array[i].count_ary[0]*student) + student_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        student_sales = (cafeteria->vegetarian_menu_array[i].count_ary[0]*student) + student_sales;
    }

    for(int i = 0; i < line_count/3; i++){
        academic_sales = (cafeteria->normal_menu_array[i].count_ary[1]*academic) + academic_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        academic_sales = (cafeteria->vegan_menu_array[i].count_ary[1]*academic) + academic_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        academic_sales = (cafeteria->vegetarian_menu_array[i].count_ary[1]*academic) + academic_sales;
    }

    for(int i = 0; i < line_count/3; i++){
        administration_sales = (cafeteria->normal_menu_array[i].count_ary[2]*administration) + administration_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        administration_sales = (cafeteria->vegan_menu_array[i].count_ary[2]*administration) + administration_sales;
    }
    for(int i = 0; i < line_count/3; i++){
        administration_sales = (cafeteria->vegetarian_menu_array[i].count_ary[2]*administration) + administration_sales;
    }

    int total_people = 0;
    int total_menu = 0;
    total_people = student_sales + academic_sales + administration_sales;
    total_menu = normal_menu_sales + vegan_menu_sales + vegetarian_menu_sales;

    printf("\n****** The Sale Results *****\n");
    printf("Normal Menu Sales: %d, Vegan Menu Sales: %d, Vegetarian Menu Sales: %d\n", normal_menu_sales, vegan_menu_sales, vegetarian_menu_sales);
    printf("Student Sales: %d, Academic Personal Sales: %d, Administrative Personal Sales: %d\n", student_sales, academic_sales, administration_sales);
    printf("Total Sale Income: %d\n", total_menu);
}

void record_customers(Cafeteria *cafeteria){
    srand(time(NULL));
    for(int i = 0; i < line_count/3; i++){
        for(int j = 0; j < 3; j++){
            int random_number = rand() % 51;
            cafeteria->normal_menu_array[i].count_ary[j] = random_number;
        }
    }
    for(int i = 0; i < line_count/3; i++){
        for(int j = 0; j < 3; j++){
            int random_number = rand() % 51;
            cafeteria->vegan_menu_array[i].count_ary[j] = random_number;
        }
    }
    for(int i = 0; i < line_count/3; i++){
        for(int j = 0; j < 3; j++){
            int random_number = rand() % 51;
            cafeteria->vegetarian_menu_array[i].count_ary[j] = random_number;
        }
    }

}

void initialize_menus(Cafeteria *cafeteria, char *csv_file_name){
    cafeteria->normal_menu_array =  (NormalMenu*)malloc(sizeof(NormalMenu)*line_count/3);
    cafeteria->vegan_menu_array = (VeganMenu*)malloc(sizeof(VeganMenu)*line_count/3);
    cafeteria->vegetarian_menu_array = (VegetarianMenu*)malloc(sizeof(VegetarianMenu)*line_count/3);
    FILE *file;
    file = fopen(csv_file_name,"r");
    if(file==NULL){
        printf("Error");
    }
    char line[500];
    char *sp;
    int i = 0;
    int j = 0;
    int k = 0;
    while(fgets(line,100,file) != NULL){

        sp = strtok(line, ",");
        sp = remove_quotes(sp);

        if(strcmp("Normal",sp) == 0){
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->normal_menu_array[i].date, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->normal_menu_array[i].soup, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->normal_menu_array[i].main_dish, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->normal_menu_array[i].side_dish, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->normal_menu_array[i].extra, sp);
            i++;
        }
        else if(strcmp("Vegan", sp) == 0){
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegan_menu_array[j].date, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegan_menu_array[j].soup, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegan_menu_array[j].main_dish, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegan_menu_array[j].side_dish, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegan_menu_array[j].extra, sp);
            j++;
        }
        else if(strcmp("Vegetarian", sp) == 0){
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegetarian_menu_array[k].date, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegetarian_menu_array[k].soup, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegetarian_menu_array[k].main_dish, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegetarian_menu_array[k].side_dish, sp);
            sp = strtok(NULL,",");
            sp = remove_quotes(sp);
            strcpy(cafeteria->vegetarian_menu_array[k].extra, sp);
            k++;
        } 
    }   
}
int main() {
    Cafeteria *cafeteria = (Cafeteria*)malloc(sizeof(Cafeteria));
    char filename[] = "cafeteria_march_menu.csv";
    line_counter(filename);
    initialize_menus(cafeteria,filename);
    record_customers(cafeteria);
    print_menus(cafeteria);
    calc_and_show_income(cafeteria);
}