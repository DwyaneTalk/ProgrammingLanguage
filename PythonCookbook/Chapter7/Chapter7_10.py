#	FileName : Chapter7_10.py
'''
带额外状态信息的回调函数：
1、通过类/闭包记录状态，或者通过访问全局变量记录状态（nolocal标识全局变量），通过协程实线
'''

if __name__ == '__main__':
	def apply_async(func, args, *, callback):
		result = func(*args)
		callback(result)

	def add(x, y):
		return x + y
	def show(result):
		print(result)

	apply_async(add, (2, 3), callback=show)
	apply_async(add, ('hello', 'world'), callback=show)

	class ResultHander:
		def __init__(self):
			self.count = 0
		def show(self, result):
			self.count += 1
			print('[{}] Got: {}'.format(self.count, result))

	r = ResultHander()
	apply_async(add, (2, 3), callback=r.show)
	apply_async(add, ('Hello', 'World'), callback=r.show)

	def resultHandler():
		count = 0
		def show(result):
			nonlocal count
			count += 1
			print('[{}] Got: {}'.format(count, result))
		return show
	r = resultHandler()
	apply_async(add, (2, 3), callback=r)
	apply_async(add, ('Hello', 'World'), callback=r)

	def resultShow():
		count = 0
		while True:
			result = yield
			count += 1
			print('[{}] Got: {}'.format(count, result))
	r = resultShow()
	next(r)
	apply_async(add, (2, 3), callback=r.send)
	apply_async(add, ('Hello', 'World'), callback=r.send)
