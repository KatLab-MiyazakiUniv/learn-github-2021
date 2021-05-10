/**
* @file Direction.cpp
* @brief 進行方向を求める
* @author 児玉 github名
*/

#include <stdio.h>
#include "Direction.h"

Direction calcNextDirection(Coordinate now, Coordinate next){
  int x_vec = next.x - now.x;
  int y_vec = next.y - now.y;
  if(x_vec == 0 && y_vec == -1){
    return Direction::N;
  }else if(x_vec >= 1 && y_vec <= -1){
    return Direction::NE;
  }else if(x_vec >= 1 && y_vec == 0){
    return Direction::E;
  }else if(x_vec >= 1 && y_vec >= 1){
    return Direction::SE;
  }else if(x_vec == 0 && y_vec >= 1){
    return Direction::S;
  }else if(x_vec <= -1 && y_vec >= 1){
    return Direction::SW;
  }else if(x_vec <= -1 && y_vec == 0){
    return Direction::W;
  }else if(x_vec <= -1 && y_vec <= -1){
    return Direction::NW;
  }
}

int main(){
  Coordinate now = {1,1};
  Coordinate next = {0,0};

  printf("%d\n", int(calcNextDirection(now, next)));

  return 0;
}
