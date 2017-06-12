#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void squaregrid (int a, int b);
void introduction();
void totalgrid();
void player1();
void final(int a, int b, int c);
void totalwinning();


string realthing[9];
string thing[9]={"1","2","3","4","5","6","7","8","9"};
string alphabet;
string alphabet2;
int f;
string choice;
int g;


int main(){

	introduction();


	cout << "Okay, so here is the grid." << endl;
	totalgrid();

	cout << "The box is labelled from 1 to 9" << endl;
	cout << "To choose the box, just enter a number from 1 to 9" << endl;

	player1();

	return 0;
}

void introduction(){
	cout << "Welcomeee to this tic tac toe game" << endl;
	cout << "For player 1, pls choose whether do you want to use 'X' or 'O'" << endl;
	cout << "If player 1 want to choose 'X', pls insert capital X not small letter x.";
	cout << "Same thing if you want to use 'O'. If you do input small letter x or o, you will get a warning."<< endl;

	
	while (true){
		cin >> alphabet;
		if (alphabet!="O" && alphabet!="X"){
			cout << "Pls enter capital X or O, depending on which player 1 want to use" << endl;
			cout << "Enter ypur input: " << endl;
		} 
		else {
			break;
		}


	}
	if (alphabet=="O"){
		alphabet2="X";
	}
	else {
		alphabet2="O";
	}

	cout << "Therefore, player 1 will be: " << alphabet << " while player 2 will be: " << alphabet2 << endl;


}

void squaregrid (int a, int b){

	for (int i=0; i<3; i++){
		cout << " "<< "-----";
		if (i==2){
			cout << '\n';
		}

		
	}

	for (int i=0; i<3; i++){
		cout << "|" << "     ";
		if (i==2){
			cout << "|";
			cout << '\n';
		}
	}
	for (int c=a ; c<b; c++){
		cout << "|" << "  " << thing[c] << "  ";
		if (c==a+2){
			cout << "|";
			cout << '\n';
		}
	}
	for (int i=0; i<3; i++){
		cout << "|" << "     ";
		if (i==2){
			cout << "|";
			cout << '\n';
		}
	}

}	

void totalgrid(){
	squaregrid(0,3);
	squaregrid(3,6);
	squaregrid(6,9);

	for (int i=0; i<3; i++){
		cout << " "<< "-----" ;
	}
	cout << '\n';

}

void player1(){
	int move[9];
	int decision[9];
	int y=0;
	int w;
	for (int z=0; z<10; z++){
		if(y==0){
			cout << "Player 1 turn. Pls insert number." << endl;
			cout << "DO NOT INPUT STRING OR YOU WILL GET AN ERROR" << endl;
			y= 1;  
		}
		else if (y==1){
			cout << "Player 2 turn. Pls insert number." << endl;
			cout << "DO NOT INPUT STRING OR YOU WILL GET AN ERROR" << endl;
			y= 0;
		}
		
		cin >> move[z];

		
		while (true){
			loop2:
			switch (move[z]){
				case 1: 
					goto ended;
					break;
				case 2: 
					goto ended;
					break;
				case 3: 
					goto ended;
					break;
				case 4:
					goto ended; 
					break;
				case 5: 
					goto ended;
					break;
				case 6: 
					goto ended;
					break;
				case 7: 
					goto ended;
					break;
				case 8: 
					goto ended;
					break;
				case 9: 
					goto ended;
					break;					
			}

			cout << "Pls enter the number between the range from 1 to 9" << endl;
			cout << "Enter new number: " << endl;
			cin >> move[z];
			goto loop2;
		}

		ended:

		decision[z] = move[z];


		if (z!=0){
			loop:
			for (int correct=0; correct<z ; correct++){
				if (move[z]!= decision[correct]){
					continue;
				}
				else {
					cout << "Pls dont enter the number which has been previously entered." << endl;
					cout << "Pls enter a new number: " << endl;
					cin >> move[z];
					goto loop2;
					goto loop;
				}

			}

		}

			if (y==1){
				w= move[z]-1;
				thing[w]= alphabet;
				totalgrid();

			}
			else if (y==0){
				w= move[z]-1;
				thing[w]= alphabet2;
				totalgrid();
			}

			totalwinning();
			if (f==1){
				break;
			}

			if (z==9){
				cout << "Draw!" << endl;
			}		
		
	}
		
}

void final(int a, int b, int c){
		

		if (thing[a]==thing[b] && thing[a]== thing[c] ){
			if (thing[a]==alphabet){
				cout << "Player 1 Win!" << endl;
				f=1;
			}
			else if (thing[a]==alphabet2){
				cout << "Player 2 Win!" << endl;
				f=1;
			}

		}
}

void totalwinning(){
	final (0,1,2);
	final (3,4,5);
	final (6,7,8);
	final (0,3,6);
	final (1,4,7);
	final (2,5,8);
	final (0,4,8);
	final (2,4,6);
}








	