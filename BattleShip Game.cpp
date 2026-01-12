//BattleShip game using only the basic concepts of C++

#include <iostream>
#include<iomanip>
#include <windows.h>
#include <cstdlib>
#include<ctime>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

//player vs player logic
void menu();
void instructions();
void leaderboard();
void message();
void start();
void vsPlayer(char board1[10][10], char board2[10][10]);
int shipCounter(char board[10][10]);
void playerAttack(char opponentBoard[10][10], int &playerScore);
void setRandomShips(char board[10][10]);
void setColor(int textColor=7, int bgColor=0);
void colour();
void clearScreen();
void initializeBoard(char arr[10][10]);
void printBoard(char arr[10][10]); 

//player vs computer logic
void newgame();
void playerVScomputer(char player_board[10][10]);
void placeShips(char arr[10][10]);
void printboard(char arr[10][10]); 
void initializeBoardP(char arr[10][10]);
void initializeBoardC(char arr[10][10]);
void computer_placement(char arr[10][10]);
void game_commence();
void player_attack(char opponentBoard[10][10]);
void computer_attack(char arr[10][10]);
void updatescoreP(int &score);
void updatescoreC(int &score);
void player_random(char arr[10][10]);
void printMainBoard();
void showGameMenu();



// variable defined for player vs player 
int choice;
string player1 , player2;
int color;

// variable defined for player vs computer
char player_board[10][10];       
char board[10][10];              
int colorVAL;                    
bool hit;                        
bool hideshipP;                  
static int scoreP = 0;           
static int scoreC = 0;           


//the logic of the game starts from here

void setColor(int textColor, int bgColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}

//color function 
void colour()
{
	
	cout<<"\n Choose your battleship Color : \n";
    cout<<" \nBlue = 1, Green = 2, Cyan = 3, \nRed = 4, Purple = 5, Yellow = 6, \nWhite = 7 \n";
    cin>>color;
    
    setColor(7,0);
     if(color<1 || color>7)
    {
    	cout<<"Invlid Input! (Enter again)"<<endl;
    	getch();
    	colour();	
	}
	
    colorVAL = color; 
}

//clear screen function
void clearScreen()
{
	system("CLS");
}

//initializing board player vs player 
void initializeBoard(char board[10][10])
{
	
    for(int i=0; i<10; i++)
    {
	
    	for(int j=0; j<10; j++)
    	{
    		
    		board[i][j] = '~';
    		
    	}
    }
}


void initializeBoardP(char arr[10][10]) 
{
    initializeBoard(arr);
}

void initializeBoardC(char arr[10][10]) // PvC wrapper
{
    initializeBoard(arr);
}

//using for player score in player vs computer
void updatescoreP(int &score) 
{
    if(hit)
    {
        score += 10;
    }
    else
    {
        score -= 1;
    }
}

//uing for computer score in player vs computer
void updatescoreC(int &score) 
{
    if(hit)
    {
        score += 10;
    }
    else
    {
        score -= 1;
    }
}

// Board printing in player vs player 
void printBoard(char arr[10][10])
{
	
	cout << "     ";
    for(int j=0; j<10; j++)
    {
        cout << j << "   ";
    }
    cout<<endl;
    for(int i=0; i<10; i++)
    {
    	cout << i << " ";
        if (i < 10)
		{
		 cout << " ";
	    }
    	for(int j=0; j<10; j++)
    	{
    	
    		cout<<"|";
    		
    		int bgcolor=1;
    		char cell = arr[i][j];
            
    		if (cell == 'A' || cell == 'B' || cell == 'D' || cell == 'S' || cell == 'P')
    		{
    			bgcolor = color;
			}
			else if( cell== 'O')
			{
				bgcolor = 8;
			}
			else if(cell == 'X')
			{
				bgcolor = 12;
			}
    		
    		setColor(7,bgcolor);
    		cout<<" ";
			cout<<arr[i][j];
			cout<<" ";
			setColor(7,0);
    		
    	}
    	
    	cout<<"|"<<endl;
    	
    	
    }
    
}

