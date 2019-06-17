#include "game.hpp"



//parameterized constructor
Game::Game(int n)
{
	N = n;

	//Allocating space for N*N board cells
	board = new player*[N];
	for (int i = 0; i < N; ++i)
		board[i] = new player[N];

	//Initiating board w/ empty fields
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			board[i][j] = player::none;
}

//destructor
Game::~Game()
{
	for (int i = 0; i < N; ++i)
		delete[] board[i];
	delete[] board;
}

void Game::showBoard() //shows board
{
	for (int i = 0; i < N; ++i)
	{
		std::cout << "\n";
		for (int j = 0; j < N; ++j)
		{
			std::cout << std::setw(3) << static_cast<char>(board[i][j]) << std::setw(3);
			if (j != N - 1)
				std::cout << "|";
		}
		if (i != N - 1)
		{
			std::cout << std::endl;
			for (int j = 0; j < N; j++)
			{
				
				std::cout << "------";
			}
			//std::cout << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
}

bool Game::isDraw()	//returns true if draw
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] == player::none)
				return false;

	return true;
}

//win for 3 in a row
bool Game::checkWin(player contestant)
{
	//sprawdzenie dla kolumn i wierszy
	for (int i = 0; i < N; ++i)
	{
		bool rowwin = true;
		bool colwin = true;
		for (unsigned j = 0; j < N; ++j)
		{
			rowwin &= board[i][j] == contestant;	//bitwise AND assignment
			colwin &= board[j][i] == contestant;
		}
		if (colwin || rowwin)
			return true;
	}

	// sprawdzenie dla przekatnych wygranej
	bool diagwin = true;
	for (unsigned i = 0; i < N; ++i)
		diagwin &= board[i][i] == contestant;

	if (diagwin)
		return true;

	diagwin = true;
	for (unsigned i = 0; i < N; ++i)
		diagwin &= board[N - i - 1][i] == contestant;

	return diagwin;

}
//{
//		if ((board[1][1] == contestant) && (board[1][2] == contestant))
//			return true;
//		else
//			return false;
//}

//{
//	if (board[3][0] == contestant && board[3][1] == contestant && board[3][2] == contestant)
//		return true;
//	else
//		return false;
//}

//{
//	bool win = false;
//	/*
//	i - ROW
//	j - COLUMN
//	*/
//
//	//checking rows
//	for (int i = 0; i < N; ++i)
//	{
//		int howMany = N-2;
//		for (int j = 0; j < howMany; ++j)
//			if (board[i][j] == contestant && board[i][j+1] == contestant && board[i][j + 2] == contestant)
//				return true;
//	}
//
//	//checking columns
//	for (int j = 0; j < N; ++j)
//	{
//		int howMany = N - 2;
//		for (int i = 0; i < howMany; ++i)
//			if (board[i][j] == contestant && board[i + 1][j] == contestant && board[i + 2][j] == contestant)
//				return true;
//	}
//		
//	/*
//	DIAGONALS !!!
//	*/
//
//
//	return win;
//}

//move Game::bestMove()	//best move for PC (AI)
//{
//	int score = INT_MAX;
//	move position;
//
//	int depth = countDepth();
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			if (board[i][j] == player::none)
//			{
//				//board[i][j] = player::PC;
//				move tempPosition(i, j);
//
//				if (minimax(tempPosition, depth, player::PC) < score)
//				{
//					score = minimax(tempPosition, depth, player::PC);
//					position.x = tempPosition.x;
//					position.y = tempPosition.y;
//				}
//
//				//board[i][j] = player::none;
//
//			}
//		}
//	}
//
//	//std::cout << std::endl << depth << std::endl;
//	return position;
//
//
//}

move Game::bestMove()
{

	int score = -1000; // zmienna pomocnicza do algorytmu min max
	move _move;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == player::none)
			{
				board[i][j] = player::PC;

				int temp = minimax(0, 0, -1000, 1000); //glebokosc 0

				board[i][j] = player::none;

				if (temp > score)
				{
					score = temp; //przypisanie nowej wartosci do wyniku ruchu
					_move.x = i;
					_move.y = j;
				}
			}
		}
	}

	return _move;
}

void Game::playersMove()	//player move
{
	bool fail = true;
	int x = -1, y = -1;
	int a, b;

	do
	{
		std::cout << "Please insert coordinates [x] [y] of your next move: ";
		do
		{
			std::cout << std::endl;
			std::cout << "x: ";
			std::cin >> a;
		} while (a-1 < 0 || a-1>N-1);
		x = a-1;

		do
		{
			std::cout << "y: ";
			std::cin >> b;
		} while (b-1 < 0 || b-1>N-1);
		y = b-1;

		fail = board[x][y] != player::none;

		
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	} while (fail);

	board[x][y] = player::human;
	//system("CLS");
}

