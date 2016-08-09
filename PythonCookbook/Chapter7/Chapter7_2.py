#	FileName : Chapter7_2.py
'''
强制接受关键字参数
'''

if __name__ == '__main__':

	def recv(maxsize, *, block):
		print(maxsize)
		print(block)
	def mininum(*value, clip=None):
		m = min(value)
		if clip is not None:
			m = clip if clip > m else m
		return m

	recv(1024, block=True)
	print(mininum(1, 5, 2, -5, 10))
	print(mininum(1, 5, 2, -5, 10, clip=0))