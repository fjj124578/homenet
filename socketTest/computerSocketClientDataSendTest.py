import socket

import read_ini
 

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
    

def serialDataSend(dataList):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((SERVER_IP, SERVER_PORT))
    for i in dataList:
        print("{:016b}".format(i))
        binary = i.to_bytes(2,'big')
        print(binary)
        s.send( binary)
        print("{} is sended".format(i))
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
test_list = [83,3450,1700, 450,450, 400,450, 400,1300, 400,1300, 400,450, 450,1250, 450,450, 400,450, 400,450, 450,1200, 450,450, 400,450, 400,1300, 500,350, 450,1250, 500,400, 450,1150, 600,350, 500,350, 500,1100, 600,400, 450,400, 450,400, 450,400, 450,1250, 500,350, 500,1200, 500,350, 500,1200, 500,1200, 500,400, 500,350, 500,350, 500,350, 500,1200, 500,1250, 450,1250, 450,1250, 450,400, 450,400, 500]
test_list2 =[83,3450,1700, 450,450]
test_list3 = [3450]
turn_on_list= [83,3450,1700, 450,450, 400,450, 400,1300, 400,1300, 400,450, 450,1250, 450,450, 400,450, 400,450, 450,1200, 450,450, 400,450, 400,1300, 500,350, 450,1250, 500,400, 450,1150, 600,350, 500,350, 500,1100, 600,400, 450,400, 450,400, 450,400, 450,1250, 500,350, 500,1200, 500,350, 500,1200, 500,1200, 500,400, 500,350, 500,350, 500,350, 500,1200, 500,1250, 450,1250, 450,1250, 450,400, 450,400, 500]
turn_off_list = [83,3450,1700, 400,450, 400,450, 400,1300, 450,1300, 400,400, 450,1300, 400,450, 400,450, 400,450, 400,1300, 450,400, 450,400, 450,1250, 450,400, 450,1300, 450,400, 450,1300, 400,400, 450,400, 450,1300, 400,400, 450,450, 400,450, 400,450, 450,1250, 450,1250, 450,1250, 450,450, 400,1300, 450,1300, 400,400, 450,400, 450,400, 450,1300, 400,1300, 450,1300, 400,1300, 400,1300, 400,450, 400,450, 450]

list_length = len(test_list)
print(list_length)
print(type(list_length))
print("=======================================")

#uint16_t rawData_1[83] = {3450,1700, 450,450, 400,450, 400,1300, 400,1300, 400,450, 450,1250, 450,450, 400,450, 400,450, 450,1200, 450,450, 400,450, 400,1300, 500,350, 450,1250, 500,400, 450,1150, 600,350, 500,350, 500,1100, 600,400, 450,400, 450,400, 450,400, 450,1250, 500,350, 500,1200, 500,350, 500,1200, 500,1200, 500,400, 500,350, 500,350, 500,350, 500,1200, 500,1250, 450,1250, 450,1250, 450,400, 450,400, 500};


serialDataSend(turn_on_list)
#singleDataSend(3000)