// Board printing in player vs computer
void printboard(char arr[10][10])
{
	
	bool CompBoardDetect = true;
    
    // Checking if the array is of computer board
    for (int k = 0; k < 10; k++) 
    {
        for (int l = 0; l < 10; l++) 
        {
            if (arr[k][l] != board[k][l]) 
            {
                CompBoardDetect = false;
                break;
            }
        }
        if (!CompBoardDetect) 
        {
            break;
        }
    }
	
	
	int colorval=color;
 
    // Print column headers (hardcoded)
    cout << "        0     1     2     3     4     5     6     7     8     9  " << endl;

    // Top border
    cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;

    for (int j=0;j<10;j++)
    {
        cout << "  " << j << " ¦"; 
        for (int i = 0; i < 10; i++)
        {
            char cell = arr[j][i];
            
            if (cell == 'O') 
            { 
                setColor(0, 8); 
                cout << "  O  "; 
                setColor(7,0); 
            }
            
            else if (cell == 's' || cell == 'a' || cell == 'b' || cell == 'd' || cell == 'p') 
            { 
                setColor(15, 12); 
                cout << "  X  "; 
                setColor(7,0); 
            }
            
            else if (cell == 'H') 
            { 
                setColor(15,5); 
                cout << "  X  "; 
                setColor(7,0); 
            } 
            
            else if ((cell == 'S' || cell == 'A' || cell == 'B' || cell == 'D' || cell == 'P') && hideshipP == false && CompBoardDetect == false)
            { 
                setColor(7,colorval); 
                cout << "  S  "; 
                setColor(7,0);
            }
            
            else 
            { 
                setColor(7, 1); 
                cout << "  ~  "; 
                setColor(7,0); 
            } 
            cout << "¦";
        }
        cout << endl;
        cout << "    +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
    }
}


//ship counter for counting ships which helps in deciding the winner/looser of the game
int shipCounter(char board[10][10])
{
	int count = 0;
	
	for(int i = 0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(board[i][j]=='A' || board[i][j]=='B' || board[i][j]=='D' || board[i][j]=='S' || board[i][j]=='P')
			{
				count++;
			}
		}
	}

    return count;

}


// For random placement of the ships
void random_placement(char arr[10][10])
{
    initializeBoard(arr);
    int x, y;
    bool valid;
    int decider;

    
    do 
    {
        decider = rand()%2; 
        valid = true;
        if (decider) 
        {
            x = rand()%8; 
            y = rand()%10;
            for(int i=0;i<3;i++) 
            {
                if(arr[y][x+i]!='~') 
                {
                    valid = false;
                }
            }
        } 
        else 
        {
            x = rand()%10; 
            y = rand()%8;
            for(int i=0;i<3;i++) 
            {
                if(arr[y+i][x]!='~') 
                {
                    valid = false;
                }
            }
        }
    } while(!valid);
    if(decider) 
    {
        for(int i=0;i<3;i++) 
        {
            arr[y][x+i]='S';
        }
    }
    else 
    {
        for(int i=0;i<3;i++) 
        {
            arr[y+i][x]='S';
        }
    }

    
    do 
    {
        decider = rand()%2; 
        valid = true;
        if(decider) 
        {
            x = rand()%8; 
            y = rand()%10;
            for(int i=0;i<3;i++) 
            {
                if(arr[y][x+i]!='~') 
                {
                    valid=false;
                }
            }
        } 
        else 
        {
            x = rand()%10; 
            y = rand()%8;
            for(int i=0;i<3;i++) 
            {
                if(arr[y+i][x]!='~') 
                {
                    valid=false;
                }
            }
        }
    } while(!valid);
    if(decider) 
    {
        for(int i=0;i<3;i++) 
        {
            arr[y][x+i]='D';
        }
    }
    else 
    {
        for(int i=0;i<3;i++) 
        {
            arr[y+i][x]='D';
        }
    }

     
    do 
    {
        decider = rand()%2; 
        valid = true;
        if(decider) 
        {
            x = rand()%9; 
            y = rand()%10;
            for(int i=0;i<2;i++) 
            {
                if(arr[y][x+i]!='~') 
                {
                    valid=false;
                }
            }
        } 
        else 
        {
            x = rand()%10; 
            y = rand()%9;
            for(int i=0;i<2;i++) 
            {
                if(arr[y+i][x]!='~') 
                {
                    valid=false;
                }
            }
        }
    } while(!valid);
    if(decider) 
    {
        for(int i=0;i<2;i++) 
        {
            arr[y][x+i]='P';
        }
    }
    else 
    {
        for(int i=0;i<2;i++) 
        {
            arr[y+i][x]='P';
        }
    }

     
    do 
    {
        decider = rand()%2; 
        valid = true;
        if(decider) 
        {
            x = rand()%7; 
            y = rand()%10;
            for(int i=0;i<4;i++) 
            {
                if(arr[y][x+i]!='~') 
                {
                    valid=false;
                }
            }
        } 
        else 
        {
            x = rand()%10; 
            y = rand()%7;
            for(int i=0;i<4;i++) 
            {
                if(arr[y+i][x]!='~') 
                {
                    valid=false;
                }
            }
        }
    } while(!valid);
    if(decider) 
    {
        for(int i=0;i<4;i++) 
        {
            arr[y][x+i]='B';
        }
    }
    else 
    {
        for(int i=0;i<4;i++) 
        {
            arr[y+i][x]='B';
        }
    }

     
    do 
    {
        decider = rand()%2; 
        valid = true;
        if(decider) 
        {
            x = rand()%6; 
            y = rand()%10;
            for(int i=0;i<5;i++) 
            {
                if(arr[y][x+i]!='~') 
                {
                    valid=false;
                }
            }
        } 
        else 
        {
            x = rand()%10; 
            y = rand()%6;
            for(int i=0;i<5;i++) 
            {
                if(arr[y+i][x]!='~') 
                {
                    valid=false;
                }
            }
        }
    } while(!valid);
    if(decider) 
    {
        for(int i=0;i<5;i++) 
        {
            arr[y][x+i]='A';
        }
    }
    else 
    {
        for(int i=0;i<5;i++) 
        {
            arr[y+i][x]='A';
        }
    }
}

