#include <assert.h>
#include<iostream>
using namespace std;
class Polynomial
{
    private :
    double* arr;
    int length;
    friend ostream& operator << (ostream& os , const Polynomial& p);
    friend istream& operator >> (istream& is , Polynomial& p);

    public:
    Polynomial(int order = 100)
    {
        if (order < 0)
        {
            cout << "The Polynomial degree must be greater than or equal zero. " << endl;
            length = 100;
        }
        else
            length = order + 2;
        arr = new double[length];
        assert(arr!= nullptr);
        for (int i = 0; i < length ; i++)
        {
            arr[i] = 0.0;
        }
    }
    ~Polynomial()
    {
        delete [] arr;
    }
    int max(int x , int y) const
    {
        if (x>y)
            return x;
        else
            return y;
    }
    int min(int x , int y) const
    {
        if (x>y)
            return y;
        else
            return x;
    }
    Polynomial operator + (const Polynomial& other)
    {
        Polynomial R;
        R.length = max(length , other.length);
        for (int i = 0 ; i < min(length , other.length) ; i++)
        {
            R.arr[i] = arr[i] + other.arr[i];
        }
        if (R.length == length)
        {
            for (int i = min(length , other.length) ; i < R.length ; i++)
            {
                R.arr[i] = arr[i];
            }
        }
        else
        {
            for (int i = min(length , other.length) ; i < R.length ; i++)
            {
                R.arr[i] = other.arr[i];
            }
        }
        return R;
    }
    Polynomial operator - (const Polynomial& other)
    {
        Polynomial R;
        R.length = max(length , other.length);
        for (int i = 0 ; i < min(length , other.length) ; i++)
        {
            R.arr[i] = other.arr[i] - arr[i];
        }
        if (R.length == length)
        {
            for (int i = min(length , other.length) ; i < R.length ; i++)
            {
                R.arr[i] = -arr[i];
            }
        }
        else
        {
            for (int i = min(length , other.length) ; i < R.length ; i++)
            {
                R.arr[i] = other.arr[i];
            }
        }
        return R;
    }


};

ostream& operator<<(ostream& os, const Polynomial& p)
{
    bool firstTerm = true;
    for (int i = p.length - 1; i > 0; i--)
    {
        double coef = p.arr[i];
        if (coef == 0)
            continue;
        if (!firstTerm)
        {
            os << (coef > 0 ? " + " : " - ");
        }
        else
        {
            if (coef < 0)
                os << "-";
            firstTerm = false;
        }
        if (abs(coef) != 1 || i == 1)
            os << abs(coef);
        if (i > 1)
            os << "x";
        if (i > 2)
            os << "^" << (i - 1);
    }
    if (firstTerm)
        os << "0";
    os << " = " << p.arr[0];

    return os;
}

istream& operator >> (istream& is , Polynomial& p)
{
    cout << "Enter the right hand side of the polynomial : ";
    is >> p.arr[0];
    for (int i = 1; i <= p.length-1 ; i++)
    {
        cout << "The coefficient of x^" << i-1 << " is : ";
        is >> p.arr[i];
    }
    return is;
}
void progress()
{
    int p,q;
    cout << "Enter the order of the first polynomial : " << endl;
    cin >> p;
    Polynomial F(p);
    cin >> F;
    cout << "Enter the order of the second polynomial : " << endl;
    cin >> q;
    Polynomial S(q);
    cin >> S;
    cout <<endl;
    cout << "The first polynomial is : " << F << endl;
    cout << "The second polynomial is : " << S << endl;
    cout << "Sum of polynomials is : " << F+S << endl;
    cout << "Difference of polynomials is : " << F-S << endl;
}
void menu()
{
    cout << "Welcome to the polynomials' operations program! " << endl;
    cout << "Do you want to start ?\na)yes\nb)no" << endl;
    char answer;
    cin >> answer;
    while (answer != 'a' && answer != 'b')
    {
        cout << "Please choose either a or b" << endl;
        cin >> answer;
    }
    while (answer != 'b')
    {
        progress();
        cout << "\nDo you want to continue ?\na)yes\nb)no" << endl;
        cin >> answer;
        while (answer != 'a' && answer != 'b')
        {
            cout << "Please choose either a or b" << endl;
            cin >> answer;
        }
    }
    cout << "I hope u enjoyed :) " << endl;
}
int main()
{
    menu();
}