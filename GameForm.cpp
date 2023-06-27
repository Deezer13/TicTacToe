#include "GameForm.h"
#include "StartForm.h"

enum GameMode {
	PvP = 0,
	PvE
} gameMode;

GameMap map;
Gamer player1;
Gamer player2;
GamerStatus currentPlayer;
Vector2 selectedCellPlayer;

bool canPlay;
bool endGame;
bool sound;

std::vector<Vector2> allMoves;
int currentMoves;

System::Void TicTacToegame::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	if (selectedGameMode == 0) {
		gameMode = PvP;
	}
	else {
		gameMode = PvE;
	}

	soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\1.wav");
	soundEndGame = gcnew System::Media::SoundPlayer("..\\Resources\\2.wav");
	sound = true;

	NewGame();
}

void TicTacToegame::GameForm::GameLogic()
{
	if (gameMode == PvE) {
		if (currentPlayer == Computer) {
			StepAI();
		}

		Update();
	}
}

void TicTacToegame::GameForm::Update()
{
	if (endGame)
		return;

	
	int state_game = map.CheckingWin();

	if (state_game == 1) {
		UpdateGameGrid();
		if (gameMode == PvP) {
			MessageBox::Show("Поздравляем Игрока1 с Победой!!!", "Победа!");
		}
		else {
			MessageBox::Show("Поздравляем Игрока с победой!!!", "Победа!");
		}

		endGame = true;
	}
	else if (state_game == 2) {
		UpdateGameGrid();
		if (gameMode == PvP) {
			MessageBox::Show("Поздравляем Игрока2 с Победой!!!", "Победа!");
		}
		else {
			MessageBox::Show("Поздравляем Компьютер с победой!!!", "Победа!");
		}

		endGame = true;
	}
	else if (state_game == 3) {
		UpdateGameGrid();
		MessageBox::Show("Победила дружба!!!", "Ничья!");

		endGame = true;
	}

	if (endGame) {
		if (sound) {
			soundEndGame->Play();
		}

		if (MessageBox::Show("Начать новую игру?", "Играть?!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
			NewGame();
		}
		return;
	}

	if (gameMode == PvE) {
		if (currentPlayer == Computer) {
			status->Text = "Ход: Игрока!";
			currentPlayer = Player;
			return;
		}
		else {
			status->Text = "Ход: Компьютера!";
			currentPlayer = Computer;

			GameLogic();
			UpdateGameGrid();
			return;
		}
	}
	else {
		if (currentPlayer == Player1) {
			status->Text = "Ход: 0!";
			currentPlayer = Player2;
		}
		else {
			status->Text = "Ход: X!";
			currentPlayer = Player1;
		}
	}

	GameLogic();
	UpdateGameGrid();
}

void TicTacToegame::GameForm::NewGame()
{
	
	map.SetMap(rows, columns, length);
	rand = gcnew Random();
	endGame = false;

	CreateGameGrid(map.GetSize()); 

	
	currentMoves = 0;
	allMoves.clear();
	Vector2 buf;
	for (int i = 0; i < map.GetSize().x; i++) {
		for (int j = 0; j < map.GetSize().x; j++) {
			buf.x = i;
			buf.y = j;

			allMoves.push_back(buf);
		}
	}

	
	int num_mixing = rand->Next(1, 10);
	for (int i = 0; i < num_mixing; i++)
		std::random_shuffle(allMoves.begin(), allMoves.end());

	
	int state_gamer = rand->Next(1, 3);
	if (state_gamer == 1) {
		if (gameMode == PvE) {
			player1.SetField(Player, 1);
			player2.SetField(Computer, 2);

			status->Text = "Ход: Игрока!";

			currentPlayer = Player;
		}
		else {
			player1.SetField(Player1, 1);
			player2.SetField(Player2, 2);

			status->Text = "Ход: X!";

			currentPlayer = Player1;
		}
	}
	else if (state_gamer == 2) {
		if (gameMode == PvE) {
			player1.SetField(Player, 1);
			player2.SetField(Computer, 2);

			status->Text = "Ход: Компьютера!";

			currentPlayer = Computer;

			GameLogic();
			UpdateGameGrid();

		}
		else {
			player1.SetField(Player1, 1);
			player2.SetField(Player2, 2);

			status->Text = "Ход: 0!";

			currentPlayer = Player2;
		}
	}
	else {
		MessageBox::Show("Не получилось выбрать число!", "Ошибка!");
		return;
	}
}

void TicTacToegame::GameForm::StepAI()
{
	if (currentMoves < allMoves.size()) {
		
		if (map.IsEmpty(allMoves[currentMoves])) {
			map.SetPosition(allMoves[currentMoves], player2.GetMark());
			currentMoves++;
		}
		else {
			currentMoves++;
			StepAI();
		}
	}
}

void TicTacToegame::GameForm::UpdateGameGrid()
{
	for (int i = 0; i < map.GetSize().x; i++) {
		for (int j = 0; j < map.GetSize().y; j++) {
			if (!map.IsEmpty(i, j)) {
				if (map.GetValue(i, j) == 1) {
					dataGridView->Rows[i]->Cells[j]->Value = "X";
				}
				else {
					dataGridView->Rows[i]->Cells[j]->Value = "0";
				}
			}
		}
	}
}

void TicTacToegame::GameForm::CreateGameGrid(Vector2 size)
{
	
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	
	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 14);
	dataGridView->DefaultCellStyle->Font = font;
	dataGridView->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView->RowHeadersDefaultCellStyle->Font = font;

	
	for (int i = 0; i < size.x; i++) {
		DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
		column->HeaderCell->Value = Convert::ToString(i + 1);
		column->Name = "column" + i;
		column->Width = 50;

		dataGridView->Columns->Add(column);
	}

	
	for (int i = 0; i < size.y; i++) {
		dataGridView->Rows->Add();
		dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView->Rows[i]->Height = 50;
	}
}

