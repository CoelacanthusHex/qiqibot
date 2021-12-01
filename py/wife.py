import json
import random
f = open('./musicData.json', 'r', encoding = 'utf-8')
obj = json.load(f)
f.close()
r = random.choice(obj)
f = open('./wifeResult.txt', 'w', encoding = 'utf-8')
print(r['id'] + '. ' + r['title'], file = f)
print(r['id'], file = f)
print('/'.join(str(x) for x in r['level']), file = f)
f.close()
