/*
This challenge demonstrates the powerful combination of enum and typedef working together.
The typedef creates a clean, readable type name Shape instead of repeatedly writing enum ShapeType. 
The enum constants make the switch statements self-documenting, clearly showing what each case represents. 
You'll practice defining both concepts, using them in function parameters, 
and implementing logic that depends on the enum values.

*/

#include <stdio.h>



typedef enum ShapeType{
    CIRCLE,
    RECTANGLE,
    TRIANGLE
} Shape;

float calculateArea(Shape name, float d1, float d2){
    float area;
    switch (name)
    {
    case CIRCLE:
        area = 3.14159 * d1;
        break;
    case RECTANGLE:
        area = d1 * d2;
        break;
    case TRIANGLE:
        area = 0.5 * d1 * d2;
        break;
    default:
        break;
    }
    return area;
}

void printShapeInfo(Shape name){
    switch (name)
    {
    case CIRCLE:
        printf("Shape: CIRCLE\n");
        break;
    case RECTANGLE:
        printf("Shape: RECTANGLE\n");
        break;
    case TRIANGLE:
        printf("Shape: TRIANGLE\n");
        break;
    
    default:
        break;
    }
}


int main(){
    Shape slectedShape;
    int numShape;
    float dim1, dim2;
    printf("Enter Shape Value: ");
    scanf("%d", &numShape);
    slectedShape = numShape;
    printf("Enter dimension1: ");
    scanf("%f", &dim1);
    printf("Enter dimension2: ");
    scanf("%f", &dim2); 
    
    printShapeInfo(slectedShape);
    float area =calculateArea(slectedShape, dim1, dim2);
    printf("Area: %.2f\n", area);
    return 0;

}