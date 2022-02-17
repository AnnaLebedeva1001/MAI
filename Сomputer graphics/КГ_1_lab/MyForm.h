#pragma once
//#include<cmath>
//#include<windows.h>

namespace КГ1lab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightCoral;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(515, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 58);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Движение по Лемнискате Бернули";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(31, 25);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(460, 268);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// timer1
			// 
			this->timer1->Interval = 5;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MistyRose;
			this->ClientSize = System::Drawing::Size(664, 339);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Лабораторная №1";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//private:

			/*void Paint_Graphic(int x0, int y0, int r2, int x, int y, array<Point>^ p)
			{ // лемниската
				Graphics^ gr = pictureBox1->CreateGraphics();
				gr->Clear(BackColor);
				gr->DrawLines(Pens::Black, p); // траектория
			}


			System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
			{
				Graphics^ G = pictureBox1->CreateGraphics();
				double InitT = 0, LastT = Math::PI * 2; // оборот в 360 градусов (6,28 радиан)
				double Step = 0.1, fi = InitT; // шаг
				double x, y, x1, y1, a = 150;
				int x0 = (pictureBox1->Right - pictureBox1->Left) / 2, y0 = (pictureBox1->Bottom - pictureBox1->Top) / 2; // центр формы
				int i = 0; // количество точек прорисовки
				array<Point>^ p = gcnew array<Point>(64); // точки для прорисовки (LastT/Step)
				while (fi <= LastT)
				{
					if (cos(2 * fi) >= 0)
					{
						int r = a * sqrt(2 * cos(2 * fi)); // радиус лемнискаты
						x = (int)(r * cos(fi)); // приращение по x
						y = (int)(r * sin(fi)); // приращение по y
						p[i] = Point(x0 + int(x), y0 + int(y)); // расчет следующей точки траектории
						if (i >= 1) Paint_Graphic(x0, y0, r, x, y, p);
						x1 = r * sin(fi + Math::PI / 2); // приращение
						y1 = r * cos(fi + Math::PI / 2);
					}
					fi += Step; // увеличение угла
					i++; // увеличение кол-ва точек прорисовки
				}
			}*/


	private: int x1, y1, x2, y2, sign;
	private: double a, t, fi, p;
	private: Pen^ pen;


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		timer1->Enabled = true; //запуск отрисовки
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		fi += 0.01;
		p = Math::Tan(Math::PI / 4 - fi);
		sign = -1;
		if (p < 0)
		{
			sign *= -1;
		}
		t = sign * Math::Sqrt(Math::Abs(p));
		x2 = x1 + (int)((a * Math::Sqrt(2) * (t + Math::Pow(t, 3))) / (1 + Math::Pow(t, 4)));
		y2 = y1 - (int)((a * Math::Sqrt(2) * (t - Math::Pow(t, 3))) / (1 + Math::Pow(t, 4)));
		Graphics^ gr = pictureBox1->CreateGraphics();
		gr->Clear(BackColor);
		gr->DrawEllipse(pen, x2, y2, 5, 5);
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		pen = gcnew Pen(Color::DarkRed, 2);
		x1 = pictureBox1->Width / 2;
		y1 = pictureBox1->Height / 2;
		a = 100;
		fi = 0;
		t = -Math::Sqrt(Math::Tan(Math::PI / 4 - fi));
		x2 = x1 + (int)((a * Math::Sqrt(2) * (t + Math::Pow(t, 3))) / (1 + Math::Pow(t, 4)));
		y2 = y1 - (int)((a * Math::Sqrt(2) * (t - Math::Pow(t, 3))) / (1 + Math::Pow(t, 4)));
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
	{
		Graphics^ gr = e->Graphics;
		gr->DrawEllipse(pen, x2, y2, 5, 5);
	}
	};
}