// Optional for player and compulsory for computer placement
void player_random(char arr[10][10]) 
{
    random_placement(arr);
}

void computer_placement(char arr[10][10]) 
{
    random_placement(arr);
}

// A function which handles both manual and random placement in accordance to the requirements of the user
void setRandomShips(char board[10][10]) 
{
	int boards[5] = {5,4,3,3,2}; 
    char boardch[5] = {'A', 'B', 'D', 'S', 'P'};
    int row, col;
    char place;
	bool placed = true;
	
	char placement;
	cout<<"\n Do you want to place your ships Manually or Randomly (M/R) : ";
	cin>>placement;
	
	if(placement!= 'M' && placement != 'R')
	{
		cout<<"INAVLID INPUT!"<<endl;
		getch();
        setRandomShips(board); 
        return;
	}
	
	// Function inside the if-statement for the manual placement
	if(placement=='M')
	{
 
        for(int d=0; d<5; d++)
        {
            int size = boards[d];
            char shipch = boardch[d];
            
            do 
            {
                placed = true;
            
                cout<<" Placing ship of size "<< size <<endl<<endl;
                cout<<"Enter the row (0-9): ";
                cin>>row; 
                if(row<0 || row>9) 
                { 
                    cout<<"Invalid Input!"<<endl; 
                    continue; 
                }
                
                cout<<"Enter the column (0-9): ";
                cin>>col;
                
                if(col<0|| col>9) 
                { 
                    cout<<"Invalid Input!"<<endl; 
                    continue; 
                }

                cout<<"Do you want to place the ship Vertical (Y/N): ";
                cin>>place;
                clearScreen();
                if(place!='Y' && place!='N') 
                { 
                    cout<<" Invalid input! "<<endl; 
                    continue; 
                }
                
                if(place=='Y') 
                {
                    if(row + size > 10) 
                    { 
                        cout<<" Ship does not fit vertically try again !"<<endl<<endl; 
                        placed = false; 
                        continue; 
                    }
                    for(int k=0; k<size; k++) 
                    {
                        if(board[row + k][col] != '~') 
                        {
                            cout<<" The ships are overlapping! select any-other cell  : ";
                            placed = false; 
                            break;
                        }
                    }
                }
                else if(place=='N') 
                {
                    if(col + size > 10) 
                    { 
                        cout<<" Ship does not fit horizontally try again !"<<endl<<endl; 
                        placed = false; 
                        continue; 
                    }
                    for(int k=0; k<size; k++) 
                    {
                        if(board[row][col + k] != '~') 
                        {
                            cout<<" The ships are overlapping! select any-other cell  : ";
                            placed = false; 
                            break;
                        }
                    }
                }
            } while(!placed);

            if(placed)
            {
                if(place == 'Y') 
                {
                    for (int k = 0; k < size; k++) 
                    {
                        board[row + k][col] = shipch;
                    }
                }
                else if(place == 'N') 
                {
                    for (int k = 0; k < size; k++) 
                    {
                        board[row][col + k] = shipch;
                    }
                }
            }
                        
            clearScreen();
            cout<< " \n\t--- Updated Board ---\n"<<endl;
            printBoard(board);
            getch();
        }
    }

	
	// Calling function for the random placement of the ships 
    if(placement=='R') 
    {
        random_placement(board);
        clearScreen();
        cout << "Random placement complete." << endl;
        printBoard(board);
        getch();
    }	
				
}

