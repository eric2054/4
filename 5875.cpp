#include <iostream>
using namespace std;

class ListNode {
   public:
    ListNode(int a, int b) {
        coef = a;
        exp = b;
        link = 0;
    }

   private:
    int coef;
    int exp;
    ListNode* link;
    friend class PolyList;
};

class PolyList {
   public:
    void InsertLast(int, int);
    void Add(PolyList&);
    void PrintList();

   private:
    ListNode* first = 0;
    ListNode* last = 0;
};

void PolyList::InsertLast(int coef, int exp) {
    ListNode* newNode = new ListNode(coef, exp);
    if (last == 0)
        first = newNode;
    else
        last->link = newNode;
    last = newNode;
}

void PolyList::Add(PolyList& b) {
  
    ListNode *current_a = first, *current_b = b.first;
    ListNode* preNode = 0;
    
    while (current_a != 0 && current_b != 0) {
        
        if (current_a->exp == current_b->exp) {
          
            current_a->coef = current_a->coef + current_b->coef;
            preNode = current_a;

            current_a = current_a->link;
            current_b = current_b->link;
        }

        else if (current_a->exp > current_b->exp || current_b == 0) {
            preNode = current_a;
            current_a = current_a->link;

        }

        else if (current_a->exp < current_b->exp) {
            ListNode* nextNode_a = current_a;  
            ListNode* newNode = new ListNode(current_b->coef, current_b->exp);
            if (nextNode_a == first) {  
                newNode->link = first;
                first = newNode;
            } else {  
                preNode->link = newNode;
                newNode->link = nextNode_a;
            }
            preNode = newNode;
            current_b = current_b->link;
        }
    }
    while (current_b != 0) {
        last->link = current_b;
        last = current_b;
        preNode = current_b;
        current_b = current_b->link;
    }
}

void PolyList::PrintList() {
    ListNode* currentNode = first;
    for (; currentNode != 0; currentNode = currentNode->link) {
        cout << currentNode->coef << "x^" << currentNode->exp << " ";
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    PolyList A, B;
    int times, input, input2;
    for (cin >> times, times /= 2; times > 0; times--) {
        cin >> input >> input2;
        A.InsertLast(input, input2);
    }
    for (cin >> times, times /= 2; times > 0; times--) {
        cin >> input >> input2;
        B.InsertLast(input, input2);
    }
    A.Add(B);
    A.PrintList();
}
