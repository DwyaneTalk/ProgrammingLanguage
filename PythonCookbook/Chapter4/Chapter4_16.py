#	FileName : Chapter4_16.py
'''
迭代器代替while循环
'''
if __name__ == '__main__':
	CHUNKSIZE = 8192
	def reader1(s):
		while(True):
			data = s.recv(CHUNKSIZE)
			if data == b'':
				break
			#process_data(data)

	def reader2(s):
		for data in iter(lambda : s.recv(CHUNKSIZE), b''):
			print(data)
			#process_data(data)