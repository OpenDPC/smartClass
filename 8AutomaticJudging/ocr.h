#include <iostream>
#include <string>
#include "C:\Users\14418\Desktop\aip-cpp-sdk-4.15.8\ocr.h"//OCR
#include  <json\json.h>
#include <curl\curl.h>
#include<fstream>
using namespace std;
//#define DEBUG
char m[] = "E:\\vs\\code\\OCR_1\\test0.cpp";
std::string app_id = "26213509";
std::string api_key = "bxKwGrARcSZ6vvPY8G3G1Eyr";
std::string secret_key = "1oIEkGk9VkYunDxjWWsyS4x8wnXD21g1";
aip::Ocr client(app_id, api_key, secret_key);
const char* cpp_name1 = "E:\\vs\\community\\VC\\Tools\\MSVC\\14.31.31103\\bin\\Hostx86\\x64\\cl.exe /EHsc E:\\vs\\code\\OCR_1\\test0.cpp";
const char* exe_name1 = "C:\\Users\\14418\\Desktop\\amend\\amend\\test0.exe";
//const char* input_name1 = "E:\\vs\\code\\OCR_1\\test0.input";
const char* output_name1 = "E:\\vs\\code\\OCR_1\\test0.output";
//const char* correct_name1 = "E:\\vs\\code\\OCR_1\\test0.correct";
//const char* input_name2 = "E:\\vs\\code\\OCR_1\\test1.input";
const char* output_name2 = "E:\\vs\\code\\OCR_1\\test1.output";
//const char* correct_name2 = "E:\\vs\\code\\OCR_1\\test1.correct";
void write_txt(std::string sss)
{
	std::string write_file_name = m;
	ofstream os;
	os.open(write_file_name, ios::app);
	os << sss + '\n';
	os.close();
}
void OCR(string filename,string txt_name)
{
	std::string jsonStr;
	Json::StreamWriterBuilder writerBuilder;
	std::ostringstream os;
	writerBuilder.settings_["indentation"] = "\t";
	Json::Value result;
	std::string image;
	const char* p = filename.data();
	aip::get_file_content(p, &image);
	std::map<std::string, std::string> options;
	options["language_type"] = "CHN_ENG";
	options["detect_direction"] = "true";
	options["detect_language"] = "true";
	options["probability"] = "true";

	// 带参数调用通用文字识别, 图片参数为本地图片
	result = client.general_basic(image, options);
	std::unique_ptr<Json::StreamWriter> jsonWriter(writerBuilder.newStreamWriter());
	jsonWriter->write(result, &os);
	jsonStr = os.str();
	std::string write_file_name = txt_name;
	ofstream pp;
	pp.open(write_file_name, ios::in);
	for (auto item : result["words_result"])
	{
		cout << item["words"].asString() << endl;
		pp << item["words"].asString() << endl;
	}
	pp.close();
}
void Write_Cpp(const char* cpp_name, const char* exe_name, const char* input_name, const char* output_name)
{
	/*system("E:\\vs\\community\\Common7\\Tools\\VsDevCmd.bat");*/
	system(cpp_name);
	string exe_file(exe_name);
	string input_file(input_name);
	string output_file(output_name);
	string command = exe_file + " < " + input_file + " > " + output_file;
	system(command.c_str());
}
void Solve(string Cppname,string cppname)
{
	string tmp; int u = 0;
	std::ifstream cpp_file(Cppname, std::ifstream::in);
	std::string write_file_name = cppname;
	ofstream pp;
	pp.open(write_file_name, ios::in);
	while (getline(cpp_file, tmp))
	{
		u++;
		if (u == 4) { tmp.erase(0, 3); }
		if (u == 7) { tmp.insert(46, "}"); }
		if (u == 12) { tmp.insert(13, ":"); }
		if (u == 13) { tmp.erase(0, 1); tmp.insert(0, "{"); }
		if (u == 19) { tmp.insert(16, ":"); tmp.insert(38, "{"); }
		if (u == 20) { tmp.erase(42, 1); tmp.insert(42, "}"); }
		if (u == 21) { tmp.insert(37, "{"); tmp.insert(16, ":"); }
		if (u == 22) { tmp.insert(42, "}"); }
		if (u == 24) { tmp.erase(0, 2); tmp.insert(0, "{"); }
		if (u == 28) { tmp.insert(15, ";"); tmp.insert(31, ";"); }
		cout << tmp << endl;
		pp << tmp << endl;
	}
}
void Check_Answer(string CorrectFilename, string OutputFilename,string& score)//对答案函数
{
	string tmp;

	//参考答案
	std::ifstream correct_file(CorrectFilename,
		std::ifstream::in);
	vector<string> vec_correct_str;
	while (getline(correct_file, tmp)) {
		if (!tmp.empty()) vec_correct_str.push_back(tmp);  //tmp为空就说明这一行是空行
	}

	//考生答案
	std::ifstream output_file(OutputFilename,
		std::ifstream::in);
	vector<string> vec_output_str;
	while (getline(output_file, tmp)) {
		if (!tmp.empty()) vec_output_str.push_back(tmp);   //tmp为空就说明这一行是空行
	}

	if (vec_correct_str.size() != vec_output_str.size()) {
		cout << "此测试用例不通过" << endl;
		score = "此测试用例不通过";
	}
	else {
		size_t i = 0;
		for (; i < vec_correct_str.size(); i++) {
			if (vec_correct_str[i] != vec_output_str[i]) {
				cout << "此测试用例不通过" << endl;
				score = "此测试用例不通过";
				break;
			}
		}
		if (i >= vec_correct_str.size()) {
			cout << "此测试用例通过" << endl;
			score = "此测试用例通过";
		}
	}
}