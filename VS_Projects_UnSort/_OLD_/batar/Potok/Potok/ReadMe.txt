===============================================================================
   ���������� MICROSOFT FOUNDATION CLASS: ����� ������� Potok 
===============================================================================

������ ���������� Potok ������� �������� ����������. ��� 
���������� ���������� ������ ������������� ��������������� ������� Microsoft,
� ����� �������� ��������� ������ ��� �������� ����������� ����������.

� ���� ����� ���������� ������� �������� ����������� ������, ������������
���������� ���������� Potok.

Potok.vcxproj
    ��� �������� ���� ������� ��� �������� VC++, ����������� � ������� �������
    ����������. � ��� ���������� �������� � ������ Visual C++, ��������� ����,
    � ����� �������� � ����������, ������������� � ��������� �������, ���������
    � ������� ������� ����������.

Potok.vcxproj.filters
    ��� ���� �������� ��� �������� VC++, ��������� � ������� ������� ����������.
    �� �������� �������� � �������������� ����� ������� � ����� ������� � 
    ���������. ��� ������������� ������������ � ����� IDE ��� ����������� ������
    � ����������� ������������ � ����� ���� (�������� ����� ".cpp" 
    �������������� � �������� "�������� �����").

Potok.h
    ��� �������� ���� ��������� ��� ����������. � ���� �������� ������
    ������������ ��� ������� ��������� (� ��� ����� Resource.h) � �������� �����
    ���������� CPotokApp.

Potok.cpp
    ��� �������� �������� ���� ����������, ���������� ����� ����������
    CPotokApp.

Potok.rc
    ��� ������ ���� �������� Microsoft Windows, ������������ ����������. � ����
    �������� ������, ������� � �������, ���������� � ����������� RES. ���� ����
    ����� ������������� ��������������� � Microsoft Visual C++. �������
    ����������� ������� ��������� � 1049.

res\Potok.ico
    ��� ���� ������, ������������� � �������� ������ ����������. ���� ������
    ������� ����������� ��������� ����� �������� Potok.rc.

res\Potok.rc2
    ���� ���� �������� �������, �� ������������� � Microsoft Visual C++. ���
    �������, �� ������������� ���������� ��������, ������� ��������� � ����
    ����.

/////////////////////////////////////////////////////////////////////////////

��� ���� �������� �����:
    � ������ ���������� ����������� ��������� MFC.

MainFrm.h, MainFrm.cpp
    ��� ����� �������� ����� ����� CMainFrame, ���������� ��
    CFrameWnd � ����������� ����� ���������� ����� SDI.

res\Toolbar.bmp
    ���� ���� ��������� ������� ������������ ��� ���������� ������ ������������
    �������������. ��������� ������ ������������ � ������ ��������� ��������� �
    ������ CMainFrame. �������� ���� �������� ������� ������ 
    ������������ � ������� ��������� �������� � �������� ������ IDR_MAINFRAME 
    TOOLBAR � Potok.rc, ����� �������� ������ ������ 
    ������������.
/////////////////////////////////////////////////////////////////////////////

������ ���������� ������� ���� ��� ���������� � ���� �������������:

PotokDoc.h, PotokDoc.cpp �  ��������
    ��� ����� �������� ����� CPotokDoc. �������� ��� �����, �����
    �������� ������ ������ ��������� � ����������� ���������� � �������� 
    ������ (� ������� CPotokDoc::Serialize).

PotokView.h, PotokView.cpp � ������������� ��������� ��� 
    ����� �������� ����� CPotokView.
    ������� CPotokView ������������ ��� ������������� �������� 
    CPotokDoc.





/////////////////////////////////////////////////////////////////////////////

������ �����������:

�������� ActiveX
    ���������� �������� ��������� ������������� ��������� ActiveX.

��������� ������� ������ � ���������������� ���������
    ������ ���������� ������� ��� ��� ��������� ������ ������, ��������� ������ 
    � ���������������� ��������� � ������� ������ �������-������ ������ CView 
    �� ���������� MFC.

/////////////////////////////////////////////////////////////////////////////

������ ����������� �����:

StdAfx.h, StdAfx.cpp
    ��� ����� ������������ ��� ���������� ����� �������������������� 
    ��������� (PCH) � ������ Potok.pch � ����� 
    ������������������� ����� � ������ StdAfx.obj.

Resource.h
    ��� ����������� ���� ���������, ������������ ����� �������������� 
    ��������. Microsoft Visual C++ ����������� � ��������� ���� ����.

Potok.manifest
    ����� ���������� ���������� ������������ Windows XP ��� �������� 
    ����������� ���������� �� ������������ ������ ������������ ������. 
    ��������� ���������� ��� �������� ��� �������� ���������� ������ �� ���� 
    ������ ��� ��������� ���� ������ �� ����������. �������� ���������� ����� 
    ���� ������� ��� ��������������� � �������� �������� ����� .manifest, 
    ���������������� � �� �� �����, ��� � ����������� ���� ����������, ��� �� 
    ����� ���� ������� � ����������� ���� � ���� �������.
/////////////////////////////////////////////////////////////////////////////

������ ���������:

������ ���������� ���������� "TODO:" ��� �������� ������ ��������� ����, 
������� ������� ��������� ��� ���������.

���� ���� ���������� ���������� MFC � ����� ���������� DLL, ����������� 
�������������� ���������� DLL ��� MFC. ���� ���� ������ ���������� ������� �� 
��������� ��������� ������������ �������, ����������� ����� �������������� 
��������������� �������������� ������� MFC100XXX.DLL. �������������� �������� 
�� ���� ���� ����� ��. � ������� � ��������������� ���������� Visual C++ � 
������������ �� MSDN.

/////////////////////////////////////////////////////////////////////////////
