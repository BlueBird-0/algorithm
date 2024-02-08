#include <iostream>
#include <string>
#include <queue>
using namespace std;
namespace {
	int N, M;

	void Swap(char &ch1, char &ch2)
	{
		char temp = ch1;
		ch1 = ch2; ch2 = temp;
	}
	class Board {
	public:
		char ch[10][10];
		bool r_clear = false;
		bool b_clear = false;
		Board(char _ch[10][10])
		{
			for (int y = 0; y < 10; y++)
			{
				for (int x = 0; x < 10; x++)
				{
					ch[y][x] = _ch[y][x];
				}
			}
		}
		Board(Board* board)
		{
			r_clear = board->r_clear;
			b_clear = board->b_clear;
			for (int y = 0; y < 10; y++)
			{
				for (int x = 0; x < 10; x++)
				{
					ch[y][x] = board->ch[y][x];
				}
			}
		}
	};
	class Marble {
	public:
		Marble() {}
		Marble(Marble* marble)
		{
			this->x = marble->x;
			this->y = marble->y;
			this->isRed = marble->isRed;
		}
		int x, y;
		bool isRed;
		char Left(Board* board)
		{
			return board->ch[y][x-1];
		}
		char Right(Board* board)
		{
			return board->ch[y][x+1];
		}
		char Up(Board* board)
		{
			return board->ch[y-1][x];
		}
		char Down(Board* board)
		{
			return board->ch[y+1][x];
		}

		bool CanMoveLeft(Board* board)
		{
			return Left(board) == '.' || Left(board) == 'O';
		}
		bool CanMoveRight(Board* board)
		{
			return Right(board) == '.' || Right(board) == 'O';
		}
		bool CanMoveUp(Board* board)
		{
			return Up(board) == '.' || Up(board) == 'O';
		}
		bool CanMoveDown(Board* board)
		{
			return Down(board) == '.' || Down(board) == 'O';
		}

		void MoveLeft(Board* board)
		{
			while (true)
			{
				if (Left(board) == '.')
				{
					Swap(board->ch[y][x], board->ch[y][x-1]);
					x--;
				}
				if (Left(board) == '#' || Left(board) == 'B' || Left(board) == 'R')
				{
					break;
				}
				if (Left(board) == 'O')
				{
					board->ch[y][x] = '.';
					(isRed) ? board->r_clear = true : board->b_clear = true;
					return;
				}
			}
		}
		void MoveRight(Board* board)
		{
			while (true)
			{
				if (Right(board) == '.')
				{
					Swap(board->ch[y][x], board->ch[y][x+1]);
					x++;
				}
				if (Right(board) == '#' || Right(board) == 'B' || Right(board) == 'R')
				{
					break;
				}
				if (Right(board) == 'O')
				{
					board->ch[y][x] = '.';
					(isRed) ? board->r_clear = true : board->b_clear = true;
					return;
				}
			}
		}
		void MoveUp(Board* board)
		{
			while (true)
			{
				if (Up(board) == '.')
				{
					Swap(board->ch[y][x], board->ch[y-1][x]);
					y--;
				}
				if (Up(board) == '#' || Up(board) == 'B' || Up(board) == 'R')
				{
					break;
				}
				if (Up(board) == 'O')
				{
					board->ch[y][x] = '.';
					(isRed) ? board->r_clear = true : board->b_clear = true;
					return;
				}
			}
		}
		void MoveDown(Board* board)
		{
			while (true)
			{
				if (Down(board) == '.')
				{
					Swap(board->ch[y][x], board->ch[y+1][x]);
					y++;
				}
				if (Down(board) == '#' || Down(board) == 'B' || Down(board) == 'R')
				{
					break;
				}
				if (Down(board) == 'O')
				{
					board->ch[y][x] = '.';
					(isRed) ? board->r_clear = true : board->b_clear = true;
					return;
				}
			}
		}
	};

	Board* TiltLeft(Board* board, Marble* r, Marble* b)
	{
		Board* newBoard = new Board(board);
		if (r->x < b->x)
		{
			r->MoveLeft(newBoard);
			b->MoveLeft(newBoard);
		}
		else {
			b->MoveLeft(newBoard);
			r->MoveLeft(newBoard);
		}
		return newBoard;
	}
	Board* TiltRight(Board* board, Marble* r, Marble* b)
	{
		Board* newBoard = new Board(board);
		if (r->x > b->x)
		{
			r->MoveRight(newBoard);
			b->MoveRight(newBoard);
		}
		else {
			b->MoveRight(newBoard);
			r->MoveRight(newBoard);
		}
		return newBoard;
	}
	Board* TiltUp(Board* board, Marble* r, Marble* b)
	{
		Board* newBoard = new Board(board);
		if (r->y < b->y)
		{
			r->MoveUp(newBoard);
			b->MoveUp(newBoard);
		}
		else {
			b->MoveUp(newBoard);
			r->MoveUp(newBoard);
		}
		return newBoard;
	}
	Board* TiltDown(Board* board, Marble* r, Marble* b)
	{
		Board* newBoard = new Board(board);
		if (r->y > b->y)
		{
			r->MoveDown(newBoard);
			b->MoveDown(newBoard);
		}
		else {
			b->MoveDown(newBoard);
			r->MoveDown(newBoard);
		}
		return newBoard;
	}

