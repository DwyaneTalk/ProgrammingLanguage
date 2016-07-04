#	FileName : Chapter1_3.py
'''
保留最后优先个历史记录
关键点：
collections.deque
with *A as *B：将*A赋值给*B，并在前后会执行*B对象的__enter__()和__exit()__
yield: 指定函数为生成器函数，作用是将序列的结果依次返回节省空间
'''
from collections import deque

def search(lines, pattern, history = 5):
	previous_lines = deque(maxlen = history)
	for line in lines:
		if pattern in line:
			yield line, previous_lines
		previous_lines.append(line)

if __name__ == '__main__':
	with open(r'..\work\text.txt') as f:
		for line, prelines in search(f, 'Python', 5):
			for plines in prelines:
				print(plines, end='')
			print(line, end='')
			print('-' * 20)