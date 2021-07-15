#include <iostream>

using namespace std;

string map[3][3]{
	{".",".",".\n"},
	{".",".",".\n"},
	{".",".",".\n"}
};

bool gameover = false;
bool totc = true;
bool ttz = false;

void checkgameend(string sym){
	string syminend = sym + "\n";
	if(map[0][0] == sym && map[0][1] == sym && map[0][2] == syminend){
		gameover = true;
		cout << sym << " победил!";
	}
	else if(map[0][0] == sym && map[1][0] == sym && map[2][0] == sym){
		gameover = true;
		cout << sym << " победил!";
	}
	else if(map[2][0] == sym && map[2][1] == sym && map[2][2] == syminend){
		gameover = true;
		cout << sym << " победил!";
	}
	else if(map[0][2] == syminend && map[1][1] == sym && map[2][0] == sym){
		gameover = true;
		cout << sym << " победил!";
	}
	else if(map[0][0] == sym && map[1][1] == sym && map[2][2] == syminend){
		gameover = true;
		cout << sym << " победил!";
	}
	else if(map[0][1] == sym && map[1][1] == sym && map[2][1] == sym){
		gameover = true;
		cout << sym << " победил!";
	}
	else if(map[0][2] == syminend && map[1][1] == sym && map[2][0] == sym){
		gameover = true;
		cout << sym << " победил!";
	}

}

void cellskid(string sym){
	cout << "очередь " << sym << endl;
	int x;
	int y;
	string syminend = sym + "\n";
	do{
		cout << "введи позицию x,y: ";
		cin >> x >> y;
		x -=1; y -=1;
		if(map[x][y] == "X" || map[x][y] == "X\n" || map[x][y] == "O" || map[x][y] == "O\n")
			cout << "клетка занята\n";
	}while(map[x][y] == "X" || map[x][y] == "X\n" || map[x][y] == "O" || map[x][y] == "O\n");
	
	if(x == 0 && y == 2 || x == 1 && y == 2 || x == 2 && y == 2) map[x][y] = syminend;

	else map[x][y] = sym;

	if(sym == "X"){
		totc = false;
		ttz = true;
	}
	else if(sym == "O"){
		totc = true;
		ttz = false;
	}

}

void viewmap(){
	cout << endl;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << map[i][j];
		}
	}
}

void alg(){
	while(!gameover){
		viewmap();
		if(totc){
			cellskid("X");
			checkgameend("X");
		}
		else if(ttz){
			cellskid("O");
			checkgameend("O");
		}
	}

}

int main(){
	setlocale(LC_ALL, "RUS");
	cout << "tictactoe !\nучитесь, двоечники!!";

	alg();
	viewmap();
	return 0;
}