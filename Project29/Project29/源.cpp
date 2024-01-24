#include <iostream>

#define longint long long
#define reg register
#define qwq puts("fzy qwq ~");

using namespace std;

int n;
string t[10] = { "geng", "xin", "ren", "gui", "jia", "yi", "bing", "ding", "wu", "ji" };
string d[12] = { "shen", "you", "xu", "hai", "zi", "chou", "yin", "mao", "chen", "si", "wu", "wei" };

int main()
{
    cin >> n;
    cout << t[n % 10] << d[n % 12] << endl;
    return 0;
}