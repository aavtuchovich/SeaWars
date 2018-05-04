// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// ������������� ������ �����������: �������������� � ������������
enum direction {
	h, v
};

class player {
public:
	bool defeat_flag; // ���������� ������ ���������� � ���������
	int hits[10][10]; // ������ "���������" �������
	int ships[10][10]; // ������ �������� �������

	player() : defeat_flag(0) {
	} // �����������

	void ships_init();
	void set(int deck);
	int place_ship(int s, int c, direction dir, int deck);
	void turn(player&, int character, int digit);
	void turn(player&);
};

player human;
player computer;

// � ������� ��������������� � ����������� ����� defeat_flag �������.
int check_ending() {
	int flag = 0;
	int human_flag = 0;
	int computer_flag = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (human.ships[i][j] == 2)
				human_flag = 1; // � ������������ ��� �������� ������������� �������
			if (computer.ships[i][j] == 2)
				computer_flag = 1; // � ���������� ��� �������� ������������� �������
		}
	}
	if (human_flag == 0)
		flag = 2;
	if (computer_flag == 0)
		flag = 1;
	if (flag == 1) {
		ShowMessage("������� �����!");
		return 2;
	}
	if (flag == 2) {
		ShowMessage("������� ���������!");
		return 2;
	}
}

void player::ships_init() {
	// ������������� �������� hits � ships
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ships[i][j] = 1;
			hits[i][j] = 0;
		}
	}

	// ��������� ��������
	set(4);
	set(3);
	set(3);
	set(2);
	set(2);
	set(2);
	set(1);
	set(1);
	set(1);
	set(1);
}

void player::set(int deck) {
	int my = deck - 1;
	bool isset = 0;
	int s, c;
	direction dir;
	while (isset == 0) // �������� ������� �� ���������� �������
	{
		dir = static_cast<direction>(rand() % 2); // �������� �����������

		s = rand() % 10; // ��������� ������� ������������ ����������
		c = rand() % 10;
		int e = 0;
		switch(dir) {
		case h:
			if (ships[s][c + deck - 1] == 1) {
				e = place_ship(s, c, dir, deck); // �������� ������� ������
				if (e == 0) {
					for (int i = 0; i < deck; i++) {
						ships[s][c + i] = 2;
						// ��������� ������� � ������� ships
					}
					isset = 1;
				}
			}
			break;
		case v:
			if (ships[s + deck - 1][c] == 1) {
				e = place_ship(s, c, dir, deck);
				if (e == 0) {
					for (int i = 0; i < deck; i++) {
						ships[s + i][c] = 2;
					}
					isset = 1;
				}
			}
			break;
		} // ����� switch
	} // ����� while
}
// ����� set4()

/*
������� ���������, ����� �� � ������ ���������� [s][c]
���������� ������� � �������� deck.
� ������������ �������� ����� ������ ����������� ��� ���������
��������������� ������� � [4][3]
 */
int player::place_ship(int s, int c, direction dir, int deck) {
	int e = 0;
	switch(dir) {
	case h:
		if (ships[s - 1][c - 1] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|X
			3| 2222
			4|
			 */
		}
		if (ships[s - 1][c + deck] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|     X
			3| 2222
			4|
			 */
		}
		if (ships[s + 1][c - 1] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2222
			4|X
			 */
		}
		if (ships[s + 1][c + deck] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2222
			4|     X
			 */
		}

		if (ships[s][c - 1] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|
			3|X2222
			4|
			 */
		}
		if (ships[s][c + deck] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2222X
			4|
			 */
		}
		for (int i = 0; i < deck; i++) {
			if (ships[s - 1][c + i] == 2) {
				e = 1;
				/*
				345678
				#-------
				2| XXXX
				3| 2222
				4|
				 */
			}
			if (ships[s + 1][c + i] == 2) {
				e = 1;
				/*
				345678
				#-------
				2|
				3| 2222
				4| XXXX
				 */
			}
		}
		break;
	case v:
		if (ships[s - 1][c - 1] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|X
			3| 2
			4| 2
			5| 2
			6| 2
			7|
			 */
		}
		if (ships[s - 1][c + 1] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|  X
			3| 2
			4| 2
			5| 2
			6| 2
			7| X
			 */
		}
		if (ships[s + deck][c - 1] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2
			4| 2
			5| 2
			6| 2
			7|X
			 */
		}
		if (ships[s + deck][c + 1] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2
			4| 2
			5| 2
			6| 2
			7|  X
			 */
		}

		if (ships[s - 1][c] == 2) {
			e = 1;
			/*
			345678
			#-------
			2| X
			3| 2
			4| 2
			5| 2
			6| 2
			7|
			 */
		}
		if (ships[s + deck][c] == 2) {
			e = 1;
			/*
			345678
			#-------
			2|
			3| 2
			4| 2
			5| 2
			6| 2
			7| X
			 */
		}
		for (int i = 0; i < deck; i++) {
			if (ships[s + i][c - 1] == 2) {
				e = 1;
				/*
				345678
				#-------
				2|
				3|X2
				4|X2
				5|X2
				6|X2
				7|
				 */
			}
			if (ships[s + i][c + 1] == 2) {
				e = 1;
				/*
				345678
				#-------
				2|
				3| 2X
				4| 2X
				5| 2X
				6| 2X
				7|
				 */
			}
		}
		break;
	}
	return e;
}

// ��� ����������: ������ ��������� � ������� human.ships � computer.hits
void player::turn(player& enemy) {
	// srand(static_cast<unsigned int>(time(NULL)));
	bool flag = 0;
	while (flag == 0) {
		int character = rand() % 10; // ���������� �� ������� ����� �������� ���������
		int digit = rand() % 10; // ���������� ��������
		if (hits[character][digit] != 1) // ��������: ������� �� ��� ��������� ��� ����������
		{
			hits[character][digit] = 1;
			flag = 1;
			if (enemy.ships[character][digit] == 2) {
				enemy.ships[character][digit] = 3;
			}
		}
	}
}

// ��� ������: ������ ��������� � ������� computer.ships � human.hits
void player::turn(player& enemy, int character, int digit) {
	hits[character][digit] = 1;
	if (enemy.ships[character][digit] == 2) {
		enemy.ships[character][digit] = 3;
		Form1->DrawGrid2->Canvas->FillRect(Form1->DrawGrid2->CellRect(character,digit));
	}
}

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject * Sender) {
	randomize();
}

void clearsea() {
	Form1->DrawGrid1->Canvas->Brush->Color = clWhite;
	Form1->DrawGrid2->Canvas->Brush->Color = clWhite;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			Form1->DrawGrid1->Canvas->FillRect(Form1->DrawGrid1->CellRect(i,
					j));
			Form1->DrawGrid2->Canvas->FillRect(Form1->DrawGrid1->CellRect(i,
					j));

		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender) {
	clearsea();
	human.ships_init(); // ������������� �������� ��������
	computer.ships_init(); // ������������� �������� ����������
	DrawGrid1->Canvas->Brush->Color = clBlue;
	DrawGrid2->Canvas->Brush->Color = clGreen;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (human.ships[i][j] == 2) {
				DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(i, j));
			}
			if (computer.ships[i][j] == 2) {
				DrawGrid2->Canvas->FillRect(DrawGrid2->CellRect(i, j));
			}
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid2Click(TObject *Sender) {
	ShowMessage(DrawGrid2->Row);
	human.turn(computer, DrawGrid2->Row, DrawGrid2->Col);
	computer.turn(human);
	check_ending();
}
// ---------------------------------------------------------------------------