// PLacing ships for the player vs computer part of the game
void placeShips(char arr[10][10]) 
{
    char randomchoice;

	cout << "Do you wish to place your ships randomly?(Y/N)";
	cin >> randomchoice;
	while (randomchoice != 'Y' && randomchoice != 'N')
    {
		cout << "Please enter a valid option:";
		cin >> randomchoice;
	}
	if (randomchoice=='Y')
    {
		player_random(arr);
	}
	else
	{
        setRandomShips(arr); 
    }
    
	clearScreen();
	cout << endl << "ALL ships have been successfully placed!" << endl;
	printboard(arr);

	char hidechoice;
	cout << endl << "Do you wish to hide your ships?(Y/N)";
	cin >> hidechoice;
	while (hidechoice!='Y' && hidechoice!='N')
	{
		cout << endl << "Please enter a valide choice:";
		cin >> hidechoice;
	}
	hideshipP = (hidechoice == 'Y'); 
		
	clearScreen();
	game_commence(); 
}

// Attack logic for the Player vs Player part of the game 
void playerAttack(char opponentBoard[10][10], int &playerScore) // PvP Attack
{
	int row,col;
	int nattacks = 6;
	
	//checking for the number of ships sank
	bool hasA = false;
	bool hasB = false;
	bool hasD = false;
	bool hasS = false;
	bool hasP = false;
	
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(opponentBoard[i][j] == 'A') 
			{
			    hasA = true;
			}
			if( opponentBoard[i][j] == 'B') 
			{
			    hasB = true;
			}
			if(opponentBoard[i][j] == 'D' ) 
			{
			    hasD = true;
			}
			if(opponentBoard[i][j] == 'S' ) 
			{
			    hasS = true;
			}
			if(opponentBoard[i][j] == 'P' ) 
			{
			    hasP = true;
			}
		}		
	}
	
	// Checks for each of the ships that has sunk so that the number attacks can change in accordance to it
	if(!hasA || !hasB || !hasD || !hasP || !hasS) 
	{
	    nattacks = 5;
	}
    if((!hasA && !hasB) || (!hasA && !hasD) || (!hasA && !hasS) || (!hasA && !hasP) ||
        (!hasB && !hasP) || (!hasB && !hasS) || (!hasB && !hasD) || (!hasS && !hasP)|| (!hasS && !hasD)|| (!hasP && !hasD)) 
    {
        nattacks = 4;
    }
    if((!hasA && !hasB && !hasD) || (!hasA && !hasB && !hasS) || (!hasA && !hasB && !hasP) || (!hasA && !hasS && !hasP)
        || (!hasA && !hasS && !hasD) || (!hasS && !hasB && !hasP) || (!hasB && !hasS && !hasD) || (!hasP && !hasB && !hasD) || (!hasS && !hasP && !hasD)) 
    {
        nattacks = 3;
    }
    if((!hasA && !hasB && !hasD &&!hasS) || (!hasA && !hasB && !hasP &&!hasS) || (!hasA && !hasP && !hasD &&!hasS)
        || (!hasA && !hasB && !hasD &&!hasP) || (!hasP && !hasB && !hasD &&!hasS)) 
    {
        nattacks = 2;
    }
    if(!hasA && !hasB && !hasD && !hasS && !hasP) 
    {
        nattacks = 1;
    }
							
	cout<<" You have "<<nattacks<<" attacks this turn!" << endl;
	cout<<" Your current score is : "<<playerScore << endl;

	//attacks starts from here
	for(int i=0; i<nattacks; i++)
	{
		
        cout<<" Attack "<<i+1<<" of "<<nattacks<<". Enter the row (0-9): ";
        cin>>row;
        if(row<0 || row>9) 
        { 
            cout<<"Invalid Input!"<<endl; 
            getch(); 
            i--; 
            continue; 
        }
        
        cout<<" Attack "<<i+1<<" of "<<nattacks<<". Enter the col (0-9): ";
        cin>>col;
        if(col<0 || col>9) 
        { 
            cout<<"Invalid Input!"<<endl; 
            getch(); 
            i--; 
            continue; 
        }
        
        if(opponentBoard[row][col] == 'X' || opponentBoard[row][col] == 'O' )
        {
            cout<<"\n You have already attacked this cell! Select another cel : \n";
            i--;
            getch();
            continue;	
        }

        if(opponentBoard[row][col] != '~' )
        {
            opponentBoard[row][col] = 'X';
            playerScore+=10;
            cout<<"\a"<<" HIT! (+10)  \n Score : "<<playerScore;
            cout<<endl;
        }
        
        else if(opponentBoard[row][col] == '~' )
        {
            opponentBoard[row][col] = 'O';
            playerScore-=1;
            cout<<" MISS! (-1)  \n Score : "<<playerScore;
            cout<<endl;
        }
		cout<<endl;
	}
		

    cout<<" Your Total score is  : "<<playerScore;
    cout<<endl;
}

