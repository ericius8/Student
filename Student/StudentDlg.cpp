
// StudentDlg.cpp: файл реализации
//
#include "pch.h"
#include "framework.h"
#include "Student.h"
#include "StudentDlg.h"
#include "afxdialogex.h"

#include "StudentLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CStudentDlg



CStudentDlg::CStudentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_DIALOG, pParent)
	, Human_check_value(FALSE)
	, Student_check_value(FALSE)
	, Name_value(_T(""))
	, Age_value(_T(""))
	, Weight_value(_T(""))
	, Study_year_value(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_Human, Human_check_value);
	DDX_Check(pDX, IDC_CHECK_Student, Student_check_value);
	DDX_Text(pDX, IDC_EDIT_Name, Name_value);
	DDX_Text(pDX, IDC_EDIT_Age, Age_value);
	DDX_Text(pDX, IDC_EDIT_Weight, Weight_value);
	DDX_Text(pDX, IDC_EDIT_Study_Year, Study_year_value);
	DDX_Control(pDX, IDC_COMBO_Gender, Combo_gender);
	DDX_Control(pDX, IDC_LIST, ListBox);
	DDX_Control(pDX, IDC_EDIT_Study_Year, Study_year_control);
	DDX_Control(pDX, IDC_STATIC_Year, Static_year);
	DDX_Control(pDX, IDC_BUTTON3, button_year);
	DDX_Control(pDX, IDC_CHECK_Student, control_check_student);
}

BEGIN_MESSAGE_MAP(CStudentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CStudentDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStudentDlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK_Student, &CStudentDlg::OnClickedCheckStudent)
	ON_BN_CLICKED(IDC_CHECK_Human, &CStudentDlg::OnClickedCheckHuman)
