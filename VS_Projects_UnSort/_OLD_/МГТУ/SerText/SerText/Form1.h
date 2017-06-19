#pragma once

namespace SerText {
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// —водка дл€ Form1
///
/// ¬нимание! ѕри изменении имени этого класса необходимо также изменить
/// свойство имени файла ресурсов ("Resource File Name") дл€ средства компил€ции управл€емого ресурса,
/// св€занного со всеми файлами с расширением .resx, от которых зависит данный класс. ¬ противном случае,
/// конструкторы не смогут правильно работать с локализованными
/// ресурсами, сопоставленными данной форме.
/// </summary>
public ref class Form1 : public System::Windows::Forms::Form
{
public:
Form1(void)
{
InitializeComponent();
//
//TODO: добавьте код конструктора
//
}

protected:
/// <summary>
/// ќсвободить все используемые ресурсы.
/// </summary>
~Form1()
{
if (components)
{
delete components;
}
}
private: System::Windows::Forms::MenuStrip^ menuStrip1;
protected: 
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem_File;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem_OpenFile;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem_Save;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem_Exit;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem_Work;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem_FindGood;
private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem_Find;
private: System::Windows::Forms::RichTextBox^ richTextBox;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::TextBox^ textBox2;

private:
/// <summary>
/// “ребуетс€ переменна€ конструктора.
/// </summary>
System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
/// <summary>
/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
/// содержимое данного метода при помощи редактора кода.
/// </summary>
void InitializeComponent(void)
{
this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
this->toolStripMenuItem_File = (gcnew System::Windows::Forms::ToolStripMenuItem());
this->toolStripMenuItem_OpenFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
this->toolStripMenuItem_Save = (gcnew System::Windows::Forms::ToolStripMenuItem());
this->toolStripMenuItem_Exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
this->toolStripMenuItem_Work = (gcnew System::Windows::Forms::ToolStripMenuItem());
this->toolStripMenuItem_FindGood = (gcnew System::Windows::Forms::ToolStripMenuItem());
this->toolStripMenuItem_Find = (gcnew System::Windows::Forms::ToolStripMenuItem());
this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
this->textBox1 = (gcnew System::Windows::Forms::TextBox());
this->textBox2 = (gcnew System::Windows::Forms::TextBox());
this->menuStrip1->SuspendLayout();
this->SuspendLayout();
// 
// menuStrip1
// 
this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^ >(2) {this->toolStripMenuItem_File, 
this->toolStripMenuItem_Work});
this->menuStrip1->Location = System::Drawing::Point(0, 0);
this->menuStrip1->Name = L"menuStrip1";
this->menuStrip1->Size = System::Drawing::Size(537, 24);
this->menuStrip1->TabIndex = 0;
this->menuStrip1->Text = L"menuStrip1";
// 
// toolStripMenuItem_File
// 
this->toolStripMenuItem_File->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^ >(3) {this->toolStripMenuItem_OpenFile, 
this->toolStripMenuItem_Save, this->toolStripMenuItem_Exit});
this->toolStripMenuItem_File->Name = L"toolStripMenuItem_File";
this->toolStripMenuItem_File->Size = System::Drawing::Size(48, 20);
this->toolStripMenuItem_File->Text = L"‘айл";
// 
// toolStripMenuItem_OpenFile
// 
this->toolStripMenuItem_OpenFile->Name = L"toolStripMenuItem_OpenFile";
this->toolStripMenuItem_OpenFile->Size = System::Drawing::Size(162, 22);
this->toolStripMenuItem_OpenFile->Text = L"ќткрыть";
this->toolStripMenuItem_OpenFile->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem_OpenFile_Click);
// 
// toolStripMenuItem_Save
// 
this->toolStripMenuItem_Save->Name = L"toolStripMenuItem_Save";
this->toolStripMenuItem_Save->Size = System::Drawing::Size(162, 22);
this->toolStripMenuItem_Save->Text = L"—охранить как...";
this->toolStripMenuItem_Save->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem_Save_Click);
// 
// toolStripMenuItem_Exit
// 
this->toolStripMenuItem_Exit->Name = L"toolStripMenuItem_Exit";
this->toolStripMenuItem_Exit->Size = System::Drawing::Size(162, 22);
this->toolStripMenuItem_Exit->Text = L"¬ыход";
this->toolStripMenuItem_Exit->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem_Exit_Click);
// 
// toolStripMenuItem_Work
// 
this->toolStripMenuItem_Work->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^ >(2) {this->toolStripMenuItem_FindGood, 
this->toolStripMenuItem_Find});
this->toolStripMenuItem_Work->Name = L"toolStripMenuItem_Work";
this->toolStripMenuItem_Work->Size = System::Drawing::Size(57, 20);
this->toolStripMenuItem_Work->Text = L"–абота";
// 
// toolStripMenuItem_FindGood
// 
this->toolStripMenuItem_FindGood->Name = L"toolStripMenuItem_FindGood";
this->toolStripMenuItem_FindGood->Size = System::Drawing::Size(180, 22);
this->toolStripMenuItem_FindGood->Text = L"ѕоиск хорошистов";
this->toolStripMenuItem_FindGood->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem_FindGood_Click);
// 
// toolStripMenuItem_Find
// 
this->toolStripMenuItem_Find->Name = L"toolStripMenuItem_Find";
this->toolStripMenuItem_Find->Size = System::Drawing::Size(180, 22);
this->toolStripMenuItem_Find->Text = L"ќтобразить";
this->toolStripMenuItem_Find->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem_Find_Click);
// 
// richTextBox
// 
this->richTextBox->Location = System::Drawing::Point(12, 27);
this->richTextBox->Name = L"richTextBox";
this->richTextBox->Size = System::Drawing::Size(513, 223);
this->richTextBox->TabIndex = 1;
this->richTextBox->Text = L"";
// 
// textBox1
// 
this->textBox1->Location = System::Drawing::Point(112, 1);
this->textBox1->Name = L"textBox1";
this->textBox1->Size = System::Drawing::Size(100, 20);
this->textBox1->TabIndex = 2;
// 
// textBox2
// 
this->textBox2->Location = System::Drawing::Point(218, 1);
this->textBox2->Name = L"textBox2";
this->textBox2->Size = System::Drawing::Size(100, 20);
this->textBox2->TabIndex = 3;
// 
// Form1
// 
this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
this->ClientSize = System::Drawing::Size(537, 262);
this->Controls->Add(this->textBox2);
this->Controls->Add(this->textBox1);
this->Controls->Add(this->richTextBox);
this->Controls->Add(this->menuStrip1);
this->MainMenuStrip = this->menuStrip1;
this->Name = L"Form1";
this->Text = L"Form1";
this->menuStrip1->ResumeLayout(false);
this->menuStrip1->PerformLayout();
this->ResumeLayout(false);
this->PerformLayout();

}
#pragma endregion
private: System::Void toolStripMenuItem_OpenFile_Click(System::Object^ sender, System::EventArgs^ e) {
OpenFileDialog^open=gcnew OpenFileDialog;
open->DefaultExt="*.rtf";
open->Filter="RTF Files|*.rtf";
//richTextBox1->Close();
if(open->ShowDialog()==System::Windows::Forms::DialogResult::OK&&open->FileName->Length>0)
richTextBox->LoadFile(open->FileName, RichTextBoxStreamType::PlainText);
}

