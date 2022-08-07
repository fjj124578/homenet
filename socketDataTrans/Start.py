import computerSocketClientDataSendClass as CSCDSC


SERVER_IP = "192.168.11.16"    #目標IP
SERVER_PORT = 1235            #目標port
cd = r"C:\Users\14540\Desktop\homenet\socketDataTrans"
fileName = "rawDataTest.txt"
test_a = CSCDSC.twoByteSendbySocket(SERVER_IP,SERVER_PORT,cd,fileName)
#print(test_a.turn_on_data)
#print(test_a.turn_off_data)
test_a.serialDataSend(test_a.AC_COLD)
