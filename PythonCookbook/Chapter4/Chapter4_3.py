#	FileName : Chapter4_3.py
'''
用生成器产生迭代器：在函数中用yield返回结果
'''
if __name__ == '__main__':
	def myRange(start, stop, inc):
		while start < stop:
			yield start
			start += inc

	for val in range(1, 20, 3):
		print(val, end=' ')
	print()
	for val in myRange(1, 20, 3.5):
		print(val, end=' ')
	print()

	def countDown(value):
		print('starting count!')
		while value > 0:
			yield value
			value -= 1
		print('\nending count')
	for value in countDown(5):
		print(value, end=' ')
	it = countDown(3)
	print(it)
	print(next(it))
	print(next(it))
	print(next(it))
