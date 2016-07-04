#	FileName : Chapter1_1.py

'''
可以将包含N个元素的列表、元组、字符串等序列解压赋值给变量
1:被赋值的变量个数必须为N
2:可以通过'_'指定无意义变量名实现部分解压赋值
'''

p = (4, 5)
x, y = p
print('x: %d, y:%d' %(x, y))

data = ['ACME', 50, 91.1, (2012, 12, 21)]
name, shares, price, date = data
print('name: %s, shares: %d, price: %f, date:' %(name, shares, price), date)

s = 'Hello'
a, b, c, d, e = s
print(a, b, c, d, e)

_, newShares, newPrice, _ = data
print('newName: %s, newShares: %f' %(newShares, newPrice))
