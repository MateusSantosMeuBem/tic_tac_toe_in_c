#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define lg 3

// Draw our game in screen
void drawHash(char mtz[3][3]){
	printf("\n\t  %c | %c | %c\n", mtz[0][0], mtz[0][1], mtz[0][2]);
	printf("\t-------------\n");
	printf("\t  %c | %c | %c\n", mtz[1][0], mtz[1][1], mtz[1][2]);
	printf("\t-------------\n");
	printf("\t  %c | %c | %c\n\n", mtz[2][0], mtz[2][1], mtz[2][2]);
}

// Verify is any player has been won
int verifyResult(char mtz[3][3], char aux_m){
	int c = 0;
	//	Replace '_' to 'X' or 'O' to verify just with this
	//	this players
	for (int i = 0; i < lg; i++){
		for (int j = 0; j < lg; j++){
			if (mtz[i][j] == '_'){
				mtz[i][j] = aux_m;
			}
			// Count how many turns are left
			if(mtz[i][j] == ' '){
				c++;
			}
		}	
	}
	
	//	Verify in there is only 'X' or 'O' in horizontals or verticals
	//	if there is, see which player just played, give it the victory
	//	and it returns 0 to finish the game
	for (int i = 0; i < lg; i++){
		if(((mtz[i][0] == 'X') && (mtz[i][1] == 'X') && (mtz[i][2] == 'X')) || ((mtz[i][0] == 'O') && (mtz[i][1] == 'O') && (mtz[i][2] == 'O'))){
			printf("[FIM DE JOGO!]\n");
			printf("--> %c <-- EH O VENCEDOR!\n",aux_m);
			return 0;
		}else if(((mtz[0][i] == 'X') && (mtz[1][i] == 'X') && (mtz[2][i] == 'X')) || ((mtz[0][i] == 'O') && (mtz[1][i] == 'O') && (mtz[2][i] == 'O'))){
			printf("[FIM DE JOGO!]\n");
			printf("--> %c <-- EH O VENCEDOR!\n",aux_m);
			return 0;
		}
	}
	
	//	Verify in there is only 'X' or 'O' in main diaginals
	//	if there is, see which player just played, give it the victory
	//	and it returns 0 to finish the game
	if(((mtz[0][0] == 'X') && (mtz[1][1] == 'X') && (mtz[2][2] == 'X')) || ((mtz[0][0] == 'O') && (mtz[1][1] == 'O') && (mtz[2][2] == 'O'))){
		printf("[FIM DE JOGO!]\n");
		printf("--> %c <-- EH O VENCEDOR!\n",aux_m);
		return 0;
	}else if(((mtz[0][2] == 'X') && (mtz[1][1] == 'X') && (mtz[2][0] == 'X')) || ((mtz[0][2] == 'O') && (mtz[1][1] == 'O') && (mtz[2][0] == 'O'))){
		printf("[FIM DE JOGO!]\n");
		printf("--> %c <-- EH O VENCEDOR!\n",aux_m);
		return 0;
	//	if there is no turns to do, print EMPATE, cause
  	//	no one has won and it returns 0 to finish the game
	}else if(c == 0){
		printf("[FIM DE JOGO!]\n");
		printf("EMPATE!\n");
		return 0;
	//	if no one of these options is true, it returns 1
	//	to resume the game
	}else{
		return 1;
	}
}

int main(){
	char hash[lg][lg], player, aux;
	int pl = 1, match = 1, pos = 0, x = 0, y = 0, aux_x = 0, aux_y = 0;
	
	for(int i  = 0; i < lg; i++){
		for(int j = 0; j < lg; j++){
			hash[i][j] = ' ';
		}
	}
	//	It starts dawing our game
	drawHash(hash);
	
	do{	
	
		//	Verify which player will play
		player = (pl % 2 == 0) ? 'X' : 'O';
		printf("\n VEZ DE --> %c <--\n", player);
		
		pos = 0;
		//	Just put the 'X' or 'O' in the game if the player
		//	has pressed enter
		while ((pos != 13)){
			//	Get a key from keyboard
   			pos = getch();
	        if (pos == 0 || pos == 224){
	        	pos = getch();
	        	
				// I REALLY DON'T KNOW WHY I DID THIS CONDITION
				// BUT IT WORKS
				// I should commented this when I finished it
	        	if(x != aux){
					hash[aux_x][aux_y] = aux;
				}
	        	
	        	// Verify which arrow the player has choosen
	        	switch(pos){
	        		case 72:
	        			// Case to up
	        			if(x - 1 >= 0){
	        				x--;
	        				if (hash[x][y] !=  '_'){
		        				aux = hash[x][y];
		        				aux_x = x;
		        				aux_y = y;
							}
	        				hash[x][y] = '_';
						}
	        			break;
	       			case 75:
	       				// Case to left
	       				if (y - 1 >= 0){
	       					y--;
	       					if (hash[x][y] !=  '_'){
		        				aux = hash[x][y];
		        				aux_x = x;
		        				aux_y = y;
							}
	        				hash[x][y] = '_';
						   }
	       				break;
	       			case 77:
	       				// Case right 
	       				if (y + 1 < lg){
	       					y++;
	       					if (hash[x][y] !=  '_'){
		        				aux = hash[x][y];
		        				aux_x = x;
		        				aux_y = y;
							}
	        				hash[x][y] = '_';
						   }
	       				break;
	       			case 80:
	       				// Case to down
	       				if (x + 1 < lg){
	       					x++;
	       					if (hash[x][y] !=  '_'){
		        				aux = hash[x][y];
		        				aux_x = x;
		        				aux_y = y;
							}
	        				hash[x][y] = '_';
						   }
	       				break;
	       				
				}
				
				system("cls");
				drawHash(hash);
				printf("\n VEZ DE --> %c <--\n", player);
			}
			printf("\n");
    	}
		
		// If this move is an empty place and is in the area
		// the player can do it move
		if(((hash[x][y] == ' ') || (aux == ' ')) && ((x < lg) && (y < lg))){
			hash[x][y] = player;
			aux = player;
			pl++;
			system("cls");
			drawHash(hash);
		}else{
			printf("[JOGADA INCORRETA]\n");
		}
	match = verifyResult(hash, aux);
	}while(match);
	
	system('pause');
	return 0;
}