private: System::Void toolStripMenuItem_Save_Click(System::Object^ sender, System::EventArgs^ e) {
SaveFileDialog^save=gcnew SaveFileDialog;
save->DefaultExt="*.rtf";
//save1->Filter="RTF Files|*.rtf";
if(save->ShowDialog()==System::Windows::Forms::DialogResult::OK&&save->FileName->Length>0)
richTextBox->SaveFile(save->FileName, RichTextBoxStreamType::PlainText);
}

private: System::Void toolStripMenuItem_Exit_Click(System::Object^ sender, System::EventArgs^ e) {
Application::Exit();
}

private: System::Void toolStripMenuItem_FindGood_Click(System::Object^ sender, System::EventArgs^ e) {
// перебираем строки richTextBox в цикле, дл€ каждой строки провер€ем,
// удовлетвор€ет ли она условию
for(int i = 0; i < richTextBox->Lines->Length; i++)
{
if(StringIsGood(richTextBox->Lines[i])) {
// что-то делаем с найденной строкой
}

}
}

private: System::Void toolStripMenuItem_Find_Click(System::Object^ sender, System::EventArgs^ e) {
// вместо этого вставить запрос начала и конца фамилии из диалога,
// передать в функцию StringIsMatch
String^ start = textBox1->Text;
String^ end = textBox2->Text;
//String^ start = "»в";
//String^ end = "ов";

// перебираем строки richTextBox в цикле, дл€ каждой строки провер€ем,
// удовлетвор€ет ли она условию
for(int i = 0; i < richTextBox->Lines->Length; i++)
{
if(StringIsMatch(richTextBox->Lines[i], start, end)) {
// что-то делаем с найденной строкой
}
}
}

// возвращает true, если все оценки >= 4
private: System::Boolean StringIsGood(String^ str) {
// Substring выдел€ет подстроку из строки, аргументы: индекс начала и длина подстроки
// int::Parse перевозит строковое представление числа в int
int o1 = int::Parse(str->Substring(29, 3));
int o2 = int::Parse(str->Substring(32, 3));
int o3 = int::Parse(str->Substring(36, 3));

// вернуть true, если все оценки >= 4
return o1 >= 4 && o2 >= 4 && o3 >= 4;
}

// возвращает true, если строка str начинаетс€ с подстроки start и заканчиваетс€ подстрокой end
private: System::Boolean StringIsMatch(String^ str, String^ start, String^ end) {
// StartsWith возвращает true, если строка начинаетс€ со строки-аргумента,
// EndsWith - аналогично дл€ хвоста строки
return str->StartsWith(start) && str->EndsWith(end);
}
};
}