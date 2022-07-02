
// amendDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "amend.h"
#include "amendDlg.h"
#include "afxdialogex.h"

#include <string>
#include <fstream>
#include <iostream>
#include"ocr.h"
using namespace std;
string cpp_name = "E:\\vs\\code\\OCR_1\\test0.txt";
string img_name, Input_name1, Input_name2,Correct_name1,Correct_name2,score1,score2,txtname,cppname,outputname1,outputname2;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
 afx_msg void OnBnClickedOk();
 //afx_msg void OnBnClickedButton1();
 //afx_msg void set();
 //afx_msg void help();
 afx_msg void OnBnClickeddakai();
 afx_msg void OnBnClickedbianyi();
 afx_msg void OnEnChangeEdit3();
 afx_msg void OnEnChangeEdit2();
 afx_msg void OnBnClickedButton8();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
//ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
////ON_BN_CLICKED(IDC_BUTTON6, &CAboutDlg::set)
//ON_BN_CLICKED(IDC_BUTTON7, &CAboutDlg::help)
ON_BN_CLICKED(IDC_BUTTON5, &CAboutDlg::OnBnClickeddakai)
ON_BN_CLICKED(IDC_BUTTON2, &CAboutDlg::OnBnClickedbianyi)
//ON_EN_CHANGE(IDC_EDIT2, &CAboutDlg::OnEnChangeEdit2)
ON_BN_CLICKED(IDC_BUTTON8, &CAboutDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CamendDlg 对话框



CamendDlg::CamendDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AMEND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CamendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_PIC, my_picture);
	DDX_Control(pDX, IDC_EDIT1, jpg_name);
	DDX_Control(pDX, IDC_EDIT2, input_name01);
	DDX_Control(pDX, IDC_EDIT3, input_name02);
	DDX_Control(pDX, IDC_EDIT4, input_name03);
	DDX_Control(pDX, IDC_EDIT5, input_name04);
	DDX_Control(pDX, IDC_EDIT6_, input_name05);
	DDX_Control(pDX, IDC_EDIT7, inputname05);
	DDX_Control(pDX, IDC_EDIT6, inputname06);
	DDX_Control(pDX, IDC_EDIT8, inputname07);
	DDX_Control(pDX, IDC_EDIT9, inputname08);
}
BEGIN_MESSAGE_MAP(CamendDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
        ON_BN_CLICKED(IDOK, &CamendDlg::OnBnClickedOk)
        ON_BN_CLICKED(IDC_BUTTON1, &CamendDlg::OnBnClickedButton1)
        ON_BN_CLICKED(IDC_BUTTON_SAVE, &CamendDlg::OnBnClickedButtonSave)
	//ON_BN_CLICKED(IDC_BUTTON5, &CamendDlg::OnBnClickedButton5)
	//ON_BN_CLICKED(IDC_BUTTON6, &CamendDlg::OnBnClickedButton6)
	//ON_BN_CLICKED(IDC_BUTTON7, &CamendDlg::OnBnClickedButton7)
	/*ON_BN_CLICKED(IDC_BUTTON3, &CamendDlg::OnBnClickedButton3)*/
	ON_EN_CHANGE(IDC_EDIT_CODE, &CamendDlg::OnEnChangeEditCode)
	/*ON_EN_CHANGE(IDC_EDIT_STATUS, &CamendDlg::OnEnChangeEditStatus)*/
	ON_BN_CLICKED(IDC_BUTTON2, &CamendDlg::OnBnClickedButton2)
	//ON_EN_CHANGE(IDC_EDIT2, &CamendDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CamendDlg::OnEnChangeEdit1)
	/*ON_STN_CLICKED(IDC_STATIC_PIC, &CamendDlg::OnStnClickedStaticPic)*/
	ON_BN_CLICKED(IDC_BUTTON3, &CamendDlg::OnBnClickeddakai2)
	ON_BN_CLICKED(IDC_BUTTON4, &CamendDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CamendDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CamendDlg::OnBnClickedButton9)
	ON_EN_CHANGE(IDC_EDIT5, &CamendDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CamendDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON11, &CamendDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &CamendDlg::OnBnClickedButton10)
	ON_EN_CHANGE(IDC_EDIT8, &CamendDlg::OnEnChangeEdit8)
	ON_BN_CLICKED(IDC_BUTTON13, &CamendDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &CamendDlg::OnBnClickedButton12)
	ON_EN_CHANGE(IDC_EDIT9, &CamendDlg::OnEnChangeEdit9)
END_MESSAGE_MAP()


// CamendDlg 消息处理程序

BOOL CamendDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

 //       CImage image;
 //       image.Load(L"D:\\zhangweiye\\2.jpg");

 //       //CBitmap m_bmp;
 //       //BITMAP bm;
 //       //m_bmp.Attach(image);
 //       //m_bmp.GetObject(sizeof(BITMAP), &bm);


	////CRect rect(0, 0, image.GetWidth(), image.GetHeight());
 //       CRect rect;
 //       my_picture.GetWindowRect(&rect);
 //       ScreenToClient(&rect);
 //       my_picture.MoveWindow(rect.left, rect.top, image.GetWidth(),
 //                             image.GetHeight(),true);


 //       my_picture.GetClientRect(&rect);
 //       auto pDC=my_picture.GetDC();
 //       image.Draw(pDC->m_hDC, rect);
 //       ReleaseDC(pDC);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CamendDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CamendDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CamendDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedOk() {
  // TODO: 在此添加控件通知处理程序代码
  CDialogEx::OnOK();
}

