#pragma once
#include <unordered_map>
#include <string>
#include <vector>

// ����һ���Լ�ѧϰͼд�Ĵ���, �в���
// ͼ��д�������Ӿ���,�����ӱ�

// ���Ӿ���
namespace matrix
{
	class Graph
	{
	public:
		Graph()
		{

		}
		~Graph(){

		}
	public:
		bool insert

	private:
		std::unordered_map<std::string, int> _hash;  // ת����
		std::vector<int> _matrix;                    // ���Ӿ���
	};
}

// ���ӱ�
namespace table
{
	class Graph
	{
	public:
		Graph();
		~Graph();

	private:

	};
}