void TicTacToegame::GameForm::SetPositionPlayer(Vector2 cell)
{
	
	if (gameMode == PvE) {
		
		if (currentPlayer == Player) {
			
			if (!map.SetPosition(cell, player1.GetMark())) {
				MessageBox::Show("Клетка занята!", "Переходите!");
				return;
			}
		}
		else {
			MessageBox::Show("Не ваша очередь!", "Ждите!");
			return;
		}
	}
	else {
		
		if (currentPlayer == Player1) {
			if (!map.SetPosition(cell, player1.GetMark())) {
				MessageBox::Show("Клетка занята!", "Переходите!");
				return;
			}
		}
		else {
			
			if (!map.SetPosition(cell, player2.GetMark())) {
				MessageBox::Show("Клетка занята!", "Переходите!");
				return;
			}
		}
	}

	Update();
}

System::Void TicTacToegame::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	auto senderGrid = (DataGridView^)sender;

	
	selectedCellPlayer.x = e->RowIndex;
	selectedCellPlayer.y = e->ColumnIndex;

	
	SetPositionPlayer(selectedCellPlayer);
}

System::Void TicTacToegame::GameForm::âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	if (MessageBox::Show("Выйти?", "Выход!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

System::Void TicTacToegame::GameForm::îÏðîãðàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	MessageBox::Show("Игра Крестики-Нолики!");
}

System::Void TicTacToegame::GameForm::íîâàÿÈãðàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	if (MessageBox::Show("Начать новую игру?", "Начать новую игру?!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		NewGame();
	}
}

System::Void TicTacToegame::GameForm::âåðíóòüñÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	if (MessageBox::Show("Вернуться?", "Вернуться на старт?!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		StartForm^ form = gcnew StartForm();
		form->Show();
		this->Hide();
	}
}

System::Void TicTacToegame::GameForm::âêëÂûêëÇâóêToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	sound = !sound;
}