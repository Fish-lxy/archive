# @Time     ：2020.8.31
# @Author   ：王盛
# @FileName ：app.py
# @Software ：pycharm
# @Blog     ：https://blog.csdn.net/kcyxws

from flask import Flask, render_template
from flask import request
import pymysql
# from flask_script import Server
# server = Server(host="47.94.217.220",threaded=True)

app = Flask(__name__)


@app.route('/', methods=['GET', 'POST'])
def hello_world():
    if request.method == "POST":
        stu_name = request.form.get('stu_name')
        stu_id = request.form.get('stu_id')
        print(stu_id,stu_name)
        data = search(stu_name, stu_id)
        return data
    return render_template('index.html')


def search(stu_name, stu_id):
    '''源码公开 我的服务器以及数据库的ip 管理员密码等不公开了'''
    host = 'mysql地址'
    user = 'mysql管理员用户名'
    password = 'mysql管理员密码'
    database = 'mysql数据库'
    port = '端口'
    con = pymysql.connect(host=host, user=user, password=password, database=database, port=port)
    cur = con.cursor()
    data_list = []
    tables_name = ['temp8_18', 'temp8_19', 'temp8_20', 'temp8_21', 'temp8_22', 'temp8_23', 'temp8_24', 'temp8_25', 'temp8_26', 'temp8_27', 'temp8_28', 'temp8_29', 'temp8_30']
    for i in tables_name:
        sql = 'select class,name,id,time,temperature from %s where name="%s" and id="%s" ' % (i, stu_name, stu_id)
        cur.execute(sql)
        data = cur.fetchone()
        data_list.append(data)
    if data is None:
        rec_post = '''
        <!DOCTYPE html>
<html>
<head>
	<title>19计科到梦空间打卡体温查询</title>
	<meta name="viewport" content="width=device-width,height=device-height,inital-scale=1.0,maximum-scale=1.0,user-scalable=no;">
	<meta name="apple-mobile-web-app-capable" content="yes">
	<meta name="apple-mobile-web-app-status-bar-style" content="black">
	<meta name="format-detection" content="telephone=no">
	<link rel="stylesheet" type="text/css" href="../static/css/login.css">
    <link rel="icon" href="../static/images/favicon.ico" type="image/x-icon" />
    <link rel="shortcut icon" href="../static/images/favicon.ico" type="image/x-icon" />
</head>
<body>
<body background="../static/images/5.jpg">
<div class="content">
	<div class="contain">
    <p style="font-size:30px;color:white">输入信息有误，或您不是19级计科学生。</p>
	</div>
    </div>
</body>
        '''
    else:
        rec_post = '''<!DOCTYPE html>
    <html lang="en">
    <head>
        <title>19计科到梦空间打卡体温查询</title>
        <meta name="viewport" content="width=device-width,height=device-height,inital-scale=1.0,maximum-scale=1.0,user-scalable=no;">
        <meta name="apple-mobile-web-app-capable" content="yes">
        <meta name="apple-mobile-web-app-status-bar-style" content="black">
        <meta name="format-detection" content="telephone=no">
        <link rel="stylesheet" type="text/css" href="../static/css/login.css">
        <link rel="icon" href="../static/images/favicon.ico" type="image/x-icon" />
        <link rel="shortcut icon" href="../static/images/favicon.ico" type="image/x-icon" />
    </head>
    <body>
    <body background="../static/images/5.jpg">
    <body text="white">
    <table border="1" align="center">
        <tr>
            <th width="20%">班级</th>
            <th width="20%">姓名</th>
            <th width="20%">学号</th>
            <th width="20%">日期</th>
            <th width="20%">体温</th>
        </tr>
        '''
        for i in data_list:
            rec_post += '<tr>'
            for j in i:
                temp = '<td align="center">' + j + '</td>'
                rec_post += temp
            rec_post += '</tr>'
        rec_post += '''
    </table>
    </body>
    </html>
    '''
    return rec_post
    cur.close()
    con.close()

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=8080,threaded=True)


