#include<iostream>
using namespace std;
class Move
{
public:
    void moveGo(int i, int a, int b, int c);
    void display(int i, int a, int b);
private:
    static int count;
};
int Move::count = 1;

void Move::moveGo(int i, int a, int b, int c)
{
    if (1 == i)
    {
        display(1, a, b);
    }
    else
    {
        moveGo(i - 1, a, c, b);
        display(i, a, b);
        moveGo(i - 1, c, b, a);
    }
}
void Move::display(int i, int a, int b)
{
    printf(" %dth:move %dth from %dth to %dth\n", count,i, a, b);
    count++;
}
int main()
{
    Move mo;
    mo.moveGo(4,1,2,3);
    cout << endl;
    system("pause");
    return 0;
}