ON_BN_CLICKED(IDC_BUTTON3, &CStudentDlg::OnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CStudentDlg::OnClickedButton4)
ON_LBN_SELCHANGE(IDC_LIST, &CStudentDlg::OnSelchangeList)
ON_BN_CLICKED(IDC_BUTTON5, &CStudentDlg::OnClickedButton5)
ON_UPDATE_COMMAND_UI(IDD_STUDENT_DIALOG, &CStudentDlg::OnUpdateIddStudentDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CStudentDlg

BOOL CStudentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	control_check_student.SetCheck(1);
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CStudentDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CStudentDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CStudentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int sh = 0, ss = 0, id;
Human* harray = new Human[sh];
Student* sarray = new Student[sh];


template<class T>
void push(T*& arr,int& size, T value)
{
	T* newarray = new T[size+1];

	for (int i = 0; i < size; i++)
	{
		newarray[i] = arr[i];
	}
	newarray[size] = value;
	size++;
	delete[] arr;
	arr = newarray;
}

template<class T>
void pop(T*& arr, int& size,int delindex)
{	
		if (delindex >= size) return;

		T* newarray = new T[size];
		for (int i = 0; i < size; ++i) newarray[i] = arr[i];

		delete[] arr;
		arr = new T[size - 1];

		for ( int i = 0, j = 0; i < size; ++i, ++j)
			if (i != delindex) arr[j] = newarray[i];
			else --j;
		--size;

		delete[] newarray;
}

template<class T>
void viev(T*& arr, int& size, CListBox& ListBox)
{
	CString str_in_list;
	ListBox.ResetContent();
for (int i = 0; i < size; i++)
{
	str_in_list = arr[i].get_string();
	ListBox.AddString(str_in_list);
}
}

CString protection(CString str)
{
	CString tempstr= str;
	for (int i = 0, l = tempstr.GetLength(); i < l; ++i)
	{
		if ((tempstr[i] > '9') || (tempstr[i] < '0'))tempstr.SetAt(i,_T(' '));
	}
	tempstr.Remove(' ');
	return tempstr;
}
 

void CStudentDlg::OnClickedButton1()
{
	UpdateData(TRUE);

	CString temp_age = Age_value,
		temp_weight = Weight_value,
		temp_name = Name_value,
		temp_st_year = Study_year_value;
	bool gender;
	 int age =_ttoi(temp_age);
	 int weight = _ttoi(temp_weight);
	 int st_year = _ttoi(temp_st_year);
	if (Combo_gender.GetCurSel() == 0) gender = 0;
	else gender = 1;

	id = ListBox.GetCurSel();
	if (id == -1)id = 0;
		if (Human_check_value)
		{
			Human tempHuman(gender, age, weight, temp_name);
			push(harray, sh, tempHuman);
			viev(harray, sh, ListBox);
		}
		else
		{
			Student tempStudent(gender, age, weight, temp_name, st_year);
			push(sarray, ss, tempStudent);
			viev(sarray, ss, ListBox);
		};
	UpdateData(FALSE);
}


void CStudentDlg::OnClickedButton2()
{
	UpdateData(TRUE);
	id = ListBox.GetCurSel();
	if (id == -1)id = 0;
		if (Human_check_value)
		{
			if (sh >= 0) {
				pop(harray, sh, id);
				viev(harray, sh, ListBox);
			}
		}
		else
		{
			if (ss >= 0) {
				pop(sarray, ss, id);
				viev(sarray, ss, ListBox);
			}
		}
		UpdateData(FALSE);
}

void CStudentDlg::OnClickedButton3()
{
	UpdateData(TRUE);
	id = ListBox.GetCurSel();
	if (id == -1)id = 0;
	if  (ss >= 0) {
		if (Student_check_value)
		{
			int year = sarray[ListBox.GetCurSel()].get_study_year();
			sarray[ListBox.GetCurSel()].set_study_year(year + 1);
			viev(sarray, ss, ListBox);
		}
	}
	UpdateData(FALSE);
}

void CStudentDlg::OnClickedButton4()
{
	UpdateData(TRUE);
	id = ListBox.GetCurSel();
	if (id == -1)id = 0;
		if (Human_check_value)
		{
			if (sh >= 0)
			{
				Student tempStudent(harray[id].get_gender(), harray[id].get_age(), harray[id].get_weight(), harray[id].get_name(), 0);
				push(sarray, ss, tempStudent);
				pop(harray, sh, id);
				viev(sarray, sh, ListBox);
			}
		}
		else
		{
			if (ss >= 0)
			{

				Human tempHuman(sarray[id].get_gender(), sarray[id].get_age(), sarray[id].get_weight(), sarray[id].get_name());
				push(harray, sh, tempHuman);
				pop(sarray, ss, id);
				viev(sarray, ss, ListBox);
			}
		
		}

	UpdateData(FALSE);
}


void CStudentDlg::OnSelchangeList()
{
	UpdateData(TRUE);
	int id = ListBox.GetCurSel();
	id = ListBox.GetCurSel();
	if (id == -1)id = 0;
		if (Human_check_value)
		{
			if (harray[id].get_gender())Combo_gender.SetCurSel(1);
			else  Combo_gender.SetCurSel(0);
			Age_value.Format(_T("%d"), harray[id].get_age());
			Weight_value.Format(_T("%d"), harray[id].get_weight());
			Name_value = harray[id].get_name();
			Study_year_value;
		}
		else
		{
			if (harray[id].get_gender())Combo_gender.SetCurSel(1);
			else  Combo_gender.SetCurSel(0);
			Age_value.Format(_T("%d"), sarray[id].get_age());
			Weight_value.Format(_T("%d"), sarray[id].get_weight());
			Name_value = sarray[id].get_name();
			Study_year_value.Format(_T("%d"), sarray[id].get_study_year());
		}

	UpdateData(FALSE);
}



void CStudentDlg::OnClickedButton5()
{
	UpdateData(TRUE);
	CString temp_age = Age_value,
		temp_weight = Weight_value,
		temp_name = Name_value,
		temp_st_year = Study_year_value;
	bool gender;
	int age = _ttoi(temp_age);
	int weight = _ttoi(temp_weight);
	if (Combo_gender.GetCurSel() == 0) gender = 0;
	else gender = 1;
	id = ListBox.GetCurSel();
	if (id == -1)id = 0;
		if (Human_check_value)
		{
			if (sh >= 0)
			{
				harray[id].set(gender, age, weight, temp_name);
				viev(harray, sh, ListBox);
			}
		}
		else
		{
			if (ss >= 0)
			{
				int st_year = _ttoi(temp_st_year);
				sarray[id].set(gender, age, weight, temp_name, st_year);
				viev(sarray, ss, ListBox);
			}
		};
	UpdateData(FALSE);
}



void CStudentDlg::OnClickedCheckStudent()
{
	UpdateData(TRUE);
	Human_check_value = FALSE;
	Study_year_control.ShowWindow(SW_SHOW);//показать
	Static_year.ShowWindow(SW_SHOW);
	button_year.ShowWindow(SW_SHOW);
	viev(sarray, ss, ListBox);
	UpdateData(FALSE);
}

void CStudentDlg::OnClickedCheckHuman()
{
	UpdateData(TRUE);
	Student_check_value = FALSE;
	Study_year_control.ShowWindow(SW_HIDE);//скрыть
	Static_year.ShowWindow(SW_HIDE);
	button_year.ShowWindow(SW_HIDE);
	viev(harray, sh, ListBox);
	UpdateData(FALSE);
}

void CStudentDlg::OnOK()
{
	delete[] sarray;
	delete[] harray;
	CDialogEx::OnOK();
}

void CStudentDlg::OnUpdateIddStudentDialog(CCmdUI* pCmdUI)
{
	id = ListBox.GetCurSel();
	if (id == -1)id = 0;
}
