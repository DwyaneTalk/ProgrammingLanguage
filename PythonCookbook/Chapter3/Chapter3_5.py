#	FileName : Chapter3_5.py
'''
字节字符串、大整数相互转换
'''

if __name__ == '__main__':
	data = b'\x00\x124V\x00x\x90\xab\x00\xcd\xef\x01\x00#\x004'
	print(len(data))
	print(data)
	print(int.from_bytes(data, 'little'))
	print(int.from_bytes(data, 'big'))

	x = 94522842520747284487117727783387188
	print(x.to_bytes(16, 'big'))
	x = 69120565665751139577663547927094891008
	print(x.to_bytes(16, 'little'))