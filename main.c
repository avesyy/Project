/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "lr.h"

int main()
{
    int variant;
    int add;
    printf("Xotite vibrat laby s dop.zadaniem ili obichnuyu?\n");
    printf("1 - Obichnaya\n2 - S dop.zadaniem.\n");
    scanf("%d", &add);
    if (add == 1){
    printf("Vedite nomer laby");
    scanf("%d", &variant);
    
    if(variant == 1){
        laba1();
    }
    else if(variant == 2){
        laba2();
    }
    else if(variant == 3){
        laba3();
    }
    
    else if(variant == 4){
        laba4();
    }
    else if(variant == 5){
        laba5();
    }
    else if(variant == 6){
        laba6();
    }
    else if(variant == 7){
        laba7();
    }
    else {
        
        printf("Такого варианта не существует.");
        
    }
    }
    else{
    printf("Vedite nomer laby");    
    scanf("%d", &variant);
    
    if(variant == 1){
        laba8();
    }
    else if(variant == 2){
        laba9();
    }
    else if(variant == 3){
        laba3();
    }
    
    else if(variant == 4){
        laba10();
    }
    else if(variant == 5){
        laba11();
    }
    else if(variant == 6){
        laba12();
    }
    else if(variant == 7){
        laba7();
    }
        
    }
    return 0;
}
    
