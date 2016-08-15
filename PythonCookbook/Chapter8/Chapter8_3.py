#	FileName : Chapter8_3.py
'''
让对象支持上下文管理协议
'''

if __name__ == '__main__':
	from socket import socket, AF_INET, SOCK_STREAM
	class LazyConnection:
		def __init__(self, address, family=AF_INET, type=SOCK_STREAM):
			self.address = address
			self.family = family
			self.type = type
			self.socks = []
		def __enter__(self):
			print('enter')
			sock = socket(self.family, self.type)
			sock.connect(self.address)
			self.socks.append(sock)
			return sock
		def __exit__(self, exc_type, exc_val, exc_tb):
			print('exit')
			self.socks.pop().close()
	from functools import partial
	conn = LazyConnection(('www.python.org', 80))
	with conn as s:
		s.send(b'GET /index.html HTTP/1.0\r\n')
		s.send(b'Host: www.python.org\r\n')
		s.send(b'\r\n')
		resp = b''.join(iter(partial(s.recv, 8192), b''))
		print(resp)
	with conn as s:
		with conn as s:
			pass