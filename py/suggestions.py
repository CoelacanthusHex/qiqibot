#!usr/bin/python3
import json
import time
import random
import os.path
import zipfile
import requests

def download():
    try:
        rObj = requests.get(r'https://www.diving-fish.com/api/maimaidxprober/music_data')
        r = requests.get(r'https://www.diving-fish.com/maibot/static.zip', stream = True)
        with open(r'./staic.zip', "wb") as staic:
            for chunk in r.iter_content():
                if chunk:
                    staic.write(chunk)
            staic.close()
    except:
        print('无法取得乐曲信息')
        return False
    f = zipfile.ZipFile(r'./staic.zip', 'r')
    f.extractall()
    f.close()
    print('解压完成')
    f = open(r'./musicData.json', 'w', encoding = 'utf-8')
    f.write(rObj.text)
    f.close()
    f = open(r'./timestamp', 'w')
    f.write(str(time.time()))
    f.close()
    print('下载完成')
    return True

def getData():
    if (os.path.isfile(r'./timestamp')):
        f = open(r'./timestamp')
        t = int(eval(f.read()))
        f.close()
        if t + 8640000 <= time.time():
            if(download()):
                print('ok')
                return True
            else:
                print('no')
                return False
    else:
        print('not exist')
        download()
    return True

if getData():
    f = open(r'./musicData.json', 'r', encoding = 'utf-8')
    jsonObj = json.load(f)
    f.close()
    r = jsonObj[random.randint(0, len(jsonObj))]
    f = open(r'./result.txt', 'w', encoding = 'utf-8')
    f.write(r['title'])
    gener = {'POPSアニメ' : '流行&动画', 'ゲームバラエティ' : '其它游戏', 
             'niconicoボーカロイド' : 'niconico&VOCALOID', 
             'オンゲキCHUNITHM' : '音击中二'}
    genre = gener.get(r['basic_info']['genre'], r['basic_info']['genre'])
    f.write('\n' + genre)
    level = ['Basic', 'Advanced', 'Expert', 'Master', 'Re:Master']
    nDif = random.randint(2, len(r['level']) - 1)
    diff = level[nDif] + ' ' + r['level'][nDif]
    f.write('\n' + diff)
    f.write('\n' + r['charts'][nDif]['charter'])
    f.write('\n'+ r['id'])
else:
    print('Something went wrong')
