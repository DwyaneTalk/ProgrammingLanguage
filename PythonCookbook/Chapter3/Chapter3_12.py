#	FileName : Chapter3_12.py
'''
日期的表示与计算：
时间段：timedelta
时间点：datetime
'''
if __name__ == '__main__':
	from datetime import timedelta, datetime
	a = timedelta(days=2, hours=6)
	b = timedelta(hours=4.5)
	c = a + b
	print('time delta a is :', a)
	print('time delta b is :', b)
	print('time delta c is :', c)
	print('day delta in c is :', c.days)
	print('seconds delta in c is :',c.seconds)
	print('hour delta in c is :',c.seconds / 3600)
	print('total hour delta in c is :',c.total_seconds() / 3600)

	a = datetime(2012, 9, 23)
	b = datetime(2012, 12, 21, 2)
	c = b - a
	print(a)
	print(b)
	print(c)
	print(c.days)
	print(c.total_seconds() / 3600)
	print(datetime.now())
