#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> arr;
public:
    void Enqueue(int x) {
        arr.push_back(x);
    }

    void Dequeue() {
        if (!arr.empty()) {
            arr.erase(arr.begin());
        }
    }

    void PrintQueue() {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int times, input;

    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> input;
        queue.Enqueue(input);
    }

    cin >> times;
    for (int i = 0; i < times; i++) {
        queue.Dequeue();
    }

    queue.PrintQueue();

    return 0;
}
