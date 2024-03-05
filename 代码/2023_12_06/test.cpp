//
////#include <boost/thread/thread.hpp> 
////#include <boost/function/function0.hpp>
////#include <iostream> 
////
////class boostTest
////{
////private:
////    boost::thread* thread_;
////    bool running;
////public:
////    boostTest()
////    {
////        std::cout << "Hello world, I''m a thread!" << std::endl;
////        running = true;
////    }
////
////    ~boostTest()
////    {
////        std::cout << "Destroy the object!" << std::endl;
////        thread_->join();
////    }
////
////    void startThread()
////    {
////        thread_ = new boost::thread(boost::bind(&boostTest::sayHello, this));
////        std::cout << " Thread " << thread_->get_id() << " is started! " << std::endl;
////    }
////
////    void stopThread()
////    {
////        running = false;
////    }
////
////    void sayHello()
////    {
////        int counter = 1;
////        std::cout << " Hello world! " << std::endl;
////        while (running)
////        {
////            std::cout << " Trapped in the loop! Time:" << counter++ << std::endl;
////            Sleep(1000);
////        }
////    }
////
////};
////
////int main(int argc, char* argv[])
////{
////    boostTest* test = new boostTest();
////    test->startThread();
////    Sleep(2500);
////    test->stopThread();
////    delete test;
////    return 0;
////}
////
//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <fstream>
//
//#include <boost/filesystem.hpp> // 引入boost库
//using namespace std;
//
//bool EnumFile(const std::string& src_path, std::vector<std::string>* file_list)
//{
//    assert(file_list);
//    namespace fs = boost::filesystem; // 这是一个习惯, C++支持
//    fs::path root_path(src_path);     // 定义一个path对象
//
//    if (fs::exists(root_path) == false) // 判断路径是不是存在
//    {
//        std::cerr << src_path << " 路径是不存在的" << std::endl;
//        return false;
//    }
//
//    // 定义一个空的迭代器, 用来判断 迭代器递归结束
//    fs::recursive_directory_iterator end;
//    for (fs::recursive_directory_iterator iter(root_path); iter != end; iter++)
//    {
//        // 保证是普通的文件
//        if (fs::is_regular_file(*iter) == false)
//        {
//            continue;
//        }
//
//        // 普通文件需要 html 文件后缀结束
//        if (iter->path().extension() != ".txt")
//        {
//            continue;
//        }
//
//        // std::cout << "debug: " << iter->path().string() << std::endl;
//
//        // 此时一定 是以 html 后缀结尾的普通文件
//        file_list->push_back(iter->path().string());
//    }
//
//    return true;
//}
//void rewriter(const string& val, const string& filename)
//{
//    std::vector<string> v;
//    std::ifstream ifs;
//    ifs.open(filename, std::ifstream::in);
//    string str;
//    while (getline(ifs, str))
//    {
//       /* cout << str << endl;*/
//        v.push_back(str);
//    }
//    /*cout <<"aa";*/
//    for (auto& e : v)
//    {
//        auto pos = e.find(' ');
//        e = val + e.substr(pos);
//        cout << e << endl;
//    }
//    ifs.close();
//    std::ofstream ofs;
//    ofs.open(filename, std::ofstream::out);
//    for (auto& e : v)
//    {
//        ofs << e << endl;
//    }
//    ofs.close();
//}
//int main()
//{
//    /*std::string path;
//    std::vector<std::string> file_list;
//    EnumFile(path, &file_list);
//
//    string val;
//    for (auto e : file_list)
//    {
//        rewriter(val, e);
//    }*/
//
//  /*  std::ofstream ofs;
//    ofs.open("test.txt", std::ofstream::out);
//
//    ofs << " more lorem ipsum1\n";
//    ofs << " more lorem ipsum2\n";*/
//    rewriter("0.6", "WIN_20230904_13_55_34_Pro.txt");
//    return 0;
//}





//#include <boost/thread/thread.hpp> 
//#include <boost/function/function0.hpp>
//#include <iostream> 
//
//class boostTest
//{
//private:
//    boost::thread* thread_;
//    bool running;
//public:
//    boostTest()
//    {
//        std::cout << "Hello world, I''m a thread!" << std::endl;
//        running = true;
//    }
//
//    ~boostTest()
//    {
//        std::cout << "Destroy the object!" << std::endl;
//        thread_->join();
//    }
//
//    void startThread()
//    {
//        thread_ = new boost::thread(boost::bind(&boostTest::sayHello, this));
//        std::cout << " Thread " << thread_->get_id() << " is started! " << std::endl;
//    }
//
//    void stopThread()
//    {
//        running = false;
//    }
//
//    void sayHello()
//    {
//        int counter = 1;
//        std::cout << " Hello world! " << std::endl;
//        while (running)
//        {
//            std::cout << " Trapped in the loop! Time:" << counter++ << std::endl;
//            Sleep(1000);
//        }
//    }
//
//};
//
//int main(int argc, char* argv[])
//{
//    boostTest* test = new boostTest();
//    test->startThread();
//    Sleep(2500);
//    test->stopThread();
//    delete test;
//    return 0;
//}
//

