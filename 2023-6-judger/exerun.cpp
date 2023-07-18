#include"exerun.h"

//运行单个文件
QStringList MainWindow::run_single_file(QString pth, QString inpdtpth = "", QString outpdtpth = "")
{
	QDir inpdir(inpdtpth), judgedir(outpdtpth);//打开输入文件路径，评测文件路径
	QFileInfoList inplist,tmplist,judgelist;//文件列表
	QFileInfo tmpinfo,inpinfo, judgeinfo;//单个文件信息

	//筛选特定后缀名的文件
	tmplist=inpdir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
	for (int i = 0; i < tmplist.count(); i++)
	{
		tmpinfo=tmplist.at(i);
		if(tmpinfo.suffix()=="in")inplist.append(tmpinfo);
	}//输入文件后缀名".in"

	tmplist=judgedir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
	for (int i = 0; i < tmplist.count(); i++)
	{
		tmpinfo=tmplist.at(i);
		if(tmpinfo.suffix()=="out")judgelist.append(tmpinfo);
	}//评测文件后缀名".out"

	//没有评测数据
    if (judgelist.isEmpty())
    {
        QStringList ret("0/0");
        ret.append("No judge data.");
        return ret;
    }

	//开始评测
	int pts = 0, pts_all = judgelist.count();//通过的数据点个数，总数据点个数
	QStringList runret_single;

	if (inpdtpth.isEmpty() || inplist.isEmpty())//没有输入
	{
		for (int i = 0; i < judgelist.count(); i++)
		{
			judgeinfo = judgelist.at(i);
			pts += (int)(judge_single_data(pth, judgeinfo));
		}
	}
	else//有输入
	{
		for (int i = 0; i < inplist.count(); i++)
		{
			inpinfo = inplist.at(i);
			judgeinfo = judgelist.at(i);
			pts += (int)(judge_single_data(pth, inpinfo, judgeinfo));
		}
	}

	runret_single.append(QString::number(pts) + '/' + QString::number(pts_all));//得分格式"通过的数据点个数/总数据点个数"
	if (pts == pts_all)runret_single.append((QString)("Accepted"));//全部通过
	else runret_single.append((QString)("Wrong Answer"));//没有全部通过
	return runret_single;
}

bool MainWindow::judge_single_data(QString pth, QFileInfo inpinfo, QFileInfo judgeinfo)
{
	QProcess* prc = new QProcess(this);//创建进程
	QFile inpfile, judgefile;//打开文件
	QByteArray inparr, judgearr;//读取文件数据
	QByteArray outparr;//运行结果
	QElapsedTimer prctimer;//计时器

	inpfile.setFileName(inpinfo.absoluteFilePath());//准备打开输入数据
	judgefile.setFileName(judgeinfo.absoluteFilePath());//准备打开评测数据

	if (!inpfile.open(QIODevice::ReadOnly) || !judgefile.open(QIODevice::ReadOnly))return _FILE_OPEN_ERROR;//打开失败

	inparr = inpfile.readAll();//读取输入数据	
	judgearr = judgefile.readAll();//读取评测数据

	prc->start(pth, QStringList(pth));
    prc->waitForStarted(3000);

	prctimer.start();//开始计时

    prc->write(inparr);

	prc->waitForReadyRead(timelimit);
	outparr = prc->readAll();

	prc->terminate();

	if (prctimer.elapsed() >= qint64(timelimit))return _TIME_LIMIT_ERROR;//判断是否TLE

	//比较输出和评测数据
	if (outparr == judgearr)return _ACCEPTED;
	else return _WRONG_ANSWER;

	return _UNKNOWN_ERROR;//未知错误
}

bool MainWindow::judge_single_data(QString pth, QFileInfo judgeinfo)
{
	QProcess* prc = new QProcess(this);//创建进程
	QFile judgefile;//打开评测文件
	QByteArray judgearr;//读取评测文件数据
	QByteArray outparr;//运行结果
	QElapsedTimer prctimer;//计时器

	judgefile.setFileName(judgeinfo.absoluteFilePath());//准备打开评测数据

	if (!judgefile.open(QIODevice::ReadOnly))return _FILE_OPEN_ERROR;//打开失败

	judgearr = judgefile.readAll();//读取评测数据

	prc->start(pth, QStringList(pth));
    prc->waitForStarted(3000);

	prctimer.start();//开始计时

	prc->waitForReadyRead(timelimit);
	outparr = prc->readAll();

	prc->terminate();

	if (prctimer.elapsed() >= qint64(timelimit))return _TIME_LIMIT_ERROR;//判断是否TLE

	//比较输出和评测数据
	if (outparr == judgearr)return _ACCEPTED;
	else return _WRONG_ANSWER;

	return _UNKNOWN_ERROR;
}


QString MainWindow::struced_sample(QString pth, QString inpdata="")
{
	QProcess* prc=new QProcess(this);
	QByteArray outparr;
	QElapsedTimer prctimer;

	prc->start(pth, QStringList(pth));
	prc->waitForStarted(3000);

	prctimer.start();//开始计时

	prc->write(inpdata.toUtf8());

	prc->waitForReadyRead(timelimit);
	outparr = prc->readAll();

	prc->terminate();

	if (prctimer.elapsed() >= qint64(timelimit))return QString("Time Limit Error.");
	return QString(outparr);
}
