import socket
import read_ini
import time
 


class twoByteSendbySocket:
    def __init__(self,SERVER_IP,SERVER_PORT,cd,fileName):
        
        self.SERVER_IP = SERVER_IP
        self.SERVER_PORT = SERVER_PORT
        self.dataPath = cd
        self.fileName = fileName

        read_data_instance = read_ini.read_ini_txt(self.dataPath,self.fileName)
        self.turn_on_data = self.append_len(self.divide_with_comma(read_data_instance.find_target("TURN_ON")))
        #self.turn_on_data = temp_turn_on_data.insert(0,22)
        self.turn_off_data = self.append_len(self.divide_with_comma(read_data_instance.find_target("TURN_OFF")))
        self.AC_JYOSHITSU = self.append_len(self.divide_with_comma(read_data_instance.find_target("AC_JYOSHITSU")))
        self.AC_STOP = self.append_len(self.divide_with_comma(read_data_instance.find_target("AC_STOP")))
        self.AC_COLD = self.append_len(self.divide_with_comma(read_data_instance.find_target("AC_COLD")))






    #print(type(turn_on_data))
    def append_len(self,listArg):
        tempList = []
        length = len(listArg)
        tempList.append(length)
        for i in listArg:
            tempList.append(i)
        return tempList

    def divide_with_comma(self,string_list):
        tempList = string_list.split(',')
        resultList = []

        for i in tempList:
            x = i.strip(" ")
            x = int(x)
            resultList.append(x)
        return resultList

    #only for test and deve
    def singleDataSend(self,data):
        #data2 = data.to_bytes(4,'big')
        print("{:016b}".format(data))
        binary = data.to_bytes(2,'big')
        print(binary)
        #binary = bin(data)
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((self.SERVER_IP, self.SERVER_PORT))
        s.send( binary)
        print("{} is sended".format(data))
        #クライアントとして返信を受ける(受信)
        

    def serialDataSend(self,dataList):
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.connect((self.SERVER_IP, self.SERVER_PORT))
        for i in dataList:
            print("{:016b}".format(i))
            binary = i.to_bytes(2,'big')
            print(binary)
            s.send( binary)
            print("{} is sended".format(i))
            msg = s.recv(1024)
            print(msg.decode("utf-8"))
            #time.sleep(0.02)
        
    



    def make_it_to_bin(self,a):
        print(a)
        b= "{:08b}".format(a)
        print(b)
        print(type(b))
        c = int(b,base=2)
        print(c)
        print(type(c))
        return c



if __name__ == "__main__":
    SERVER_IP = "192.168.11.17"    #目標IP
    SERVER_PORT = 1235            #目標port
    cd = r"C:\Users\14540\Desktop\homenet\socketDataTrans"
    fileName = "rawDataTest.txt"
    test_a = twoByteSendbySocket(SERVER_IP,SERVER_PORT,cd,fileName)
    #print(test_a.turn_on_data)
    #print(test_a.AC_JYOSHITSU)
    #test_a.serialDataSend(test_a.turn_on_data)
    test_a.serialDataSend(test_a.AC_JYOSHITSU)


