#	FileName : Chapter1_2.py
'''
在解压包含N个元素的可迭代序列时，如果变量个数超过N个，会抛出ValueRooro错误，可以通过‘*’解决
arrayList = [1, 2, 3]
a, *b = arrayList
print(b)	#将输出：[2, 3]
print(*b)	#将输出：2, 3
'''

def drop_first_and_last(grades):
	first, *middles, last = grades
	return middles
grades = drop_first_and_last([10, 60, 65, 54, 100])
print(grades)

record = ('DwyaneTalk', 'DwyaneTalk@163.com', '10000', '10086')
name, email, *phone_number = record
print('name: %s, email: %s, phone:' %(name, email), phone_number)

*trailing, current = [10, 8, 7, 1, 9, 5, 10, 3]
print('trailing:', trailing, 'current:', current)

records = [
	('foo', 1, 2),
	('bar', 'hello'),
	('foo', 3, 4)
]

def doFoo(x, y):
	print('foo-> x : %d, y : %d' %(x, y))
def doBar(s):
	print('bar-> s : %s' %s)
for tag, *args in records:
	if tag == 'foo':
		doFoo(*args)
	elif tag == 'bar':
		doBar(*args)

record = ('ACME', 50, 123.45, (12, 18, 2012))
name, *_, (*_, year) = record
print('name: %s, year: %d' %(name, year))

def sum(items):
	head, *tail = items
	return head + sum(tail) if tail else head

print('sum:',sum([1, 10, 7, 4, 5, 9]))