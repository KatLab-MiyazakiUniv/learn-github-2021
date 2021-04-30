#include<stdio.h>

enum class Direction{N,NE,E,SE,S,SW,W,NW,NON};

struct Coordinate {
 int x;
 int y;
};

Direction calcNextDirection(Coordinate&,Coordinate&);

int main(){

        
Direction result;
int now_x, now_y;
int future_x, future_y; 

printf("現在の座標を入力してください\n");
scanf("%d %d", &now_y, &now_x);
        
printf("次に進む座標を入力してください\n") ;
scanf("%d %d", &future_y, &future_x);


Coordinate now={now_x,now_y}, future={future_x,future_y};

result = calcNextDirection( now, future);

printf("%d\n",(int)result );
        
}

Direction calcNextDirection(Coordinate& now, Coordinate& future){
 int _x;
 int _y;

_x = future.x - now.x; //_x > 0　右　、　_x < 0 　左
_y = future.y - now.y; //_y > 0 下　、　_y < 0 上


    if(_x > 0){     //右側
        if(_y == 0){
                return Direction::E;
        }else if(_y > 0){
                return Direction::SE;
        }else if(_y < 0){
                return Direction::NE;
        }
    }

    if(_x < 0){   //左
        if(_y == 0){
                return Direction::W;
        }else if(_y > 0){
                return Direction::SW;
        }else if(_y < 0){
                return Direction::NW;
        }
    }

    if(_x == 0){

        if(_y > 0){
                return Direction::S;
        }else if(_y < 0){
                return Direction::N;
        }else if(_y == 0){
                return Direction::NON;
        }
    } 
        

}