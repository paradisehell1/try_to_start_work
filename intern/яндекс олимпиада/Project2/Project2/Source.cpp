#include <iostream>
#include <string>
using namespace std;
struct Node
{
    int day;
    int hour;
    int minute;
    int id;
    string status;
    Node* next;
    int count = 0;
};
class List
{
private:
    Node* head; //"голова" связанного списка

public:
    List() //конструктор класса без параметров
    {
        head = NULL; //первого элемента пока нет
    }
    ~List() {
        while (head != NULL) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    //метод, добавляющий новый узел в список
    void addNode(int d, int h, int m, int i, string s)
    {
        Node* nd = new Node; //динамически создаем новый узел
        nd->day = d;
        nd->hour = h;
        nd->minute = m;
        nd->id = i;
        nd->status = s;
        nd->next = NULL;     //новый узел в конце, поэтому NULL
        if (head == NULL)     //если создаем первый узел
            head = nd;
        else                 //если узел уже не первый
        {
            Node* current = head;
            //ищем в цикле предшествующий последнему узел
            while (current->next != NULL)
                current = current->next;
            //предшествующий указывает на последний
            current->next = nd;
        }
        head->count = head->count + 1;
    }
    void find() {
        Node* current = head;
        Node* current1 = head;
        Node* current2 = head;
        List l1;
        while (current->next != NULL) {
            current1 = current;
            l1.addNode(current->day, current->hour, current->minute, current->id, current->status);
            while (current1->next != NULL) {

                if ((((current->day != current1->next->day) && (current->day + 1 != current1->next->day) && (current->day != current1->next->day + 1)) || (current->id != current1->next->id))) {
                    current1 = current1->next;
                    continue;

                }
                else
                    l1.addNode(current1->next->day, current1->next->hour, current1->next->minute, current1->next->id, current1->next->status);

                current1 = current1->next;

            }

            l1.printList();
            int sum;
            sum = l1.findABCS();
            if (l1.head->count != 0)
                cout << sum << endl;
            l1.~List();
            current = current->next;
        }

    }
    //метод, выводящий связанный список на экран
    void printList()
    {
        Node* current = head;
        while (current != NULL)
        {
            cout << current->day << " " << current->id << " " << current->status << endl;
            current = current->next;
        }
    }
    int findABCS() {
        Node* current = head;
        Node* current1 = head;
        Node* current2 = head;
        int sum;
        int sumh;
        int summ;
        int flag = 0;
        int flag1 = 0;
        current1 = current->next;
        current2 = current1->next;
        if (current2 == NULL) {
            if (current->status == "C") {
                sumh = current->hour - current1->hour;
                if (current->day != current1->day)
                    sumh = abs(sumh);
                summ = current->minute - current1->minute;
                if (summ < 0) {
                    summ = summ + 60;
                }
                sumh = sumh * 60;
                sum = sumh + summ;

            }
            else
            {
                sumh = current1->hour - current->hour;
                if (current->day != current1->day)
                    sumh = abs(sumh);
                summ = current1->minute - current->minute;
                if (summ < 0) {
                    summ = summ + 60;
                }
                sumh = sumh * 60;
                sum = sumh + summ;

            }
            return sum;
        }
        if (current->status == "S" || current->status == "C") {
            flag1 = 1;
        }
        if (current1->status == "S" || current1->status == "C") {
            flag1 = 2;
        }
        if (current2->status == "S" || current2->status == "C") {
            flag1 = 3;
        }
        if (current->status == "A") flag = 1;
        if (current1->status == "A") flag = 2;
        if (current2->status == "A") flag = 3;
        if (flag == 1 && flag1 == 2) {
            sumh = current->hour - current1->hour;
            if (current->day != current1->day)
                sumh = abs(sumh);
            summ = current->minute - current1->minute;
            if (summ < 0) {
                summ = summ + 60;
            }
            sumh = sumh * 60;
            sum = sumh + summ;


        }
        if (flag == 1 && flag1 == 3) {
            sumh = current->hour - current2->hour;
            if (current->day != current2->day)
                sumh = abs(sumh);
            summ = current->minute - current2->minute;
            if (summ < 0) {
                summ = summ + 60;
            }
            sumh = sumh * 60;
            sum = sumh + summ;
        }
        if (flag == 2 && flag1 == 3) {
            sumh = current1->hour - current2->hour;
            if (current1->day != current2->day)
                sumh = abs(sumh);
            summ = current1->minute - current2->minute;
            if (summ < 0) {
                summ = summ + 60;
            }
            sumh = sumh * 60;
            sum = sumh + summ;
        }
        if (flag == 2 && flag1 == 1) {
            sumh = current1->hour - current->hour;
            if (current1->day != current->day)
                sumh = abs(sumh);
            summ = current1->minute - current->minute;
            if (summ < 0) {
                summ = summ + 60;
            }
            sumh = sumh * 60;
            sum = sumh + summ;
        }
        if (flag == 3 && flag1 == 1) {
            sumh = current2->hour - current->hour;
            if (current2->day != current->day)
                sumh = abs(sumh);
            summ = current2->minute - current->minute;
            if (summ < 0) {
                summ = summ + 60;
            }
            sumh = sumh * 60;
            sum = sumh + summ;
        }
        if (flag == 3 && flag1 == 2) {
            sumh = current2->hour - current1->hour;
            if (current2->day != current1->day)
                sumh = abs(sumh);
            summ = current2->minute - current1->minute;
            if (summ < 0) {
                summ = summ + 60;
            }
            sumh = sumh * 60;
            sum = sumh + summ;
        }

        return sum;
    }

};
int main() {
    List l;
    int q;
    int d; int h; int m; int i; char s;
    string d1 = ""; string h1 = ""; string m1 = ""; string id1 = ""; string s1 = "";
    int j = 0;
    cin >> q;
    char c[1000];
    for (int i1 = 0; i1 < q; i1++) {
        cin >> d1 >> h1 >> m1 >> id1 >> s1;
        d = stoi(d1);
        h = stoi(h1);
        m = stoi(m1);
        i = stoi(id1);
        l.addNode(d, h, m, i, s1);

    }
    l.find();
}