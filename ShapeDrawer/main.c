#include <stdio.h>
#include "circle.h"
#include "rectangle.h"
#include "shape.h"

int main(){

    
    int n;
    printf("Enter Number of Shapes to create: ");
    scanf("%d", &n);
    Shape * shape[n];
    char type;
    double radius;
    double width;
    double height;
    Circle circle;
    Rectangle rectangle;
    double total_area = 0.0;
    getchar();
    for (int i = 0; i < n; i++){
        printf("Enter c for Circle or r for Rectangle: ");
        scanf("%c", &type);
        
        if (type == 'c'){
            printf("Enter radius: ");
            scanf("%lf", &radius);
            circle = create_circle(radius);
            shape[i] = &circle.shape;
        }
        else if (type == 'r'){
            printf("Enter width and height: ");
            scanf("%lf %lf", &width, &height);
            rectangle = create_rectangle(width,height);
            shape[i] = &rectangle.shape;

        }
        getchar();

        shape[i]->draw_ptr(shape[i]);
        total_area += shape[i]->area_ptr(shape[i]);        
    }


    /*for (int i = 0; i < n; i++){
        shape[i]->draw_ptr(shape[i]);
        total_area += shape[i]->area_ptr(shape[i]);
    }*/

    printf("Total Area: %.2f\n", total_area);
    
    /*
    if (type == 'c'){
        printf("Enter radius: ");
        scanf("%lf", &radius);
        Circle circle = create_circle(radius);
        process_shape(&circle.shape);
    }
    else if (type == 'r'){
        printf("Enter width and height: ");
        scanf("%lf %lf", &width, &height);
        Rectangle rectangle = create_rectangle(width, height);
        process_shape(&rectangle.shape);
    }
*/
    
}