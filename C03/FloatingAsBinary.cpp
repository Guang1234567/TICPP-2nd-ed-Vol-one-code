//: C03:FloatingAsBinary.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
//{L} printBinary
//{T} 3.14159
#include "printBinary.h"
#include <cstdlib>
#include <iostream>

using namespace std;

long FloatToHex(float HEX)//单精度浮点数到十六进制
{
    return *((long *) &HEX);
}

long long DoubleToHex(double HEX)//双精度浮点数到十六进制
{
    return *((long long *) &HEX);
}

float HexToFloat(unsigned char bytes[4]) {
    return *((float *) bytes);
}

/**
 * https://www.jianshu.com/p/5760d471715a
 * 如何手工算出 263.3 在按照单精度的规则下的二进制形式
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Must provide a number" << endl;
        exit(1);
    }

    for (int i = 1; i < argc; i++) {

        float d = (float) atof(argv[i]);

        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++" << endl;
        wstring wstr = L"输入的浮点数是:";
        //为使得wcout输出中文(中英混合)，仅需要下述2条语句：
        setlocale(LC_ALL, "");                          // 需要 #include <locale>
        ios_base::sync_with_stdio(false);       // 缺少的话，wcout wchar_t 会漏掉中文
        //完全不需要  std::wcout.imbue(std::locale(""));
        //locale oldLoc = wcout.imbue(locale("chs"));
        wcout << endl << wstr << L"(第" << i << L"个)" << endl << d << endl << endl;

        unsigned char *cp =
                reinterpret_cast<unsigned char *>(&d);

        int endIdx = sizeof(d) - 1;

        for (int j = endIdx; j >= 0; j--) {
            wcout << L'第' << j + 1 << L"个字节 : " << endl;
            printBinary(cp[j]);
            cout << endl;
        }

        cout << endl << "+++++++++++++++++++++++++++++++++" << endl << endl;

        wcout << L"对比一下:  0100 0011 1000 0011 1010 0110 0110 0110" << endl;

        cout << "sizeof(long) = " << sizeof(long) << endl;
        cout << "sizeof(int) = " << sizeof(int) << endl;

        cout << "in hex : " << hex << FloatToHex(d) << endl;

        // 尝试修改内存
        // https://www.cnblogs.com/zhugehq/p/5918599.html
        printf("%f\r\n", d);

        printf("%p\r\n", &d);

        //此处用WinHex查看内存中f的存储是否和预想的一样

        system("pause");
        //此处用WinHex修改f在内存中的数值，并验证是否的到预期的新浮点数
        printf("%f\r\n", d);

        system("pause");
    }

    unsigned char pMem[] = {0x00, 0x00, 0x60, 0x40};
    cout << HexToFloat(pMem) << endl << hex << FloatToHex(HexToFloat(pMem)) << endl;

    cout << hex << FloatToHex(3.5f);

    exit(EXIT_SUCCESS);
} ///:~
