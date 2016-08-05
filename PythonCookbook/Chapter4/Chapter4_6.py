#	FileName : Chapter4_6.py
'''
带有外部状态的生成器函数：
构造一个外部可以获取状态的生成器函数：将生成器函数封装到类里面，类的成员变量存储外部状态
'''

if __name__ == '__main__':
	from collections import deque
	class lineHistory:
		def __init__(self, lines):
			self._lines = lines
			self._history = deque(maxlen = 3)
		def __iter__(self):
			for lno, line in enumerate(self._lines):
				self._history.append((lno, line))
				yield  line
		def clear(self):
			self._history.clear()

	with open(r'..\work\text.txt') as f:
		lines = lineHistory(f)
		for line in lines:
			if 'Python' in line:
				for hlno, hline in lines._history:
					print('{} : {}'.format(hlno, hline), end='')
