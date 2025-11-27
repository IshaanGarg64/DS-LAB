#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> h;

    void push(int x)
    {
        h.push_back(x);
        int i = h.size() - 1;
        while (i > 0 && h[(i - 1) / 2] < h[i])
        {
            swap(h[(i - 1) / 2], h[i]);
            i = (i - 1) / 2;
        }
    }

    void pop()
    {
        if (h.empty())
            return;
        h[0] = h.back();
        h.pop_back();
        int i = 0;

        while (true)
        {
            int l = 2 * i + 1, r = 2 * i + 2, mx = i;
            if (l < h.size() && h[l] > h[mx])
                mx = l;
            if (r < h.size() && h[r] > h[mx])
                mx = r;
            if (mx == i)
                break;
            swap(h[i], h[mx]);
            i = mx;
        }
    }

    int top()
    {
        if (h.empty())
            return -1;
        return h[0];
    }

    bool empty()
    {
        return h.empty();
    }
};

int main()
{
    MaxHeap pq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";
    return 0;
}
