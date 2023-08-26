#define  _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE "\r\n"
#define SPACE " "
#define MAXLINE 1204
#define MINLINE 100

void serve_static(int fd, char* filename, int fileszie)
{
	char buf[MAXLINE] = { 0 };
	sprintf(buf, "HTTP/1.0 200 OK\n");
	sprintf(buf, "%sServer: Tiny Web Server\n", buf);
	sprintf(buf, "%sContent-length: %d\n", buf, fileszie);
	// sprintf(buf, "%sContent-type: TXT\r\n", buf);
	sprintf(buf, "%s", LINE);

	printf("%s\n", buf);

}
int main()
{
	char* filename = "/home/bit/read/readbook/深入理解计算机系统/11网络编程/tiny-web-ser/wwwroot/index.html";
	int fd = 1;
	serve_static(fd, filename, 10000);
	return 0;
}






















/* strtok example */
//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str[] = "This, a sample string.";
//    char* pch;
//    //printf("Splitting string \"%s\" into tokens:\n", str);
//    printf("%s %d %p\n", str, strlen(str), (void*)str);
//
//    pch = strtok(str, " ,.");
//    while (pch != NULL)
//    {
//        printf("%s %d %p\n", pch, strlen(pch), (void*)pch);
//        pch = strtok(NULL, " ,.-");
//    }
//    return 0;
//}

//#include <stdio.h>
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//    char* s = "0x11";
//
//    int ret = strtol(s, NULL, 16);
//    printf("%d\n", ret);
//
//    return 0;
//}

//#include <stdio.h>    
////#include <arpa/inet.h>    
//#include <stdlib.h>    
//struct my_in_addr
//{
//    unsigned int s_addr;
//};

// 十六进制转化为 点分十进制    
//char* inet_(struct my_in_addr in)
//{
//    // 拿到,注意由于我们不知道是大端还是小端,此时同意转换位大端    
//    unsigned int it = htonl(in.s_addr);
//    char* p = (char*)&it;
//    char* str = (char*)malloc(10);
//    for (int i = 0; i < 4; i++)
//    {
//        sprintf(str, "%d", p[i]);
//    }
//}

//int main()
//{
//    unsigned int it = 0x11;
//    char* p = (char*)&it;
//    char* str = (char*)malloc(10);
//    if (str == NULL)
//        return 0;
//    //for (int i = 0; i < 4; i++)
//    //{
//    //    //sprintf(str, "%d", p[i]);
//    //}
//    sprintf(str, "%d", it);
//
//    printf("%s\n", str);
//    printf("%d", strlen(str));
//
//    return 0;
//}

//int exchange(int* xp, int y)
//{
//	int x = *xp;
//	*xp = y;
//	return x;
//}
////中xp at% ebp + 8, 的意思是我们把xp的地址保存在% ebp + 8中吗
//int main()
//{
//	int a = 10;
//	printf("%p\n", &a);
//	exchange(&a, 10);
//	return 0;
//}
//int main()
//{
//	printf("%d\n", sizeof(long double));
//	return 0;
//}

//typedef unsigned char* byte_pointer;
//void show_bytes(byte_pointer start, int len)
//{
//    int i = 0;
//    for (; i < len; i++)
//    {
//        printf("%.2x ", start[i]);
//    }
//    printf("\n");
//}
//
//int main()
//{
//    char ret = 1;
//    char* p = &ret;
//    byte_pointer(p, (int)sizeof(ret));
//    return 0;
//}

//int main()
//{
//	printf("%d\n", (int)sizeof(long int));
//	printf("%d\n", (int)sizeof(long long));
//	return 0;
//}
