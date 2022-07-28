
// StudentDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CStudentDlg
class CStudentDlg : public CDialogEx
{
// Создание
public:
	CStudentDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	BOOL Human_check_value;
	BOOL Student_check_value;
	CString Name_value;
	CString Age_value;
	CString Weight_value;
	CString Study_year_value;
	CComboBox Combo_gender;
	afx_msg void OnClickedButton1();
	CListBox ListBox;
	afx_msg void OnClickedButton2();
//	afx_msg void OnSelchangeList();
	afx_msg void OnClickedCheckStudent();
	afx_msg void OnClickedCheckHuman();
	CEdit Study_year_control;
	CStatic Static_year;
	CButton button_year;
//	afx_msg void OnUpdateIddStudentDialog(CCmdUI* pCmdUI);
	CButton control_check_student;
	afx_msg void OnClickedButton3();
	virtual void OnOK();
	afx_msg void OnClickedButton4();
	afx_msg void OnSelchangeList();
	afx_msg void OnClickedButton5();
	afx_msg void OnUpdateIddStudentDialog(CCmdUI* pCmdUI);
};
