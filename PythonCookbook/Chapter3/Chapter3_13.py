#	FileName : Chapter3_13.py
'''
关于日期操作的一个示例和相关星期操作
'''

if __name__ == '__main__':
	from datetime import datetime, timedelta
	weekdays = ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun']
	def get_pre_byday(dayname, start_date = None):
		if start_date == None:
			start_date = datetime.now()
		day_num_now = start_date.weekday()
		day_num_tar = weekdays.index(dayname)
		day_pre = (7 + day_num_now - day_num_tar) % 7
		if day_pre == 0:
			day_pre = 7
		return start_date - timedelta(days = day_pre)
	print(datetime.now())
	print(datetime.today())
	print(get_pre_byday('Mon'))
	print(get_pre_byday('Thu'))
	print(get_pre_byday('Mon', datetime(2012, 12, 21)))
	print(datetime(2012, 12, 21).weekday())