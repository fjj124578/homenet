from ctypes.wintypes import tagRECT
import os
import re

from sqlalchemy import null
'''
iniファイルを読み取るためのクラス
初期化引数:cd（普段は結合工場配下）


'''


class read_ini_txt():
    def __init__(self, cd):
        self.cd = cd
    def find_target(self,target):
        '''
        self.cdを利用してini.txt中の指定した情報を取得する
        '''
        ini_path = self.cd+"\\rawDataTest.txt"            #iniファイルの絶対パスを作る
        ini_file = open(ini_path,'r',encoding='UTF-8')      #ファイル開く
        ini_data = ini_file.readlines()                   #一行ずつ読み込み
        ini_file.close()                                   #ファイル閉じる
        for i in ini_data:

            if target in i:
                content = re.search(r"{.+}",i)            #正規表現でdb行を取り出す
                if content==None:
                    content_str = ""
                    print("find {} from ini.txt is: {}".format(target,content_str))
                else:
                    content_str = content.group(0)            #結果から文字列を取り出す
                    content_str = content_str.strip('{')      #括弧消し
                    content_str = content_str.strip('}')      #括弧消し
                    print("find {} from ini.txt is: {}".format(target,content_str))
        return content_str

    
if __name__ == '__main__':
    # for test
    cd = os.getcwd()
    print(cd)
    test_obj = read_ini_txt(cd)
    test_obj.find_target("TURN_ON")
    test_obj.find_target("TURN_OFF")


