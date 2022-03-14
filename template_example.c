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
*
* 1.  NAME
*     divide_by_three.c
*
* 2.  DESCRIPTION
*     ask numbers from user, and calculate together all numbers that are 
*     dividable by three
*
* 3.  VERSIONS
*       Original:
*         1.1.2009 / juma
*
*       Version history:
*       $Log$
*
**********************************************************************/

/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES                                                *
*--------------------------------------------------------------------*/
/* Control flags */
#define DEBUG

/* Globaal constants */

/* Globaal variables */

/* Globaal structures */

/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
int divided_by_three(int number_to_be_divided);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/


int main(void)
{
  int i=0,numer_asked_from_user,sum=0;

/* ask numbers from user, zero or negative number will end it */ 
do
  {
    printf("Give positive integer, zero will stop!");
    scanf("%d",&numer_asked_from_user);
    sum=sum+divided_by_three(numer_asked_from_user); /* add, what ever the subfunction is returning, to sum*/
    i++;
  }
 while(numer_asked_from_user>0);

/* Finally printing out the results */

 printf("Sum of numbers, that were dividable by three, was %d\n", sum);
 printf("Total amount of entered numbers was %d\n",i );
 printf("Bye bye, for now");
 return 0;


} /* end of main */


/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME:
; DESCRIPTION:  check if number given by parameter is dividable by three 
;	Input: Number to be checked
;	Output: Number if its devidable by three, zero otherwise
;  Used global variables: none
; REMARKS when using this function: 
;       This will work also with negative numbers
;*********************************************************************/

int divided_by_three(int numer_to_be_divided)
{
 /* check if number is dividable by three */ 
  if (numer_to_be_divided%3==0)
    {
      return numer_to_be_divided;
    }
/* if not return zero*/
return 0;
} /* end of divided_by_three*/

