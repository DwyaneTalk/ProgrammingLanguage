#	FileName : Chapter3_15.py
'''
日期与字符串转换：datetime.strptime()和datetime.strftime()
'''

if __name__ == '__main__':
	from datetime import datetime, timedelta
	text1 = '2012-09-20'
	text2 = '2014&03&21'
	date1 = datetime.strptime(text1, '%Y-%m-%d')
	date2 = datetime.strptime(text2, '%Y&%m&%d')
	deltadate = date2 - date1
	print(date1)
	print(date2)
	print(deltadate)
	print(datetime.strftime(date2, '%A %B %d, %Y'))

	def parse_ymd(s):
		y, m, d = s.split('-')
		return datetime(int(y), int(m), int(d))
	print(parse_ymd('2012-10-12'))