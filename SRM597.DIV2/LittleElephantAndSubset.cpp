#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int Mod = 1000000007;

class LittleElephantAndSubset {
public:
	int getNumber(int);
private:
    int M;
    int factorial[10];
    int count[(1 << 10)];

    int f[(1 << 10)];

    void precomputation(int);
    int counting(const vector<int> &, const vector<int> &, bool);
};

int LittleElephantAndSubset::counting(const vector<int> &digit, const vector<int> &limit, bool heading_zero)
{
    if (limit.empty() && digit.empty()) return 1;
    if (digit.empty()) return 0; //empty set

    int len = digit.size();

    if (len > limit.size())
        return 0;

    if (len < limit.size())
    {
        if (!heading_zero && digit[0] == 0)
            return (len - 1) * factorial[len - 1];    
        else
            return factorial[len];
    }
    int ret = 0;
    for (int i = 0; i < len; ++ i)
    {
        if (!heading_zero && digit[i] == 0)
            continue;
        if (digit[i] < limit[0])
            ret += factorial[len - 1];
        else if (digit[i] == limit[0])
        {
            vector<int> next_digit;
            vector<int> next_limit;
            next_digit.clear();
            next_limit.clear();

            for (int j = 0; j < len; ++ j)
                if (i != j)
                    next_digit.push_back(digit[j]);
            for (int j = 1; j < len; ++ j)
                next_limit.push_back(limit[j]);
            ret += counting(next_digit, next_limit, true); 
        }
        else
            break;
    }
    return ret;
}

void LittleElephantAndSubset::precomputation(int N)
{
    factorial[0] = 1;
    for (int i = 1; i < 10; ++ i)
        factorial[i] = factorial[i - 1] * i;

    M = (1 << 10);

    vector<int> limit;
    vector<int> digit;

    limit.clear();
    while (N)
    {
        limit.push_back(N % 10);
        N /= 10;
    }
    reverse(limit.begin(), limit.end());

    for (int i = 0; i < M; ++ i)
    {
        digit.clear();
        int x = 0;
        for (int ptr = 1; ptr < M; ptr <<= 1, ++ x)
            if ((i & ptr) != 0)
                digit.push_back(x);
        count[i] = counting(digit, limit, false);
    }

}

int LittleElephantAndSubset::getNumber(int N) {
    precomputation(N);	
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 1; i < M; ++ i)
        for (int k = i; k < M; ++ k)
            if ((i | k) == k)
                f[k] = (f[k] + ((long long)count[i] * f[i ^ k]) % Mod) % Mod;

    int ans = 0;
    for (int i = 1; i < M; ++ i)
        ans = (ans + f[i]) % Mod;
    return ans;
}


double test0() {
	int p0 = 3;
	LittleElephantAndSubset * obj = new LittleElephantAndSubset();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 10;
	LittleElephantAndSubset * obj = new LittleElephantAndSubset();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 767;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 47;
	LittleElephantAndSubset * obj = new LittleElephantAndSubset();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 25775;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 4777447;
	LittleElephantAndSubset * obj = new LittleElephantAndSubset();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 66437071;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