void CamendDlg::OnBnClickedOk() {


  //CDialogEx::OnOK();
}
//打开按钮
void CamendDlg::OnBnClickedButton1() {
  // TODO: 在此添加控件通知处理程序代码

  CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                   L"*.JPG|*.JPG");
  if (fdlg.DoModal() == IDOK) {
    jpg_name.SetWindowTextW(fdlg.GetPathName());
	CString c_s = fdlg.GetPathName();
	std::string str(CW2A(c_s.GetString()));
	img_name = str;
   
  }
}

void CamendDlg::OnBnClickedButtonSave() {
  // TODO: 在此添加控件通知处理程序代码

  CFileDialog fdlg(false, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                   L"*.cpp|*.cpp");
  if (fdlg.DoModal() == IDOK) {

	 auto filename = fdlg.GetPathName();

    CString tmp_cstring;
   /* edit_code.GetWindowTextW(tmp_cstring);*/

    wofstream code_file(filename);

    if (!code_file.is_open()) {
      //cout << "error" << endl;
    }

	
	code_file << wstring(tmp_cstring.GetBuffer());

    code_file.close();
  }
}
void CAboutDlg::OnBnClickeddakai()
{
	// TODO: 在此添加控件通知处理程序代码
}
//void CAboutDlg::OnBnClickedButton1()
//{
//
//}
void CamendDlg::OnEnChangeEditCode()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


//void CamendDlg::OnEnChangeEditStatus()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}
void __cdecl CamendDlg::OnBnClickedButton2(void)
{
	OCR(img_name,txtname);
	Solve(txtname,cppname);
	/*****************************调编译写文件实现*****************************************/
	const char* inputname1 = Input_name1.data();
	const char* inputname2 = Input_name2.data();
	const char* outname1 = outputname1.data();
	const char* outname2 = outputname2.data();
	string str = "E:\\vs\\community\\VC\\Tools\\MSVC\\14.31.31103\\bin\\Hostx86\\x64\\cl.exe /EHsc " + cppname;
	const char* cppname0 = str.data();
	const char* exename0 = "C:\\Users\\14418\\Desktop\\amend\\amend\\x64\\Release\\test0.exe";
	Write_Cpp(cppname0, exename0, inputname1, outname1);
	//   /***************************对答案实现**************************************************/
	Check_Answer(Correct_name1, outname1,score1);
	Write_Cpp(cppname0, exename0, inputname2, outname2);
	Check_Answer(Correct_name2,outname2,score2);
	string ans = score1 + "\r\n" + score2;
	CString Cans(ans.c_str());
	input_name05.SetWindowTextW(Cans);

}
void CAboutDlg::OnBnClickedbianyi()
{
	
}


void CamendDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CamendDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//
//void CamendDlg::OnStnClickedStaticPic()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}


