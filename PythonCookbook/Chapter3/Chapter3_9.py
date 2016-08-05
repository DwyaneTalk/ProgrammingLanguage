#	FileName : Chapter3_9.py
'''
大型数组操作：列表和numpy库区别
'''
if __name__ == '__main__':
	x = [1, 2, 3, 4]
	y = [5, 6, 7, 8]
	print(x * 2)
	print(x + y)

	import numpy as np
	ax = np.array([1, 2, 3, 4])
	ay = np.array([5, 6, 7, 8])
	print(ax * 2)
	print(ax + 10)
	print(ax + ay)

	def f(x):
		return 3 * x ** 2 + 2 * x + 7
	print(f(ax))
	print(np.sqrt(ax))
	print(np.cos(ax))
	grid = np.zeros(shape=(10, 10), dtype = float)
	print(grid)
	print(grid + 10)
	print(np.sin(grid))