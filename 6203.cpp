#include <iostream>
#include <queue>
using namespace std;

class QueueSystem {
private:
    queue<int> q;
public:
    void Enqueue(int x) {
        q.push(x);
    }

    void Dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    void PrintQueue() {
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    QueueSystem queueSystem;
    int n, input;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input;
        queueSystem.Enqueue(input);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        queueSystem.Dequeue();
    }

    queueSystem.PrintQueue();

    return 0;
}

