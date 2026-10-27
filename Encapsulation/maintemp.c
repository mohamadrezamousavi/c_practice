#include <stdio.h>
#include "temperature.h"

int main(){
    int initial_temp, valid_temp;
    printf("Enter Initial Tempreture: ");
    scanf("%d", &initial_temp);
    printf("Enter Valid Tempreture:");
    scanf("%d", &valid_temp);
 
    Temperature *temp = create_temp(initial_temp);
    printf("Initial temp is: %d\n", temp_get_degrees(temp));
    int validatio_check;
    validatio_check = temp_set_degrees(temp,valid_temp);
    if (validatio_check == 0){
        printf("Invalid Temperature\n");
    }
    else {
        printf("valid Temperature: %d\n", temp_get_degrees(temp));
    }
    free_temp(temp);
    printf("memory freed\n");

}