// Player attack logic for Player vs Computer part of the game
void player_attack(char opponentBoard[10][10]) 
{

	int row,col;
	int nattacks = 6;
	
    bool hasA=false, hasB=false, hasD=false, hasS=false, hasP=false;
    for(int i=0; i<10; i++) 
    {
        for(int j=0; j<10; j++) 
        {
            if(board[i][j] == 'A') 
            {
                hasA = true;
            }
            if(board[i][j] == 'B') 
            {
                hasB = true;
            }
            if(board[i][j] == 'D') 
            {
                hasD = true;
            }
            if(board[i][j] == 'S') 
            {
                hasS = true;
            }
            if(board[i][j] == 'P') 
            {
                hasP = true;
            }
        }
    }
    
	if(!hasA || !hasB || !hasD || !hasP || !hasS) 
	{
	    nattacks = 5;
	}
    if((!hasA && !hasB) || (!hasA && !hasD) || (!hasA && !hasS) || (!hasA && !hasP) ||
        (!hasB && !hasP) || (!hasB && !hasS) || (!hasB && !hasD) || (!hasS && !hasP)|| (!hasS && !hasD)|| (!hasP && !hasD)) 
    {
        nattacks = 4;
    }
    if((!hasA && !hasB && !hasD) || (!hasA && !hasB && !hasS) || (!hasA && !hasB && !hasP) || (!hasA && !hasS && !hasP)
        || (!hasA && !hasS && !hasD) || (!hasS && !hasB && !hasP) || (!hasB && !hasS && !hasD) || (!hasP && !hasB && !hasD) || (!hasS && !hasP && !hasD)) 
    {
        nattacks = 3;
    }
    if((!hasA && !hasB && !hasD &&!hasS) || (!hasA && !hasB && !hasP &&!hasS) || (!hasA && !hasP && !hasD &&!hasS)
        || (!hasA && !hasB && !hasD &&!hasP) || (!hasP && !hasB && !hasD &&!hasS)) 
    {
        nattacks = 2;
    }
    if(!hasA && !hasB && !hasD && !hasS && !hasP) 
    {
        nattacks = 1;
    }


    cout << "\nYOUR TURN: You have "<<nattacks<<" attacks!\n";
    cout << "Your cuurent score is :" << scoreP << endl;

    for(int i = 0; i < nattacks; i++)
    {
        cout << "\nAttack " << i+1 << "/"<<nattacks<<"\n";
        cout << "Row: ";
        cin >> row;
        cout << "Column: ";
        cin >> col;

        while(row < 0 || row > 9 || col < 0 || col > 9)
        {
            cout << "Invalid! Re-enter row and column: ";
            cin >> row >> col;
        }

        
        if (opponentBoard[row][col]=='s' || opponentBoard[row][col]=='b' || opponentBoard[row][col]=='p' ||
		     opponentBoard[row][col]=='d' || opponentBoard[row][col]=='a' || opponentBoard[row][col]=='O')
        {
            cout << "Already attacked!\n";
            i--; 
            continue;
        }

         
        if(opponentBoard[row][col]=='S'||opponentBoard[row][col]=='D'||opponentBoard[row][col]=='P'||opponentBoard[row][col]=='B'
		     ||opponentBoard[row][col]=='A')
        {
            cout << "HIT!" << endl;
        	opponentBoard[row][col] += 32;
            hit=true;
        }
        else
        {
            cout << "MISS!" << endl;
            opponentBoard[row][col]='O';
            hit=false;
        }

        updatescoreP(scoreP);
        cout << "Current score: " << scoreP << endl;
        hit=true; 
    }
}

