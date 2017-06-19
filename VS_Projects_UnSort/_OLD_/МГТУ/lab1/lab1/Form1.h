#pragma once
#include "math.h"

	float xmax,ymax;
	const int nn=20;
	const int a=60;
	float f,vv,vd;


namespace lab1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label1;

	private:
	
		static array <float> ^x=gcnew array<float> (nn);
		static array <float> ^y=gcnew array<float> (nn) ;
		static Color ^col=gcnew Color();
		static Pen ^pen =gcnew Pen (col->White);	
		private: System::Windows::Forms::Timer^  timer2;
		private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;






			 static Graphics ^im;
	   	 void koord() {  
			 int x1,y1;
			 x1=this->ClientSize.Width;
			 y1=this->ClientSize.Height;
			 int wallw=(2/3)*x1, wallh=(1/2)*y1;
			 x[0]=x1;         
			 y[0]=y1;  	
			 x[1]=x[0]+wallw;
			 y[1]=y[0]; 
			 x[2]=x1;
			 y[2]=y1; 
			 x[3]=x1-a;
			 y[3]=y1; 	
			 x[4]=x1-a/2;
			 y[4]=y1; 
			 x[5]=x1;
			 y[5]=y1-a/2;	
			 x[6]=x1-a/2;
			 y[6]=y1-a/2;	
		
		 }
		  void ris() {
			  int i;
			  im=this->CreateGraphics();
			  pen->Color=col->White;
			  im->FillRectangle(pen->Brush,0,0,this->Size.Width,this->Size.Height);
			  pen->Color=col->Green;
			  im->DrawLine(pen,x[0],y[0],x[1],y[1]);
			  im->DrawLine(pen,int(x[1]),int(y[1]),int(x[3]),int(y[3]));
			  im->DrawLine(pen,int(x[3]),int(y[3]),int(x[2]),int(y[2]));
			  im->DrawLine(pen,int(x[1]),int(y[1]),int(x[4]),int(y[4]));
			  im->DrawLine(pen,int(x[2]),int(y[2]),int(x[6]),int(y[6]));
		      im->DrawLine(pen,int(x[3]),int(y[3]),int(x[5]),int(y[5]));
			 }
			
		  void go()
			{
			int i;
			for (i=0;i<7;i++)
			{	
				x[i]-=vd;
				y[i]-=vd*ClientSize.Height/ClientSize.Width;
			    
			}	
			}
			
		  void povorot()
		  {
		  	float xc,yc,t;
			xc=x[0];
			yc=y[0];
			for (int i=0;i<8;i++)
			{
				t=x[i];
				x[i]=xc+(x[i]-xc)*cos(f)+(y[i]-yc)*sin(f);
				y[i]=yc-(t-xc)*sin(f)+(y[i]-yc)*cos(f);
			}
		  }
		
		
	private: System::ComponentModel::IContainer^  components;
			 /// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(656, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Рисунок";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(656, 131);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Ввод ск-ти движения";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(656, 201);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(125, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(656, 252);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(125, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(656, 52);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(125, 31);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Движение";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(656, 89);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(125, 36);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Остановка";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(656, 330);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(125, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Выход";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(590, 252);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 8;
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Form1::timer2_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(437, 264);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 9;
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(653, 185);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(146, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Поступательное (пикс/сек)";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(653, 233);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(137, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Вращательное (град/сек)";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(811, 438);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}      
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				timer2->Enabled=true;
				
			 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				koord();
				ris();
				this->button1->Show();
				this->button2->Show();
			}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {///
				String ^s=this->textBox1->Text;
				vd=vd.Parse(s);
				f=Convert::ToDouble(textBox2->Text)/57;
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {///
			
				f=Convert::ToDouble(textBox2->Text)/57;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				timer2->Enabled=false;
			}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
				Close();
			}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
				int i;
				pen->Color=col->Blue;  
				ris();
				go();	
				povorot();
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

