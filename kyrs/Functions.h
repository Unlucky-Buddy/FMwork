#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int x;
    int y;
    int w;
};

vector <int> leader;
vector <edge> e;

bool comparator(const edge &a, const edge &b);
int getLeader(int x);
bool unite(int x, int y);