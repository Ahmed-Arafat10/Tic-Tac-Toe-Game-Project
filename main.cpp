/*
Tic-Tac-Toe Game Project
Created By Ahmed Arafat
BIS
Egypt
9/2020
*/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::pair<std::string, std::string> pss;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::vector<pii> vii;
typedef std::vector<ll> vl;
typedef std::vector<vl> vvl;
typedef std::map<ll,ll> mpll;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORD(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORSQ(a, b, c) for (int(a) = (b); (a) * (a) <= (c); ++(a))
#define FORC(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))
#define FOREACH(a, b) for (auto&(a) : (b))
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PERMUTE next_permutation
#define TC(t) while (t--)
#define HANDLE_WRONG_INPUT          while(std::cin.fail()){std::cin.clear();std::cin.ignore();}
#define debug                       printf("I am here\n");
#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define scf(n)              scanf("%lf", &n)
#define pfl(x)              printf("%lld\n",x)
#define md                  10000007
#define pb                  push_back
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define asort(a)            sort(a,a+n)
#define dsort(a)            sort(a,a+n,greater<int>())
#define pn                  printf("\n")
#define debug               printf("I am here\n")
#define ps                  printf(" ")
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
mpll board_cell;
char board[10];
char R_P_S[4]={'-','R','P','S'};
int cnt_user=0,cnt_pc=0,cnt_turns=0,cnt_player1=0,cnt_player2=0,cnt_pc1=0,cnt_pc2=0;
    char user_sign,pc_sign,player1_sign,player2_sign,pc1_sign,pc2_sign;
    int edge[6]={0,1,3,5,7,9};
bool check_cell(int c){
if(board_cell[ c ]==0)
   return 0;
return 1;
}
bool change_cell(int c,char sign){
board[c]=sign;
board_cell[ c ]++;
}
bool undo_cell(int c,char sign){
board[c]=sign;
board_cell[ c ]--;
}
void print_board(){
    cout<<"\nBoard\n";
 for(int i=1;i<=9;i++){
        cout<<board[i];
        if(i%3==0) cout<<endl;
         if(i%3!=0) cout<<"|";
}
    cout<<"\n\n";
}
void print_board_instruction(){
 for(int i=1;i<=9;i++){
        cout<<i;
        if(i%3==0) cout<<endl;
         if(i%3!=0) cout<<"|";
}
    cout<<"\n\n";
}
bool check_winner(string name,char sign){

if(board[1]==sign&&board[2]==sign&&board[3]==sign){
    cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[1]==sign&&board[4]==sign&&board[7]==sign){
    cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[1]==sign&&board[5]==sign&&board[9]==sign){
    cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[7]==sign&&board[8]==sign&&board[9]==sign){
    cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[3]==sign&&board[6]==sign&&board[9]==sign){
    cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[4]==sign&&board[5]==sign&&board[6]==sign){
    cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[2]==sign&&board[5]==sign&&board[8]==sign){
    cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[3]==sign&&board[5]==sign&&board[7]==sign){
    cout<<name<<" is the winner\n\n";
    return 1;
}
return 0;
}
bool check_winner(char sign){

if(board[1]==sign&&board[2]==sign&&board[3]==sign){
   // cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[1]==sign&&board[4]==sign&&board[7]==sign){
   // cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[1]==sign&&board[5]==sign&&board[9]==sign){
   // cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[7]==sign&&board[8]==sign&&board[9]==sign){
   // cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[3]==sign&&board[6]==sign&&board[9]==sign){
   // cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[4]==sign&&board[5]==sign&&board[6]==sign){
  //  cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[2]==sign&&board[5]==sign&&board[8]==sign){
  //  cout<<name<<" is the winner\n\n";
    return 1;
}
if(board[3]==sign&&board[5]==sign&&board[7]==sign){
   // cout<<name<<" is the winner\n\n";
    return 1;
}
return 0;
}
void rest_board(char arr[]){
for(int i=0;i<=9;i++)
arr[i]=' ';
}
void print_wait(){
    cout << "\nPlease wait";
    for(int i=1;i<=3;i++)
    {
Sleep(600);
cout<<".";
    }
    cout<<"\n\n";
    }

    bool check_edges(){
    if(board_cell[1]==1&&board_cell[3]==1&&board_cell[5]==1&&board_cell[7]==1&&board_cell[9]==1)
        return 0;
    return 1;
    }

///MAIN FUNC.
int main()
{
        cout << "\n\t\t\t\t\t\t\t\t\t------------------------\n";
        cout << "\n\t\t\t\t\t\t\t\t\t Welcome to Tic-Tac-Toe\n";
        cout << "\n\t\t\t\t\t\t\t\t\t------------------------\n";
            srand((unsigned)time(0));
while(!(!(!false))){
    cout << "Please enter:\n(1)To know instructions\n(2)To play with another player\n(3)To play with PC\n(4)For PC VS PC\n(5)To end program\n\n";
    int user_option;
    cin>>user_option;
    if(user_option==1){
            cout<<"You have to follow every instruction in program .. if it is your turn all you have to do is to enter number of cell you want to play in it like this\n";
        print_board_instruction();
    cout<<"Note: Please make sure that you have entered numbers form 1-9 and to enter number for empty (not occupied) cell .. that's it\nHave Fun <3\n\n";
    }
     else if(user_option==2){
            bool is_again;
             string player1,player2;
                cout <<"Please enter player1 name\n";
    getline(cin,player1);
    getline(cin,player1);
     cout <<"Please enter player2 name\n";
     getline(cin,player2);
     cout<<"\n";
     AGAIN:
     print_board();
    srand((unsigned)time(0));
     int turn=1+(rand()%2);
     bool player_turn;
     if(turn==1) {
         cout<<"Player1 will start\n\n";
           PLAYER1_SIGN_AGAIN:
            cout<<"Please choose (X)/(O)\n\n";
            cin>>player1_sign;
            if(player1_sign=='X') player2_sign='O';
             else if(player1_sign=='O') player2_sign='X';
                else {
                    cout<<"\nPlease make sure that you entered (X) or (O)\n\n";
                goto PLAYER1_SIGN_AGAIN;
                    }
            player_turn=true;
     }
       if(turn==2){
           cout<<"Player2 will start\n\n";
             PLAYER2_SIGN_AGAIN:
            cout<<"Please choose (X)/(O)\n\n";
            cin>>player2_sign;
            if(player2_sign=='X') player1_sign='O';
             else if(player2_sign=='O') player1_sign='X';
                else {
                    cout<<"\nPlease make sure that you entered (X) or (O)\n\n";
                goto PLAYER2_SIGN_AGAIN;
                    }
            player_turn=false;
     }
        while(1){
        ///PLAYER 1
        if(player_turn){
        cout<<"\nThis is "<<player1<<"'s turn\n\n";
      PLAYER1:
      int cell;
      cout<<"Please Enter Number of cell you want to play in\n";
      cin>>cell;
      if(cell>9||cell<1){
        cout<<"Please Enter a valid cell from 1 to 9\n\n ";
        goto PLAYER1;
      }
       else if(check_cell(cell)){
        cout<<"This cell is already occupied \n\n";
        goto PLAYER1;
      }
      else{
        cnt_turns++;
        change_cell(cell,player1_sign);
        print_board();
        cnt_player1++;
        if(cnt_player1>=3){
            if(check_winner(player1,player1_sign)){
                    cout<<"Congratulations\n\n";
                    ERROR_AGAIN1:
                    cout<<"Do you want to play again[Y/N]\n";
                    char again;
                     cin>>again;
                     if(again=='Y'){
        is_again=true;
        break;
     }
         else if(again=='N') break;
            else {
                cout<<"please make sure that you have entered (Y) or (N)\n\n";
                goto ERROR_AGAIN1;
            }
            }
        }
      }
      if(cnt_turns==9){
                cout<<"No one is winner\n\n";
                 ERROR_AGAIN2:
                    cout<<"Do you want to play again[Y/N]\n";
                    char again;
                     cin>>again;
                     if(again=='Y'){
        is_again=true;
        break;
     }
         else if(again=='N') break;
            else {
                cout<<"please make sure that you have entered (Y) or (N)\n\n";
                goto ERROR_AGAIN2;
            }
            }
      player_turn=false;
        }

        ///Player 2
       if(!player_turn){
               cout<<"\nThis is "<<player2<<"'s turn\n\n";
     PLAYER2:
      int cell;
      cout<<"Please Enter Number of cell you want to play in\n";
      cin>>cell;
      if(cell>9||cell<1){
        cout<<"Please Enter a valid cell from 1 to 9\n\n ";
        goto PLAYER2;
      }
       else if(check_cell(cell)){
        cout<<"This cell is already occupied \n\n";
        goto PLAYER2;
      }
      else{
        cnt_turns++;
        change_cell(cell,player2_sign);
        print_board();
        cnt_player2++;
        if(cnt_player2>=3){
            if(check_winner(player2,player2_sign)){
                    cout<<"Congratulations\n\n";
                ERROR_AGAIN3:
                    cout<<"Do you want to play again[Y/N]\n";
                    char again;
                    cin>>again;
                     if(again=='Y'){
        is_again=true;
        break;
     }
         else if(again=='N') break;
            else {
                cout<<"please make sure that you have entered (Y) or (N)\n\n";
                goto ERROR_AGAIN3;
            }
            }
        }
      }
      if(cnt_turns==9){
                cout<<"No one is winner\n\n";
               ERROR_AGAIN:
                    cout<<"Do you want to play again[Y/N]\n";
                    char again;
                     cin>>again;
                     if(again=='Y'){
        is_again=true;
        break;
     }
         else if(again=='N') break;
            else {
                cout<<"please make sure that you have entered (Y) or (N)\n\n";
                goto ERROR_AGAIN;
            }
            }
      player_turn=true;
       }
}
        board_cell.clear();
        rest_board(board);
cnt_player1=0,cnt_player2=0,cnt_turns=0;
if(is_again) goto AGAIN;

     }
    else if(user_option==3){
           cout <<"Please enter your name\n";
    string username;
    getline(cin,username);
     getline(cin,username);
                string Winner;
    while(1){
            HERE:
          cout << "\nPlease enter (R) for Rock .. (P) for Paper .. (S) for Scissors" << endl;
    char User_choice;
    cin>>User_choice;
    cout<<"\n";
    if(User_choice!='R'&&User_choice!='P'&&User_choice!='S'){
            cout<<"Please Make sure to enter (R),(P) or (S)\n\n";
        goto HERE;
    }
 srand((unsigned)time(0));
    int PC_No=1+(rand()%3);
     char PC_choice=R_P_S[PC_No];
     if(User_choice==PC_choice){
                  cout<<User_choice<<"="<<PC_choice<<endl;
          cout<<"Same .. one more\n";
     continue;
     }
        else if(User_choice=='R'&&PC_choice=='S'){
                cout<<User_choice<<">"<<PC_choice<<endl;
             cout<<"You win\n";
Winner="user";
break;
        }
          else if(User_choice=='S'&&PC_choice=='P'){
                      cout<<User_choice<<">"<<PC_choice<<endl;
              cout<<"You win\n";
              Winner="user";
              break;
        }
          else if(User_choice=='P'&&PC_choice=='R'){
                      cout<<User_choice<<">"<<PC_choice<<endl;
              cout<<"You win\n";
              Winner="user";
              break;
        }
         else if(PC_choice=='R'&&User_choice=='S'){
                      cout<<User_choice<<"<"<<PC_choice<<endl;
             cout<<"You loss\n";
             Winner="pc";
             break;
        }
          else if(PC_choice=='S'&&User_choice=='P'){
                      cout<<User_choice<<"<"<<PC_choice<<endl;
              cout<<"You loss\n";
                  Winner="pc";
                  break;
        }
          else if(PC_choice=='P'&&User_choice=='R'){
                      cout<<User_choice<<"<"<<PC_choice<<endl;
              cout<<"You loss\n";
                  Winner="pc";
                  break;
        }

    }
    cout<<endl;
    print_board();
    bool who_will_start;
    if(Winner == "user"){
            cout<<"You will start first\n\n";
            USER_SIGN_AGAIN:
            cout<<"Please choose (X)/(O)\n\n";
            cin>>user_sign;
            if(user_sign=='X') pc_sign='O';
             else if(user_sign=='O') pc_sign='X';
                else {
                    cout<<"Please make sure that you entered (X) or (O)\n\n";
                goto USER_SIGN_AGAIN;

                    }
    who_will_start=true;
    }
        else if(Winner == "pc"){
             cout<<"PC will start first\n\n";
              srand((unsigned)time(0));
             int rand_sign=1+(rand()%2);
               if(rand_sign==1){
                pc_sign='O',user_sign='X';
               cout<<"Your sign is (X)\n\n";
               }
             else if(rand_sign==2){
                    pc_sign='X',user_sign='O';
                    cout<<"Your sign is (O)\n\n";
               }
        who_will_start=false;
        }
        bool easy_or_hard;
        LVL_AGAIN:
        cout<<"Please (e) for easy level or (h) for hard level\n\n";
        char lvl;
        cin>>lvl;
        if(lvl=='e'){
            easy_or_hard=false;
        }
        else if(lvl=='h'){
             easy_or_hard=true;
        }
        else {
             cout<<"Please make sure that you entered (e) or (h)\n\n";
                goto LVL_AGAIN;
        }
while(1){
        ///PLAYER
        if(who_will_start){
      HERE2:
      int cell;
      cout<<"\nPlease Enter Number of cell you want to play in\n";
      cin>>cell;
      if(cell>9||cell<1){
        cout<<"Please Enter a valid cell from 1 to 9\n\n";
        goto HERE2;
      }
       else if(check_cell(cell)){
        cout<<"This cell is already occupied \n\n";
        goto HERE2;
      }
      else{
        cnt_turns++;
        change_cell(cell,user_sign);
        print_board();
        cnt_user++;
        if(cnt_user>=3){
            if(check_winner(username,user_sign)){
                    cout<<"Congratulations\n\n";
               break;
            }
        }
      }
      if(cnt_turns==9){
                cout<<"No one is winner\n\n";
                break;
            }
      who_will_start=false;
        }
        ///PC
       if(!who_will_start){
         //   print_wait();
            bool good_turn=false,enough=false;
            if(cnt_pc>=2&&easy_or_hard){
                for(int i=1;i<=9;i++){
                   if(!check_cell(i)){
                     change_cell(i,pc_sign);
                   if(check_winner(pc_sign)){
                        print_board();
                    cnt_turns++,cnt_pc++;
                good_turn=true,enough=true;
                        break;
                    }
                    else{
                        undo_cell(i,' ');
                    }
                   }
                }
           }
           if(!enough&&easy_or_hard){
            if(cnt_user>=2&&easy_or_hard){
                    for(int i=1;i<=9;i++){
                   if(!check_cell(i)){
                    change_cell(i,user_sign);
                    if(check_winner(user_sign)){
                        undo_cell(i,' ');
                        change_cell(i,pc_sign);
                        print_board();
                        cnt_turns++,cnt_pc++;
                good_turn=true,enough=true;
                    break;
                    }
                    else{
                        undo_cell(i,' ');
                    }
                   }
                }
            }
           }
           if(!enough){
            if(check_edges()){
                     EDGE:
                int e=1+(rand()%5);
                 if(!check_cell(edge[e])){
                    change_cell(edge[e],pc_sign);
                        print_board();
                        cnt_turns++,cnt_pc++;
                        who_will_start=true;
                 }
                 else
                    goto EDGE;
            }
            else{
            if(!good_turn){
            //cout<<"HERE";
           HERE3:
        srand((unsigned)time(0));
        int PC_cell=1+(rand()%9);
      if(check_cell(PC_cell))
        goto HERE3;
            cnt_turns++;
        change_cell(PC_cell,pc_sign);
        print_board();
        cnt_pc++;
            }
            }
           }
        if(cnt_pc>=3){
            if(check_winner("PC",pc_sign)){
                    cout<<"Hard Luck\n\n";
                  break;
            }
        }
  if(cnt_turns==9){
                cout<<"No one is winner\n\n";
                break;
            }
      who_will_start=true;
       }
}
        board_cell.clear();
        rest_board(board);
cnt_user=0,cnt_pc=0,cnt_turns=0;
      }
        else if(user_option==4){
    print_board();
    srand((unsigned)time(0));
     int turn=1+(rand()%2);
     bool pc_turn;
     if(turn==1) {
         cout<<"PC1 will start\n\n";
             pc1_sign='O',pc2_sign='X';
            pc_turn=true;
     }
       if(turn==2){
           cout<<"PC2 will start\n\n";
          pc1_sign='X',pc2_sign='O';
            pc_turn=false;
     }
     while(1){
            ///PC1
             if(pc_turn){
print_wait();
        ///START
 bool good_turn=false,enough=false;
            if(cnt_pc1>=2){
                for(int i=1;i<=9;i++){
                   if(!check_cell(i)){
                     change_cell(i,pc1_sign);
                   if(check_winner(pc1_sign)){
                        print_board();
                    cnt_turns++,cnt_pc1++;
                good_turn=true,enough=true;
                        break;
                    }
                    else{
                        undo_cell(i,' ');
                    }
                   }
                }
           }
           if(!enough){
            if(cnt_pc2>=2){
                    for(int i=1;i<=9;i++){
                   if(!check_cell(i)){
                    change_cell(i,pc2_sign);
                    if(check_winner(pc2_sign)){
                        undo_cell(i,' ');
                        change_cell(i,pc1_sign);
                        print_board();
                        cnt_turns++,cnt_pc1++;
                good_turn=true,enough=true;
                    break;
                    }
                    else{
                        undo_cell(i,' ');
                    }
                   }
                }
            }
           }
           if(!enough){
            if(check_edges()){
                     EDGE_PC1:
                int e=1+(rand()%5);
                 if(!check_cell(edge[e])){
                    change_cell(edge[e],pc1_sign);
                        print_board();
                        cnt_turns++,cnt_pc1++;
                        pc_turn=false;
                 }
                 else
                    goto EDGE_PC1;
            }
            else{
            if(!good_turn){
            //cout<<"HERE";
           PC1:
        srand((unsigned)time(0));
        int PC_cell=1+(rand()%9);
      if(check_cell(PC_cell))
        goto PC1;
            cnt_turns++;
        change_cell(PC_cell,pc1_sign);
        print_board();
        cnt_pc1++;
            }
            }
           }
        ///END

        if(cnt_pc1>=3){
            if(check_winner("PC1",pc1_sign)){
                   // cout<<"PC2 IS THE WINNER\n\n";
                  break;
            }
        }
  if(cnt_turns==9){
                cout<<"No one is winner\n\n";
                break;
            }
      pc_turn=false;
       }
       ///PC2
           if(!pc_turn){
print_wait();
        ///START
bool good_turn=false,enough=false;
            if(cnt_pc2>=2){
                for(int i=1;i<=9;i++){
                   if(!check_cell(i)){
                     change_cell(i,pc2_sign);
                   if(check_winner(pc2_sign)){
                        print_board();
                    cnt_turns++,cnt_pc2++;
                good_turn=true,enough=true;
                        break;
                    }
                    else{
                        undo_cell(i,' ');
                    }
                   }
                }
           }
           if(!enough){
            if(cnt_pc1>=2){
                    for(int i=1;i<=9;i++){
                   if(!check_cell(i)){
                    change_cell(i,pc1_sign);
                    if(check_winner(pc1_sign)){
                        undo_cell(i,' ');
                        change_cell(i,pc2_sign);
                        print_board();
                        cnt_turns++,cnt_pc2++;
                good_turn=true,enough=true;
                    break;
                    }
                    else{
                        undo_cell(i,' ');
                    }
                   }
                }
            }
           }
           if(!enough){
            if(check_edges()){
                     EDGE_PC2:
                int e=1+(rand()%5);
                 if(!check_cell(edge[e])){
                    change_cell(edge[e],pc2_sign);
                        print_board();
                        cnt_turns++,cnt_pc2++;
                        pc_turn=true;
                 }
                 else
                    goto EDGE_PC2;
            }
            else{
            if(!good_turn){
            //cout<<"HERE";
           PC2:
        srand((unsigned)time(0));
        int PC_cell=1+(rand()%9);
      if(check_cell(PC_cell))
        goto PC2;
            cnt_turns++;
        change_cell(PC_cell,pc2_sign);
        print_board();
        cnt_pc2++;
            }
            }
           }
        ///END
        if(cnt_pc2>=3){
            if(check_winner("PC2",pc2_sign)){
                  //  cout<<"PC2 IS THE WINNER\n\n";
                  break;
            }
        }
  if(cnt_turns==9){
                cout<<"No one is winner\n\n";
                break;
            }
      pc_turn=true;
       }
        }
        board_cell.clear();
        rest_board(board);
cnt_pc1=0,cnt_pc2=0,cnt_turns=0;
        }
     else if(user_option==5){
            ENDPROG:
           std::cout<<"Are you really want to Exit Program "<<std::endl;
     std::cout<<"[Y/N]"<<std::endl<<std::endl;
     char c;
     std::cin>>c;
     std::cout<<std::endl;
     if(c=='Y'){
        std::cout<<"Thanks For Using Our Program (^_^) "<<std::endl;
         break;
     }
         else if(c=='N')
            continue;
            else {
                cout<<"please make sure that you have entered (Y) or (N)\n\n";
                goto ENDPROG;
            }
     }
    else    std::cout<<"Error .. please make sure that you have entered (1),(2),(3),(4) or (5)"<<std::endl<<std::endl;

}
    return 0;
}
