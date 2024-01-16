#include<bits/stdc++.h>
#define max_std 10

using namespace std;

struct static_array{
    int Array[max_std];
    int len = 0;

    void print()
    {
        if (len == 0)
        {
            cout<<"Array is empty."<<endl;
            return;
        }
        cout<<"Printing array elements:"<<endl;
        for(int i = 0; i < len; i++)
        {
            cout<<i<<": "<<this->Array[i]<<endl;
        }
    }
    /// Insert
    void insert_element_first(int val)
    { ///push
        len++;
        for(int i=len-1;i>0;i--)
        {
            Array[i]=Array[i-1];
        }
        Array[0]=val;
        return;
    }

    void insert_element_last(int val)
    { ///queue
        len++;
        Array[len-1]=val;
        return;

    }

    void insert_element_any(int pos, int val)
    {
        if(pos<=len)
        {
            len++;
            for(int i=len-1;i>pos;i--)
            {
                Array[i]=Array[i-1];
            }
            Array[pos]=val;
            return;
        }
        else return;
    }

    /// Delete
    int delete_element_any(int pos)
    {
        if(pos<len)
        {
            int c=Array[pos];
            for(int i=pos;i<len-1;i++)
            {
                Array[i]=Array[i+1];
            }
            len--;
            return c;
        }
        else return -1;
    }

    int delete_element_first()
    { ///dequeue
        int c=Array[0];
        for(int i=0;i<len-1;i++)
        {
            Array[i]=Array[i+1];
        }
        len--;
        return c;
    }

    int delete_element_last()
    { ///pop
        int c=Array[len-1];
        len--;
        return c;
    }

    /// Rotate
    void rotate_left()
    {
        int c=Array[0];
        for(int i=0;i<len-1;i++)
            {
                Array[i]=Array[i+1];
            }
        Array[len-1]=c;
        return;
    }

    void rotate_right()
    {
        int c=Array[len-1];
        for(int i=len-1;i>0;i--)
            {
                Array[i]=Array[i-1];
            }
        Array[0]=c;
        return;
    }

    /// Sort
    void sort_()
    {
        for(int i=0;i<len;i++)
        {
            for(int j=i;j<len;j++)
            {
                if(Array[i]>Array[j])
                {
                    int temp=Array[i];
                    Array[i]=Array[j];
                    Array[j]=temp;
                }
            }
        }
    }
};
int main(){
    static_array arr;
    arr.print();    ///Array is empty.
    arr.insert_element_last(10);
    arr.insert_element_first(20);
    arr.insert_element_last(30);
    arr.insert_element_last(40);
    arr.insert_element_first(50);
    arr.insert_element_last(60);



    arr.print();
    /*
    Printing array elements:
    0: 50
    1: 20
    2: 10
    3: 30
    4: 40
    5: 60*/



    cout<<arr.delete_element_last()<<endl;  ///60
    cout<<arr.delete_element_first()<<endl; ///50
    cout<<arr.delete_element_first()<<endl; ///20
    cout<<arr.delete_element_last()<<endl;  ///40
    arr.print();
    /*
    Printing array elements:
    0: 10
    1: 30*/
    arr.insert_element_any(0, 60);
    arr.insert_element_any(5, 60); ///Can not insert at this position.
    arr.insert_element_any(3, 60);
    arr.print();
    /*
    Printing array elements:
    0: 60
    1: 10
    2: 30
    3: 60*/
    cout<<arr.delete_element_any(0)<<endl;  ///60
    cout<<arr.delete_element_any(5)<<endl;  ///Can not delete at this position. -1
    cout<<arr.delete_element_any(2)<<endl;  ///60
    arr.print();
    /*
    Printing array elements:
    0: 10
    1: 30*/
    arr.rotate_left();
    arr.rotate_right();
    arr.print();
    /*
    Printing array elements:
    0: 10
    1: 30*/
    arr.sort_();
    arr.print();
    /*
    Printing array elements:
    0: 10
    1: 30*/
}