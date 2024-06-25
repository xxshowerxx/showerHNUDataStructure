#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793238463;
struct Point {
    int x, y;
    double du = 0;
    Point *next = NULL;
    Point *prev = NULL;
    Point() {}
    Point(int ix, int iy) : x(ix), y(iy) {}
    Point(int ix, int iy, int d) : x(ix), y(iy), du(d) {}
    void print() {
        cout << x << " " << y << endl;
    }
};
bool cmp(const Point &a, const Point &b) {
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;
}
class List {
public:
    Point *head;
    int size = 0;
    List() {
        init();
    }
    ~List() {
        clear();
    }
    List(const vector<Point> &point) {
        init();
        Point *l = head, *r = head->next;
        head->x = point[0].x;
        head->y = point[0].y;
        head->du = point[0].du;
        size = point.size();
        for (int i = 1; i <(int) point.size(); ++i) {
            Point *tmp = new Point(point[i].x, point[i].y, point[i].du);
            tmp->prev = l;
            tmp->next = r;
            l->next = tmp;
            r->prev = tmp;
            l = l->next;
        }
    }
    void init() {
        head = new Point;
        head->next = head;
        head->prev = head;
    }
    void clear() {
        Point *p = head->next, *q = p->next;
        while (q != head) {
            delete p;
            p = q;
            q = q->next;
        }
        delete head;
    }
    void solve() {
        Point *x = head, *rx = head->next, *rrx = head->next->next;
        while(rrx!=head->next){
            double k = (x->x - rx->x) * (rrx->y - rx->y) - (x->y - rx->y) * (rrx->x - rx->x);
            if (k >= 0) {
                x->next = rrx;
                rrx->prev = x;
                if(rx==head)head=x;
                delete rx;
                rx = x;
                x = rx->prev;
                size--;
            } else {
                x = x->next;
                rx = rx->next;
                rrx = rrx->next;
            }
        }
    }
    void print() {
        Point *p = head;
        do{
            p->print();
            p = p->next;
        }while(p!=head);
    }
};
int main() {
    int n;
    cin >> n;
    vector<Point> point(n);
    for (int i = 0; i < n; ++i) {
        cin >> point[i].x >> point[i].y;
    }
    if (n == 1) point[0].print();
    else if (n == 2) {
        sort(point.begin(), point.end(), cmp);
        for (int i = 0; i < n; ++i) {
            point[i].print();
        }
    } else {
        if (point[0].x == point[1].x) {
            int i;
            for (i = 2; i < n; ++i) {
                if (point[i].x != point[0].x) {
                    break;
                }
            }
            if (i == n) {
                sort(point.begin(), point.end(), cmp);
                point[0].print();
                point[n - 1].print();
                return 0;
            }
        } else {
            double k = 1.0 * (point[0].y - point[1].y) / (point[0].x - point[1].x);
            int i;
            for (i = 2; i < n; ++i) {
                if (1.0 * (point[0].y - point[i].y) / (point[0].x - point[i].x) != k) {
                    break;
                }
            }
            if (i == n) {
                sort(point.begin(), point.end(), cmp);
                point[0].print();
                point[n - 1].print();
                return 0;
            }
        }
        double X=0 ,Y=0;
        for(int i=0;i<n;++i)
        {
            X+=point[i].x;
            Y+=point[i].y;
        }
        X/=n*1.0;
        Y/=n*1.0;
        for (auto &it: point) {
            double d;
            d = atan2(it.y - Y, it.x - X)+PI/2.0;
            if(d<0) d+=PI*2;
            it.du = d * 180/PI;
        }
        sort(point.begin(), point.end(), [X, Y](const Point &a, const Point &b) {
            if (a.du == b.du)
                return (a.x - X) * (a.x - X) + (a.y - Y) * (a.y - Y) < (b.x - X) * (b.x - X) + (b.y - Y) * (b.y - Y);
            return a.du < b.du;
        });
        List sPoint(point);
        sPoint.solve();
        Point *p=sPoint.head;
        vector<Point> ans;
        do {
            Point tmp(p->x,p->y);
            ans.push_back(tmp);
            p=p->next;
        }while(p!=sPoint.head);
        sort(ans.begin(),ans.end(),cmp);
        for (int i = 0; i <(int)ans.size(); ++i) {
            ans[i].print();
        }
    }
    return 0;
}



