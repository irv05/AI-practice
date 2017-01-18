//https://www.hackerrank.com/challenges/pacman-dfs
/*
 * Implementing a Depth-First search algorigthm for pac-man pathfinding
 */

#include <iostream>
#include <vector>
using namespace std;
void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
    vector <int> row, col, psr, psc;
    int rc = pacman_r, cc = pacman_c, len = 1;

    while (rc != food_r || cc != food_c) {
        bool dead_end = true;
        if(grid[rc][cc] != 'e') {
            psr.push_back(rc);
            psc.push_back(cc);
            ++len;
        }       
        //up
        if((rc - 1 >= 0) && (grid[rc - 1][cc] == '-' || grid[rc - 1][cc] == '.')) {
            dead_end = false;
            grid[rc - 1][cc] = 's';
            row.push_back(rc - 1);
            col.push_back(cc);
        }
        //left
        if((cc - 1 >= 0) && (grid[rc][cc - 1] == '-' || grid[rc][cc - 1] == '.')) {
            dead_end = false;
            grid[rc][cc - 1] = 's';
            row.push_back(rc);
            col.push_back(cc - 1); 
        }         
        //right
        if((cc + 1 < c) && (grid[rc][cc + 1] == '-' || grid[rc][cc + 1] == '.')) {
            dead_end = false;
            grid[rc][cc + 1] = 's';
            row.push_back(rc);
            col.push_back(cc + 1); 
        }
        //down
        if((rc + 1 < r) && (grid[rc + 1][cc] == '-' || grid[rc + 1][cc] == '.')) {
            dead_end = false;
            grid[rc + 1][cc] = 's';
            row.push_back(rc + 1);
            col.push_back(cc);
        }
        
        //pop it   
        if(dead_end) {
            grid[rc][cc] = '%';                    
            row.pop_back();
            col.pop_back();  
        }
        else
            grid[rc][cc] = 'e';

        rc = row.back();       
        cc = col.back();             
    }
    
    //print1
    cout << len << endl; 
    int p_len = 0;
    for(int i = 0; i < psr.size(); ++i) {
        int ch = grid[psr[i]][psc[i]];
        if(ch == 'e' || ch == '.') p_len++;
        cout << psr[i] << " " << psc[i] << endl;
    }
    cout << rc << " " << cc << endl;
    //print2
    cout << p_len << endl;
    for(int i = 0; i < psr.size(); ++i) {
        int ch = grid[psr[i]][psc[i]];
        if(ch == 'e' || ch == '.') 
            cout << psr[i] << " " << psc[i] << endl;
    }
       cout << rc << " " << cc << endl;
}
int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;
    
    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;
    
    vector <string> grid;

    for(int i=0; i<r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}

