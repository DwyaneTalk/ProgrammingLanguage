#	FileName : Chapter3_14.py
'''
对日期的另一个操作
'''

if __name__ == '__main__':
	from datetime import datetime, timedelta
	import calendar
	def get_month_range(start_date = None):
		if start_date == None:
			start_date = datetime.today()
		start_date = start_date.replace(day=1)
		_, day_num = calendar.monthrange(start_date.year, start_date.month)
		end_date = start_date + timedelta(days = day_num)
		return (start_date, end_date)
	def month_range(start_date, end_date):
		one_day = timedelta(days=1)
		while start_date < end_date:
			yield start_date
			start_date += one_day

	for cur_date in month_range(*get_month_range(datetime.today())):
		print(cur_date)