// Computer attack for the player vs computer part of the game
void computer_attack(char opponentBoard[10][10]) 
{
	static int nattacks = 6;
	
    
    bool hasA=false, hasB=false, hasD=false, hasS=false, hasP=false;
    for(int i=0; i<10; i++) 
    {
        for(int j=0; j<10; j++) 
        {
            if(board[i][j] == 'A') 
            {
                hasA = true;
            }
            if(board[i][j] == 'B') 
            {
                hasB = true;
            }
            if(board[i][j] == 'D') 
            {
                hasD = true;
            }
            if(board[i][j] == 'S') 
            {
                hasS = true;
            }
            if(board[i][j] == 'P') 
            {
                hasP = true;
            }
        }
    }
    
	if(!hasA || !hasB || !hasD || !hasP || !hasS) 
	{
	    nattacks = 5;
	}
    if((!hasA && !hasB) || (!hasA && !hasD) || (!hasA && !hasS) || (!hasA && !hasP) ||
        (!hasB && !hasP) || (!hasB && !hasS) || (!hasB && !hasD) || (!hasS && !hasP)|| (!hasS && !hasD)|| (!hasP && !hasD)) 
    {
        nattacks = 4;
    }
    if((!hasA && !hasB && !hasD) || (!hasA && !hasB && !hasS) || (!hasA && !hasB && !hasP) || (!hasA && !hasS && !hasP)
        || (!hasA && !hasS && !hasD) || (!hasS && !hasB && !hasP) || (!hasB && !hasS && !hasD) || (!hasP && !hasB && !hasD) || (!hasS && !hasP && !hasD)) 
    {
        nattacks = 3;
    }
    if((!hasA && !hasB && !hasD &&!hasS) || (!hasA && !hasB && !hasP &&!hasS) || (!hasA && !hasP && !hasD &&!hasS)
        || (!hasA && !hasB && !hasD &&!hasP) || (!hasP && !hasB && !hasD &&!hasS)) 
    {
        nattacks = 2;
    }
    if(!hasA && !hasB && !hasD && !hasS && !hasP) 
    {
        nattacks = 1;
    }

	
    for (int i = 0; i < nattacks; i++)
    {
        int x, y;

        do
        {
            x = rand()%10;
            y = rand()%10;
        }
        
        while(opponentBoard[x][y]=='s' || opponentBoard[x][y]=='b' || opponentBoard[x][y]=='p' ||
		     opponentBoard[x][y]=='d' || opponentBoard[x][y]=='a' || opponentBoard[x][y]=='O');

        
        if(opponentBoard[x][y]=='S' || opponentBoard[x][y]=='A' || opponentBoard[x][y]=='B' || opponentBoard[x][y]=='D' || opponentBoard[x][y]=='P')
		{
            opponentBoard[x][y]+=32; 
            hit=true;
            updatescoreC(scoreC);
        }
        else
		{
            opponentBoard[x][y]='O';
            hit=false;
            updatescoreC(scoreC);
            hit=true; 
        }
    }
    cout << "Computer score is currently:" << scoreC << endl;
    
}

