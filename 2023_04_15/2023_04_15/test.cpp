#include <vector>
// ����һ��ѭ������
class MyCircularQueue
{
public:
	//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
	MyCircularQueue(int k) 
	{
		_front = 0;
		_tail = 0;
		_cap = 0;
		_v.resize(k + 1); // ע���������ǲ���ʹ��resver
	}

	//enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
	bool enQueue(int value)
	{
		if (isFull())
			return false;
		_v[_tail] = value;
		_tail = (_tail + 1) % _v.size();
		_cap++;
		return true;
	}
	// deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档

	bool deQueue() {
		if (isEmpty())
			return false;
		_cap--;
		_front = (_front + 1) % _v.size();
		return true;

	}

	//Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
	int Front() {
		if (isEmpty())
			return -1;
		return _v[_front];
	}

	//Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
	int Rear() 
	{
		if (isEmpty())
			return -1;
		// �õ����һ��Ԫ��
		if (0 == _tail)
		{
			return _v.back();
		}
		return _v[_tail - 1];
	}

	bool isEmpty() {
		return _tail == _front;
	}

	bool isFull() {
		return (_tail + 1) % (_v.size()) == _front;
	}
private:
	size_t _front;
	size_t _tail;  // ָ�����һ�����ݵ���һ��λ��    
	size_t _cap;   // ��������Ч���ݵĸ���
	std::vector<int> _v;
};

// ��˵һ�����ǳ���������
// һ�����ǻ��жϸ�ѭ�����������Ԫ�ظ��� -- �����������һ����ʽ��
// ��������� _tail - _front
// ����    rear - front + N 
// �����ܽ�һ��  (  rear - front + N ) % N