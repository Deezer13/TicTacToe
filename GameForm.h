#pragma once

#include "GameMap.h"
#include "Gamer.h"

#include <Windows.h>

namespace TicTacToegame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ ìåíþToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ íîâàÿÈãðàToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âåðíóòüñÿToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âêëÂûêëÇâóêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ îÏðîãðàììåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^ status;
	private: System::Windows::Forms::DataGridView^ dataGridView;


	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ìåíþToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->íîâàÿÈãðàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âåðíóòüñÿToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âêëÂûêëÇâóêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏðîãðàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->status = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ìåíþToolStripMenuItem,
					this->îÏðîãðàììåToolStripMenuItem, this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(709, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ìåíþToolStripMenuItem
			// 
			this->ìåíþToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->íîâàÿÈãðàToolStripMenuItem,
					this->âåðíóòüñÿToolStripMenuItem, this->âêëÂûêëÇâóêToolStripMenuItem
			});
			this->ìåíþToolStripMenuItem->Name = L"ìåíþToolStripMenuItem";
			this->ìåíþToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->ìåíþToolStripMenuItem->Text = L"Меню";
			// 
			// íîâàÿÈãðàToolStripMenuItem
			// 
			this->íîâàÿÈãðàToolStripMenuItem->Name = L"íîâàÿÈãðàToolStripMenuItem";
			this->íîâàÿÈãðàToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->íîâàÿÈãðàToolStripMenuItem->Text = L"Новая игра";
			this->íîâàÿÈãðàToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::íîâàÿÈãðàToolStripMenuItem_Click);
			// 
			// âåðíóòüñÿToolStripMenuItem
			// 
			this->âåðíóòüñÿToolStripMenuItem->Name = L"âåðíóòüñÿToolStripMenuItem";
			this->âåðíóòüñÿToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->âåðíóòüñÿToolStripMenuItem->Text = L"Вернуться на старт";
			this->âåðíóòüñÿToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::âåðíóòüñÿToolStripMenuItem_Click);
			// 
			// âêëÂûêëÇâóêToolStripMenuItem
			// 
			this->âêëÂûêëÇâóêToolStripMenuItem->Name = L"âêëÂûêëÇâóêToolStripMenuItem";
			this->âêëÂûêëÇâóêToolStripMenuItem->Size = System::Drawing::Size(178, 22);
			this->âêëÂûêëÇâóêToolStripMenuItem->Text = L"Вкл/выкл звук";
			this->âêëÂûêëÇâóêToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::âêëÂûêëÇâóêToolStripMenuItem_Click);
			// 
			// îÏðîãðàììåToolStripMenuItem
			// 
			this->îÏðîãðàììåToolStripMenuItem->Name = L"îÏðîãðàììåToolStripMenuItem";
			this->îÏðîãðàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏðîãðàììåToolStripMenuItem->Text = L"О программе";
			this->îÏðîãðàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::îÏðîãðàììåToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->âûõîäToolStripMenuItem->Text = L"Выход";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::âûõîäToolStripMenuItem_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->status });
			this->statusStrip1->Location = System::Drawing::Point(0, 350);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(709, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// status
			// 
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(71, 17);
			this->status->Text = L"Ход игрока:";
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeColumns = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->ColumnHeadersVisible = false;
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView->Location = System::Drawing::Point(0, 24);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->Size = System::Drawing::Size(709, 326);
			this->dataGridView->TabIndex = 2;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GameForm::dataGridView_CellContentClick);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(709, 372);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"GameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Tag = L"Made FirePlanetStudio";
			this->Text = L"Игра Крестики-Нолики";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: int rows;
	public: int columns;
	public: int length;
	public: int selectedGameMode;
	private: Random^ rand;
	private: System::Media::SoundPlayer^ soundClick;
	private: System::Media::SoundPlayer^ soundEndGame;

	private: void GameLogic();
	private: void Update();
	private: void NewGame();
	private: void StepAI();
	private: void UpdateGameGrid();
	private: void CreateGameGrid(Vector2);
	private: void SetPositionPlayer(Vector2);
		   
	private: System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void íîâàÿÈãðàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âåðíóòüñÿToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âêëÂûêëÇâóêToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void îÏðîãðàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	};
}