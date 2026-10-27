#include <stdio.h>
#include "speak.h"

void bark (void){
    printf("woof!\n");
}
void meow (void){
    printf("meow!\n");
}
void chirp (void){
    printf("chirp!\n");
}

int main(){
    Speak_Struct s1;
    Speak_Struct s2;
    int s1_op, s2_op;
    scanf("%d %d", &s1_op, &s2_op);
    if (s1_op == 1){
        s1.name = "bark";
        s1.spk_func = bark;
    }
    else if (s1_op == 2){
        s1.name = "meow";
        s1.spk_func = meow;
    }
    else if (s1_op == 3){
        s1.name = "chirp";
        s1.spk_func = chirp;
    }
    else return 1;

    if (s2_op == 1){
        s2.name = "bark";
        s2.spk_func = bark;
    }
    else if (s2_op == 2){
        s2.name = "meow";
        s2.spk_func = meow;
    }
    else if (s2_op == 3){
        s2.name = "chirp";
        s2.spk_func = chirp;
    }
    else return 1; 

    s1.spk_func();
    s2.spk_func();
    
    return 0;

}