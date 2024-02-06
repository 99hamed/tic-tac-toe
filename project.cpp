// tic tac toe project Hamed Saadati
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct player{
    string name;
    int win=0;
    int lose=0;
    int draw=0;
};
player player1,player2;
int digit; // element that input by user
void showtable(char [3][3]); // tic tac toe table function
void gameprocces(char[3][3]); 
bool checkwinner(char [3][3]); //check who is winner
void savetofile(player,player);
void showscore();
int main(){
int n;

while(n!=3){
 char table[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}}; // reset everytime
 cout<<"1) start game"<<endl;
 cout<<"2) scoreboard"<<endl;
 cout<<"3) exit"<<endl;
 cout<<"enter your choose: ";
 cin>>n; //coose from menu
  if(n==1) gameprocces(table);
  else if(n==2){showscore();}
  else if(n==3) exit(0); 
  else cout<<"enter between 1,2,3";
  
}

    return 0;
}
void showtable(char table[3][3]){
    for(int i=0;i<3;i++)
        cout<<"| "<<table[i][0]<<" | "<<table[i][1]<<" | "<<table[i][2]<<" |"<<endl; 
    }
void gameprocces(char table[3][3]){
cout<<"enter name of player1: ";
cin>>player1.name;
cout<<"enter name of player2: ";
cin>>player2.name;
cout<<"the player1 will start the game"<<endl;
showtable(table);
for(int i=0;i<5;i++){
    cout<<player1.name<<" please enter your selection: "; // procces for player1
    
    while(true){ // if the input digit is exist enter again
        
        cin>>digit;
        if(digit>=1 && digit<=3){ // check if the input digit is exist show eror
            if(table[0][digit-1]=='x' || table[0][digit-1]=='O') cout<<"Eror,you entered the same char,enter another one: ";
            else break;  }
        
        if(digit>=4 && digit<=6){ 
            if(table[1][digit-4]=='x' || table[1][digit-4]=='O') cout<<"Eror,you entered the same char,enter another one: ";
            else break; }
        
        if(digit>=7 && digit<=9){ 
            if(table[2][digit-7]=='x' || table[2][digit-7]=='O') cout<<"Eror,you entered the same char,enter another one: ";
            else break; }
         }
    switch(digit){
    case 1: table[0][0]='x';  break;
    case 2: table[0][1]='x';  break;
    case 3: table[0][2]='x';  break;
    case 4: table[1][0]='x';  break;
    case 5: table[1][1]='x';  break;
    case 6: table[1][2]='x';  break;
    case 7: table[2][0]='x';  break; 
    case 8: table[2][1]='x';  break;
    case 9: table[2][2]='x';    }
    
    showtable(table); // shows updated table 
    if(checkwinner(table)){
        cout<<player1.name<<" win the game"<<endl;
        player1.win++;
        player2.lose++;
        savetofile(player1,player2);
        break; } 
    if(i==4){  // if all number entered the game is equal
        cout<<"the game is draw"<<endl;
        player1.draw++;
        player2.draw++;
        savetofile(player1,player2);
        break; }
    cout<<player2.name<<" please enter your selection: "; //procces for player2
        
        while(true){ // if the input digit is exist enter again
        
        cin>>digit;
        if(digit>=1 && digit<=3){ // check if the input digit is exist show eror
         if(table[0][digit-1]=='x' || table[0][digit-1]=='O') cout<<"Eror,you entered the same char,enter another one: ";
         else break;    }
                 
        if(digit>=4 && digit<=6){ 
             if(table[1][digit-4]=='x' || table[1][digit-4]=='O') cout<<"Eror,you entered the same char,enter another one: ";
             else break;   }
                 
        if(digit>=7 && digit<=9){ 
            if(table[2][digit-7]=='x' || table[2][digit-7]=='O') cout<<"Eror,you entered the same char,enter another one: ";
            else break;  }
                 
    }  
    switch(digit){
    case 1: table[0][0]='O';  break;
    case 2: table[0][1]='O';  break;
    case 3: table[0][2]='O';  break;
    case 4: table[1][0]='O';  break;
    case 5: table[1][1]='O';  break;
    case 6: table[1][2]='O';  break;
    case 7: table[2][0]='O';  break; 
    case 8: table[2][1]='O';  break;
    case 9: table[2][2]='O';   }
    
    if(checkwinner(table)){
        showtable(table);
        cout<<player2.name<<" win the game"<<endl;
        player2.win++;
        player1.lose++;
        savetofile(player1,player2);
        break;  }
    
    showtable(table); //show uppdated table again
        }
    }
bool checkwinner(char table[3][3]){
for(int i=0;i<3;i++){
    if(table[i][0]==table[i][1] && table[i][1]==table[i][2]|| // baraye check kardan satr va soton
       table[0][i]==table[1][i] && table[1][i]==table[2][i] ) 
        return true; }

if(table[0][0]==table[1][1] && table[1][1]==table[2][2]|| // braye check kardan ghotr asli va fariee
   table[2][0]==table[1][1] && table[1][1]==table[0][2] )
         return true; 
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(table[i][i]!='x' && table[i][j]!='O')
            return false;   }
            
                    }
        
        return false;
    
}    
void savetofile(player player1,player player2){
  ofstream file;
  
  file.open ("result.txt",ios::app);
  //file<<"| name  |  wins  |  loses  | draw |"<<endl;
  file <<player1.name<<"   wins: "<<player1.win<<"   loses: "<<player1.lose<<"   draw: "<<player1.draw<<endl;
  file <<player2.name<<"   wins: "<<player2.win<<"   loses: "<<player2.lose<<"   draw: "<<player2.draw<<endl;
  file<<"------------------------------------"<<endl;
  file.close();

}

void showscore(){
    string line;
    ifstream file("result.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << "\n";
        }
        file.close();
    }





}
