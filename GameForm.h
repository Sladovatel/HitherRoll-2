#pragma once
#include <time.h>
#include <stdlib.h>

namespace SnakeGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// ������ ��� GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

		virtual void OnPaint(System::Object^ obj, PaintEventArgs^ e) override {
			Graphics^ grap = e->Graphics;
			
			Brush^ apple = gcnew SolidBrush(Color::Red);
			grap->FillRectangle(apple, applePosition.X, applePosition.Y, blockSize, blockSize);

			Brush^ snake = gcnew SolidBrush(Color::Green);
			for each (Point el in snakee)
				grap->FillRectangle(snake, el.X, el.Y, blockSize, blockSize);
		}

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		List<Point>^ snakee;
		Point applePosition;
		const int blockSize = 10;

		int appleCoiunt = 0;
		Label^ scoreLabel;

		Timer^ timer;
		int moveX = 1, moveY = 0;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(300, 300);
			this->Text = L"HitherRoll 2";
			this->BackColor = Color::Black;
			this->ResumeLayout(false);

			scoreLabel = gcnew Label();
			scoreLabel->ForeColor = Color::White;
			scoreLabel->BackColor = Color::Transparent;
			scoreLabel->Text = "���� �� ���: 0";
			scoreLabel->Location = Point(10, 10);
			this->Controls->Add(scoreLabel);

			snakee = gcnew List<Point>();
			snakee->Add(Point(100, 100));
			srand(time(NULL));
			placeApple();

			timer = gcnew Timer();
			timer->Interval = 150;
			timer->Tick += gcnew EventHandler(this, &GameForm::OnTimerTick);
			timer->Start();


			this->Paint += gcnew PaintEventHandler(this, &GameForm::OnPaint);
			this->KeyDown += gcnew KeyEventHandler(this, &GameForm::OnKeyDown);
		}

		void InitializeComponent1(void)
		{
			this->SuspendLayout();

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 400);
			this->Text = L"HitherRoll 2 | Extra";
			this->BackColor = Color::Black;
			this->ResumeLayout(false);


			scoreLabel = gcnew Label();
			scoreLabel->ForeColor = Color::White;
			scoreLabel->BackColor = Color::Transparent;
			scoreLabel->Text = "���� �� ���: 1488";
			scoreLabel->Location = Point(10, 10);
			this->Controls->Add(scoreLabel);

			snakee = gcnew List<Point>();
			snakee->Add(Point(200, 200));
			srand(time(NULL));
			placeApple();

			timer = gcnew Timer();
			timer->Interval = 80;
			timer->Tick += gcnew EventHandler(this, &GameForm::OnTimerTick);
			timer->Start();


			this->Paint += gcnew PaintEventHandler(this, &GameForm::OnPaint);
			this->KeyDown += gcnew KeyEventHandler(this, &GameForm::OnKeyDown);
		}

		void InitializeComponent2(void)
		{
			this->SuspendLayout();

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 500);
			this->Text = L"HitherRoll 2 | Ultra Extra";
			this->BackColor = Color::Black;
			this->ResumeLayout(false);


			scoreLabel = gcnew Label();
			scoreLabel->ForeColor = Color::White;
			scoreLabel->BackColor = Color::Transparent;
			scoreLabel->Text = "���� �� ���: 1488";
			scoreLabel->Location = Point(10, 10);
			this->Controls->Add(scoreLabel);

			snakee = gcnew List<Point>();
			snakee->Add(Point(250, 250));
			srand(time(NULL));
			placeApple();

			timer = gcnew Timer();
			timer->Interval = 50;
			timer->Tick += gcnew EventHandler(this, &GameForm::OnTimerTick);
			timer->Start();


			this->Paint += gcnew PaintEventHandler(this, &GameForm::OnPaint);
			this->KeyDown += gcnew KeyEventHandler(this, &GameForm::OnKeyDown);
		}

		void placeApple() {
			int maxX = this->ClientSize.Width / blockSize;
			int maxY = this->ClientSize.Height / blockSize;

			do {
				applePosition = Point(rand() % maxX * blockSize, rand() % maxY * blockSize);
			} while (snakee->Contains(applePosition));
		}

		void OnTimerTick(Object^ obj, EventArgs^ e) {
			moveSnake();
			
			if (snakee[0].X < 0 || snakee[0].Y < 0 || snakee[0].X >= this->ClientSize.Width || snakee[0].Y >= this->ClientSize.Height) {
				timer->Stop();
				int rando = rand() % 10;
				if(rando==0){MessageBox::Show("�����?");}else if(rando==1){MessageBox::Show("�����?");}else if (rando == 2) { MessageBox::Show("�� ��������"); }else if (rando == 3) { MessageBox::Show("�� ��������"); }
				else if (rando == 4) { MessageBox::Show("������� ���������, ��� ��� ����� ������"); }
				else if (rando == 5) { MessageBox::Show("������� ���������, ��� ��� ����� ������"); }
				else if (rando == 6) { MessageBox::Show("����� �� ���"); }
				else if (rando == 7) { MessageBox::Show("����� �� ���"); }
				else if (rando == 8) { MessageBox::Show("..."); }
				else if (rando == 9) { MessageBox::Show("���� ���� ������ ��������� �����"); }
				else if (rando == 10) { MessageBox::Show("�� ���� ���� ����� �������!"); }
				else { MessageBox::Show("������"); }
				this->Close();
				return;
			}

			if (snakee->Count >= 4) {
				for (int i = 1; i < snakee->Count; i++) {
					if (snakee[0] == snakee[i]) {
						timer->Stop();
						MessageBox::Show("����� �� ���...���� � 42 ���� �� �������");
						this->Close();
						return;
					}
				}
			}

			if (snakee[0] == applePosition) {
				appleCoiunt++;
				scoreLabel->Text = "���� �� ���: " + appleCoiunt.ToString();
				if (appleCoiunt==42) {
					timer->Stop();
					MessageBox::Show("����������! �� ������� 42 ���, ...! 434 �� ������ .. ��� � ������");
					MessageBox::Show("��� �� ����� � �����������");
					MessageBox::Show("� �������� ���� � ������� ����� ������ �����, ��� ����....");
					MessageBox::Show("� ��� �����, � ���� ������");
					MessageBox::Show("��� ���� ����� ������� ���������...");
					MessageBox::Show("���� �����!");
					MessageBox::Show("���� �����!");
					MessageBox::Show("���� �����!");
					MessageBox::Show("���� �����!");
					MessageBox::Show("���� �����!");
					MessageBox::Show("���� �����!");
					MessageBox::Show("���� �����!");
					MessageBox::Show("�������");
					InitializeComponent1();
				}
				if (appleCoiunt == 69) {
					timer->Stop();
					MessageBox::Show("�� �� ������ �����!");
					MessageBox::Show("������ ���� ����� �����!");
					InitializeComponent2();
				}
				if (appleCoiunt == 120) {
					timer->Stop();
					MessageBox::Show("�� ������ ���� ������...");
					MessageBox::Show("�����, �� �������� ������ ����...");
					MessageBox::Show("� ����� �� ������ �� ��������");
					MessageBox::Show("������........");
					this->Close();
				}
				growSnake();
				placeApple();
			}

			this->Invalidate();
		}

		void growSnake() {
			Point newHead = snakee[0];

			newHead.X += moveX * blockSize;
			newHead.Y += moveY * blockSize;
			snakee->Insert(0, newHead);
		}

		void moveSnake() {
			Point newHead = snakee[0];

			newHead.X += moveX * blockSize;
			newHead.Y += moveY * blockSize;
			snakee->Insert(0, newHead);
			snakee->RemoveAt(snakee->Count - 1);
		}

		void OnKeyDown(Object^ obj, KeyEventArgs^ e) {
			switch (e->KeyCode) {
			case Keys::Up:
				moveX = 0;
				moveY = -1;
				break;
			case Keys::Down:
				moveX = 0;
				moveY = 1;
				break;
			case Keys::Left:
				moveX = -1;
				moveY = 0;
				break;
			case Keys::Right:
				moveX = 1;
				moveY = 0;
				break;
			}
		}
#pragma endregion
	};
}
