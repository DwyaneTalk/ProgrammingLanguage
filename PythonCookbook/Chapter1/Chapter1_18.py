#	FileName : Chapter1_18.py
'''
映射名称到序列元素
关键嗲：
namedtuple：命名元祖，通过名称访问元组中成员。
namdtuple._replace()函数
'''
from collections import namedtuple
if __name__ == '__main__':
	Subscriber = namedtuple('Subscriber', ['addr', 'joined'])
	sub = Subscriber('jonesy@example.com', '2012-10-19')
	print(sub)
	print(sub.addr)
	print(sub.joined)
	print(len(sub))

	Stock = namedtuple('Stock', ['name', 'shares', 'price'])
	def compute_cost1(record):
		return record[1] * record[2]
	def compute_cost2(record):
		return record.shares * record.price
	s = Stock('ACME', 100, 123.45)
	print(s)
	print(s._replace(shares = 75))
	print(compute_cost1(['ACME', 100, 123.45]))
	print(compute_cost2(s))

	Stock = namedtuple('Stock', ['name', 'shares', 'price', 'date', 'time'])
	stock_prototype = Stock('', 0, 0, None, None)
	def dict_to_stock(s):
		return stock_prototype._replace(**s)
	a = {'name' : 'ACME', 'shares' : 100, 'price' : 123.45}
	b = {'name' : 'ACME', 'shares' : 100, 'price' : 123.45, 'date' : '12/17/2012'}
	print(dict_to_stock(a))
	print(dict_to_stock(b))