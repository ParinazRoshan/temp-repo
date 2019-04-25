#ifndef MAP_H
#define MAP_H


class Map {
 public :
  Map (int N) ;
  ~Map();
  void showMap();
  void findRoute ();
  void showRoute ();
 private :
  int n;
  int** H;
  int** R;
};



#endif
