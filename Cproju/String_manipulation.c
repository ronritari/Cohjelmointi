/***************************************************************************
 *   Copyright (C) 2009 by Jukka Matila,,,   *
 *   juma@subuntu   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
    String_manipulation

 2.  DESCRIPTION
    Asks a user in a loop for a command. Command manipulate given string s[].
    s[] can be manipuleted in the functions and the program will ask user for 
    command until command x. Command x will stop program.


 3.  VERSIONS
       Original:
         14.3.2022 Ron Ritari

       Version history:

**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
FILE *projekti6;

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void read_string(char s[]);
void print_string(char s[]);
int count_vowels(char s[]);
int count_consonants(char s[]);
void to_lower(char s[]);
void to_upper(char s[]);
void read_file(char s[]);
void write_file(char s[]);
void display_menu(void);
char ask_command(void);
/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
int main (void){

    char s[100]="Hello world";
    display_menu();

    char command='N';
    int numbers;  //helps int type virables in print vowels and consonants
    command=ask_command();
    while(command !='X'){   //loops until command variable is X
        switch (command){
            case 'M':
                display_menu();
                break;
            case 'A':
                numbers = count_vowels(s);
                printf("string has %d vowels\n",numbers);
                break;
            case 'B':
                numbers = count_consonants(s);
                printf("string has %d consonants\n",numbers);
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
/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: void read_string(char s[])
; DESCRIPTION:  This function will change our string s[] in to a 
;    new string. the maximum characters is 100 letters
;   input: Original string
;   Output: new string defined by user
;*********************************************************************/
void read_string(char s[]){
    printf("Give string:\n");
    fgets(s , 100, stdin);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: void print_string(char s[])
; DESCRIPTION:  Prints sting 
;	Input: string s[]
;	Output: none
;*********************************************************************/
void print_string(char s[]){
    printf("%s\n",s);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: int count_vowels(char s[])
; DESCRIPTION:  Checks if character at index i is any of the following vowels
;   for loop repeats until there isnt any more characters
;	Input: string s[]
;	Output: vowels variable
;  Used global variables: none
; REMARKS when using this function: 
;       this function will ignore spaces
;*********************************************************************/
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

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: int count_consonants(char s[])
; DESCRIPTION:  works the same way as count vowels but will do nothing 
;   and will add consonants at else
;	Input: Srting s[]
;	Output: Consonants integer
;  Used global variables: none
; REMARKS when using this function: 
;       returns consonants but it adds one integer too many. thats why -1
;*********************************************************************/
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

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: void to_lower(char s[])
; DESCRIPTION:  check if char at index i is ASCII number between 65 and 90
;   if it falls between these the int will be added 32 whitch will convert to lower
;	Input: Srting s[]
;	Output: none
;*********************************************************************/
void to_lower(char s[]){
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 65 && s[i]<= 90){
            s[i]=s[i]+32;
        }
    }
    printf("%s\n",s);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: void to_upper(char s[])
; DESCRIPTION:  check if char at index i is ASCII number between 97 and 122
;   if it falls between these the int will be reduced 32 whitch will convert to upper
;	Input: Srting s[]
;	Output: none
;  Used global variables: none
; 
;*********************************************************************/
void to_upper(char s[]){
    for(int i=0;s[i]!='\0';i++){      
        if(s[i] >= 97 && s[i]<= 122){   
            s[i]=s[i]-32;
        }
    }
    printf("%s\n",s);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: void read_file(char s[])
; DESCRIPTION:  reads form projekti6.txt file the string
;	Input: Srting s[]
;       
;*********************************************************************/
void read_file(char s[]){
    projekti6 = fopen("projekti6.txt", "r");    
    fgets(s, 100, projekti6);
    fclose(projekti6);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: void write_file(char s[])
; DESCRIPTION:  Writes to a txt file the current string s[]
;	Input: Srting s[]
;	Output: Number if its devidable by three, zero otherwise
;*********************************************************************/
void write_file(char s[]){
    projekti6 = fopen("projekti6.txt", "w");
    fprintf(projekti6, " %s\n",s);
    fclose(projekti6);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: void display_menu(void)
; DESCRIPTION:  Displays options to use in the switch case in main
;	Input: none
;	Output: 
;  Used global variables: 
;*********************************************************************/
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

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: char ask_command(void)
; DESCRIPTION:  asks user for an input and checks with if statement if
;   character is a lowercase to convert it to uppercase
;	Input: none
;	Output: Command
;  Used global variables: none
;*********************************************************************/
char ask_command(void){
    printf("Enter command: \n");
    char command[6];
    fgets(command , 6, stdin);
    if(command[0] >= 97 && command[0]<= 122){ 
        command[0]=command[0]-32;
    }
    return command[0];
}