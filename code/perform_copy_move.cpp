// movePerformance.cpp
 
#include <array>
#include <forward_list>
#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

constexpr int SIZE = 10000000; 

using dchro = chrono::duration<double>;

template <typename T>
void measurePerformance(T& t, const string& cont){
  
  cout << fixed << setprecision(10);

  auto begin = chrono::system_clock::now();
  T t1(t);
  auto last =  chrono::system_clock::now() - begin;
  cout << cont << endl;
  auto copyTime =  dchro(last).count();
  cout <<  "    Copy: " << copyTime << " sec" << endl;

  begin = chrono::system_clock::now();
  T t2(move(t));
  last =  chrono::system_clock::now() - begin;
  auto moveTime= dchro(last).count();
  cout <<  "    Move: " << moveTime << " sec" << endl;
  
  cout << setprecision(2);
  cout << "    Ratio (copy time/move time): " << (copyTime/moveTime) << endl;
  
  cout << endl;
     
}

void perform_copy_move()
{
    
    cout << endl;
    
    {
      array<int,SIZE/1000> data;
      measurePerformance(data,"array<int,SIZE/1000>");   
    }
    
    {
      vector<int> data(SIZE);
      measurePerformance(data,"vector<int>(SIZE)");
    }

    {
      deque<int>data(SIZE);
      measurePerformance(data,"deque<int>(SIZE)");
    }
    
    {
      list<int>data(SIZE);
      measurePerformance(data,"list<int>(SIZE)");
    }
    
    {
      forward_list<int>data(SIZE);
      measurePerformance(data,"forward_list<int>(SIZE)");
    } 
       
    {
      string data(SIZE,' ');
      measurePerformance(data,"string(SIZE,' ')");
    }
    
    {
        vector<int> tmpVec(SIZE);
        iota(tmpVec.begin(),tmpVec.end(),0);
        {
            set<int>data(tmpVec.begin(),tmpVec.end());
            measurePerformance(data,"set<int>");
        }
        
        {
            unordered_set<int>data(tmpVec.begin(),tmpVec.end());
            measurePerformance(data,"unordered_set<int>");
        }
    }
    {
      map<int,int>data;
      for (auto i= 0; i <= SIZE; ++i) data[i]= i;
      measurePerformance(data,"map<int,int>");
    }
    
    {
      unordered_map<int,int>data;
      for (auto i= 0; i <= SIZE; ++i) data[i]= i;
      measurePerformance(data,"unordered_map<int,int>");
    }  
    
}