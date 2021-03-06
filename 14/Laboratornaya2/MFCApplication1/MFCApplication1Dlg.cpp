
// MFCApplication1Dlg.cpp: файл реализации
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

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


// Диалоговое окно CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, path_shifr(_T("C:\\shifr.txt"))
	, path_orig(_T("C:\\text.txt"))
	//, password_length(5)
	//, passwords(_T("asd\r\nsdfsdfsdf\r\n"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PATH_SHIFR, path_shifr);
	DDV_MaxChars(pDX, path_shifr, 255);
	DDX_Text(pDX, IDC_PATH_ORIG, path_orig);
	DDV_MaxChars(pDX, path_orig, 255);
	//DDX_Text(pDX, IDC_PATH_LENGTH, password_length);
	//DDV_MinMaxInt(pDX, password_length, 0, 255);
	//DDX_LBString(pDX, IDC_LIST1, passwords);
	DDX_Control(pDX, IDC_LIST1, passwords);
	DDX_Control(pDX, IDC_PATH_LENGTH, password_lenght);
	DDX_Control(pDX, IDC_EDIT_SHIFR_TEXT, decripted_text);
	DDX_Control(pDX, IDC_EDIT2, save_path);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
//	ON_BN_CLICKED(IDC_BUTTON_DECRIPT, &CMFCApplication1Dlg::OnBnClickedButtonDecript)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_BUTTON_DECRIPT, &CMFCApplication1Dlg::OnBnClickedButtonDecript)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
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
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
using namespace std;
#include <iostream>
#include <istream>
#include <fstream>
#include <codecvt>
#include <vector>
#include <map>
#include <algorithm>
#include "VishenerLib.h"
bool pair_less(const std::pair<char, std::size_t>& p1, const std::pair<char, std::size_t>& p2)
{
	return p1.second > p2.second;
}
void sort_char_from_text_by_column_and_frequency(const char* filename, std::string& text, std::size_t columns, std::vector<std::vector<std::pair<char, std::size_t>>>& c_freq)
{
	vector<map<char, size_t>> dict;
	dict.resize(columns);
	text.insert(text.end(), istreambuf_iterator<char>(ifstream(filename, ios::binary)), istreambuf_iterator<char>());
std:size_t i = 0;
	for (char c : text)
	{
		dict[i][c]++;
		i = (i + 1) % columns;
	}
	c_freq.resize(columns);
	for (int i = 0;i < columns;++i)
	{
		c_freq[i].insert(c_freq[i].end(), dict[i].begin(), dict[i].end());
		std::sort(c_freq[i].begin(), c_freq[i].end(), pair_less);
	}
}
void sort_char_from_text_and_frequency(const char* filename, std::vector<std::pair<char, std::size_t>>& c_freq)
{
	map<char, size_t> dict;
	std::string text;
	text.insert(text.end(), istreambuf_iterator<char>(ifstream(filename, ios::binary)), istreambuf_iterator<char>());
	for (char c : text)
	{
		dict[c]++;
	}
	c_freq.insert(c_freq.end(), dict.begin(), dict.end());
	std::sort(c_freq.begin(), c_freq.end(), pair_less);
}

std::vector<std::string> deshifrator(const char* file_shifr,std::string& text, const char* file_orig, std::size_t pass_length)
{
	std::vector<std::vector<std::pair<char, std::size_t>>> c_shifr;
	std::vector<std::pair<char, std::size_t>> c_orig;
	sort_char_from_text_by_column_and_frequency(file_shifr, text, pass_length, c_shifr);
	sort_char_from_text_and_frequency(file_orig, c_orig);
	std::vector<std::vector<char>> dict_diff;
	dict_diff.resize(pass_length);
	for (int i = 0;i < pass_length;++i)
	{
		for (auto sh_column = c_shifr[i].begin(), orig_column = c_orig.begin();sh_column != c_shifr[i].end() && orig_column != c_orig.end();++sh_column, ++orig_column)
		{
			dict_diff[i].push_back(sh_column->first - orig_column->first);
		}
	}
	std::vector<std::string> pass;
	for (int i = 0; i < pass_length;++i)
	{
		if (pass.size() < dict_diff[i].size())
			pass.resize(dict_diff[i].size());
		for (int j = 0;j < dict_diff[i].size();++j)
		{
			pass[j].push_back(dict_diff[i][j]);
		}
	}
	return pass;
}
std::wstring GetWChar(const std::string &aString)
{
	const int maxSize = 1024 * 1024;
	static wchar_t buff[maxSize];

	int nSize = ::MultiByteToWideChar(CP_UTF8, 0, aString.c_str(), static_cast<int>(aString.length() + 1), NULL, NULL);

	wchar_t *tBuff = buff;
	if (nSize > maxSize)
	{
		tBuff = new wchar_t[nSize];
	}
	if (nSize <= 0 && tBuff == NULL)
		return L"";

	::MultiByteToWideChar(1251, 0, aString.c_str(), static_cast<int>(aString.length() + 1), buff, nSize);

	std::wstring result(tBuff);

	if (tBuff != buff)
		delete[] tBuff;

	return result;
}
void CMFCApplication1Dlg::OnBnClickedButton1()
{}

void CMFCApplication1Dlg::OnBnClickedButton2()
{
	CString tmp;
	password_lenght.GetWindowText(tmp);
	int pass_len = _ttoi(tmp);
	auto pass = deshifrator(CT2A(path_shifr).m_psz, shifr_text, CT2A(path_orig).m_psz, pass_len);
	passwords.ResetContent();
	for (auto p : pass)
		passwords.InsertString(passwords.GetCount(), GetWChar(p).c_str());

}

void CMFCApplication1Dlg::OnBnClickedButtonDecript()
{
	
		// TODO: добавьте свой код обработчика уведомлений
}

void CMFCApplication1Dlg::OnBnClickedButton3()
{
	int nSel = passwords.GetCurSel();
	if (nSel < 0)
		return;
	CString cur_password;
	passwords.GetText(nSel, cur_password);
	std::string decripted_text_;
	VishenerEncodeDecode(Decription, shifr_text, cur_password.GetString(), decripted_text_);
	decripted_text.SetWindowText(GetWChar(decripted_text_).c_str());
}

void CMFCApplication1Dlg::OnBnClickedButton5()
{
	CString str,saving_text;
	save_path.GetWindowText(str);
	wofstream save(str.GetString());
	std::locale mylocale("");
	save.imbue(mylocale);
	decripted_text.GetWindowText(saving_text);
	save << saving_text.GetString() <<std::endl;
	save.close();
}
