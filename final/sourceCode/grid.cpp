#include "grid.h"

Grid::Grid(int size)
{
    itsSize=size;
}

void Grid::setSize(int size){
    itsSize=size;
}

int Grid::getItsSize(){
    return itsSize;
}


void Grid::initGrid(){
for(int line=0;line<itsSize;line++){
    itsGrid.push_back(vector<State>());
    for(int column=0;column<itsSize;column++){
        itsGrid[line].push_back(VOID);
    }
}
}


void Grid::displayGrid(){
    for(char i=65;i<itsSize+65;i++){
        cout<<"   "<<i;
    }
    cout<<endl;
    for(int line=0;line<itsSize;line++){
        cout<<line;
        for(int column=0;column<itsSize;column++){
            if(itsGrid[line][column]==VOID){
                cout<<"|   ";
            }
            else if(itsGrid[line][column]==CROSSES){
                cout<<"| X ";
            }
            else{
                cout<<"| O ";
            }

        }

        cout<<"|"<<endl<<" ";
        for(int i=0;i<itsSize;i++){
            cout<<"| - ";
        }
        cout<<"|"<<endl;
    }
}

void Grid::clearScreen()
{
    system("pause");
    system("cls");
}


bool Grid::checkCoord(string coord){
    bool check = false;
    if (coord.length()== 2){
        char letter;
        string str = "";
        int number;
        letter = toupper(coord[0]);
        str += coord[1];
        number = stoi(str);
        if (letter>=65 and letter<=65+itsSize and number >=0 and number<=0+itsSize){
            if(itsGrid[number][letter-65]==VOID){
                check = true;
            }
            else{
                check = false;
            }
        }
        else{
            check = false;
        }
    }
    else {
        check = false;
    }
    return check;
}

void Grid::placePion(string coord, State state){
    char letter;
    string str = "";
    int number;
    letter = toupper(coord[0]);
    str += coord[1];
    number = stoi(str);
    itsGrid[number][letter-65]=state;

}

string Grid::IAcase()
{
    srand(time(NULL));
    string coord;
    do{
        int number=rand()% itsSize;
        char letter=65 +rand()%itsSize;
        coord=letter+to_string(number);
    }while(!checkCoord(coord));
    return coord;
}

void Grid::save(string coord, State type){
    ofstream ofs("aGame",ios::app);
    ofs<<coord<<" : "<<type<<endl;
    ofs.close();
}

bool Grid::checkWin(string coord, Player player){
    char letter;
    string str = "";
    int number;
    letter = toupper(coord[0]);
    str += coord[1];
    number = stoi(str);
    int verifline=0, verifcolumn=0,verifdiag1=0,verifdiag2=0, verifnull=0;

    for(int line=0; line<itsSize;line++){
        for(int column=0;column<itsSize;column++){
            if(itsGrid[line][column]!=VOID){
                verifnull++;
            }
        }
    }


    for(int i=0;i<itsSize;i++){
        if(itsGrid[0+i][letter-65]== player.getItsState()){
            verifcolumn++; //colonne
        }
        if (itsGrid[number][0+i]==player.getItsState()){
            verifline++;//ligne
        }
        if(itsGrid[0+i][0+i]==player.getItsState()){
            verifdiag1++;//diagonale en partant du haut a gauche
        }
        if(itsGrid[itsSize-1-i][0+i]==player.getItsState()){
            verifdiag2++;//diagonale en partant du bas a gauche
        }

    }
    if(verifline==itsSize or verifcolumn==itsSize or verifdiag1==itsSize or verifdiag2==itsSize){

        cout<<"le gagnant est : "<<player.getItsName()<<endl;
        return true;
    }
    else if (verifnull==itsSize*itsSize){
        cout<<"MATCH NULL !"<<endl;
        return true;
    }
    else{
        cout<<"on continue"<<endl;
        return false;
    }
    cout<<"erreur check"<<endl;
    return false;
}
