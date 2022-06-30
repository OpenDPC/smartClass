#!/bin/zsh
#创建 temp 文件夹 并在 文件夹内解压文件
mkdir temp
unzip  target.zip -d ./temp
cd ./temp/
rm -rf __MACOSX 
rm -rf .DS_Store
# 执行 cpl 脚本  进行多文件的编译的准备
python3 cpl.py 

#获取 g++指令
num=0
array_me=(name count gcc_commond)
for line in 'gcc.txt'
    ${array_me[$num]}=$line
    num++


#执行 g++ 指令
${array_me[0]} 

if [ -f "a.out" ];then
	./a.out > out.txt # 编译结果放在 out 文件中
fi

# 和答案进行对比

g++ judge.cpp -o b.out






# 执行 xlsx 脚本  进行成绩的录入
pyhton3 xlsx.py



#删除编译的文件
rm -rf temp a.out b.out gcc_commond.txt grade1.txt
