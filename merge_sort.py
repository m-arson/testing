import random

def merge_sort(arr):
	if len(arr) > 1:
		mid = len(arr)//2

		l_arr = arr[:mid]
		r_arr = arr[mid:]

		merge_sort(l_arr)
		merge_sort(r_arr)

		l_inx = r_inx = m_inx = 0

		while l_inx < len(l_arr) and r_inx < len(r_arr):
			if l_arr[l_inx] < r_arr[r_inx]:
				arr[m_inx] = l_arr[l_inx]
				l_inx += 1
			else:
				arr[m_inx] = r_arr[r_inx]
				r_inx += 1
			m_inx += 1

		while l_inx < len(l_arr):
			arr[m_inx] = l_arr[l_inx]
			l_inx += 1
			m_inx += 1

		while r_inx < len(r_arr):
			arr[m_inx] = r_arr[r_inx]
			r_inx += 1
			m_inx += 1

def req_sort(arr):
	for i in range(len(arr)):
		for j in range(len(arr)):
			if arr[j] > arr[i]:
				tmp = arr[i]
				arr[i] = arr[j]
				arr[j] = tmp
def q_sort(arr):
	merge_sort(arr)
	#req_sort(arr)
	return arr

r_random = []

for _ in range(10000):
	r_random.append(random.randint(0,1000))

print(q_sort(r_random))