// PLayer vs player logic for the pvp part of the game
void vsPlayer(char board1[10][10], char board2[10][10])
{
	
	cout<<" Enter Player 1 name : ";
    cin>>player1;
    cout<<" Enter Player 2 name : ";
    cin>>player2;
    clearScreen(); 
    cout<<" "<<player1 <<" - Place your ships : "<<endl;
    
    colour();
    initializeBoard(board1);
    printBoard(board1);
    setRandomShips(board1);
    
    
    cout<<endl<<endl<<endl;
    
    
    cout<<" "<<player2 <<" - Place your ships : "<<endl;
    
    colour();
    initializeBoard(board2);
	 clearScreen();	
    printBoard(board2);
    setRandomShips(board2);
    
}

// player vs computer logic for the pvc part of the game

void vsComputer(char player_board[10][10]) // PvC Setup
{
    string playername;
    
    cout << "Enter player name: ";
    cin >> playername;

    colour();
    
    initializeBoard(player_board);
    placeShips(player_board); 
}

//Game loop for Player vs Computer part of the game
void game_commence() 
{
	cout << "The computer is now placing its ships!!!" << endl;
	computer_placement(board);
    int count = 0;
    
    scoreP = 0;
    scoreC = 0;
    hit = false;

    do
    {
        cout << "YOUR TURN!" << endl;
        player_attack(board); 
        printboard(board);

        cout << endl << "COMPUTER TURN..." << endl;
        computer_attack(player_board); 
        printboard(player_board);
        
        getch(); 
        
        count++;

    } while(shipCounter(player_board)>0 && shipCounter(board)>0);
    
    // Game winning logic 
    clearScreen();
    cout<<"\t === GAME OVER === \t"<<endl;
    if(shipCounter(board)==0)
    {
        cout<<"\t PLAYER WINS! by sinking all enemy ships!"<<endl;
    }
    else if(shipCounter(player_board)==0)
    {
        cout<<"\t COMPUTER WINS! by sinking all player ships!"<<endl;
    }
    else if(scoreP > scoreC)
    {
        cout<<"\t PLAYER WINS! on score!"<<endl;
    }
    else if(scoreC > scoreP)
    {
        cout<<"\t COMPUTER WINS! on score!"<<endl;
    }
    else
    {
        cout<<"\t IT'S A DRAW "<<endl;
    }

    cout<<" Player Score : "<<scoreP<<endl;
    cout<<" Computer Score : "<<scoreC<<endl;

    getch();
    menu(); 
}

//Game logic sleection of different modes of the game either pvp or pvc
void start() 
{
    clearScreen();
    int choose;
    
    cout<<" ---------------------------------------"<<endl<<endl;
    cout<<" \t\t Start New Game \t "<<endl<<endl;
    cout<<" ---------------------------------------"<<endl<<endl;
    cout<<" 1. Player vs Player "<<endl;
    cout<<" 2. Player vs Computer "<<endl;
    cin>>choose;

    if(choose <1 || choose > 2)
    {
        cout<<" Invalid Choice! (Enter again)"<<endl;
        getch();
        clearScreen();
        start();
        return;
    }
	
	//For player vs player game 
	if(choose==1)
	{
		int p1score = 0;
		int p2score = 0;
		char p1board[10][10]; 
		char p2board[10][10];
		
		vsPlayer(p1board, p2board);

       // Check for the pvp game 
		while(shipCounter(p1board)>0 && shipCounter(p2board)>0)
        {
            
            clearScreen();
            cout<<" Player 1 : "<<player1<<" your turn to attack : "<<endl;
            printBoard(p2board);
            clearScreen();
            playerAttack(p2board, p1score);
            printBoard(p2board);
            
            
            getch();

            clearScreen();
            cout<<" Player 2 : "<<player2<<" your turn to attack : "<<endl<<endl;
            printBoard(p1board);
            clearScreen();
            playerAttack(p1board, p2score);
            printBoard(p1board);
            
            getch();
        }

		cout<<endl<<endl;
	
		cout<<"\t === GAME OVER === \t"<<endl;
		
		if(shipCounter(p2board)==0)
		{
			cout<<"\t Player 1 "<<player1<<" WINS! by sinking ships!"<<endl;
		}
		else if(shipCounter(p1board)==0)
		{
			cout<<"\t Player 2 "<<player2<<" WINS! by sinking ships!"<<endl;
		}
		else if(p1score>p2score)
		{
			cout<<"\t Player 1 "<<player1<<" WINS! by score!"<<endl;
		}
		else if(p1score<p2score)
		{
			cout<<"\t Player 2 "<<player2<<" WINS! by score!"<<endl;
		}
		else
		{
			cout<<"\t IT'S A DRAW "<<endl;
		}
		
		cout<<" "<<player1<<"  Score : "<<p1score<<endl;
		cout<<" "<<player2<<"  Score : "<<p2score<<endl;
        getch();
        menu(); 
		
	}
	
	//For Player vs Computer
	if(choose==2)
	{
		 vsComputer(player_board);
		
	}
}

