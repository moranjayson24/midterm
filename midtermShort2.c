#include<stdio.h>
#include<stdlib.h>

//------ POINT ----------------------------------------------------------------
typedef struct point point;
struct point { double x, y; };

//------ SQUARE -----------------------------------------------------------------
typedef struct square square;
struct square { point ul; size_t side; };

square* square_init(double ulx, double uly, double side){
    square* S = (square*)malloc(sizeof(square));
    S->ul.x = ulx;
    S->ul.y = uly;
    S->side = side;
    return S;
}

void square_delete(square* sq){
    free(sq);
}

void square_move(square* sq, double x, double y){
    sq->ul.x += x;
    sq->ul.y += y;
}

void square_expandby(square* sq, double expandby){
    sq->ul.x += expandby;
    sq->ul.y += expandby;
}

double square_area(square* sq){
    return (sq->side * sq->side);
}

double square_perimeter(square* r){
    return ((r->side) * 4);
}

// print location, side, area and perimeter
void square_print(const char* msg, square* sq){
    printf("%s %f %f %f ", msg, sq->ul.x, sq->ul.y, sq->ul.x + sq->ul.y);
}
void test_square(double ulx, double uly, double side) {
    square* sq = square_init(ulx, uly, side);
    square_print(“sq is: “, sq);
    square_move(2, 2);
    square_print(“sq is now: “, sq);
    square_expandby(sq, 10);
    square_print(“sq has expanded to: “, sq);
    square_delete(sq);
    printf(“\n\n”);
}

void tests_square() {
    test_square(0, 0, 10);
    test_square(1, 1, 5);
 // add other tests if you wish // TODO (optional)
}


int main(int argc, const char* argv[]) {
 tests_square();
 return 0;
}
