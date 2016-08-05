#	FileName : Chapter3_10.py
'''
矩阵和线性代数运算：
numpy库中定义matrix对象表示矩阵，并可以进行相应操作
'''

if __name__ == '__main__':
	import numpy as np
	import numpy.linalg as npline
	m = np.matrix([[1,-2,3],[0,4,5],[7,8,-9]])
	print(m)
	print(m.T)
	print(m.I)
	v = np.matrix([[2], [3], [4]])
	print(v)
	print(m * v)

	print(npline.det(m))
	print(npline.eigvals(m))
	print(npline.solve(m, v))
	print(m * npline.solve(m, v))