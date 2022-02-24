#include <stdio.h>
#include <stdlib.h>


//FILE *projekti6;

//Function will print guide text (Give string:) and read string
void read_string(char s[]){

}

//Function will print current string
void print_string(char s[]){
for(int i=0;s[i]!='\0';i++){
    printf("%s",s[i]);
}
return 0;
}

//function that counts and returns the number of vowels in the string. 5 vowels -- A, E, I, O, U, Y).
int count_vowels(char s[]){
int counter;
for(int i=0;s[i]!='\0';i++){
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y'){
        counter++;
    }
}
return counter;
}

//a function that counts and returns the number of consonants in the string. Counting consonants might bi similar than counting vowel. There might be other alternative
int count_consonants(char s[]){
int counter;
for(int i=0;s[i]!='\0';i++){
    if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y'){
        
    }else{
        counter++;
    }
}
return counter;
}

//a function that converts the string to all lowercase.
void to_lower(char s[]){
for(int i=0;s[i]!='\0';i++){
    if(s[i] >= 97 && s[i]<= 122){
        s[i]=s[i]-32;
    }
}
}

//a function that converts the string to all uppercase.
void to_upper(char s[]){
for(int i=0;s[i]!='\0';i++){
    if(s[i] >= 65 && s[i]<= 90){
        s[i]=s[i]+32;
    }
}
for(int i=0;s[i]!='\0';i++){
    printf("%s",s[i]);
}
printf("\n");

}/*
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
printf("G)  Read string from file \n");
printf("H)  Write string to file\n \n");

printf("M)  Display this menu \n");
printf("X)  Exit the program \n");
}
//kysyy komentoa switch a-h ja x lopettaa m=display_menu
char ask_command(void){
printf("Enter command: \n");
char c;
scanf(" %c",&c);
if(c >= 97 && c<= 122){
    c=c-32;
}
return c;
}

//main 
int main (void){
char s[100]="Hello world";
display_menu();

char i='N';
i=ask_command();
while(i!='X'){

    switch (i)
    {
    case 'M':
        display_menu();
        break;
    case 'X':
        
        break;
    case 'A':
        int count_vowels(char s[]);
        printf("%d\n",count_vowels);
        break;
    case 'B':
        int x = count_consonants(char s[]);
        printf("%d\n",x);
        break;
    case 'C':
        
        break;
    case 'D':
        
        break;
    case 'E':
        void print_string(char s[]);
        break;
    case 'F':
        
        break;
    case 'G':
        
        break;
    case 'H':
        
        break;
    
    default:
        printf("error\nTry again\n");
        break;
    }
    i=ask_command();
}
return 0;
}