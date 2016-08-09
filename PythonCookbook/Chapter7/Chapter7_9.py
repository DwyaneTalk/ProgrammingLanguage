#	FileName : Chapter7_9.py
'''
将单方法（除__init__()）的类转换成函数：
一般单方法的类，是通过__init__()记录状态，另外一个函数进行处理，可以通过闭包(内部函数)来代替
'''

if __name__ == '__main__':
	from urllib.request import urlopen

	class URLTemplate:
		def __init__(self, template):
			self._template = template
		def open(self, **kwargs):
			return urlopen(self._template.format_map(kwargs))

	yahoo = URLTemplate('http://finance.yahoo.com/d/quotes.csv?s={names}&f={fields}')
	for line in yahoo.open(names = 'IBM,AAPL,FB', fields='sl1clv'):
		print(line.decode('utf-8'))

	def urlTemplate(template):
		def open(**kwargs):
			return urlopen(template.format_map(kwargs))
		return open

	yahoo = URLTemplate('http://finance.yahoo.com/d/quotes.csv?s={names}&f={fields}')
	for line in yahoo.open(names='IBM,AAPL,FB', fields='sl1clv'):
		print(line.decode('utf-8'))
