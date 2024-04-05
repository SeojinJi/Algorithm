#include <stdio.h>
#include <stdlib.h>

/* define structures - Point, Rectangle */
/* Write your code here */
typedef struct Point{
    float x;
    float y;
} Point;

typedef struct Rectangle{
    Point a;
    Point b;
} Rectangle;

/* declare functions*/
float area(Rectangle rect);
float width(Rectangle rect);
float height(Rectangle rect);
Point centroid(Rectangle rect);

int main(int argc, char *argv[]){
    if ((argc == 2) || (argc == 4) || (argc > 5)){
        printf("Invalid Input!\n");
        }
    else{
        /* Write your Code here */
        // hint) use atoi(str) to convert string into a integer
        Point a, b;
        if(argc == 5){
            a.x = atoi(argv[1]);
            a.y = atoi(argv[2]);
            b.x = atoi(argv[3]);
            b.y = atoi(argv[4]);
        }
        else if(argc == 3){
            a.x = atoi(argv[1]);
            a.y = atoi(argv[2]);
            printf("Enter a bottom-right point : ");
            scanf("%f %f", &b.x, &b.y);
        }
        else if(argc == 1){
            printf("Enter a top-left point : ");
            scanf("%f %f", &a.x, &a.y);
            printf("Enter a bottom-right point : ");
            scanf("%f %f", &b.x, &b.y);
        }
        if(a.x > b.x || a.y < b.y){
            printf("Invalid Input!\n");
        }
        else{
            Rectangle rect = {a, b};
            Point center = centroid(rect);
            printf("Bounding Box : (%.1f, %.1f, %.1f, %.1f)\n", center.x, center.y, width(rect), height(rect));
            printf("Area : %.1f", area(rect));
        }
    }
    return 0;
}

/* define functions - area, width, height, centroid */
/* Write your code here */
float area(Rectangle rect){
    return (width(rect) * height(rect));
}

float width(Rectangle rect){
    return (rect.b.x - rect.a.x);
}

float height(Rectangle rect){
    return (rect.a.y - rect.b.y);
}

Point centroid(Rectangle rect){
    Point center;
    center.x = (rect.a.x + rect.b.x) / 2;
    center.y = (rect.a.y + rect.b.y) / 2;
    return center;
}