void Game::play()	//function responsible for gameplay
{
	int turn = 0;
	bool exit = false;

	//showBoard();

	do
	{
		showBoard();
		//cout << string(50, '\n');

		//Human's move
		if (turn == 0)
		{
			playersMove();

			if (checkWin(player::human))
			{
				std::cout << std::endl;
				showBoard();
				std::cout << std::endl;
				std::cout << "################" << std::endl;
				std::cout << "#  HUMAN WON!  #" << std::endl;
				std::cout << "################" << std::endl;
				exit = true;
			}
		}
		else
		{
			std::cout << "PC's move..." << std::endl;
			move aiMove = bestMove();
			std::cout << '\n' << "AI's move: " << std::endl;
			std::cout << "[x]: " << aiMove.x + 1 << std::endl;
			std::cout << "[y]: " << aiMove.y + 1 << std::endl;

			board[aiMove.x][aiMove.y] = player::PC;

			if (checkWin(player::PC))
			{
				std::cout << std::endl;
				showBoard();
				std::cout << std::endl;
				std::cout << "################" << std::endl;
				std::cout << "#    PC WON!   #" << std::endl;
				std::cout << "################" << std::endl;
				exit = true;
			}
		}

		if (isDraw())
		{
			std::cout << std::endl;
			showBoard();
			std::cout << std::endl;
			std::cout << "################" << std::endl;
			std::cout << "#     DRAW!    #" << std::endl;
			std::cout << "################" << std::endl;
			exit = true;
		}

		turn ^= 1;	//operator roznicy symetrycznej (zwraca 0, gdy bitys¹ takie same; 1, gdy rózne)
		
		

	} while (!exit);
}

//int Game::minimax(move position, int depth, player maximizingPlayer)
//{
//	//int maxEval = INT_MAX;
//	//int minEval = INT_MIN;
//	int eval = 0;
//
//	//PC wants -infinity
//	//human wants +infnity
//	if (depth == 0)
//		if (maximizingPlayer == player::human) return 100;
//		else if (maximizingPlayer == player::PC) return -100;
//		else if (isDraw()) return 0;
//
//	if (maximizingPlayer == player::human)
//	{
//		int maxEval = 30000;
//		for (int i = 0; i< N; ++i)
//			for (int j = 0; j < N; ++j)
//				if (board[i][j] == player::none)
//				{
//					board[i][j] = player::human;	//zrob symulacje, ze stawiasz tu krok
//					for (int i = 0; i < N; ++i)
//						for (int j = 0; j < N; ++j)
//							if (board[i][j] == player::none)
//							{
//								move pos(i, j);
//								eval = minimax(pos, depth - 1, player::PC);
//							}
//					maxEval = std::max(maxEval, eval);
//					board[i][j] = player::none;	//cofnij postawiony krok
//					return maxEval;
//				}
//	}
//	else
//	{
//		int minEval = -30000;
//		for (int i = 0; i < N; ++i)
//			for (int j = 0; j < N; ++j)
//				if (board[i][j] == player::none)
//				{
//					board[i][j] = player::PC;	//zrob symulacje, ze stawiasz tu krok
//					for (int i = 0; i < N; ++i)
//						for (int j = 0; j < N; ++j)
//							if (board[i][j] == player::none)
//							{
//								move pos(i, j);
//								eval = minimax(pos, depth - 1, player::human);
//							}
//					minEval = std::min(minEval, eval);
//					board[i][j] = player::none;	//cofnij postawiony krok
//					return minEval;
//				}
//	}
//
//	return 0;
//}

int Game::minimax(int depth, bool czyMax, int alpha, int beta)
{
	int value;
	unsigned int end;

	if (checkWin(player::human)) { return -100; } // sprawdzenie wygranej gracza
	else if (checkWin(player::PC)) { return 100; } // sprawdzenie wygranej kmputera
	else if (isDraw()) { return 0; } // czy jest remis


	if (czyMax == true)//czy ruch komputera
	{
		end = 0;
		value = -1000;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == player::none)//dla wszystkich wolnych pol na planszy
				{
					board[i][j] = player::PC;
					value = std::max(value, minimax(depth + 1, false, alpha, beta));
					alpha = std::max(value, alpha);
					board[i][j] = player::none;
					if (alpha >= beta)
					{
						end = 1;
						break;
					}

				}

			}

			if (end)//if(end!=0)
				break;
		}
	}
	else
	{
		end = 0;
		value = 1000;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == player::none)
				{
					board[i][j] = player::human;
					value = std::min(value, minimax(depth + 1, true, alpha, beta));
					beta = std::min(value, beta);
					board[i][j] = player::none;
					if (alpha >= beta)
					{
						end = 1;
						break;
					}


				}

			}
			if (end)
				break;
		}

	}

	return value;
}
int Game::countDepth()
{
	int depth = N * N;	//na tyle sposobow mozna postawic ruch

	//teraz odejme wszystkie pola zajete
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (board[i][j] != player::none)
				depth--;

	return depth;
}