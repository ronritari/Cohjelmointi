#include <stdio.h>
#include <stdlib.h>


FILE *projekti6;

//Function will print guide text (Give sing:) and read sing
void read_sing(char s[]){
printf("Give sing:\n");
fgets(s , 100, stdin);

}

//Function will print current sing
void print_sing(char s[]){
for(int i=0;s[i]!='\0';i++){
    printf("%c",s[i]);
}
printf("\n");
return 0;
}

//function that counts and returns the number of vowels in the sing. 5 vowels -- A, E, I, O, U, Y).
int count_vowels(char s[]){
int vowels = 0;
  
    int i=0;
    char ch=0;
    for (i = 0; s[i] != '\0'; i++) {
  
        ch = s[i];
        if (ch == 'a' || ch == 'e'|| ch == 'i' || ch == 'o'|| ch == 'u' || ch == 'A'|| ch == 'E' || ch == 'I'|| ch == 'O' || ch == 'U'){
            vowels++;
        }
        else if (ch == ' '){
            continue;
        }
    }
 
    return vowels;
}

//a function that counts and returns the number of consonants in the sing. Counting consonants might bi similar than counting vowel. There might be other alternative
int count_consonants(char s[]){
int consonants = 0;
  
    int i=0;
    char ch=0;
  
    for (i = 0; s[i] != '\0'; i++) {
  
        ch = s[i];
        if (ch == 'a' || ch == 'e'|| ch == 'i' || ch == 'o'|| ch == 'u' || ch == 'A'|| ch == 'E' || ch == 'I'|| ch == 'O' || ch == 'U'){
            
        }
        else if (ch == ' '){
            continue;
        }
        else{
            consonants++;
        }
    } 
return consonants;
}

//a function that converts the sing to all lowercase.
void to_lower(char s[]){
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 65 && s[i]<= 90){
            s[i]=s[i]+32;
        }
    }
    for(int i=0;s[i]!='\0';i++){
        printf("%c",s[i]);
    }
printf("\n");
}

//a function that converts the sing to all uppercase.
void to_upper(char s[]){
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 97 && s[i]<= 122){
            s[i]=s[i]-32;
        }
    }
    for(int i=0;s[i]!='\0';i++){
        printf("%c",s[i]);
    }
printf("\n");
}
//Read the sing from file. Filename may be hard coded in function tee vikana
void read_file(char s[]){
projekti6 = fopen("projekti6.txt", "r");
fgets(s, 100, projekti6);
fclose(projekti6);
}
//Save sing to file ei vielä toimi viimene
void write_file(char s[]){
projekti6 = fopen("projekti6.txt", "w");
fprintf(projekti6, " %s\n",s);
fclose(projekti6);
}
//displays menu
void display_menu(void){
printf("A)  Count the number of vowels in the sing \n");
printf("B)  Count the number of consonants in the sing \n");
printf("C)  Convert the sing to uppercase \n");
printf("D)  Convert the sing to lowercase \n");
printf("E)  Display the current sing \n");
printf("F)  Enter another sing \n");
printf("G)  Read sing from file \n");
printf("H)  Write sing to file\n \n");

printf("M)  Display this menu \n");
printf("X)  Exit the program \n");
}
//kysyy komentoa switch a-h ja x lopettaa m=display_menu
char ask_command(void){
printf("Enter command: \n");
char c[6];
fgets(c , 6, stdin);
if(c[0] >= 97 && c[0]<= 122){
    c[0]=c[0]-32;
}
return c[0];
}

//main 
int main (void){

char s[100]="Hello world";
display_menu();

char i='N';
int *x;
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
        x = count_vowels(s);
        printf("string has %d vowels\n",x);
        break;
    case 'B':
        x = count_consonants(s);
        printf("string has %d consonants\n",x);
        break;
    case 'C':
        to_upper(s);
        break;
    case 'D':
        to_lower(s);
        break;
    case 'E':
        print_sing(s);
        break;
    case 'F':
        read_sing(s);
        break;
    case 'G':
        read_file(s);
        break;
    case 'H':
        write_file(s);
        break;
    
    default:
        printf("error\nTry again\n");
        break;
    }
    i=ask_command();
}
return 0;
}