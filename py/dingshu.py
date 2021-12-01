from maimaidx_music import *
from collections import defaultdict
import re

def inner_level_q(ds1, ds2=None):
    result_set = []
    diff_label = ['Bas', 'Adv', 'Exp', 'Mst', 'ReM']
    if ds2 is not None:
        music_data = total_list.filter(ds=(ds1, ds2))
    else:
        music_data = total_list.filter(ds=ds1)
    for music in sorted(music_data, key = lambda i: int(i['id'])):
        for i in music.diff:
            result_set.append((music['id'], music['title'], music['ds'][i], diff_label[i], music['level'][i]))
    return result_set

def dscg():
    f = open('./dingshu.txt', 'r', encoding = 'utf-8')
    argv = f.read().strip().split(" ")
    f.close()
    f = open('./dingshu.txt', 'w', encoding = 'utf-8')
    if len(argv) > 3 or len(argv) == 1:
        print("命令格式为\n定数查歌 <定数>\n定数查歌 <定数下限> <定数上限>", file = f)
        f.close()
        return
    if len(argv) == 2:
        result_set = inner_level_q(float(argv[1]))
    else:
        result_set = inner_level_q(float(argv[1]), float(argv[2]))
    if len(result_set) > 50:
        print(f"结果过多（{len(result_set)} 条），请缩小搜索范围。", file = f)
        f.close()
        return
    s = ""
    for elem in result_set:
        s += f"{elem[0]}. {elem[1]} {elem[3]} {elem[4]}({elem[2]})\n"
    print(s.strip(), file = f, end = '')
    f.close()

dscg()
