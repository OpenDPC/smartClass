
// amendDlg.h: 头文件
//

#pragma once


// CamendDlg 对话框
class CamendDlg : public CDialogEx
{
// 构造
public:
	CamendDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AMEND_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
       public:
        CStatic my_picture;
        afx_msg void OnBnClickedOk();
        afx_msg void OnBnClickedButton1();
        CEdit jpg_name;
        /*CEdit edit_code;*/
        afx_msg void OnBnClickedButtonSave();
		afx_msg void OnBnClickedButton5();
		afx_msg void OnBnClickedButton6();
		afx_msg void OnBnClickedButton7();
		afx_msg void OnBnClickedButton3();
		afx_msg void OnEnChangeEditCode();
		afx_msg void OnEnChangeEditStatus();
		afx_msg void OnBnClickedButton2();
		afx_msg void OnEnChangeEdit2();
		afx_msg void OnEnChangeEdit1();
		/*afx_msg void OnStnClickedStaticPic();*/
		afx_msg void OnBnClickeddakai2();
		CEdit input_name01;
		/*CEdit input_name01;*/
		/*CEdit input_name01;*/
		CEdit input_name02;
		CEdit input_name03;
		CEdit input_name04;
		CEdit input_name05;
		afx_msg void OnBnClickedButton4();
		afx_msg void OnBnClickedButton8();
		afx_msg void OnBnClickedButton9();
		afx_msg void OnEnChangeEdit5();
		afx_msg void OnEnChangeEdit6();
		afx_msg void OnBnClickedButton11();
		CEdit inputname05;
		CEdit inputname06;
		CEdit inputname07;
		CEdit inputname08;
		afx_msg void OnBnClickedButton10();
		afx_msg void OnEnChangeEdit8();
		afx_msg void OnBnClickedButton13();
		afx_msg void OnBnClickedButton12();
		afx_msg void OnEnChangeEdit9();
};
