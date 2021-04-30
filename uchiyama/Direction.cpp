#include<stdio.h>

enum class Direction{n,ne,e,se,s,sw,w,nw};

struct Coordinate{
    int _x;
    int _y;
};

Direction calcNextDirection(Coordinate _direction,Coordinate _nextdirection){
    int x,y;
    x = _direction._x - _nextdirection._x;
    y = _direction._y - _nextdirection._y; 
    if(x==1&&y==1){
        return Direction::nw;
    }else if(x==1&&y==0){
        return Direction::n;
    }else if(x==1&&y==-1){
        return Direction::ne;
    }else if(x==0&&y==-1){
        return Direction::e;
    }else if(x==-1&&y==-1){
        return Direction::se;
    }else if(x==1&&y==0){
        return Direction::s;
    }else if(x==-1&&y==1){
        return Direction::sw;
    }else if(x==1&&y==-1){
        return Direction::w;
    }
}

int main(){
    Direction result;
    Coordinate coodinate1 = {1,1};
    Coordinate coodinate2 = {0,0};

    result = calcNextDirection(coodinate1,coodinate2);

    printf("%d\n",(int)result);
}
