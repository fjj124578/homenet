import tkinter as tk
import socket

#AUDIO　SWITCHサーバー情報
AUDIO_SERVER_IP = "192.168.11.9"    #目標IP
AUDIO_SERVER_PORT = 1235            #目標port


#GUIの設定
window = tk.Tk()
window.title("机上総合照明コントロールパネル")
window.geometry("300x500+10+10")
frame_1 = tk.Frame(window,height=500,width=300,borderwidth=5,relief="ridge")
frame_1.grid()
image_flag =tk.PhotoImage(file="shit2_gaitubao_256x128.png")




def audio():
	try:
		#変数
		data  =  0   # 詳細はdata設計資料に参照

		data = data.to_bytes(1,'big') #intをbyteに変換

		s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		s.connect((AUDIO_SERVER_IP, AUDIO_SERVER_PORT))
		#クライアントとして送信

		s.send(data)
		print("sended")
		#クライアントとして返信を受ける(受信)
		msg = s.recv(1024)
		print(msg.decode("utf-8"))
	except:
		print("audio switchには何か変")









#label
l1=tk.Label(frame_1,text="キーボード")
l1.place(relx=0.02,rely=0.02)
l2=tk.Label(frame_1,text="中央")
l2.place(relx=0.2,rely=0.02)
l3=tk.Label(frame_1,text="真上")
l3.place(relx=0.38,rely=0.02)
l4=tk.Label(frame_1,text="なし")
l4.place(relx=0.56,rely=0.02)
l4=tk.Label(frame_1,text="一括")
l4.place(relx=0.74,rely=0.02)
label_flag = tk.Label(frame_1,image = image_flag)
label_flag.place(relx=0.05,rely=0.73)

#label of panasonic_1
l5=tk.Label(frame_1,text="Panasonic light一番")
l5.place(relx=0.02,rely=0.25)

#label of panasonic_2
l6=tk.Label(frame_1,text="Panasonic light二番")
l6.place(relx=0.02,rely=0.5)
#label of harman
l7=tk.Label(frame_1,text="音響")
l7.place(relx=0.78,rely=0.25)
'''
#bottons of desk
button1_0 = tk.Button(frame_1,text="一号開",width=6,height=2,command=num_1_on)
button1_0.place(relx=0.02,rely=0.06)
button1_1=tk.Button(frame_1,text="一号閉",width=6,height=2,command=num_1_off)
button1_1.place(relx=0.02,rely=0.15)
button2_0 = tk.Button(frame_1,text="二号開",width=6,height=2,command=num_2_on)
button2_0.place(relx=0.2,rely=0.06) 
button2_1=tk.Button(frame_1,text="二号閉",width=6,height=2,command=num_2_off)
button2_1.place(relx=0.2,rely=0.15)
button3_0 = tk.Button(frame_1,text="三号開",width=6,height=2,command=num_3_on)
button3_0.place(relx=0.38,rely=0.06) 
button3_1=tk.Button(frame_1,text="三号閉",width=6,height=2,command=num_3_off)
button3_1.place(relx=0.38,rely=0.15)
button4_0 = tk.Button(frame_1,text="四号開",width=6,height=2,command=num_4_on)
button4_0.place(relx=0.56,rely=0.06) 
button4_1=tk.Button(frame_1,text="四号閉",width=6,height=2,command=num_4_off)
button4_1.place(relx=0.56,rely=0.15)
button_sum_0 =tk.Button(frame_1,text="一括開",width=6,height=2,command=all_on)
button_sum_0.place(relx=0.74 ,rely=0.06)
button_sum_1 =tk.Button(frame_1,text="一括閉",width=6,height=2,command=all_off)
button_sum_1.place(relx=0.74,rely=0.15)

#bottons of panasonic_1
button5_1_0 = tk.Button(frame_1,text="点灯",width=6,height=5,command=num_5_on)
button5_1_0.place(relx=0.02,rely=0.3)

button5_1_1 = tk.Button(frame_1,text="消灯",width=6,height=5,command=num_5_off)
button5_1_1.place(relx=0.20,rely=0.3)

button5_2_0 = tk.Button(frame_1,text="白い色",width=6,height=2,command=num_5_white)
button5_2_0.place(relx=0.38,rely=0.3)

button5_2_1 = tk.Button(frame_1,text="暖かい色",width=6,height=2,command=num_5_warm)
button5_2_1.place(relx=0.38,rely=0.392)

button5_3_0 = tk.Button(frame_1,text="明るい",width=6,height=2,command=num_5_bright)
button5_3_0.place(relx=0.56,rely=0.3)

button5_3_1 = tk.Button(frame_1,text="暗い",width=6,height=2,command=num_5_dark)
button5_3_1.place(relx=0.56,rely=0.392)

#buttons of panasonic_2
button6_1_0 = tk.Button(frame_1,text="点灯2",width=6,height=5,command=num_6_on)
button6_1_0.place(relx=0.02,rely=0.55)

button6_1_1 = tk.Button(frame_1,text="消灯2",width=6,height=5,command=num_6_off)
button6_1_1.place(relx=0.2,rely=0.55)
 
button6_2_0 = tk.Button(frame_1,text="白い色２",width=6,height=2,command=num_6_white)
button6_2_0.place(relx=0.38,rely=0.55)

button6_2_1 =tk.Button(frame_1,text="暖かい色\n2",width=6,height=2,command=num_6_warm)
button6_2_1.place(relx=0.38,rely=0.642)

button6_3_0 = tk.Button(frame_1,text="明るい２",width=6,height=2,command=num_6_bright)
button6_3_0.place(relx=0.56,rely=0.55)

button6_3_1 = tk.Button(frame_1,text="暗い２",width=6,height=2,command=num_6_dark)
button6_3_1.place(relx=0.56,rely=0.642)

button_close_everything = tk.Button(frame_1,text="暗黒降臨",width=15,height=3,command=all)
#button_close_everything.place(relx=0.2,rely=0.8)
'''
button_audio=tk.Button(frame_1,text="音響 \n on/off",width=6,height=5,command=audio)
button_audio.place(relx=0.74,rely=0.3)

'''
button_delay=tk.Button(frame_1,text="二号機20分後 \n 自動閉め \n (一回押すのみ)",width=10,height=3,command=thr)
#button_delay.place(relx=0.2,rely=0.8)
'''
window.mainloop()