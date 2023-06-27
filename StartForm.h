#pragma once

namespace TicTacToegame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void);

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ îÏðîãðàììåToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ âûõîäToolStripMenuItem;
	private: System::Windows::Forms::ListBox^ listBoxGameMode;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownSizeMap;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownLength;
	private: System::Windows::Forms::Button^ buttonStartGame;
	protected:

	private:
		/// <summary>
		/// Îáÿçàòåëüíàÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Òðåáóåìûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà — íå èçìåíÿéòå 
		/// ñîäåðæèìîå ýòîãî ìåòîäà ñ ïîìîùüþ ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->îÏðîãðàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listBoxGameMode = (gcnew System::Windows::Forms::ListBox());
			this->numericUpDownSizeMap = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownLength = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonStartGame = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSizeMap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownLength))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(214, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Выберите режим игры:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(273, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Выберите количество клеток:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(329, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Выберите комбинацию для победы:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->îÏðîãðàììåToolStripMenuItem,
					this->âûõîäToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(529, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// îÏðîãðàììåToolStripMenuItem
			// 
			this->îÏðîãðàììåToolStripMenuItem->Name = L"îÏðîãðàììåToolStripMenuItem";
			this->îÏðîãðàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏðîãðàììåToolStripMenuItem->Text = L"О программе";
			this->îÏðîãðàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::îÏðîãðàììåToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(53, 20);
			this->âûõîäToolStripMenuItem->Text = L"Выход";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::âûõîäToolStripMenuItem_Click);
			// 
			// listBoxGameMode
			// 
			this->listBoxGameMode->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxGameMode->FormattingEnabled = true;
			this->listBoxGameMode->ItemHeight = 23;
			this->listBoxGameMode->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"PvP", L"PvE" });
			this->listBoxGameMode->Location = System::Drawing::Point(261, 33);
			this->listBoxGameMode->Name = L"listBoxGameMode";
			this->listBoxGameMode->Size = System::Drawing::Size(246, 27);
			this->listBoxGameMode->TabIndex = 4;
			// 
			// numericUpDownSizeMap
			// 
			this->numericUpDownSizeMap->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->numericUpDownSizeMap->Location = System::Drawing::Point(357, 68);
			this->numericUpDownSizeMap->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownSizeMap->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericUpDownSizeMap->Name = L"numericUpDownSizeMap";
			this->numericUpDownSizeMap->Size = System::Drawing::Size(150, 32);
			this->numericUpDownSizeMap->TabIndex = 5;
			this->numericUpDownSizeMap->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// numericUpDownLength
			// 
			this->numericUpDownLength->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownLength->Location = System::Drawing::Point(387, 106);
			this->numericUpDownLength->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDownLength->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			this->numericUpDownLength->Name = L"numericUpDownLength";
			this->numericUpDownLength->Size = System::Drawing::Size(120, 32);
			this->numericUpDownLength->TabIndex = 6;
			this->numericUpDownLength->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// buttonStartGame
			// 
			this->buttonStartGame->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStartGame->Location = System::Drawing::Point(183, 141);
			this->buttonStartGame->Name = L"buttonStartGame";
			this->buttonStartGame->Size = System::Drawing::Size(168, 35);
			this->buttonStartGame->TabIndex = 7;
			this->buttonStartGame->Text = L"Начать игру";
			this->buttonStartGame->UseVisualStyleBackColor = true;
			this->buttonStartGame->Click += gcnew System::EventHandler(this, &StartForm::buttonStartGame_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 190);
			this->Controls->Add(this->buttonStartGame);
			this->Controls->Add(this->numericUpDownLength);
			this->Controls->Add(this->numericUpDownSizeMap);
			this->Controls->Add(this->listBoxGameMode);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(545, 228);
			this->MinimumSize = System::Drawing::Size(545, 228);
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Tag = L"Made FirePlanetStudio";
			this->Text = L"Новая игра";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownSizeMap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownLength))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Media::SoundPlayer^ sound;

	private: System::Void îÏðîãðàììåToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e);
	};
}