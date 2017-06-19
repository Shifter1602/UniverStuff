#pragma once
#include "conio.h"
#include "io.h"
#include "stdio.h"
#include "math.h"
#include "string.h"

char path[300];
struct stud
{
	int nom;
	char gr[9];
	char fam[11];
	int oc[3];
};

bool caseP1 (char *sf, char *Mask)
{  bool flag1 = true;
   int i=0, j=0;
	 while ( Mask[j] !='*')
      { if ( sf[i] != Mask[j] ) {flag1=false; break;}
		 else { i++; j++;}
	  }
	if (flag1) return true;
	else return false;
}
bool caseP0 (char *sf, char *Mask)
{  bool flag1 = true;
   int i=strlen(sf)-1, j=strlen(Mask)-1;
	 while ( Mask[j] !='*')
      { if ( sf[i] != Mask[j] ) {flag1=false; break;}
		 else { i--; j--;}
	  }
	if (flag1) return true;
	else return false;
}

namespace My111 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Form1
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������ToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ������������ToolStripMenuItem;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->����ToolStripMenuItem, 
				this->������ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(891, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->�������ToolStripMenuItem, 
				this->���������ToolStripMenuItem, this->��������ToolStripMenuItem, this->�����ToolStripMenuItem});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���������ToolStripMenuItem_Click);
			// 
			// ��������ToolStripMenuItem
			// 
			this->��������ToolStripMenuItem->Name = L"��������ToolStripMenuItem";
			this->��������ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->��������ToolStripMenuItem->Text = L"��������";
			this->��������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����ToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�����������������������������ToolStripMenuItem, 
				this->������������ToolStripMenuItem});
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->������ToolStripMenuItem->Text = L"������";
			// 
			// �����������������������������ToolStripMenuItem
			// 
			this->�����������������������������ToolStripMenuItem->Name = L"�����������������������������ToolStripMenuItem";
			this->�����������������������������ToolStripMenuItem->Size = System::Drawing::Size(277, 22);
			this->�����������������������������ToolStripMenuItem->Text = L"���������� �� ����������� ������";
			this->�����������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����������������������������ToolStripMenuItem_Click);
			// 
			// ������������ToolStripMenuItem
			// 
			this->������������ToolStripMenuItem->Name = L"������������ToolStripMenuItem";
			this->������������ToolStripMenuItem->Size = System::Drawing::Size(277, 22);
			this->������������ToolStripMenuItem->Text = L"����� �� ����� \"*\"";
			this->������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::������������ToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(16, 33);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(843, 288);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::dataGridView1_KeyUp);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(177, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(118, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(301, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"������� �����";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(891, 421);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 	 if (e->KeyCode==Keys::Enter)
				 dataGridView1->RowCount++;
			 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 dataGridView1->RowCount = 2;
				 dataGridView1->ColumnCount = 6;
				 dataGridView1->Columns[0]->HeaderText="�����";
				 dataGridView1->Columns[1]->HeaderText="������";
				 dataGridView1->Columns[2]->HeaderText="�������";
				 dataGridView1->Columns[3]->HeaderText="������ 1";
				 dataGridView1->Columns[4]->HeaderText="������ 2";
				 dataGridView1->Columns[5]->HeaderText="������ 3";
		 }
private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  FILE *f;
				 stud a;
				 int i, j, size = sizeof(a);
				 char *sl;
				 OpenFileDialog ^open1 = gcnew OpenFileDialog;
				 open1->DefaultExt="*.dat";
			     open1->Filter="DATFiles|*.dat";
				 String ^s;
				 if (open1->ShowDialog() == System::Windows::Forms::DialogResult::OK&& open1->FileName->Length > 0)
				 {
					 s = gcnew String(open1->FileName);
					 sl = (char*) (void*) Marshal::StringToHGlobalAnsi(s);
					 strcpy(path, sl); 
					 f=fopen (sl,"rb");
					 
					 if ((f = fopen(path, "rb")) == NULL)
					 {
						 MessageBox::Show("������ �������� �����");
						 Application::Exit();
					 }	 
					 
					 i = 0;
					 while (fread(&a, size, 1,f)>0)
					 {
						 if (i >= dataGridView1->RowCount) dataGridView1->RowCount++;
						 dataGridView1[0, i]->Value = gcnew String(Convert::ToString(a.nom));
						 dataGridView1[1, i]->Value = gcnew String(a.gr);
						 dataGridView1[2, i]->Value = gcnew String(a.fam);
						 for (j = 0; j < 3; j++)
							 dataGridView1[3 + j, i]->Value = gcnew String(Convert::ToString(a.oc[j]));
						 i++;
					 }
					 dataGridView1->RowCount = i;
					 fclose(f);
				 }
		 }
private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FILE *f;
			 stud a;
			 int i, j, size = sizeof(a);
			 char *sl;
			 SaveFileDialog ^save1 = gcnew SaveFileDialog;
			 save1->DefaultExt="*.dat";
			 save1->Filter="DATFiles|*.dat";
			 String ^s;
			 if (save1->ShowDialog() == System::Windows::Forms::DialogResult::OK&& save1->FileName->Length > 0)
			 {
				 s = gcnew String(save1->FileName);
				 sl = (char*) (void*) Marshal::StringToHGlobalAnsi(s);
				    f=fopen (sl,"wb");
				    if ((f = fopen(sl, "wb")) == NULL)
				    {
					 MessageBox::Show("������ �������� �����");
				     Application::Exit();
				    }	


				   
				 for (i = 0; i < dataGridView1 -> RowCount; i++)
				 {
					 a.nom = Convert::ToInt32(dataGridView1[0, i]->Value->ToString());
					 
					 sl = (char*) (void*) Marshal::StringToHGlobalAnsi(dataGridView1[1, i]->Value->ToString());
					 strcpy(a.gr, sl);	

					 sl = (char*) (void*) Marshal::StringToHGlobalAnsi(dataGridView1[2, i]->Value->ToString());
					 strcpy(a.fam, sl);

					 for (j = 0; j < 3; j++)
						 a.oc[j] = Convert::ToInt32(dataGridView1[3 + j, i]->Value->ToString());
					 fwrite(&a, size, 1, f);
				 }
				 fclose(f);
			 }
		 }
private: System::Void ��������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			  int i, j;
			 for (i=0; i<dataGridView1->RowCount; i++)
				 for (j=0; j<dataGridView1->ColumnCount; j++)
					 dataGridView1[j,i]->Value=" ";
		 }
private: System::Void �����������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			    FILE *f1, *f2;
				 stud a, b;
				 bool flag=true;
				 int i, j, nn, size = sizeof(a);
				 char *sl;
				 OpenFileDialog ^open1 = gcnew OpenFileDialog;
				 open1->DefaultExt="*.dat";
			     open1->Filter="DATFiles|*.dat";
				 String ^s;
				 if (open1->ShowDialog() == System::Windows::Forms::DialogResult::OK&& open1->FileName->Length > 0)
				 {
					 s = gcnew String(open1->FileName);
					 sl = (char*) (void*) Marshal::StringToHGlobalAnsi(s);
					 f1=fopen (sl,"rb");
					 nn = filelength (fileno (f1)) / size;
			         f2 = fopen("����������", "wb+");

			         while (fread(&a, size, 1, f1) > 0)
			           
			             	 fwrite(&a, size, 1, f2);
		           
			          fclose(f1);
			 while (flag)
			 {
				 flag = false;
				 fseek(f2, 0, SEEK_SET);
				 for (i = 0; i < nn - 1; i++)
				 {
					 fread(&a, size, 1, f2);
					 fread(&b, size, 1, f2);
					 if ( a.nom > b.nom )
					 {
						 fseek(f2, -2 * size, SEEK_CUR);
						 fwrite( &b, size, 1, f2);
						 fwrite( &a, size, 1, f2);
						 flag = true;
					 }
					 fseek(f2, -size, SEEK_CUR);
				 }
				 nn--;
			 }
			 fseek(f2, 0, SEEK_SET);
			 i = 0;
			 while (fread(&a, size, 1, f2)>0)
			 {
				 dataGridView1[0, i]->Value = gcnew String(Convert::ToString(a.oc));;
				 dataGridView1[1, i]->Value = gcnew String(a.fam);
				 dataGridView1[2, i]->Value = gcnew String(a.gr);
				 for (int j = 0; j < 3; j++)
					 dataGridView1[3 + j, i]->Value = gcnew String(Convert::ToString(a.oc[j]));
				 i++;
			 }
			 fclose(f2);
				 }
		 }
private: System::Void ������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FILE *f1;
				 stud a;
				 bool flag;
				 int i, j, p, size = sizeof(a);
				 char *sl, *s2, *Mask, sf[11];
				 OpenFileDialog ^open1 = gcnew OpenFileDialog;
				 open1->DefaultExt="*.dat";
			     open1->Filter="DATFiles|*.dat";
				 String ^s;
				 String ^textbox=this->textBox1->Text;
				 Mask=(char*)(void*)Marshal::StringToHGlobalAnsi(textbox); // mask from textbox
				 for ( i=0; i < strlen(Mask); i++)
				   { if ( Mask[i]=='*')
				          { p=2;                  // ��������� � ��������
							if (i==0) p=0;           //      � ������
				            if (i==(strlen(Mask)-1)) p=1; // � �����
				          } 
				    }
				 if (open1->ShowDialog() == System::Windows::Forms::DialogResult::OK&& open1->FileName->Length > 0)
				 {   
					 s = gcnew String(open1->FileName);
					 sl = (char*) (void*) Marshal::StringToHGlobalAnsi(s);
                      f1=fopen (sl,"rb");
						int   q=0;
						 while  (fread (&a, size, 1 ,f1)>0 )
						 {   flag=true; 
							strcpy ( sf, a.fam );

							 if ( p == 1)
							    { if (!caseP1 ( sf, Mask ) ) flag=false; }

							 if ( p == 0)
							   {  if (!caseP0 (sf, Mask) ) flag=false;}
							
							 if ( p == 2)
							    { if ( (!caseP1(sf, Mask)) || (!caseP0(sf, Mask)) ) flag=false; }

							 if (flag) 
							 {  dataGridView1[0, q]->Value = gcnew String(Convert::ToString(a.nom));;
				                dataGridView1[1, q]->Value = gcnew String(a.gr);
				                dataGridView1[2, q]->Value = gcnew String(a.fam);
				                   for (int j = 0; j < 3; j++)
				                 	 dataGridView1[3 + j, q]->Value = gcnew String(Convert::ToString(a.oc[j]));
								   q++;
							 }
				      }
				 fclose ( f1 );   
		       }
		 }
};
}

