#	FileName : Chapter7_1.py
'''
使用可接受任意数量的位置参数和强制参数
'''

if __name__ == '__main__':
	import html
	def ave(first, *rest):
		return (first + sum(rest)) / (1 + len(rest))
	def make_element(name, value, **attrs):
		keyvals = ['%s = %s' % item for item in attrs.items()]
		attr_str = ' '.join(keyvals)
		element = r'<{name} "{attrs}">{value}<{name}/>'.format(name=name, attrs=attr_str, value=value)
		return element

	print(ave(1, 2, 3, 4, 5))
	print(ave(1, 2, 3))
	print(make_element('item', 'Albatross', size='large', quantity=6))