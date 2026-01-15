#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int roll;
    double gpa;
};

struct Examinee : public Student
{
    double score;
};

bool compareStudent(const Student &a, const Student &b)
{
    if (a.gpa == b.gpa)
        return a.roll < b.roll;
    return a.gpa < b.gpa;
}

void bucketSort(Examinee examinees[], int n)
{
    vector<Student> b[401];
    for (int i = 0; i < n; i++)
    {
        int tmp = examinees[i].score * 4;
        b[tmp].push_back({examinees[i].roll, examinees[i].gpa});
    }
    for (int i = 0; i < 401; i++)
    {
        sort(b[i].begin(), b[i].end(), compareStudent);
    }
    int j = 0;
    for (int i = 0; i < 401; i++)
    {
        for (auto it : b[i])
        {
            examinees[j].roll = it.roll;
            examinees[j].gpa = it.gpa;
            examinees[j].score = i / 4.0;
        }
    }
    for (int i = 0; i < n; i++)
        cout << "(" << examinees[i].score << ", " << examinees[i].gpa << ", " << examinees[i].roll << ")";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    Examinee examinees[n];
    for (int i = 0; i < n; i++)
    {
        cin >> examinees[i].gpa >> examinees[i].roll >> examinees[i].score;
    }
    bucketSort(examinees, n);
    return 0;
}
