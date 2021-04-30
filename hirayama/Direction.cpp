// hirayama のプログラム
#include <stdio.h>
using  namespace std;


enum class Direction
{
    N,NE,E,SE,S,SW,W,NW
};

struct Coodinate 
{
    int x;
    int y;

};

Direction CalcNextDirection(Coodinate current_coodinate, Coodinate next_coodinate)
{
    int diff_x = next_coodinate.x - current_coodinate.x;
    int diff_y = next_coodinate.y - current_coodinate.y;

    if (diff_x < 0){
        if (diff_y < 0){
            return Direction::NW;
        }
        else if (diff_y == 0){
            return Direction::N;
        }
        else{
            return Direction::NE;
        }
    }
    else if (diff_x == 0){
        if (diff_y < 0){
            return Direction::W;
        }
        else{
            return Direction::E;
        }
    }
    else{
        if (diff_y < 0){
            return Direction::SW;
        }
        else if (diff_y == 0){
            return Direction::S;
        }
        else{
            return Direction::SE;
        }
    } 
    
}

int main(void)
{
    struct Coodinate current_coodinate = {0, 0};
    struct Coodinate next_coodinate = {2, 1};

    Direction result= CalcNextDirection(current_coodinate, next_coodinate);
    printf("%d\n",(int)result);

}