//#include <iostream>
//#include <string>
//#include <vector>
//#include <cassert>
//#include <fstream>
//
//#include <boost/filesystem.hpp> // 引入boost库
//using namespace std;
//
//bool EnumFile(const std::string& src_path, std::vector<std::string>* file_list)
//{
//    assert(file_list);
//    namespace fs = boost::filesystem; // 这是一个习惯, C++支持
//    fs::path root_path(src_path);     // 定义一个path对象
//
//    if (fs::exists(root_path) == false) // 判断路径是不是存在
//    {
//        std::cerr << src_path << " 路径是不存在的" << std::endl;
//        return false;
//    }
//
//    // 定义一个空的迭代器, 用来判断 迭代器递归结束
//    fs::recursive_directory_iterator end;
//    for (fs::recursive_directory_iterator iter(root_path); iter != end; iter++)
//    {
//        // 保证是普通的文件
//        if (fs::is_regular_file(*iter) == false)
//        {
//            continue;
//        }
//
//        // 普通文件需要 html 文件后缀结束
//        if (iter->path().extension() != ".txt")
//        {
//            continue;
//        }
//
//        // std::cout << "debug: " << iter->path().string() << std::endl;
//
//        // 此时一定 是以 html 后缀结尾的普通文件
//        file_list->push_back(iter->path().string());
//    }
//
//    return true;
//}
//void rewriter(const string& val, const string& filename)
//{
//    std::vector<string> v;
//    std::ifstream ifs;
//    ifs.open(filename, std::ifstream::in);
//    string str;
//    while (getline(ifs, str))
//    {
//        v.push_back(str);
//    }
//    for (auto& e : v)
//    {
//        auto pos = e.find(' ');
//        e = val + e.substr(pos);
//    }
//    ifs.close();
//    std::ofstream ofs;
//    ofs.open(filename, std::ofstream::out);
//    for (auto& e : v)
//    {
//        ofs << e << endl;
//    }
//    ofs.close();
//}
//int main()
//{
//    std::string path = "D:\\Code\\Yolov5\\images(1)\\images\\0.6\\labels";
//    std::vector<std::string> file_list;
//    EnumFile(path, &file_list);
//
//    string val = "6";
//    for (auto e : file_list)
//    {
//        rewriter(val, e);
//    }
//    return 0;
//}


#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>

#include <boost/filesystem.hpp> // 引入boost库
using namespace std;

bool EnumFile(const std::string& src_path, std::vector<std::string>* file_list)
{
    assert(file_list);
    namespace fs = boost::filesystem; // 这是一个习惯, C++支持
    fs::path root_path(src_path);     // 定义一个path对象

    if (fs::exists(root_path) == false) // 判断路径是不是存在
    {
        std::cerr << src_path << " 路径是不存在的" << std::endl;
        return false;
    }

    // 定义一个空的迭代器, 用来判断 迭代器递归结束
    fs::recursive_directory_iterator end;
    for (fs::recursive_directory_iterator iter(root_path); iter != end; iter++)
    {
        // 保证是普通的文件
        if (fs::is_regular_file(*iter) == false)
        {
            continue;
        }

        // 普通文件需要 html 文件后缀结束
        /*if (iter->path().extension() != ".jpg")
        {
            continue;
        }*/

         //std::cout << "debug: " << iter->path().string() << std::endl;

        // 此时一定 是以 html 后缀结尾的普通文件
        file_list->push_back(iter->path().string());
    }

    return true;
}

void func(std::vector<std::string>& v)
{
    for (auto& e : v)
    {
        auto p1 = e.rfind('.');
        auto p2 = e.rfind('\\');
        e = e.substr(p2 + 1, p1 - p2 - 1);
    }
}
#include <cstdio>
#include <set>

int main()
{
    std::string path1 = "./images";
    std::string path2 = "./lables";
    std::vector<std::string> file_list1;
    std::vector<std::string> file_list2;

    EnumFile(path1, &file_list1);
    EnumFile(path2, &file_list2);

    func(file_list1);
    func(file_list2);

    set<string> s;
    for (auto& e : file_list1)
    {
        s.insert(e);
    }

    for (auto& e : file_list2)
    {
        auto iter = s.find(e);
        if (iter == s.end())
        {
            string path = "./images/";
            path += e;
            path += ".jpg";
            cout << path << endl;
          /*  remove(path.c_str());*/
        }
    }


    return 0;
}