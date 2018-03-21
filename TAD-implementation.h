
// Luiz Henrique B T

//SO33A-ES31

//Implementation in a function to return pointers coordinate distance

float point_distance(Point * a, Point *b){

    float distance;
    distance = sqrt((a->x - b->x )*(a->x - b->x)+(a->y - b->y)*(a->y - b-> y));

    printf(" aX = %f| aY = %f ||| bX = %f | bY = %f \n ", a->x,a->y,b->x,b->y);
    printf(" The diference between points is: %f\n", distance);
}
