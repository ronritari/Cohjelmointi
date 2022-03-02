#include <stdio.h>
#include <stdlib.h>


FILE *projekti6;

//Function will print guide text (Give string:) and read string
void read_string(char s[]){
    printf("Give string:\n");
    fgets(s , 100, stdin);
}

//Function will print current string
void print_string(char s[]){
    printf("%s\n",s);
}

//function that counts and returns the number of vowels in the string. 5 vowels -- A, E, I, O, U, Y).
int count_vowels(char s[]){
    int vowels = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e'|| s[i] == 'i' || s[i] == 'o'|| s[i] == 'u' || s[i] == 'A'|| s[i] == 'E' || s[i] == 'I'|| s[i] == 'O' || s[i] == 'U'){
            vowels++;
        }
        else if (s[i] == ' '){
            continue;   //jumps to next char
        }
    }
 
    return vowels;
}

//a function that counts and returns the number of consonants in the string. 
int count_consonants(char s[]){
    int consonants = 0;
  
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'e'|| s[i] == 'i' || s[i] == 'o'|| s[i] == 'u' || s[i] == 'A'|| s[i] == 'E' || s[i] == 'I'|| s[i] == 'O' || s[i] == 'U'){
            //does nothing
        }
        else if (s[i] == ' '){
            continue;
        }
        else{
            consonants++;
        }
    } 
    return consonants-1;    //for some reason adds one consonant too many
}

//a function that converts the string to all lowercase.
void to_lower(char s[]){
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 65 && s[i]<= 90){
            s[i]=s[i]+32;
        }
    }
    printf("%s\n",s);
}

//a function that converts the string to all uppercase.
void to_upper(char s[]){
    for(int i=0;s[i]!='\0';i++){      //checks every letter
        if(s[i] >= 97 && s[i]<= 122){   //checks between these numbers in ASCII chart
            s[i]=s[i]-32;
        }
    }

    printf("%s\n",s);
}

//Read the string from file. Filename may be hard coded 
void read_file(char s[]){
    projekti6 = fopen("projekti6.txt", "r");    
    fgets(s, 100, projekti6);
    fclose(projekti6);
}

//Save string to file 
void write_file(char s[]){
    projekti6 = fopen("projekti6.txt", "w");
    fprintf(projekti6, " %s\n",s);
    fclose(projekti6);
}

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

//asks command. changes letter to uppercase if needed
char ask_command(void){
    printf("Enter command: \n");
    char command[6];
    fgets(command , 6, stdin);

    if(command[0] >= 97 && command[0]<= 122){   //converts to uppercase
        command[0]=command[0]-32;
    }
    return command[0];
}

//main 
int main (void){

    char s[100]="Hello world";
    display_menu();

    char command='N';
    int x;  //helps int type virables in print vowels and consonants
    command=ask_command();
    while(command !='X'){   //loops until command variable is X
        switch (command){
            case 'M':
                display_menu();
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
                print_string(s);
                break;
            case 'F':
                read_string(s);
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
        command=ask_command();
    }
    return 0;
}