#pragma once
#include <iostream>
#include <vector>
struct Home
{
	Home(double length = 0, double width = 0, int number = 1) :
		_length(length)
		, _width(width)
		, _number(number)
	{
	}
	double _length;
	double	_width;
	int	_number;
};

// 计算总面积
void totalArea(const std::vector<struct Home>& homes, double& total_area)
{
	total_area = 0;
	int i = 0;
	for (auto& val : homes)
	{
		++i;
		std::cout << i << "  长: " << val._length << "  宽: " << val._width
			<< "  面积: " << val._width * val._length
			<< "  个数 " << val._number
			<< "    总面积: " << val._width * val._length * val._number
			<< std::endl;
		total_area += val._width * val._length * val._number;
	}
}



// 计算冷负荷
void coolingLoad(const std::vector<struct Home>& homes, const int& thermal_temperature_index, double& cooling_load)
{
	cooling_load = 0;
	int i = 0;
	for (auto& val : homes)
	{
		++i;
		std::cout << i << " 冷负荷 "
			<< val._width * val._length * thermal_temperature_index
			<< std::endl;
		cooling_load += val._width * val._length * val._number * thermal_temperature_index;
	}
}




// 计算新风负荷, 他的单位是 kg/s
void freshAirLoad(const int& cooling_load, int ho, int hr, int& fresh_air_load)
{
	fresh_air_load = cooling_load / (ho - hr);
}




