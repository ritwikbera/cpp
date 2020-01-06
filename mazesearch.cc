#include <iostream>
#include <bits/stdc++.h> 
using namespace std;
#define ROW 9
#define COL 10

struct Point
{
	int x;
	int y;
};

struct queueNode
{
	Point pt;
	int dist;
};

bool isValid(int row, int col)
{
	return (row >= 0) && (row < ROW) && 
           (col >= 0) && (col < COL); 
} 

int rowNum[] = {-1, 0, 0, 1}; 
int colNum[] = {0, -1, 1, 0}; 

int BFS(int mat[][COL], Point src, Point dest) 
{ 

    if (!mat[src.x][src.y] || !mat[dest.x][dest.y]) 
        return -1; 
  
    bool visited[ROW][COL]; 
    memset(visited, false, sizeof visited); 
      
    visited[src.x][src.y] = true; 
  
    queue<queueNode> q; 
      
    queueNode s = {src, 0}; 
    q.push(s); 
  
    while (!q.empty()) 
    { 
        queueNode curr = q.front(); 
        Point pt = curr.pt; 

        if (pt.x == dest.x && pt.y == dest.y) 
            return curr.dist; 

        q.pop(); 
  
        for (int i = 0; i < 4; i++) 
        { 
            int row = pt.x + rowNum[i]; 
            int col = pt.y + colNum[i]; 

            if (isValid(row, col) && mat[row][col] &&  
               !visited[row][col]) 
            { 
                visited[row][col] = true; 
                queueNode Adjcell = { {row, col}, 
                                      curr.dist + 1 }; 
                q.push(Adjcell); 
            } 
        } 
    } 
  
    // Return -1 if destination cannot be reached 
    return -1; 
} 
  
int main() 
{ 
    int mat[ROW][COL] = 
    { 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 } 
    }; 
  
    Point source = {0, 0}; 
    Point dest = {3, 4}; 
  
    int dist = BFS(mat, source, dest); 
  
    if (dist != INT8_MAX) 
        cout << "Shortest Path is " << dist ; 
    else
        cout << "Shortest Path doesn't exist"; 
  
    return 0; 
} 