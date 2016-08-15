#	FileName : Chapter8_2.py
'''
自定义字符串的格式化：format
'''

if __name__ == '__main__':
	_format = {
		'ymd' : '{d.year}--{d.month}--{d.day}',
		'mdy' : '{d.month}--{d.day}--{d.year}',
		'dmy' : '{d.day}--{d.month}--{d.year}',
	}
	class Data:
		def __init__(self, year, month, day):
			self.year = year
			self.month = month
			self.day = day
		def __format__(self, format_spec):
			if format_spec == '':
				format_spec = 'ymd'
			pat = _format[format_spec]
			return pat.format(d = self)
		def __str__(self):
			return 'Y:{d.year!s} M:{d.month!s} D:{d.day!s}'.format(d = self)
		def __repr__(self):
			return 'Date(Y:{d.year!r} M:{d.month!r} D:{d.day!r})'.format(d=self)


	d = Data(2012, 12, 21)
	print(format(d))
	print('{!s}'.format(d))
	print('{!r}'.format(d))
	print(format(d, 'mdy'))
	print('{:ymd}'.format(d))
	print('{:dmy}'.format(d))