void CamendDlg::OnBnClickeddakai2()
{
	// TODO: 在此添加控件通知处理程序代码

  CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
                   L"*.input|*.input");
  if (fdlg.DoModal() == IDOK) {
    input_name01.SetWindowTextW(fdlg.GetPathName());
	CString c_s = fdlg.GetPathName();
	std::string str(CW2A(c_s.GetString()));
	Input_name1 = str;
   /* CImage image;
    image.Load(fdlg.GetPathName());

    CRect rect;
    my_picture.GetWindowRect(&rect);
    ScreenToClient(&rect);
    my_picture.MoveWindow(rect.left, rect.top, image.GetWidth(),
                          image.GetHeight(), true);

    my_picture.GetClientRect(&rect);
    auto pDC = my_picture.GetDC();
    image.Draw(pDC->m_hDC, rect);
    ReleaseDC(pDC);

	*/
	/*ifstream code_file("E:\\vs\\code\\OCR_1\\test.cpp");

    if (!code_file.is_open()) {
      cout << "error" << endl;
    }

	string tmp;*/

	/*edit_code.SetWindowTextW(CString (""));
	while (getline(code_file, tmp)) {
          CString tmp_cstring;
          edit_code.GetWindowTextW(tmp_cstring);
          tmp_cstring += "\r\n";
          tmp_cstring += tmp.c_str();
          edit_code.SetWindowTextW(tmp_cstring);
        }*/
        /*code_file.close();*/
  }
}


void CAboutDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CAboutDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CamendDlg::OnBnClickedButton4()
{
	CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"*.input|*.input");
	if (fdlg.DoModal() == IDOK) {
		input_name02.SetWindowTextW(fdlg.GetPathName());
		CString c_s = fdlg.GetPathName();
		std::string str(CW2A(c_s.GetString()));
		Input_name2 = str;
	}
}


void CAboutDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CamendDlg::OnBnClickedButton8()
{
	CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"*.correct|*.correct");
	if (fdlg.DoModal() == IDOK) {
		input_name03.SetWindowTextW(fdlg.GetPathName());
		CString c_s = fdlg.GetPathName();
		std::string str(CW2A(c_s.GetString()));
		Correct_name1 = str;
	}
}


void CamendDlg::OnBnClickedButton9()
{
	CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"*.correct|*.correct");
	if (fdlg.DoModal() == IDOK) {
		input_name04.SetWindowTextW(fdlg.GetPathName());
		CString c_s = fdlg.GetPathName();
		std::string str(CW2A(c_s.GetString()));
		Correct_name2 = str;
	}
}


void CamendDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CamendDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CamendDlg::OnBnClickedButton11()
{
	CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"*.txt|*.txt");
	if (fdlg.DoModal() == IDOK) {
		inputname05.SetWindowTextW(fdlg.GetPathName());
		CString c_s = fdlg.GetPathName();
		std::string str(CW2A(c_s.GetString()));
		txtname = str;
	}
}


void CamendDlg::OnBnClickedButton10()
{
	CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"*.cpp|*.cpp");
	if (fdlg.DoModal() == IDOK) {
		inputname06.SetWindowTextW(fdlg.GetPathName());
		CString c_s = fdlg.GetPathName();
		std::string str(CW2A(c_s.GetString()));
		cppname = str;
	}
}


void CamendDlg::OnEnChangeEdit8()
{
	
}


void CamendDlg::OnBnClickedButton13()
{
	CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"*.output|*.output");
	if (fdlg.DoModal() == IDOK) {
		inputname08.SetWindowTextW(fdlg.GetPathName());
		CString c_s = fdlg.GetPathName();
		std::string str(CW2A(c_s.GetString()));
		outputname2 = str;
	}
}


void CamendDlg::OnBnClickedButton12()
{
	CFileDialog fdlg(true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		L"*.output|*.output");
	if (fdlg.DoModal() == IDOK) {
		inputname07.SetWindowTextW(fdlg.GetPathName());
		CString c_s = fdlg.GetPathName();
		std::string str(CW2A(c_s.GetString()));
		outputname1 = str;
	}
}


void CamendDlg::OnEnChangeEdit9()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
