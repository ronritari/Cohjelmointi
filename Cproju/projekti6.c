#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//FILE *projekti6;
/*
//Function will print guide text (Give string:) and read string
void read_string(char s[]){

}

//Function will print current string
void print_string(char s[]){

}

//function that counts and returns the number of vowels in the string. (For the purposes of this exercise, we are talking about the standard 5 vowels -- A, E, I, O, U, Y).
int count_vowels(char s[]){

}

//a function that counts and returns the number of consonants in the string. Counting consonants might bi similar than counting vowel. There might be other alternative
int count_consonants(char s[]){

}

//a function that converts the string to all lowercase.
void to_lower(char s[]){

}

//a function that converts the string to all uppercase.
void to_upper(char s[]){

}
//Read the string from file. Filename may be hard coded in function tee vikana
void read_file(char s[]){
int variable;
projekti6 = fopen("another_file.txt", "r");
fscanf(projekti6, "%d",&variable);
fclose(projekti6);
}
//Save string to file ei vielä toimi viimene
void write_file(char s[]){
int variable;
projekti6 = fopen("filename.txt", "w");
fprintf(projekti6, "Normal print statement with variables %d\n",variable);
fclose(projekti6);
}*/
//displays menu
void display_menu(void){
printf("A)  Count the number of vowels in the string \n");
printf("B)  Count the number of consonants in the string \n");
printf("C)  Convert the string to uppercase \n");
printf("D)  Convert the string to lowercase \n");
printf("E)  Display the current string \n");
printf("F)  Enter another string \n");
printf("G) Read string from file \n");
printf("H) Write string to file\n \n");

printf("M) Display this menu \n");
printf("X) Exit the program \n");
}
//kysyy komentoa switch a-h ja x lopettaa m=display_menu
char ask_command(void){
printf("Enter command: \n");
char *c;
scanf(" %c",&c);
return c;
}

//main 
int main (void){
char s[100]="Hello world";
display_menu();

int l=0;
while(l<1){
    char i='N';
    *i=ask_command();
    printf("%c ",i);
    switch (i)
    {
    case 'M':
        display_menu();
        break;
    case 'X':
        l++;
        break;
    
    default:
        break;
    }
}

}