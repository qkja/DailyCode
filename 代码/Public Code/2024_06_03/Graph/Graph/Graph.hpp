#pragma once
#include <unordered_map>
#include <string>
#include <vector>

// 这是一个自己学习图写的代码, 有不足
// 图的写法有链接矩阵,有链接表

// 链接矩阵
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
		std::unordered_map<std::string, int> _hash;  // 转换表
		std::vector<int> _matrix;                    // 链接矩阵
	};
}

// 连接表
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