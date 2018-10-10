
// MFCApplication1Dlg.h: файл заголовка
//

#pragma once
#include <string>

// Диалоговое окно CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	CString path_shifr;
	std::string shifr_text;
	CString path_orig;
	//int password_length;
	//CString passwords;
	CListBox passwords;
	CEdit password_lenght;
	CEdit decripted_text;
//	afx_msg void OnBnClickedButtonDecript();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonDecript();
	afx_msg void OnBnClickedButton3();
	CEdit save_path;
	afx_msg void OnBnClickedButton5();
};
