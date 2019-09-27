#include<stdio.h>
#include<assert.h>
#include<malloc.h>
//���һ���ҵ��������е�K��Ԫ�ص��ࣨclass����ע���������ĵ�K��Ԫ�أ����ǵ�K����ͬ��Ԫ�ء�
//��� KthLargest ����Ҫһ��ͬʱ�������� k ����������nums �Ĺ��������������������еĳ�ʼԪ�ء�ÿ�ε��� KthLargest.add�����ص�ǰ�������е�K���Ԫ�ء�
//ʾ�� :
//int k = 3;
//int[] arr = [4, 5, 8, 2];
//KthLargest kthLargest = new KthLargest(3, arr);
//kthLargest.add(3);   // returns 4
//kthLargest.add(5);   // returns 5
//kthLargest.add(10);  // returns 5
//kthLargest.add(9);   // returns 8
//kthLargest.add(4);   // returns 8
//typedef int HPDataType;
//typedef struct KthLargest
//{
//	HPDataType* _a;
//	int _size;
//	int _capacity;
//} KthLargest;
//void Swap(HPDataType* pa, HPDataType* pb)
//{
//	HPDataType tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//void ShiftDown(HPDataType* a, int n, int root)
//{
//	assert(a);
//	int parent = root;
//	int child = 2 * parent + 1;
//	while (child < n)
//	{
//		if (child + 1 < n && a[child] < a[child + 1])
//		{
//			child++;
//		}
//		if (a[child] > a[parent])
//		{
//
//			Swap(&a[parent], &a[child]);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//
//void HeapSort(int* a, int n)
//{
//	assert(a);
//	int i = 0;
//	int end = n - 1;
//	for (i = (n - 2) / 2; i >= 0; i++)
//	{
//		Shift(a, n, i);
//	}
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		ShiftDown(a, end, 0);
//		end--;
//	}
//}
//void HeapPush(KthLargest* hp, HPDataType x)
//{
//	assert(hp);
//	//�������
//	if (hp->_size == hp->_capacity)
//	{
//		int newcapacity = hp->_capacity == 0 ? 10 : 2 * hp->_capacity;
//		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * newcapacity);
//		hp->_capacity = newcapacity;
//	}
//	//β��
//	hp->_a[hp->_size] = x;
//	hp->_size++;
//	//���ϵ���
//	ShiftUp(hp->_a, hp->_size, hp->_size - 1);
//}
//KthLargest* kthLargestCreate(int k, int* nums, int numsSize)
//{
//	int i = 0;
//	KthLargest* KL = (KthLargest*)malloc(sizeof(KthLargest));
//	for (i = 0; i < numsSize; i++)
//	{
//		KL->_a[i] = nums[i];
//		KL->_size = numsSize;
//	}
//	return KL;
//}
//
//int kthLargestAdd(KthLargest* obj, int val) 
//{
//	
//}
//void kthLargestFree(KthLargest* obj) {
//
//}


//�ٷ�˼·��
typedef struct {
	int s[20000];
	int k;
	int index;
} KthLargest;

void minHeap(KthLargest* obj, int num) {
	//�Ѵ���k��������С���ѵĶѶ�Ԫ�� ���ڵ��� ��Ԫ�أ��򲻽��д���

	int flag;
	if (obj->k == obj->index + 1 && obj->s[0] >= num) {
		return;
	}
	else if (obj->k == obj->index + 1 && obj->s[0] < num) {
		flag = 1;
		obj->s[0] = num;
	}
	else {
		flag = 2;
		obj->s[++obj->index] = num;
	}

	//��һ��������Ҫ������С�Ѷѻ�����
	if (obj->index == 0) {
		return;
	}

	//heapify
	int i, temp;
	if (flag == 2) {
		i = obj->index;
		while ((i - 1) / 2 >= 0) {
			temp = (i - 1) / 2;
			if (obj->s[temp] > obj->s[i]) {
				int data = obj->s[temp];
				obj->s[temp] = obj->s[i];
				obj->s[i] = data;

				i = (i - 1) / 2;
			}
			else {
				break;
			}
		}
	}
	else {
		i = 0;
		while (1) {
			int left = i * 2 + 1;
			int right = i * 2 + 2;
			temp = i;
			if (left <= obj->index && obj->s[temp] > obj->s[left]) {
				temp = left;
			}
			if (right <= obj->index && obj->s[temp] > obj->s[right]) {
				temp = right;
			}
			if (temp == i) {
				break;
			}
			int data = obj->s[temp];
			obj->s[temp] = obj->s[i];
			obj->s[i] = data;

			i = temp;
		}
	}
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
	KthLargest* kL = (KthLargest*)malloc(sizeof(KthLargest));
	kL->k = k;
	kL->index = -1;

	int i;
	for (i = 0; i < numsSize; i++) {
		minHeap(kL, nums[i]);
	}
	return kL;
}

int kthLargestAdd(KthLargest* obj, int val) {
	minHeap(obj, val);
	return obj->s[0];
}

void kthLargestFree(KthLargest* obj) {
	obj->index = -1;
}


