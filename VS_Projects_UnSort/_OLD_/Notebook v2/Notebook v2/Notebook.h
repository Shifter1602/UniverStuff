#pragma once

// ����� �������� ������
class Notebook
{
public:
	// ����������� 
	// noteCount - ������������ ���������� �������, ��� ������� ����� �������� ������
	// unique - ������������ �� ������������ �����������, 
	// �.�., ����� �� ��������� ��������� ������� � ����������� ���������
	Notebook( int noteCount, bool unique );

	// ����������
	~Notebook(void);

	// ����� ���������� ������ � ������
	// surname -  �������
	// phone - ����� ��������
	// ������������ ��������:
	//  true - ���� ������ ���� ������� ���������
	//  false - � ��������� ������
	// ���� ����� �� ����� �������� �������� surname � phone, � �������� ��
	bool Add( char *surname, char *phone );

	// �������� ������/�������
	// surname - �������, ������/������ � �������� ������� �������
	// ������������ ��������:
	//  true - ���� ������ ���� �������/������ ���� ������� �������
	//  false - � ��������� ������
	bool Remove( char *surname );

	// ����� ������ � �������� ��������
	// surname - ������� ��� ������ ������
	// ������������ ��������:
	//  ������, ���������� �������, ���� ����� ������ ���� ������� ����
	//  0 - � ��������� ������
	char *Search( char *surname );

	// ���������� �������������
private:

	// ��������� ����� ������ � ������ - ��� ������
	struct Note
	{
		char* surname;  // �������
		char* phone;    // ����� ��������
	};

	// ��������� �� ��������� ���� Note
	// ������������ ��� ����������� ������� ������� � 
	// ������ ��������� �� ������ ������� ����� �������
	Note* notes;

	// ���������� �������, ��� ������� �������� ������, ��� ��
	// ����� �������, ��� ��
	// ����������� ���������� ���������� �������
	int reserved;

	// ���������� ����������� ������� � �������.
	// ������ � ������� �������������, ������� � ������� 0 � ���������� �������� count - 1
	int count;

	// ����, ����� �� �� ������������ ������������ �������,
	// �.�. ��� �� ����� ��������� ������� ���������� ������� � ����� � ��� �� ��������
	bool unique;
};