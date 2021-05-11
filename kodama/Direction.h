/**
* @file Direction.h
* @brief 方向を列挙したクラス
* @author kodama0720
*/

#ifndef DIRECTION_H
#define DIRECTION_H

enum class Direction{N, NE, E, SE, S, SW, W, NW};

struct Coordinate{
  int x;
  int y;
};

#endif
