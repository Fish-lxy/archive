
import re
import os
import os.path
import time
import shutil
# -*- coding:utf-8 -*-
#str.split(string)分割字符串
#'连接符'.join(list) 将列表组成字符串


def change_name(path):
    global i
    if not os.path.isdir(path) and not os.path.isfile(path):
        return False
    if os.path.isfile(path):
        file_path = os.path.split(path)  # 分割出目录与文件
        # 分割出文件与文件扩展名  lists[0]:name,lists[1]:ext
        lists = file_path[1].split('.')
        #lists_2 = file_path[0].split("\\")  # lists_2[-2]:父目录名
        file_ext = lists[-1]  # 取出后缀名(列表切片操作)
        if file_ext in tol_ext:
            newfile = Tar + "\\" + file_path[-1]
            # newfile = Tar+"\\"+lists_2[-1]+'_'+file_path[-1]
            # newfile = Tar+"\\"+lists_2[-1]+str(lists[0:-1])+"."+file_ext
            shutil.copy(path, newfile)
            print("复制文件："+str(path)+" 到："+newfile+"  Successfully！")
            i += 1
    elif os.path.isdir(path):
        for x in os.listdir(path):
            change_name(os.path.join(path, x))


Tar = input("请输入目标路径（不存在将自动创建）：")
if not os.path.exists(Tar):
    os.mkdir(Tar)
File_dir = input("请输入待复制目录路径：")
while not os.path.exists(File_dir):
    print("找不到该目录，请检查路径后后重新输入！！！")
    File_dir = input("请输入原文件夹")
if (Tar == File_dir):
    print("目标路径与源路径相同，无需移动！")
else:
    print("请输入要整理的文件后缀名(例如：hello.cpp，后缀为cpp)，以空格分隔：")
    string_get = input()
    print("\n")
    tol_ext = string_get.split(" ")
    #File_dir = File_dir.replace('\\', '/')

    start = time.time()
    i = 0
    change_name(File_dir)
    c = time.time() - start
    if(i == 0):
        print("本次运行没有复制文件！")
    else:
        print("程序运行耗时:%0.2f 秒" % (c))
        print("总共处理了 %s 个文件" % (i))
bye = input("输入任意键退出")


