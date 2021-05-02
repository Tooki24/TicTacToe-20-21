#include <iostream>
#include<time.h>
#include <stdlib.h>

#include "grid.h"

int main()
{

    cout<< "    LE MORPION | OXO" << endl;
    int size=0;
    do{
        cout<<"De quelle taille voulez vous pour votre grille ? : ";
        cin>>size;
    }
    while(size>9 or size<3);

    Grid theGrid(size);
    int gamemode=0;
    do{
        cout<<"De quelle façon voulez vous jouer ? : "<<endl<<"1: Humain/Humain"<<endl<<"2: Humain/IA"<<endl<<"3: IA/IA"<<endl;
    cin>>gamemode;
    }
    while(gamemode!=1 and gamemode!=2 and gamemode!=3);
    Player player1("temp",HUMAN,CROSSES);
    Player player2("temp",HUMAN,CROSSES);
    if(gamemode==1){
        string name1, name2;
        cout<<"Entrez le nom du premier joueur :";
        cin>>name1;
        string state;
        State etat1=VOID;
        State etat2=VOID;

        do{
            cout<<"Vous voulez jouer croix ou cercle ? :";
            cin>>state;
            if(state==("croix")){
                etat1=CROSSES;
                etat2=CIRCLES;
            }
            else if (state=="cercle"){
                etat1=CIRCLES;
                etat2=CROSSES;
            }
            else{
                cout<<"Vous n'avez pas compris la question ? croix ou cercle ?";
            }
        }
            while(state!="croix" and state!="cercle");
        cout<<"Entrez le nom du deuxième joueur : ";
        cin>>name2;
        player1.setItsName(name1);
        player1.setItsType(HUMAN);
        player1.setItsState(etat1);
        player2.setItsName(name2);
        player2.setItsType(HUMAN);
        player2.setItsState(etat2);

    }
    else if(gamemode==2) {
        string name1, name2="robot";
        cout<<"Entrez le nom du joueur humanoïde :";
        cin>>name1;
        string state;
        State etat1=VOID;
        State etat2=VOID;

        do{
            cout<<"Vous voulez jouer croix ou cercle ? :";
            cin>>state;
            if(state==("croix")){
                etat1=CROSSES;
                etat2=CIRCLES;
            }
            else if (state=="cercle"){
                etat1=CIRCLES;
                etat2=CROSSES;
            }
            else{
                cout<<"Vous n'avez pas compris la question ? croix ou cercle ?";
            }
        }
            while(state!="croix" and state!="cercle");
            player1.setItsName(name1);
            player1.setItsType(HUMAN);
            player1.setItsState(etat1);
            player2.setItsName(name2);
            player2.setItsType(IA);
            player2.setItsState(etat2);
    }
    else if(gamemode==3){
        string name1="robot1", name2="robot2";
        player1.setItsName(name1);
        player1.setItsType(IA);
        player1.setItsState(CROSSES);
        player2.setItsName(name2);
        player2.setItsType(IA);
        player2.setItsState(CIRCLES);
    }
    theGrid.initGrid();
    theGrid.clearScreen();
    theGrid.displayGrid();
    srand (time(NULL));
    int firstPlayer=rand()%2;
    string coord1;
    string coord2;
    if (firstPlayer==0){
        do {

            if (player1.getItsType()==HUMAN){
               do{


                    cout<<player1.getItsName()<<" veuillez entrer des coordonées : ";
                    cin>>coord1;
                }while(!theGrid.checkCoord(coord1));
                theGrid.placePion(coord1,player1.getItsState());
                theGrid.save(coord1, player1.getItsState());
                theGrid.clearScreen();
                theGrid.displayGrid();
            }
               else if(player1.getItsType()==IA){
                coord1 = theGrid.IAcase();
                theGrid.placePion(coord1,player1.getItsState());
                theGrid.save(coord1, player1.getItsState());
                theGrid.clearScreen();
                theGrid.displayGrid();
            }
            cout << coord1;
            if(theGrid.checkWin(coord1,player1) == false){
                if (player2.getItsType()==HUMAN){
                   do{
                        cout<<player2.getItsName()<<" veuillez entrer des coordonées : ";
                        cin>>coord2;
                    }while(!theGrid.checkCoord(coord2));
                    theGrid.placePion(coord2,player2.getItsState());
                    theGrid.save(coord2, player2.getItsState());
                    theGrid.clearScreen();
                    theGrid.displayGrid();
                }
                else if(player2.getItsType()==IA){
                    coord2 = theGrid.IAcase();
                    theGrid.placePion(coord2,player2.getItsState());
                    theGrid.save(coord2, player2.getItsState());
                    theGrid.clearScreen();
                    theGrid.displayGrid();
                }

            }
        }
        while(!theGrid.checkWin(coord1,player1) and !theGrid.checkWin(coord2, player2));
    }
    if (firstPlayer==1){
        do {
            if (player2.getItsType()==HUMAN){
               do{


                    cout<<player2.getItsName()<<" veuillez entrer des coordonées : ";
                    cin>>coord2;
                }while(!theGrid.checkCoord(coord2));
                theGrid.placePion(coord2,player2.getItsState());
                theGrid.save(coord2, player1.getItsState());
                theGrid.clearScreen();
                theGrid.displayGrid();
            }
            else if(player2.getItsType()==IA){
                coord2 = theGrid.IAcase();
                theGrid.placePion(coord2,player2.getItsState());
                theGrid.save(coord2, player1.getItsState());
                theGrid.clearScreen();
                theGrid.displayGrid();
            }
            if(theGrid.checkWin(coord2,player2)==false){
                    if (player1.getItsType()==HUMAN){
                   do{


                        cout<<player1.getItsName()<<" veuillez entrer des coordonées : ";
                        cin>>coord1;
                    }while(!theGrid.checkCoord(coord1));
                    theGrid.placePion(coord1,player1.getItsState());
                    theGrid.save(coord1, player2.getItsState());
                    theGrid.clearScreen();
                    theGrid.displayGrid();
                }
                else if(player1.getItsType()==IA){
                    coord1 = theGrid.IAcase();
                    theGrid.placePion(coord1,player1.getItsState());
                    theGrid.save(coord1, player2.getItsState());
                    theGrid.clearScreen();
                    theGrid.displayGrid();
                }
            }
        }
        while(!theGrid.checkWin(coord1,player1) and !theGrid.checkWin(coord2, player2));
    }

    return 0;
}
