#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		if (a <= 0 || b <= 0)
			return -1;
		int minNum = min(a, b);
		int maxNum = max(a, b);
		while (minNum != 1 && maxNum != 1)
		{
			maxNum = maxNum / 2;
			if (maxNum == minNum)
			{
				return minNum;
			}
			if (maxNum < minNum)
				swap(minNum, maxNum);


		}
		return 1;

	}
};

int main()
{
	std::cout << LCA().getLCA(8, 9) << std::endl;
	return 0;
}

//
//int main()
//{
//
//	int n = 0;
//
//	while (cin >> n)
//	{
//		std::vector<int> v(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> v[i];
//		}
//		int fast = 1;
//		int next = 2;
//		int slow = 0;
//		int count = 0;
//		for (; next < n;)
//		{
//			int x = v[fast] - v[slow];
//			int y = v[next] - v[fast];
//			if ((x > 0 && y < 0)
//				|| (x < 0 && y > 0))
//			{
//				count++;
//				slow = next;
//				fast = slow + 1;
//				next = fast + 1;
//			}
//			else if (x == 0 && y < 0)
//			{
//				// 判断下是不是单调递减
//				int a = slow - 1;
//				if (a >= 0 && v[slow]-v[a]>0)
//				{
//					count++;
//					slow = next;
//					fast = slow + 1;
//					next = fast + 1;
//				}
//				else
//				{
//					fast++;
//					next++;
//					slow++;
//				}
//			}
//			else
//			{
//				fast++;
//				next++;
//				slow++;
//			}
//		
//		}
//		std::cout << ++count << std::endl;
//	}
//	return 0;
//}
//298
//211 285 122 785 462 588 952 598 333 698 192 330 127 943 46 462 313 210 197 251 628 825 966 869 530 220 491 481 759 959 223 807 203 431 915 7 255 352 39 700 570 920 706 943 86 375 278 933 665 696 897 732 888 717 532 636 609 749 133 470 401 619 206 350 429 86 849 243 795 795 380 995 418 687 230 634 272 123 462 112 387 87 662 299 345 517 978 235 364 276 588 940 291 181 245 427 997 247 471 31 997 691 642 772 812 45 695 537 617 805 218 742 436 794 8 651 389 400 901 147 779 854 934 319 295 591 410 332 500 626 727 795 50 50 869 923 728 815 692 997 688 27 858 299 867 460 265 987 978 378 280 769 527 891 955 529 419 225 593 584 297 631 345 1 948 773 176 634 944 797 81 959 492 374 303 283 597 682 649 310 428 54 272 979 805 291 285 224 326 881 379 634 19 5 949 669 463 366 914 315 830 176 263 277 246 267 422 718 251 318 513 922 805 27 822 654 67 328 770 965 192 267 132 441 845 115 177 519 101 112 734 97 524 316 998 183 70 602 834 686 77 673 236 714 285 890 943 835 197 239 270 229 556 133 505 420 792 893 141 611 41 1 40 56 550 495 876 343 559 317 601 75 195 190 212 151 333 904 392 95 199 767 104 182 874 137 45 632 691 125 611 821 288 159 82 14 502 87