#include <iostream>
#include <vector>

using namespace std;

//vector<char> a[];
char map[20][30];

int main(){
    FILE *file;
    file = fopen("Map.txt","r");

    for(int i=0;i<20;i++)for(int j=0;j<30;j++){
        fscanf(file, "%c" , &map[i][j]);
    }

    fclose(file);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++) {
            cout << map[i][j] ;
        }

    }
    cout << endl;
    return 0;

}