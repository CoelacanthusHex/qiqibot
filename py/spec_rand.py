from maimaidx_music import *
from collections import defaultdict
import re

def song_txt(music: Music):
    return f"{music.id}. {music.title}\n{music.id}\n{'/'.join(music.level)}"

def spec_rand():
    f = open('spec_rand.txt', 'r', encoding = 'utf-8')
    oarg = f.read()
    f.close()
    f = open('spec_rand.txt', 'w', encoding = 'utf-8')
    level_labels = ['绿', '黄', '红', '紫', '白']
    regex = "随机((?:dx|sd|标准))?([绿黄红紫白]?)([0-9]+\+?)"
    res = re.match(regex, oarg)
    try:
        if res.groups()[0] == "dx":
            tp = ["DX"]
        elif res.groups()[0] == "sd" or res.groups()[0] == "标准":
            tp = ["SD"]
        else:
            tp = ["SD", "DX"]
        level = res.groups()[2]
        if res.groups()[1] == "":
            music_data = total_list.filter(level=level, type=tp)
        else:
            music_data = total_list.filter(level=level, diff=['绿黄红紫白'.index(res.groups()[1])], type=tp)
        if len(music_data) == 0:
            rand_result = "没有这样的乐曲哦。"
        else:
            rand_result = song_txt(music_data.random())
        print(rand_result, file = f, end = '')
    except Exception as e:
        pass
    f.close()

# main
spec_rand()
