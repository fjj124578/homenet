import socket
from unittest import result
import read_ini
import os 

SERVER_IP = "192.168.11.12"    #目標IP
SERVER_PORT = 1235            #目標port


cd = r"C:\Users\14540\Desktop\homenet\socketTest"
#read IR data from txt
read_data_instance = read_ini.read_ini_txt(cd)
turn_on_data = read_data_instance.find_target("TURN_ON")
turn_off_data = read_data_instance.find_target("TURN_OFF")





#print(type(turn_on_data))

def divide_with_comma(string_list):
    tempList = string_list.split(',')
    resultList = []

    for i in tempList:
        x = i.strip(" ")
        x = int(x)
        resultList.append(x)
    return resultList


def singleDataSend(data):
    #data2 = data.to_bytes(4,'big')
    print("{:016b}".format(data))
    binary = data.to_bytes(2,'big')
    print(binary)
    #binary = bin(data)
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((SERVER_IP, SERVER_PORT))
    s.send( binary)
    print("{} is sended".format(data))
    #クライアントとして返信を受ける(受信)
    msg = s.recv(1024)
    print(msg.decode("utf-8"))


def make_it_to_bin(a):
    print(a)
    b= "{:08b}".format(a)
    print(b)
    print(type(b))
    c = int(b,base=2)
    print(c)
    print(type(c))
    return c
#def dataListSend(resultList):

'''
#変数
data  =  31

data = data.to_bytes(2,'big') #intをbyteに変換

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((SERVER_IP, SERVER_PORT))
#クライアントとして送信

s.send(data)
print("sended")
#クライアントとして返信を受ける(受信)
msg = s.recv(1024)
print(msg.decode("utf-8"))
'''
print("=======================================")
'''
resultList = divide_with_comma(turn_off_data)

for i in resultList:
    print(i)
    print(type(i))
'''
#singleDataSend(232234)
#make_it_to_bin(1234)
#singleDataSend(1234)
#binary =format(10,"b")
#print(binary)
#print(type(binary))
#singleDataSend(0)
print("=======================================")


test_list = [0,1,2,5,10,100,200,255,256,300,1000,13333]
for i in test_list:
    singleDataSend(i)
#singleDataSend(3000)