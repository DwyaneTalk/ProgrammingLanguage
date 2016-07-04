#	FileName ： Chapter1_5.py
'''
利用heapq实现一个优先队列
关键点：
__repr__()和__str__()函数
heapq.heappush()时，当元素是列表时默认比较方式
'''
import heapq

class PriorityQueue:
	def __init__(self, option = -1):
		self.queue = []
		self.index = 0
		if option == -1:
			self.option = option
		else:
			self.option = 1
	def __str__(self):
		return 'A priority queue with %d elems : %s' %(self.index, str(self.queue))
	def __repr__(self):
		return 'A priority queue with %d elems : %s' %(self.index, str(self.queue))
	def push(self, item, priority):
		heapq.heappush(self.queue, (self.option * priority, self.index, item))
		self.index += 1
	def pop(self):
		return heapq.heappop(self.queue)[-1]

class Item:
	def __init__(self, name):
		self.name = name
	def __repr__(self):
		return 'Item({!r}) repr'.format(self.name)
	def __str__(self):
		return 'Item({!r}) str'.format(self.name)

if __name__ == '__main__':
	q = PriorityQueue(1)
	q.push(Item('foo'), 1)
	q.push(Item('bar'), 3)
	q.push(Item('spam'), 2)
	q.push(Item('grok'), 1)
	print(q.pop())
	print(q.pop())
	print(repr(q.pop()))
	print(repr(q.pop()))