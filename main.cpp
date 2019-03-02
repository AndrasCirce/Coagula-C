#include <iostream>

using namespace std;
/**area de un triangulo**/
int main()
{
    float base, altura,area;

    cout <<"Dame la base del triangulo"<<endl;
    cin>>base;

    cout <<"Dame la altura del triangulo"<<endl;
    cin>>altura;

    area=(base*altura)/2;

    cout << "El area del rectangulo es "<<area << endl;
    return 0;
}
