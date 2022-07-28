import socket


SERVER_IP = "192.168.11.12"    #目標IP
SERVER_PORT = 1235            #目標port

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