// menu page for selecting different options which are available in the game

void menu()
{
    cout<<" =======================================" << endl << endl;
    cout<<" \tWELCOME TO BATTLESHIP GAME \t" <<endl<<endl; 
    cout<<" =======================================" << endl << endl;
    cout<<"\t\t MAIN MENU \t"<<endl;
    cout<<" ---------------------------------------"<<endl;
    cout<<" 1. Start New Game"<<endl;
    cout<<" 2. Instructions"<<endl;
    cout<<" 3. View Leaderboard"<<endl;
    cout<<" 4. Exit"<<endl;
    cout<<" ---------------------------------------"<<endl;
    cout<<" Enter your choice (1-4) : ";
    cin>>choice;
	
    if(choice<1 || choice>4)
    {
    	cout<< " INVALID INPUT! (Enter again)"<<endl;
    	getch();
    	clearScreen();
    	menu();
		 	
	}
    cout<<endl;

    
}

// Instructions for the game 
void instructions()
{
    clearScreen();
    cout<<" ---------------------------------------"<<endl<<endl;
    cout<<" \t\t INSTRUCTIONS \t\t"<<endl<<endl;
    cout<<" ---------------------------------------"<<endl;
    cout<<" 1. Place your ships on the board. "<<endl;
    cout<<" 2. You and your opponent (Player or Computer) take turns firing the shots. "<<endl; 
    cout<<" 3. 'O' means MISS, 'X' means HIT. "<<endl;
    cout<<" 4. Sink all enemy ships to win! "<<endl;
    cout<<" 5. Your score is based on accuracy and speed. "<<endl;
    cout<<" ---------------------------------------"<<endl<<endl;
    cout<<" (Press any key to return to Main Menu ...)"<<endl;
    getch();
    clearScreen();
    menu();
    
    
}

// LeaderBoard which stores the highscores of the players
void Leaderboard() {
    ifstream file("leaderboard.txt");

    clearScreen();
    cout << "LEADERBOARD\n\n";

    if (!file) {
        cout << "No records found.\n";
        getch();
        return;
    }

    string name[50];
    int score[50];
    int n = 0;

    // Read file data
    while (file >> name[n] >> score[n]) {
        n++;
    }
    file.close();

    // highest score first
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (score[j] < score[j + 1]) {
                int tempScore = score[j];
                score[j] = score[j + 1];
                score[j + 1] = tempScore;

                string tempName = name[j];
                name[j] = name[j + 1];
                name[j + 1] = tempName;
            }
        }
    }

    // Display leaderboard
    cout << "NAME\tSCORE\n";
    for (int i = 0; i < n; i++) {
        cout << name[i] << "\t" << score[i] << endl;
    }

    cout << "\nPress any key to return...";
    getch();
}

// main game function in which all of the functions merge to start the game 
void showGameMenu()
{
	clearScreen();
	menu();
    
	if(choice==1)
	{
		start();
	}	
	if(choice==2)
	{
		instructions();
	}
	if(choice==3)
	{
		leaderboard();
	}
	if(choice==4)
	{
		message();
	}

}


// The main where it all begins and ends at the same time ;)
int main()
{
	srand(time(0));
    showGameMenu();
    return 0;
}
