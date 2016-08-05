#	FileName : Chapter3_16.py
'''
时区操作
'''
if __name__ == '__main__':
	from datetime import datetime, timedelta
	from pytz import timezone
	d = datetime(2012, 12, 21, 9, 30, 0)
	print(d)
	central = timezone('US/Central')
	loc_d  =central.localize(d)
	print(loc_d)
	bang_d = loc_d.astimezone(timezone('Asia/Kolkata'))
	print(bang_d)

	d = datetime(2013, 3, 10, 1, 45)
	loc_d = central.localize(d)
	print(d)
	print(loc_d)
	later = loc_d + timedelta(minutes=30)
	print(later)
	print(central.normalize(loc_d + timedelta(minutes=30)))