	int result = 11;

	enum {
		NONE = 0,
		LEFT, RIGHT, UP, DOWN
	};

	queue<Board*>q_board;
	queue<Marble*>q_r;
	queue<Marble*>q_b;
	queue<int>q_prevTilt;
	queue<int>q_count;

	Board* Function(Board* _board, int _count, Marble* _r, Marble* _b, int _prevTilt)
	{
		q_board.push(_board);
		q_r.push(_r);
		q_b.push(_b);
		q_prevTilt.push(_prevTilt);
		q_count.push(_count);


		while (q_board.size() != 0)
		{
			Marble* r = q_r.front();
			Marble* b = q_b.front();
			Board* board = q_board.front();
			int prevTilt = q_prevTilt.front();
			int count = q_count.front();
			q_r.pop();
			q_b.pop();
			q_board.pop();
			q_prevTilt.pop();
			q_count.pop();

			if (count >= 10 || count >= result || board->b_clear || board->r_clear)
			{
				if (board->r_clear && !board->b_clear && count < result)
					result = count;
				continue;
			}
			if (prevTilt != RIGHT && (r->CanMoveLeft(board) || b->CanMoveLeft(board)))
			{
				Marble* newR = new Marble(r);
				Marble* newB = new Marble(b);
				Board* newBoard = TiltLeft(board, newR, newB);
				q_board.push(newBoard);
				q_r.push(newR);
				q_b.push(newB);
				q_prevTilt.push(LEFT);
				q_count.push(count+1);
				//Function(newBoard, count+1, newR, newB, LEFT);
			}
			if (prevTilt != LEFT && (r->CanMoveRight(board) || b->CanMoveRight(board)))
			{
				Marble* newR = new Marble(r);
				Marble* newB = new Marble(b);
				Board* newBoard = TiltRight(board, newR, newB);
				q_board.push(newBoard);
				q_r.push(newR);
				q_b.push(newB);
				q_prevTilt.push(RIGHT);
				q_count.push(count + 1);
				//Function(newBoard, count+1, newR, newB, RIGHT);
			}
			if (prevTilt != DOWN && (r->CanMoveUp(board) || b->CanMoveUp(board)))
			{
				Marble* newR = new Marble(r);
				Marble* newB = new Marble(b);
				Board* newBoard = TiltUp(board, newR, newB);
				q_board.push(newBoard);
				q_r.push(newR);
				q_b.push(newB);
				q_prevTilt.push(UP);
				q_count.push(count + 1);
				//Function(newBoard, count+1, newR, newB, UP);
			}
			if (prevTilt != UP && (r->CanMoveDown(board) || b->CanMoveDown(board)))
			{
				Marble* newR = new Marble(r);
				Marble* newB = new Marble(b);
				Board* newBoard = TiltDown(board, newR, newB);
				q_board.push(newBoard);
				q_r.push(newR);
				q_b.push(newB);
				q_prevTilt.push(DOWN);
				q_count.push(count + 1);
				//Function(newBoard, count+1, newR, newB, DOWN);
			}
		}
		return nullptr;
	}
}

int Q13460()
{
	ios::sync_with_stdio(false);	//시간초과 피하기 위해 필요함 (이건 필요없음)
	cin.tie(0);						//시간초과 피하기 위해 필요함
	//보드 만들기
	cin >> N >> M;
	char bboard[10][10];

	Marble r, b;
	for (int y=0; y<N; y++)
	{
		string temp;
		cin >> temp;
		for (int x=0; x<M; x++)
		{
			bboard[y][x] = temp[x];
			if (bboard[y][x] == 'R')
			{
				r.x = x; r.y = y;
				r.isRed = true;
			}
			else if (bboard[y][x] == 'B')
			{
				b.x = x; b.y = y;
				b.isRed = false;
			}
		}
	}
	Board* board = new Board(bboard);
	//게임 그리디 알고리즘
	Function(board, 0, &r, &b, NONE);
	if (result == 11)
		result = -1;
	cout << result;

	return 0;
}