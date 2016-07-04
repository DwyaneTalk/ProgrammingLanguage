#	FileName : Chapter1_17.py
'''
从字典中提取子集
关键点：
类似过滤列表元素，使用字典推导提取子集
同样filter/compress等函数也可以使用，只不过中间需要转换过程，效率低下
'''

if __name__ == '__main__':
	prices = {
		'ACME': 45.23,
		'AAPL': 612.78,
		'IBM': 205.55,
		'HPQ': 37.20,
		'FB': 10.75
	}
	tech_names = {'AAPL', 'IBM', 'HPQ', 'MSFT'}
	print({key : value for key, value in prices.items() if value > 200})
	print({key : value for key, value in prices.items() if key.startswith('A')})
	print({key : value for key, value in prices.items() if key in tech_names})
	print(dict((key, value) for key, value in prices.items() if value > 200))
	print({key : prices[key] for key in prices.keys() & tech_names})

	def startWith(name):
		startStr = 'A'
		if name[0].startswith(startStr):
			return True
		else:
			return False
	print(dict(filter(startWith, prices.items())))

	from itertools import compress
	sel = [True if value > 200 else False for value in prices.values()]
	print(dict(compress(prices.items(), sel)))