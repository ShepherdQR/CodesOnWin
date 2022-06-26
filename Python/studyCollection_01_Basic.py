

a=0
def f():
    global a
    b=1
    c = 2
    a = b+c
'''
var a=0
def f():
    #global a
    var b=1
    var c = 2
    a = b+c
'''



def main():
    print("Hi")
    #basic_04_list()
    

def basic_01_variable():
    Thing = ' plays guitar'
    Name = 'Taylor Swift'
    print((Name + Thing + '\n') * 3)

    num = 1
    string = '1'
    B = 1 * (len('love') - len(string) * 3)
    print(num + int(string) + B)

    a='Where is Einstein'
    print(a[0]+a[-2]+a[-4]+a[-4:-3]+a[-1]+a[1]*2)

    A='Witten';B='Einstein';C='en';D='ein'
    print(A.replace(A[:3],'*'*2))
    print(str(A.find(C))+' to '+str(int(str(A.find(C)))+len(C)-1))
    print(str(B.find(D))+' to '+str(int(str(B.find(D)))+len(D)-1))

    print('{} love {}.'.format('I','you'))
    print('{preposition} love {nn}.'.format(preposition='I',nn = 'you'))
    print('{0} love {1}.'.format('I','you'))

    print(0b1111)  ##直接输出的是10进制的表示
    print("Let's go.", 'Let\s go')
    print('''hello\n world
    hello world''')
    print('hello \
          world')
    print('c:\daoh\\noudga\\nuyeowyht\\uuio')
    print(r'c:\daoh\noudga\nuyeowyht\uuio')  # 原始字符串

    print(3//2)  ##整除
    """#####20190318练习
    0bxx 表示二进制，bin
    0o 8进制，oct
    10进制，int
    0x 16进制，hex

    bool(199)=True,
    bool([])=False
    bool(None)=False

    """
    a = ['love', 45, True]  # True>False  # abs(-6)> len('hoo')
    a.append('firend');
    print('love' in a, ',', a, ',', a[-1])

    print([bool(0), bool([]), bool(''), bool(None), bool(False)])
    # and or not


def basic_04_list():
    ####list
    List = [1, 2, 3, 4, 'haha']
    List[2] = 30
    del List[1]
    print('list', List, List[-4], List[2:])
    print(4 in List)
    List2 = [1, 2, 3, 4, 5, 1]
    print(max(List2), min(List2), len(List2), List2.append('add'), List2, '\n',
          List2.count(1))
    print(List2, List2.pop())

def basic_02_file_save():
    file = open('E:/1.txt','w')
    file.write('hello world1')

    file = open('E:\9.txt','w');file.write('Hello World')
    file = open('E:/8.txt','w');file.write('Hello World')
    file = open('E://7.txt','w');file.write('Hello World')


def basic_03_loops():
    for every_letter in 'PERCEPTION':
        print(every_letter)

    for num in range(1,11):
        print(str(num),'+1=',num+1)

    list=['aa','bb','cc']
    for name in list:
        if name=='aa':print(name,'-a')
        if name == 'bb': print(name, '-b')
        if name == 'cc': print(name, '-c')

    for i in range(1,10):
        for j in range(1,i+1):
            if i*j<10:
               print('{},{},得{}'.format(j,i,i*j))
            else:
               print('{},{},{}'.format(j, i, i * j))

    i=1
    while True:
        print('Nonstop',i)
        i=i+1
        if i==6:
            break













# #Creat blank txt files
# def ten(name,number,con):
#     number=number+1
#     for i in range(1,number):
#         add='E:/'+name+str(i)+'.txt'
#         file=open(add,'w')
#         file.write(con)
#         file.close()
#     print('Finished');
# ###
# ten('love',3,'')

# def invest(amount,rate,year):
#     for i in range(1,year+1):
#         z=amount*((1+rate)**i)
#         print('year ',i,': $',z)
#     print('Finished')
#
# invest(100,1,5)

# i=2
# while i<=100:
#     print(i)
#     i=i+2
# # else:print('Finished')



#
# import tensorflow as tf
# hello = tf.constant('Hello, TensorFlow!')
# sess = tf.Session()
# print(sess.run(hello))
# a=tf.constant(10)
# b=tf.constant(32)
# print(sess.run(a+b))
# import numpy as np
# import matplotlib.pyplot as plt
# from scipy.spatial import Voronoi, voronoi_plot_2d
#
# # make up data points
# points = np.random.rand(15,2)
#
# # compute Voronoi tesselation
# vor = Voronoi(points)
#
# # plot
# voronoi_plot_2d(vor)
#
# # colorize
# for region in vor.regions:
#     if not -1 in region:
#         polygon = [vor.vertices[i] for i in region]
#         plt.fill(*zip(*polygon))
#
# plt.show()


# ###basic-practice-20181107
# c=[1,2,3,4,5,6,7]
# c0=c[2::1]
# c1=c[5:0:-1]##不取0号元素
# c11=c[5::-1]
# c2=c[-3::-2]
# print(c,c0,c1,c11,c2)
"""
f=(1,2,3) 元组，是誓言，定义好不能更改
字典dic={键：键值   }
.py 文件是模块，需要import后使用
包：含多个模块
_foo: 以单下划线开头的表示是 protected 类型的变量，
即保护只能 允许其本身与子类进行访问，不能用于 from module import *
__foo: 双下划线的表示是私有类型 (private) 的变量 ,
只能是允许这个类 本身进行访问了。
tensorf里面 变量 括号的个数是张量的阶数
"""
# dic={1:"123","name":"zs","height":180,78:"dd"}
# dic[1]="444"
# del dic[78]
# dic[87]=87
# print(dic)

# age=input("Your age\n")
# age=int(age)
# if age>50:
#     print("Old")
# elif  age> 18 and age<=50:
#     print("Adult")
# else:
#     print("Child")

# for i in range(0,4):
#     print("Hello %s " %i)

# h=["a","b","c","d"]
# for i in h:
#     print(i)
#     for j in h:
#         print(j)
# i=3;j=4
# while i<5 and j>0 :
#     i=i+1
#     j=j-1
#     print(i,j)
# import turtle
# t=turtle.Pen()
# for i in range(0,4):
#     t.forward(100)
#     t.left(90)
# t.reset()
# i=0
# while True:
#     t.forward(100)
#     t.right(90)
#     i=i+1
#     if i==4:
#         break
# def hi_name(name):
#     print("hello %s" %name)
# hi_name("tt")
# def add11(a,b):
#     return a+b+11
# print(add11(1,9))
# class Animals():
#     def breathe(self):
#         print("They breathe")
#     def move(self):
#         print("They move")
#     def eat(self):
#         print("They eat food")
# class Nammals(Animals):
#     def brestfeed(self):
#         print("They feed young")
# class Cats(Nammals):
#     def __init__(self,spots):
#         self.spots=spots
#     def catch_mouse(self):
#         print("They catch mouse")
#     def foot_forward(self):
#         print("aa")
#     def dance(self):
#         self.foot_forward()
#         self.foot_forward()
# kitty=Cats(10)
# print(kitty.spots)
# kitty.dance()
# kitty.move()
import pickle
# money_data={"position":"N2 E3","pocket":["key","knife"],"money":160}
# save_file=open("money.txt","wb")
# pickle.dump(money_data,save_file)
# save_file.close()
# load_file=open("money.txt","rb")
# load_money_data=pickle.load(load_file)
# load_file.close()
# print(load_money_data)
# exit()



####---studying 20181224
"""
import os
print(os.getcwd())

import requests
r=requests.get("http://www.baidu.com")
print(r.url)
print(r.encoding)
print(r.text)

print('name')
print("ttt")
print('''faf
dfaf
daf''')


Name='Tom'
Age=16
print('{0} is {1} years old'.format(Name,Age))
print(Name +' is ' + str(Age) +' yests old.')


# numeric type:int, float, complex( z.real,   z.imag)
a=3;b=4
c=complex(a,b)#复数
d=complex(float(a),float(b))
print(c,d,'\n',type(c),type(d),
b/3,b//3,'\n',a+c)#3个除号，约简成整形

import sys
print(sys.float_info)






###-----tuple,不能更改
###--不能append或者extend，不能remove或pop
###--速度比list快，作为只读的常量表。转化为list再修改
###---可以一次赋多值
Tuple_1=(2,)
Tuple=(1,2,['a','4'])
print(Tuple_1,Tuple)
Tuple[2][0]=3
print(Tuple, 2 in Tuple)
print( (1,2)+(3,4),(6,'hello')*4)


###--dictionary
Dictionary={'book':1,('name,','height'):6,'book':9}
Dictionary['paper']=10
del Dictionary['paper']
# Dictionary.clear()
print(Dictionary)



def rep(str,times=1):
    repp=str*times
    return repp
print(rep('hi',4))

def rep(str , *a,   times=1 , **aa ):
    print(str*times,'\n',a,'\n',aa)

rep('ik',6,1,2,3,4,5,n='45',hi=3)


####-----猜数字游戏，while版本
num=59
flag=0
while flag==0:
    guess=int(input('Enter:'))
    if guess==num:
        print('Yes it is',num,'\nDone')
        flag=1
    elif guess< num:
        print('Try a bigger one')
    else:
        print('Try a smaller one')


for i in range(4):
    print(i+2,[9,10,11,12,14][i+1])
a={'book': 1, ('name,', 'height'): 6, 'book': 9}
for i in a: print(i,a[i] )
for i,j in a.items(): print(i,j)



for i in range(4):
    if not i:
        continue
    elif i is  2:
        continue
    elif i is 3:
        pass
    print(i)



#---存文件
poem='''So long as men can breathe,
or eyes can see,
so long lives this,
and this gives life to thee'''
f =open('E://poem.txt','w')
f.write(poem)
f.close()

#---读文件
f =open('E://poem.txt' )
line=f.readline()
while line:
    print(line,end='')
    line=f.readline()
f.close()


# ###---异常时的分类报错
# while True:
#     try:
#         get=int(input('Give me a number:'))
#         break
#     except ValueError:
#         print('Me wanna a number:')


# try:
#     f=open('E://poem.txt' )
#     line=f.readline()
#     i=int(line.strip())
# except OSError as err:
#     print('os error:'.format(err))
# except ValueError:
#     print('No data')

###--在函数中要使用、对全局变量如x，需引用格式为 global x

###---类
class students:
    def __init__(self,name,points):
        self.name=name
        self.points=points
    def intrd(self):
        print(self.name,self.points)
    def imp(self,amount):
        self.points=self.points+amount
jim=students('jim',86)
jim.intrd()
jim.imp(10)
jim.intrd()




"""

# ###---装饰函数 函数之间的引用
# def candles(cake_in ):
#     def insert():
#         return cake_in + ' candles'
#     return insert
# def cake():
#      return 'cake'
# print(candles (cake())()  )
# cake=candles (cake())
# print(cake())
# @candles
# def cake1():
#     return 'cake'
# print(cake())



###---窗口化显示的猜数字小游戏
# from tkinter import *
# import tkinter.simpledialog as dl
# import tkinter.messagebox as mb
#
# myWindow=Tk()#主函数显示框
# w=Label(myWindow,text='Guess Number Game')
# # w.pack()#自动调节标签大小适应标签的文字
# width=300;height=200
# screenwidth = myWindow.winfo_screenwidth()
# screenheight = myWindow.winfo_screenheight()
# alignstr = '%dx%d+%d+%d' % (width, height, (screenwidth-width)/2, (screenheight-height)/2)
# myWindow.geometry(alignstr)
#
# mb.showinfo("welcome",'Welcome to the game')
#
# num=59
# times=4
# while times>1:
#     guess= dl.askinteger('Num', 'Your guess')
#     if guess==num:
#         times = 0
#         output1='Yes it is '+str(num)+'\nDone'
#         mb.showinfo('Good one', output1)
#     elif guess< num:
#         times = times - 1
#         output2='Try a bigger one, '+ str(times-1)+' times left.'
#         mb.showinfo('Try again', output2)
#         continue#直接进入下次循环
#     else:
#         times = times - 1
#         output3 = 'Try a smaller one, ' +str(times-1 )+ ' times left.'
#         mb.showinfo('Try again', output3)


# a=b=c=1; print(a,b,c)
# s='ababab';print(s[1:3],a is b , id(a)==id(b))


"""
total = item_one + \
        item_two + \
        item_three

#帮助
help(sys.stdout.write)

#位运算符
a = 60            # 60 = 0011 1100 
b = 13            # 13 = 0000 1101 
c = 0

c = a & b;        # 12 = 0000 1100
print "Line 1 - Value of c is ", c

c = a | b;        # 61 = 0011 1101 
print "Line 2 - Value of c is ", c

c = a ^ b;        # 49 = 0011 0001
print "Line 3 - Value of c is ", c

c = ~a;           # -61 = 1100 0011
print "Line 4 - Value of c is ", c

c = a << 2;       # 240 = 1111 0000
print "Line 5 - Value of c is ", c

c = a >> 2;       # 15 = 0000 1111
print "Line 6 - Value of c is ", c
"""

# #---输出小于给定n的奇数
# count = 1;n=10
# while (count < n):
#     count += 1
#     if count%2>0:
#         continue
#     print ('The count is:', count-1 )


# flag = 1
# while (flag): print ('Given flag is really true!');flag=0;
# else:print('It is false.')
# print ("Good bye!")

# for i in 'Python':
#     print(i)
# for i in range(len('python')):
#     print('abckue'[i]  )


# ##_--a-b之间的数因式分解
# num_min=10
# num_max=20
# for num in range(num_min,num_max+1):
#     factor=[ ]
#     ii=0
#     for j in range(2,num):
#         if num%j==0:
#             ii+=1
#             factor.insert(ii,num/j)
#     if factor:
#         print(num, ' has factors as:', factor)
#     else:
#         print(num, ' is a prime' )

# ####---小于n_num的质数
# n_max=10
# num = 2
# while(num <n_max):
#    j = 2
#    while(j <= (num/j)):
#       if not(num%j): #没有余数，即整除的时候
#          print('fdsaf');break
#       j = j + 1
#    if (j > num/j) : print (num, " 是素数")
#    num +=1

#continue 和 pass
# var = 10                    # 第二个实例
# while var > 0:
#    var = var -1
#    if var == 5:
#       continue#跳过本次循环，所以5没有打印出来
#    if var==8:
#       pass#保证结构，看起来没有作用
#       print('place')
#    print ('当前变量值 :', var)
# print ("Good bye!")




# print ("My name is %s and weight is %d kg!" % ('Zara', 21))
#
# #时间与日期
# import time;  # This is required to include time module.
#
# ticks = time.time()
# print ("Number of ticks since 12:00am, January 1, 1970:", ticks)
#
# localtime = time.localtime(time.time())
# print ("Local current time :", localtime)
#
# localtime = time.asctime( time.localtime(time.time()) )
# print ("Local current time :", localtime)
#
# import calendar
#
# cal = calendar.month(2008, 1)
# print ("Here is the calendar:")
# print (cal )


if __name__=='__main__':
    main()

