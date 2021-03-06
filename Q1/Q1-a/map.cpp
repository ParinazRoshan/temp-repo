#include <iostream>
#include <cstdlib>
#include <ctime>
#include "map.h"

Map::Map (int N) : n{N} , H{new int* [n]} , R{new int* [n]}
{
  for(int i{}; i < n;i++)
    {
      *(H+i) = new int[n] {}; //heights of map cells
      *(R+i) = new int [n] {};
    }
}


Map::~Map()
{
  delete[] H;
  delete[] R;
  std::cout<<"goodbye !"<<std::endl;
}


void Map::showMap ()
{
  std::cout<<"here are the heights :"<<std::endl;
  std::srand ( (int)time(0) );  //for generating different numbers each time
  for(int i{}; i < n;i++)
    {
      for(int j{}; j < n;j++)
	{
	  H[i][j] = (rand() % 100);  //random numbers from 0 to 99
	  if(H[i][j] - 10 >= 0)
	    std::cout<<H[i][j]<<"  ";
	  else
	    std::cout<<"0"<<H[i][j]<<"  ";
	}
      std::cout<<std::endl;
    }
}


void Map::findRoute ()
{
  int i{},j{};
  R[0][0] = 1;
  while(i != n-1 && j != n-1) // while not reaching the borders of the map
    {
      if( std::abs(H[i+1][j] - H[i][j]) <= std::abs(H[i][j+1] - H [i][j]) )
	{
	  R[i+1][j] = 1; //moving to the next cell on the same column
	  i++;
	}
      else
	{
	  R[i][j+1] = 1; //moving to the next cell on the row
	  j++;
	}
    }
  while (i == n-1 && j != n-1)  //the condition that we have reached the bottom border(last row) but not the destination
	{
	  j++; //moving to the next cell on the last row 
	  R[i][j] = 1;
	}
  while (j == n-1 && i != n-1) //the state of reaching the right border(last column) but not the destination
	{
	  i++;
	  R[i][j] = 1;
	}
}


void Map::showRoute()
{
  std::cout<<"my suggested route is :"<<std::endl;
  std::cout<<std::endl;
  for (int i{};i < n;i++)
    {
      for (int j{};j < n;j++)
	{
	  std::cout<<R[i][j]<<" ";
	}
      std::cout<<std::endl;
      std::cout<<std::endl;
    }
}
