#include<stdio.h>
#include<string>

enum class Direction{N,NE,E,SE,S,SW,W,NW};

struct Coordinate{
    int x;
    int y;
};

Direction calcNextDirection1(Coordinate&, Coordinate&);
Direction calcNextDirection2(Coordinate&, Coordinate&);
Direction calcNextDirection3(Coordinate&, Coordinate&);

int main(void){
    Coordinate now = {0,0};
    Coordinate next = {1,1};
    Coordinate & refNow = now;
    Coordinate & refNext = next;

    printf("f1 => %d\n",(int)calcNextDirection1(refNow, refNext));
    printf("f2 => %d\n",(int)calcNextDirection2(refNow, refNext));
    printf("f3 => %d\n",(int)calcNextDirection3(refNow, refNext));

    return 0;
}

// if
Direction calcNextDirection1(Coordinate& now, Coordinate& next){
    int dy = next.y - now.y;
    int dx = next.x - now.x;
    if(dy<0){
        if(dx>0) return Direction::NE;
        if(dx<0) return Direction::NW;
        return Direction::N;
    }
    if(dy>0){
        if(dx>0) return Direction::SE;
        if(dx<0) return Direction::SW;
        return Direction::S;
    }
    if(dx>0) return Direction::E;
    return Direction::W;
}

// int->enum
Direction calcNextDirection2(Coordinate& now, Coordinate& next){
    int result = 3;
    return (Direction)result;
    //return static_cast<Direction>(result);  // こっちのキャストが推奨される
}

// string->enum
Direction calcNextDirection3(Coordinate& now, Coordinate& next){
    std::string dir = "";
    int dy = next.y - now.y;
    int dx = next.x - now.x;
    dir += (dy<0)? "N" : (dy>0)? "S" : "";
    dir += (dx>0)? "E" : (dx<0)? "W" : "";
    //return (Direction)dir;    // 本当はstring->enumにキャストしたい
    //return static_cast<Direction>(dir);
    return Direction::N;
}