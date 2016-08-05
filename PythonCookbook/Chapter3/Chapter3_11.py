#	FileName : Chapter3_11.py
'''
随机数操作：random模块
random.choice():从序列中随机选择一个	random.sample():从序列中随机选择n个	random.shuffle():随机打乱序列的顺序	random.randint():产生随机整数
random.random():产生0-1内均匀分布的随机小数		random.getrandbits():产生N（二进制）位随机整数		random.seed():设置产生随机数的种子	……
'''

if __name__ == '__main__':
	import random
	values = [1, 2, 3, 4, 5, 6]
	strval1 = ''
	strval2 = ''
	strval3 = ''
	for i in range(10):
		strval1 += str(random.choice(values))
		sample = random.sample(values, 2)
		strval2 += str(sample[0]) + str(sample[1])
		strval3 += str(random.randint(0, 10))
	print('random.choice() : ' + strval1)
	print('random.sample() : ' + strval2)
	print('random.randint() : ' + strval3)
	random.shuffle(values)
	print(values)
	random.shuffle(values)
	print(values)
	print(random.random())
	print(random.random())
	print(random.getrandbits(20))
